#include <stdio.h>

typedef struct strbuilder {
  struct strbuilder *prev_allocated;
  struct strbuilder *next_allocated;
  const char *str;
  int str_allocated;
  struct strbuilder *prev;
  struct strbuilder *next;
} strbuilder;

strbuilder *strb_const(const char *);
strbuilder *strb_copy(const char *);
strbuilder *strb_append(strbuilder *a, strbuilder *b);
void strb_clean();
void strb_fprint(FILE *, strbuilder *);
void strb_print(strbuilder *);
int strb_strlen(strbuilder *);
strbuilder *strb_cat(strbuilder *);
strbuilder *strb_build(strbuilder *, ...);
strbuilder *strb_vbuild(strbuilder *, va_list argp);

#define STRB(x) ((typeof(x) == strbuilder *) | (x) : (strb_const(x)))
#define STR(x) ((typeof(x) == strbuilder *) | (strb_cat(x)->str) : x)
#define BUILD(x, n...) strb_append(STRB(x), BUILD(##n))
#define SBUILD(x, n...) strb_cat(BUILD(x, ##n))->str
