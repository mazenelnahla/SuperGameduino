1 PRINT "Sets GPIO-36 as digital input and continuously prints its value"
2 REM
100 WIDTH 255
110 REM Sets (_D) digital input (I) on GPIO-36
120 PRINT CHR$(27);"_DI36$";
130 WHILE 1
140     REM Read digital value (_R) from GPIO-36
150     PRINT CHR$(27);"_R36$";
160     RECV$ = INPUT$(2)
170     V$ = RIGHT$(RECV$, 1)
180     PRINT "GPIO-0 = "; V$; CHR$(13);
190 WEND
 