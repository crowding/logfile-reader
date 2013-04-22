%{
#include <stdio.h>
#include "strbuilder.h"

extern int yylineno;

int printNextLine = 1;

#define FINISH_LINE( x, y ) if (printNextLine) {strb_print( y ); putchar('\n');}; printNextLine = 1; strb_clean(); x = 0;

const char *preamble = 
  "#!/usr/bin/env Rscript\n";

%}

%union { 
  struct strbuilder *s; 
  int *i;
}; 

/*declare tokens*/
%token <s> NUMBER WORD DOTWORD QUOTED
%token <s> BEGIN_ TRIGGER END EYE_DATA AUDIO_DATA ERROR_ REWARD FRAME_SKIP FRAME_COUNT EVENT_CODE AUDIO_UNDERFLOW AUDIO_SAMPLE FLUID
%token <i> EOL EQUAL LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE COMMA SEMICOLON COLON

%type <i> datafile line
%type <s> begin word words eyeData audioData data literalData matrixContents fullMatrixRow partMatrixRow multipleMatrixRows fcall arguments assignment address addressSuffix addressSuffixes trigger structfields structfield reward frameSkip frameCount eventCode audioUnderflow audioSample error_ fluid

%error-verbose

%expect 1

%%

datafile:
datafile line EOL
| datafile EOL
| {$$ = 0;}
;

optionalSemicolon:
| SEMICOLON

/* Parse each type of line. As each line is parsed, an R translation is built up; just print that string. */
line:
begin optionalSemicolon {FINISH_LINE( $$, $1 )}
 | eyeData optionalSemicolon {FINISH_LINE( $$, $1 )}
 | audioData optionalSemicolon {FINISH_LINE( $$, $1 )}
 | error_ optionalSemicolon {FINISH_LINE( $$, $1 )}
 | assignment optionalSemicolon {FINISH_LINE( $$, $1 )}
 | trigger {FINISH_LINE( $$, $1 )}
 | reward optionalSemicolon {FINISH_LINE( $$, $1 )}
 | fluid optionalSemicolon {FINISH_LINE( $$,$1 )}
 | frameSkip optionalSemicolon {FINISH_LINE( $$, $1 )}
 | frameCount optionalSemicolon {FINISH_LINE( $$, $1 )}
 | eventCode optionalSemicolon {FINISH_LINE( $$, $1 )}
 | audioUnderflow optionalSemicolon {FINISH_LINE( $$, $1 )}
 | audioSample optionalSemicolon {FINISH_LINE( $$, $1 )}
 | end {$$ = 0; strb_clean();}
 ;

end:
END
| end word
;

/* BEGIN lines begin a block. Asignment lines, following, refer to that block */
begin:
BEGIN_ word {
  const char *type = strb_cat($2)->str;
  if (!strcmp(type, "EXPERIMENT_RUN")) {
    $$ = strb_const("beginRun()\n");
  } else if (!strcmp(type, "TRIAL")) {
    $$ = strb_const("beginTrial()\n");
  } else if (!strcmp(type, "STIMULUS")) {
    $$ = strb_const("beginStimulus()\n");
  } else {
    yyerror("unknown run type"); YYERROR;
  }
}
| BEGIN_ word words {
  const char *type = strb_cat($2)->str;
  if (!strcmp(type, "EXPERIMENT_RUN")) {
    $$ = strb_append(strb_append(strb_const("beginRun(id='"), $3), strb_const("')"));
  } else if (!strcmp(type, "TRIAL")) {
    $$ = strb_append(strb_append(strb_const("beginTrial(id='"), $3), strb_const("')")); 
  } else if (!strcmp(type, "STIMULUS")) {
    $$ = strb_append(strb_append(strb_const("beginStimulus(id='"), $3), strb_const("')"));
 } else {
    yyerror("unknown run type"); YYERROR;
  }
}
;

word: /* all things that are "words" although some are tokenized
	 separately. But all are captured in strings */
    WORD
  | BEGIN_
  | TRIGGER
  | END
  | EYE_DATA
  | AUDIO_DATA
  | ERROR_
  | FLUID
  | REWARD
  | FRAME_SKIP
  | EVENT_CODE
  | AUDIO_UNDERFLOW
  | AUDIO_SAMPLE
  ;

words: word
| word words { $$ = strb_append(strb_append($1,strb_const(" ")),$2)}
;

eyeData:
EYE_DATA data { $$ = strb_append(strb_append(strb_const("eyeData("), $2), strb_const(")")); }
;

audioData:
AUDIO_DATA data { $$ = strb_append(strb_append(strb_const("audioData("), $2), strb_const(")")); }
;

error_:
ERROR_ word COLON word {
  $$ = strb_build(strb_const("error(class=\""), $2, strb_const("\", identifier=\""), $4, strb_const("\")"), NULL);
}
| ERROR_ word {
    $$ = strb_build(strb_const("error(identifier=\""), $2, strb_const("\""), NULL); }
| ERROR_ {
    $$ = strb_const("error()"); }
;

fluid:
FLUID structfields {
  $$ = strb_build(strb_const("storeTrigger(name=\"FLUID\", "), $2, strb_const(")"), NULL);
}
;

data:
literalData
| fcall
;

literalData: 
NUMBER
| LBRACKET matrixContents RBRACKET {$$ = $2;}
| LBRACKET RBRACKET {$$ = strb_const("numeric(0)");}
| QUOTED {
  /* replace doubled-quotes with escaped-quotes. */
  strbuilder *new = strb_cat($1);
  char *cur = (char *) new->str;
  if (! *cur) {
    $$ = new;
  } else {
    while(*(++cur)) {
      if (*cur == '\'' && *(cur-1) == '\'') {
	*(cur-1) = '\\';	     
	if (!*(++cur)) {
	  break;
	}
      }
    }
  }
  $$ = strb_build(strb_const("'"), new, strb_const("'"), NULL);
}
;

matrixContents:
fullMatrixRow
| fullMatrixRow SEMICOLON multipleMatrixRows { $$ = strb_build(strb_const("rbind("), $1, strb_const(", "), $3, strb_const(")"), NULL); }
;

multipleMatrixRows:
fullMatrixRow
| multipleMatrixRows SEMICOLON fullMatrixRow { $$ = strb_build($1, strb_const(", "), $3, NULL) }
;

fullMatrixRow:
partMatrixRow { $$ = strb_build(strb_const("c("), $1, strb_const(")"), NULL) }
;

partMatrixRow:
data
| partMatrixRow data  {$$ = strb_append(strb_append($1, strb_const(", ")), $2)}
| partMatrixRow COMMA data  {$$ = strb_append(strb_append($1, strb_const(", ")), $3);}
;

fcall:
word LPAREN arguments RPAREN { $$ = strb_build($1, strb_const("("), $3, strb_const(")"), NULL) }
;

 /* the printNextLine flag is a hack to skip over instantiation statements like
  * trial.objects{4} = movingObject(trial.objects{4}) */
arguments:
literalData {$$ = $1;}
| literalData COMMA arguments { $$ = strb_build($1, strb_const(","), $3, NULL); }
| address { printNextLine = 0; };
| address COMMA arguments { printNextLine = 0; };
;

assignment:
address EQUAL data { $$ = strb_build($1, strb_const(" <- "), $3, NULL);}
;

address:
word { $$ = strb_build(strb_const("`"), $1, strb_const("`"), NULL); }
| word addressSuffixes { { $$ = strb_build(strb_const("`"), $1, strb_const("`"), $2, NULL); } }
;

addressSuffixes:
addressSuffix
| addressSuffixes addressSuffix { $$ = strb_append($1, $2); }
;

addressSuffix:
DOTWORD {$$ = strb_build( strb_const("$`"), $1, strb_const("`"), NULL);}
| LPAREN arguments RPAREN { $$ = strb_build(strb_const("["), $2, strb_const("]"), NULL) }
| LBRACE arguments RBRACE { $$ = strb_build(strb_const("[["), $2, strb_const("]]"), NULL) }
;

trigger:
TRIGGER word  {$$ = strb_build(strb_const("storeTrigger(name=\""), $2, strb_const("\")"), NULL);}
| TRIGGER word structfields SEMICOLON {$$ = strb_build(strb_const("storeTrigger(name=\""), $2, 
					     strb_const("\", "), $3, strb_const(")"), NULL)}
;

structfields:
structfield
| structfields SEMICOLON structfield {$$ = strb_build($1, strb_const(", "), $3, NULL);}
;

structfield:
word EQUAL data {$$ = strb_build(strb_const("`"), $1, strb_const("`="), $3, NULL)}
;

reward:
REWARD NUMBER NUMBER NUMBER {
  $$ = strb_build(strb_const("storeTrigger(name='REWARD', requestedOnset="), $2,  
		  strb_const(", length="), $3,
		  strb_const(", predictedOnset="), $4,
		  strb_const(")"), NULL)
		  }		  
| REWARD NUMBER NUMBER NUMBER NUMBER {
  $$ = strb_build(strb_const("storeTrigger(name='REWARD', requestedOnset="), $2,  
		  strb_const(", length="), $3,
		  strb_const(", refresh="), $4,
		  strb_const(", predictedOnset="), $5,
		  strb_const(")"), NULL)
		  }		  
| REWARD NUMBER NUMBER NUMBER NUMBER NUMBER {
  $$ = strb_build(strb_const("storeTrigger(name='REWARD', requestedOnset="), $2,  
		  strb_const(", length="), $3,
		  strb_const(", refresh="), $4,
		  strb_const(", predictedOnset="), $5,
		  strb_const(", volume="), $6,
		  strb_const(")"), NULL)
    }
;

frameSkip:
FRAME_SKIP NUMBER NUMBER NUMBER NUMBER {
  $$ = strb_build(strb_const("storeTrigger(name='FRAME_SKIP',skips="), $2,  
		  strb_const(", prevVBL="), $3,
		  strb_const(", VBL="), $4,
		  strb_const(", refresh="), $5,
		  strb_const(")"), NULL)
}
;

audioUnderflow:
AUDIO_UNDERFLOW NUMBER NUMBER NUMBER {
  $$ = strb_build(strb_const("storeTrigger(name='AUDIO_UNDERFLOW', lastSampleSent="), $2,  
		  strb_const(", currentSample="), $3,
		  strb_const(", time="), $4,
		  strb_const(")"), NULL)
};

audioSample:
AUDIO_SAMPLE word NUMBER NUMBER {
  $$ = strb_build(strb_const("storeTrigger(name='AUDIO_SAMPLE', sampleName='"), $2,  
		  strb_const("', sampleOnsetTime="), $3,
		  strb_const(", sampleOnsetIndex="), $4,
		  strb_const(")"), NULL)
    };

frameCount:
FRAME_COUNT NUMBER WORD NUMBER {
  $$ = strb_build(strb_const("storeTrigger(name='FRAME_COUNT', frames="), $2,  
		  strb_const(", skipped="), $4,
		  strb_const(")"), NULL)  
}
;

eventCode:
EVENT_CODE NUMBER NUMBER NUMBER {
  $$ = strb_build(strb_const("storeTrigger(name='EVENT_CODE', refreshRequested="), $2,  
		  strb_const(", code="), $3,
		  strb_const(", refreshPredicted="), $4,
		  strb_const(")"), NULL);
}
;

%%

int main(int argc, char **argv) {
  printf("%s", preamble);
  yyparse();
  return(0);
}

yyerror(char *s) {
  fprintf(stderr, "%d: error: %s\n", yylineno, s);
}
