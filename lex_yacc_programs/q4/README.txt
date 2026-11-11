Q4 - LEX + YACC program for simple variable assignment
Files   : assign.l, assign.y
Form    : id = num + id ;   (each operand may be an id or a num, so
          the example  x = a + 5;  is accepted too)
Sample  : input.txt

HOW TO RUN
  bison -y -d assign.y        (or: yacc -d assign.y)
  flex assign.l
  gcc y.tab.c lex.yy.c -o assign
  ./assign < input.txt

Expected output:
  Valid assignment      <- x = a + 5;
  Valid assignment      <- y = 3 + b;
  Invalid assignment    <- =x 5 + a;
  Invalid assignment    <- x = a + ;
  Invalid assignment    <- x = a + 5   (missing ;)
