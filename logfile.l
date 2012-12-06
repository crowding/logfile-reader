%{
#include <stdio.h>
#include "logfile.tab.h"
#include "strbuilder.h"

#ifdef TOKEN_TEST
#define TOKENIZE(c) printf("%s: %s\n",#c,yytext); return c;
#define CAPTURE(c) printf("%s: \"%s\"\n",#c,yytext); return c;
#else
#define TOKENIZE(c) return c;
#define CAPTURE(c) yylval.s = strb_copy(yytext); return c;
#endif

%}

%option yylineno

%%

[ \t]                           { }

    /* these keywords might conceivably count as "words" elsewhere, so we capture them */
"BEGIN"                         {CAPTURE(BEGIN_)          }
"TRIGGER"                       {CAPTURE(TRIGGER)         }
"END"                           {CAPTURE(END)             }
"EYE_DATA"                      {CAPTURE(EYE_DATA)        }
"AUDIO_DATA"                    {CAPTURE(AUDIO_DATA)      }
"ERROR"                         {CAPTURE(ERROR_)          }
"REWARD"                        {CAPTURE(REWARD)          }
"FRAME_SKIP"                    {CAPTURE(FRAME_SKIP)      }
"FLUID"                         {CAPTURE(FLUID)           }
"FRAME_COUNT"                   {CAPTURE(FRAME_COUNT)     }
"EVENT_CODE"                    {CAPTURE(EVENT_CODE)      }
"AUDIO_UNDERFLOW"               {CAPTURE(AUDIO_UNDERFLOW) }
"AUDIO_SAMPLE"                  {CAPTURE(AUDIO_SAMPLE)    }

    /* we capture numbers and other words as strings */
-?([0-9]*\.[0-9]+|[0-9]+\.[0-9]*|[0-9]+)([Ee][+-]?[0-9]+)? {CAPTURE(NUMBER)     }
"NaN"                           {CAPTURE(NUMBER)     }
-?Inf                           {CAPTURE(NUMBER)     }
[a-zA-Z0-9_][a-z\A-Z/0-9_\-]*   {CAPTURE(WORD)       }
\.[a-zA-Z0-9_][a-z\A-Z/.0-9_]*  {
#ifdef TOKEN_TEST
  CAPTURE(DOTWORD);
#else
  yylval.s = strb_copy(yytext+1); return DOTWORD;
#endif
}
\'([^']|\'\')*\'                {
#ifdef TOKEN_TEST
CAPTURE(QUOTED)
#else
yytext[strlen(yytext) - 1] = 0; yylval.s = strb_copy(yytext+1); return QUOTED;
#endif
}

    /* we don't bother with capturing punctuation */
":"                             {TOKENIZE(COLON)     }
"="                             {TOKENIZE(EQUAL)     }
"("                             {TOKENIZE(LPAREN)    }
")"                             {TOKENIZE(RPAREN)    }
"{"                             {TOKENIZE(LBRACE)    }
"}"                             {TOKENIZE(RBRACE)    }
"["                             {TOKENIZE(LBRACKET)  }
"]"                             {TOKENIZE(RBRACKET)  }
","                             {TOKENIZE(COMMA)     }
";"                             {TOKENIZE(SEMICOLON) }
[\n]                            {TOKENIZE(EOL)       }
.                               {
                                 fprintf(stderr, "Unknown token: %s\n", yytext);
                                 yyterminate();
                                }
%%


