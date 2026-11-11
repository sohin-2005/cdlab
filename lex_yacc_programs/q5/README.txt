Q5 - LEX program to identify and count comments in C code
Program : comments.l
Sample  : input.c

HOW TO RUN
  flex comments.l
  gcc lex.yy.c -o comments
  ./comments < input.c

Expected: 2 single-line comments, 2 multi-line comments.
