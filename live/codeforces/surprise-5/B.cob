       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 A        PIC 9(10)   VALUE ZEROES.
       01 B        PIC 9(10)   VALUE ZEROES.
       01 C        PIC 9(10)   VALUE ZEROES.
       01 F        PIC 9(1)   VALUE ZEROES.
       01 STR      PIC X(10).

       PROCEDURE DIVISION.
         ACCEPT STR
         COMPUTE C = 16777216
         COMPUTE F = 0
         MOVE STR TO A
         PERFORM UNTIL C = 0
            COMPUTE B = C
            IF A >= C THEN
                DISPLAY "1" WITH NO ADVANCING
                COMPUTE F = 1
                COMPUTE A = A - C
            ELSE
                IF F = 1 THEN
                    DISPLAY "0" WITH NO ADVANCING
                END-IF
            END-IF
            COMPUTE C = C / 2
         END-PERFORM
         DISPLAY ""
         STOP RUN.

