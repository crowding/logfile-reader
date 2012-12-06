#!/usr/bin/env RScript
loadData <- function(infile, outfile) {
  suppressPackageStartupMessages({
    require(plyr)
  })
  trial = list();
  result = list();
  stimulus = list();
  beforeRun = list();
  afterRun = list();
  params = list();

  trials = list2env(list(.nrow = 0))
  runs = list2env(list(.nrow = 0))
  triggers = list2env(list(.nrow = 0))
  stimuli = list2env(list(.nrow=0))
  eye = list2env(list(.nrow = 0))

  run.index = 0
  trial.index = 0
  trigger.index = 0
  stimulus.index = 0
  eye.index = 0

  stowRow <- function(env, index, l) {
    l <- lapply(l, function(x) if(length(x) != 1) list(x) else x)
    
    current.length <- env$.nrow
    if (any(index > current.length)) {
      #cat("Expanding\n");
      current.length <- 2^ceiling(log2(max(index)))
      for (n in ls(env)) {
        length(env[[n]]) <- current.length
      }
      env$.nrow <- current.length
    }  
    new.names <- setdiff(names(l), ls(env))
    if (length(new.names) > 0) {
      ##cat("new column(s)", paste(new.names, collapse=', '), '\n')
    }
    for (n in new.names) {
      env[[n]] <- rep(as.numeric(NA),current.length)
    }

    for (n in names(l)) {
      if (!is.null(l[[n]]))
        ##this looks CRAZY but it's the only way to get linear performance here!!!
        eval(substitute(var[ix] <- data,
                        list(var=as.name(n), ix=index, data = l[[n]])),
             envir = env)
    }
  }

  beginRun <- function(...) {
    if (run.index > 0) {
      stowRow(runs, run.index, c(beforeRun=beforeRun, afterRun=afterRun, i = run.index));
    }
    run.index <<- run.index + 1
    beforeRun <<- list(...)
    afterRun <<- list(...)
    cat(sprintf("%s: Run %d\n", infile, run.index))
  }

  beginTrial <- function(...) {
    if (trial.index > 0) {
      stowRow(trials, trial.index, c(trial=trial,result=result,params=params
                                     , i=trial$i, runs.i = trial$runs.i));
    }
    trial.index <<- trial.index + 1
    trial <<- list(i = trial.index, runs.i = run.index, ...)
    params <<- list(i = trial.index, runs.i = run.index, ...)
    result = list(i = trial.index, runs.i = run.index, ...);
    if (trial.index %% 10 == 0) {
      cat(sprintf("%s: Trial %d\n", infile, trial.index))
    }
  }

  beginStimulus <- function(...) {
    if (trial.index > 0) {
      stowRow(stimuli, stimulus.index, c(stimulus=stimulus, i=stimulus$i
                                         ,trials.i = stimulus$trials.i));
    }
    stimulus.index <<- stimulus.index + 1
    ##mark it also in the triggers, so that we can more easily align the events
    storeTrigger(name="BEGIN STIMULUS", stimuli.i = stimulus.index)
    stimulus <<- list(i = stimulus.index, trials.i = trial.index, ...)
    if (stimulus.index %% 50 == 0) {
       cat(sprintf("%s: Stim %d\n", infile, stimulus.index))
    }
  }

  storeTrigger <- function(...) {
    trigger.index <<- trigger.index+1
    trigger <- list(i = trigger.index, trials.i = trial.index, ...)
    stowRow(triggers, trigger.index, trigger);
  }

  undumpable <- function(...) NA

  cell <- function(...) array(data=list(NULL), dim=c(...))

  logical <- function(x) if (is.null(dim(x))) as.logical(x) else array(as.logical(x), dim(x))

  uint32 <- force

  zeros <- function(...) array(0, dim=c(...));

  error <- function(class="", identifier="") {
    storeTrigger(name="ERROR", class=class, identifier=identifier)
  }
  
  eyeData <- function(x) {
    if (length(x) > 0) {
      i <- eye.index + 1:dim(x)[2]
      eye.index <<- eye.index + dim(x)[2]
    } else {
      dim(x) <- c(3,0)
    }
    trial$eyeData <<- x;
    ##for now we aren't stowing eye data in a separate table, but it might be interesting.
    ##to store the time series as a huge table...
    ##stowRow(eye, i, list(i = i, trial.index = trial.index, x = x[1,], y = x[2,], t = x[3,]))
  }

  truncate <- function(env, last) {
    for (n in ls(env)) {
      length(env[[n]]) <- last
    }
    env$.nrow <- last
    0
  }

  ##we rely on an external parser to translate text into evaluable R expressions.
  if (grepl("\\.gz$", infile)) {
    pip <- base::pipe(sprintf('gzcat "%s" | %s', infile, paste(sep='', getScriptDirectory(), '/', 'logfile') ), 'r')
  } else {
    pip <- base::pipe(sprintf('%s < "%s"', paste(sep='', getScriptDirectory(), '/', 'logfile'), infile), 'r')
  }
  on.exit(close(pip))

  ##we parse 1000 statement chunks
  while (length(chunk <- parse(pip, 1000)) > 0) {
    eval(chunk);
  }

  #then finish any runs/trials/stimuli that are still open.
  capture.output({
    beginRun();
    beginTrial();
    beginStimulus();
  })
  
  truncate(runs, run.index-1)
  truncate(trials, trial.index-1)
  truncate(triggers, trigger.index)
  truncate(stimuli, stimulus.index-1)

  data.frame.sanely <- function(...) {
    L <- as.list(...)
    L <- lapply(L, function(x) substitute(I(x), list(x=x)))
    do.call(data.frame, L)
  }

  oops.NA <- colwise(function(col) {
    ##correct for list-mode columns that started out as numeric
    ##columns. Luckily, MATLAB doesn't have anything equivalent to NA,
    ##so this is safe.
    if (mode(col) == "list") {
      col[is.na(col)] <- list(NULL)
    }
    col
  })

  runs <- oops.NA(data.frame.sanely(as.list(runs)))
  trials <- oops.NA(data.frame.sanely(as.list(trials)))
  triggers <- oops.NA(data.frame.sanely(as.list(triggers)))
  stimuli <- oops.NA(data.frame.sanely(as.list(stimuli)))
  
  save(runs, trials, triggers, stimuli, file=outfile)
  invisible(0)
}

getScriptDirectory <- function() {
  #the best guass at the directory of the current script
  argv <- commandArgs(trailingOnly = FALSE)
  base_dir <- dirname(substring(argv[grep("--file=", argv)], 8))
  if (length(base_dir) == 0) {
    probe <- function(x) x+1
    base_dir <- getSrcDirectory(probe)
  }
  base_dir
}

if ("--slave" %in% commandArgs()) {##RScript...
  my.args <- commandArgs(trailingOnly=TRUE)
  do.call("loadData", as.list(my.args))
}

