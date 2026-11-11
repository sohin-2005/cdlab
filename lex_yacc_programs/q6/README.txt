Q6 - YACC program to check simple IF statements in C
Files   : ifstmt.l, ifstmt.y
Grammar : stmt -> if ( condition ) stmt      (stmt can be an assignment
          like  x=5;  or another if, so nesting is allowed)
Sample  : input.txt

HOW TO RUN
  bison -y -d ifstmt.y        (or: yacc -d ifstmt.y)
  flex ifstmt.l
  gcc y.tab.c lex.yy.c -o ifstmt
  ./ifstmt < input.txt

Expected output:
  Valid IF statement    <- if(a<b) x=5;
  Invalid IF statement  <- if(a<b x=5;
  Invalid IF statement  <- if a<b) x=5;
  Valid IF statement    <- if(a==1) if(b>2) y=a;
  Invalid IF statement  <- if(a<b) x=;
