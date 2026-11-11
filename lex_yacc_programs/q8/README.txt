Q8 - LEX + YACC program to evaluate expressions with + and - only
Files   : calc.l, calc.y
Sample  : input.txt

HOW TO RUN
  bison -y -d calc.y          (or: yacc -d calc.y)
  flex calc.l
  gcc y.tab.c lex.yy.c -o calc
  ./calc < input.txt

Expected output:
  Result = 6      <- 5+3-2
  Result = 3      <- 10-4-3
  Invalid expression  <- 7+
  Result = 100    <- 100
