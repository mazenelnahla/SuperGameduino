1 PRINT "Shows mouse positions and status"
2 PRINT "This program requires Graphics Controller"
3 REM
100 WIDTH 255
110 REM Enable mouse
120 PRINT CHR$(27);"_H1$";
130 WHILE 1
140     REM Read mouse status
150     PRINT CHR$(27);"_M$";
160     S$ = INPUT$(12)
170     PRINT S$;CHR$(13);
180 WEND
 