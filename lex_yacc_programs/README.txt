LEX & YACC LAB PROGRAMS
=======================
q1  Keywords recognizer            (LEX)
q2  Operator counter               (LEX)
q3  Arithmetic expression checker  (YACC + LEX)
q4  Variable assignment validator  (LEX + YACC)
q5  Comment counter                (LEX)
q6  IF statement checker           (YACC + LEX)
q7  Integer / float recognizer     (LEX)
q8  + / - expression evaluator     (LEX + YACC)

Each folder has its source files, a sample input and a README.txt with run steps.

Requirements: flex, bison (or lex, yacc) and gcc.
  Ubuntu/Debian:  sudo apt install flex bison gcc
  Windows:        install MinGW + win_flex/win_bison, or use WSL.

LEX-only programs :  flex x.l && gcc lex.yy.c -o x && ./x < input
LEX+YACC programs :  bison -y -d x.y && flex x.l && gcc y.tab.c lex.yy.c -o x && ./x < input
