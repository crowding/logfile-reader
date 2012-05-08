#include "strbuilder.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#undef TRACE

strbuilder *top = NULL;

strbuilder *strb_const(const char *str) {
  strbuilder *n = malloc(sizeof(strbuilder));
  const strbuilder init = {
    .prev_allocated = top,
    .next_allocated = NULL,
    .prev=n,
    .next=n,
    .str=str,
    .str_allocated=0
  };
  *n = init;
  if (top != NULL) {
    top->next_allocated = n;
  }
  top = n;
  return n;
}

strbuilder *strb_copy(const char *str) {
  strbuilder *n = strb_const("");
  n->str = strdup(str);
  n->str_allocated=1;
#ifdef TRACE
  printf("copy %x: %s -> %x: ",str, str, n); strb_print(n); puts("\n");
#endif
  return n;
}

strbuilder *strb_append(strbuilder *a, strbuilder *b) {
  /* Destructively append string b to string a, returning string a+b. */
#ifdef TRACE
  printf("append %x: ",a); strb_print(a); printf(" + %x: ",b); strb_print(b);
#endif
  strbuilder *begin_of_a = a;
  strbuilder *end_of_a = a->prev;
  strbuilder *begin_of_b = b;
  strbuilder *end_of_b = b->prev;
  begin_of_a->prev = end_of_b;
  end_of_a->next = begin_of_b;
  begin_of_b->prev = end_of_a;
  end_of_b->next = begin_of_a;
#ifdef TRACE
  printf(" -> %x: ",begin_of_a); strb_print(begin_of_a); printf("\n");
#endif
  return begin_of_a;
}

void strb_clean() {
  /* Free every node of strbuilder that exists. */
  while(top != NULL) {
    strbuilder *x = top;
    if (x->str_allocated) {
      /* cast to avoid a warning about discarding 'const' from the type */
      free((void *)x->str);
    }
    top = x->prev_allocated;
    free(x);
  }
}

void strb_fprint(FILE *stream, strbuilder *begin) {
  strbuilder *current = begin;
  do {
    fputs(current->str, stream);
    current = current->next;
  } while (current != begin);
}

void strb_print(strbuilder *begin) {
  strb_fprint(stdout, begin);
}

int strb_strlen(strbuilder *begin) {
  strbuilder *current = begin;
  int len = 0;
  do{
    len += strlen(current->str);
    current = current->next;
  } while (current != begin);
  return len;
}

strbuilder *strb_cat(strbuilder *begin) {
#ifdef TRACE
  printf("cat %x: ",begin); strb_print(begin);
#endif
  int len = strb_strlen(begin);
  char* str;
  strbuilder *out = strb_const("");
  char *to = malloc(len * sizeof(char) + 1);
  out->str = to;
  out->str_allocated = 1;
  strbuilder *current = begin;
  do {
    to = stpcpy(to, current->str);
    current = current->next;
  } while (current != begin);
#ifdef TRACE
  printf(" -> %x: ",out); strb_print(out); printf("\n");
#endif
  return out;
}

strbuilder *strb_build(strbuilder *begin, ...) {
  va_list argp;
  va_start(argp, begin);
  begin = strb_vbuild(begin, argp);
  va_end(argp);
  return begin;
}

strbuilder *strb_vbuild(strbuilder *begin, va_list argp) {
  strbuilder *next = NULL;
  while((next = va_arg(argp, strbuilder *)) != NULL) {
    begin = strb_append(begin, next);
  }
  return begin;
}
