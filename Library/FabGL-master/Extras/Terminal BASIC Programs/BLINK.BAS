1 PRINT "Sets GPIO-12 as output pin and turns it On and Off"
2 REM
100 WIDTH 255
110 REM Sets (_D) digital output (O) on GPIO-12
120 PRINT CHR$(27);"_DO12$";
130 WHILE 1
140     REM Write (_W) logic High (H) to GPIO-12
150     PRINT CHR$(27);"_WH12$";
160     GOSUB 1000: REM DELAY
165     REM
170     REM Write (_W) logic Low (L) to GPIO-12
180     PRINT CHR$(27);"_WL12$";
190     GOSUB 1000: REM DELAY
200 WEND
1000 REM
1010 REM DELAY SUBROUTINE
1020 FOR I=0 TO 100: NEXT I
1030 RETURN
 