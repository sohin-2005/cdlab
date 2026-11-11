Q7 - LEX program to identify numeric constants (integer and float)
Program : numbers.l
Sample  : input.txt

HOW TO RUN
  flex numbers.l
  gcc lex.yy.c -o numbers
  ./numbers < input.txt

Expected output:
  123 : INTEGER
  12.34 : FLOAT
  7 : INTEGER
  0.5 : FLOAT
  Integers: 2, Floats: 2
