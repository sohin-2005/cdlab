Q3 - YACC program to recognise arithmetic expressions with parentheses
Files   : expr.l (lexer), expr.y (parser)
Grammar : E -> E+T | E-T | T ;  T -> T*F | T/F | F ;  F -> (E) | num
Sample  : input.txt

HOW TO RUN
  bison -y -d expr.y          (or: yacc -d expr.y)
  flex expr.l
  gcc y.tab.c lex.yy.c -o expr
  ./expr < input.txt

Expected output:
  Valid expression      <- (2+3)*4
  Invalid expression    <- 2+*3
  Invalid expression    <- ((1+2)
  Valid expression      <- 10/(5-3)
