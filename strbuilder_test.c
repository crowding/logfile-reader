#include <stdio.h>
#include "strbuilder.h"

int main(void) {
  strbuilder *test = strb_const("this is a test");
  strbuilder *append = strb_copy("this is only a test");
  strb_fprint(stdout, test);
  fputs("\n", stdout);

  strb_fprint(stdout, append);
  fputs("\n", stdout);

  test = strb_append(test, strb_const("!"));
  strb_fprint(stdout, test);
  fputs("\n", stdout);
  test = strb_append(strb_const(", but "), test);
  test = strb_append(append, test);
  strb_fprint(stdout, test);
  fputs("\n", stdout);

  printf("Length was %d\n",strb_strlen(test));
  strbuilder *catted = strb_cat(test);
  printf("Now length is %d\n",strb_strlen(catted));
  printf("Now string is %s\n", catted->str);
				     
  printf("%s\n", strb_cat(strb_build(
				     strb_const("and "), 
				     strb_const("what "), 
				     strb_const("about "), 
				     strb_const("variable "), 
				     strb_const("args?"),
				     NULL))->str);

  //  printf("%s\n", SBUILD("and ", "(", test, ") ", "reasonable varargs?"))

  strb_clean();
}
