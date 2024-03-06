#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "O21";
  char * pch;
  pch=strrchr(str,'O');
  printf ("Last occurence of 's' found at %d \n",(int)(pch-str));
  return 0;
}