       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 N        PIC 9(10)   VALUE ZEROES.
       01 I        PIC 9(10)   VALUE ZEROES.
       01 J        PIC 9(10)   VALUE ZEROES.
       01 K        PIC 9(10)   VALUE ZEROES.
       01 M        PIC 9(10)   VALUE ZEROES.
       01 T        PIC 9(3)V9(6)   VALUE ZEROES.
       01 T1       PIC 9(1)V9(6)   VALUE ZEROES.
       01 T2       PIC 9(2)V9(6)   VALUE ZEROES.
       01 XX.
        03 X        PIC S9(10)   OCCURS 100 VALUE ZEROES.
       01 YY.
        03 Y        PIC S9(10)   OCCURS 100 VALUE ZEROES.
       01 STR      PIC X(10).
       01 BUF      PIC X(10).
       01 DAT      PIC X(30).

       PROCEDURE DIVISION.
         ACCEPT BUF
         MOVE BUF TO N
         COMPUTE I = 0
         PERFORM UNTIL I = N
            COMPUTE I = I + 1
            ACCEPT BUF
            MOVE BUF TO X(I)
            ACCEPT BUF
            MOVE BUF TO Y(I)
         END-PERFORM
         COMPUTE M = 0
         COMPUTE I = 0
         PERFORM UNTIL I = N
            COMPUTE I = I + 1
            COMPUTE J = I
            PERFORM UNTIL J = N
                COMPUTE J = J + 1
                COMPUTE K = ((X(I)-X(J))*(X(I)-X(J)))
                COMPUTE K = K + ((Y(I)-Y(J))*(Y(I)-Y(J)))
                IF M < K THEN
                    COMPUTE M = K
                END-IF
            END-PERFORM
         END-PERFORM
         COMPUTE T = FUNCTION SQRT(M)
         IF T < 10 THEN
            COMPUTE T1 = T
            DISPLAY T1
         ELSE IF T < 100 THEN
            COMPUTE T2 = T
            DISPLAY T2
         ELSE
             DISPLAY T
         END-IF
         STOP RUN.

