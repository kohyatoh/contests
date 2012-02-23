       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 C        PIC 9(10)   VALUE ZEROES.
       01 K        PIC 9(10)   VALUE ZEROES.
       01 I        PIC 9(10)   VALUE ZEROES.
       01 J        PIC 9(10)   VALUE ZEROES.
       01 T        PIC 9(10)   VALUE ZEROES.
       01 STR      PIC X(10).
       01 BUF      PIC X(10).
       01 DAT      PIC X(30).

       PROCEDURE DIVISION.
         ACCEPT STR
         ACCEPT BUF
         MOVE BUF TO K
         MOVE "ABCDEFGHIJKLMNOPQRSTUVWXYZ" TO DAT
         COMPUTE C = 1
         PERFORM UNTIL STR(C:1) < 'A' OR STR(C:1) > 'Z'
            COMPUTE I = 1
            PERFORM UNTIL STR(C:1) = DAT(I:1)
                COMPUTE I = I + 1
            END-PERFORM
            COMPUTE J = I + K - 1
            DIVIDE J BY 26 GIVING T REMAINDER J
            COMPUTE J = J + 1
            DISPLAY DAT(J:1) WITH NO ADVANCING
            COMPUTE C = C + 1
         END-PERFORM
         DISPLAY ""
         STOP RUN.
