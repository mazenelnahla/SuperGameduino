1 PRINT "Sets GPIO-36 as analog input and prints its value in Volts"
2 REM
100 WIDTH 255
110 REM Sets (_A) analog input, 12 bit resolution (12),
120 REM with 11dB attenuation (3) on GPIO-36
120 PRINT CHR$(27);"_A12;3;36$";
130 WHILE 1
140     REM Read (_G) analog value from GPIO-36
150     PRINT CHR$(27);"_C36$";
160     RECV$ = INPUT$(4)
170     V = VAL("&H" + RIGHT$(RECV$, 3))
180     PRINT V / 4096 * 3.9; "V          "; CHR$(13);
190 WEND
 