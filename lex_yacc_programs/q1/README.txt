Q1 - LEX program to recognize C keywords
Program : keywords.l
Sample  : input.c

HOW TO RUN
  flex keywords.l
  gcc lex.yy.c -o keywords
  ./keywords < input.c

(Windows/MinGW: use  keywords.exe < input.c )
