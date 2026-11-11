Q2 - LEX program to count operators (+ - * / % = ==)
Program : operators.l
Sample  : input.txt   (a = b + c * d;)

HOW TO RUN
  flex operators.l
  gcc lex.yy.c -o operators
  ./operators < input.txt

Or type input manually:  ./operators   then enter text, press Ctrl+D (Linux/Mac) / Ctrl+Z + Enter (Windows).

Expected output:
  +  : 1
  *  : 1
  =  : 1
  Total operators: 3
