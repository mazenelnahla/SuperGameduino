1 REM Draws some graphics
2 PRINT "This program requires Graphics Controller"
100 WIDTH 255
105 GOSUB 10000: REM Define functions
106 REM Disable cursor and clear screen
107 PRINT FNCURSOROFF$;FNCLR$;
110 REM
120 REM ** POINTS **
130 FOR I = 0 TO 100
140     REM Set random pen color
150     PRINT FNPEN$(RND*255, RND*255, RND*255);
160     REM Draw a pixel at random position
170     PRINT FNPIXEL$(RND*640, RND*480);
180 NEXT I
190 FOR I = 0 TO 120: PRINT FNSCROLL$(4, 4);: NEXT I
200 REM
210 REM ** LINES **
220 FOR I = 0 TO 100
230     REM Set random pen color
240     PRINT FNPEN$(RND*255, RND*255, RND*255);
250     REM Draw a line
260     PRINT FNDRAW$(RND*640, RND*480, RND*640, RND*480);
270 NEXT I
280 FOR I = 0 TO 120: PRINT FNSCROLL$(-4, 4);: NEXT I
290 REM
300 REM ** FILLED RECTANGLES **
310 FOR I = 0 TO 50
320     REM Set random brush color
330     PRINT FNBRUSH$(RND*255, RND*255, RND*255);
340     REM Set random pen color
350     PRINT FNPEN$(RND*255, RND*255, RND*255);
360     REM Fill and draw rectangle
370     X1 = RND*640: Y1 = RND*480: X2 = RND*640: Y2 = RND*480
380     PRINT FNFILLRECT$(X1, Y1, X2, Y2);
390     PRINT FNRECT$(X1, Y1, X2, Y2);
400 NEXT I
410 FOR I = 0 TO 120: PRINT FNSCROLL$(4, -4);: NEXT I
420 REM
430 REM ** FILLED ELLIPSES **
440 FOR I = 0 TO 50
450     REM Set random brush color
460     PRINT FNBRUSH$(RND*255, RND*255, RND*255);
470     REM Set random pen color
480     PRINT FNPEN$(RND*255, RND*255, RND*255);
490     REM Fill and draw ellipse
500     X = RND*640: Y = RND*480: W = RND*320: H = RND*240
510     PRINT FNFILLELLIPSE$(X, Y, W, H);
520     PRINT FNELLIPSE$(X, Y, W, H);
530 NEXT I
540 FOR I = 0 TO 120: PRINT FNSCROLL$(-4, -4);: NEXT I
550 REM
560 REM ** FILLED POLYGONS **
570 FOR I = 0 TO 50
580     REM Set random brush color
590     PRINT FNBRUSH$(RND*255, RND*255, RND*255);
600     REM Set random pen color
610     PRINT FNPEN$(RND*255, RND*255, RND*255);
620     REM Build coordinates
630     C = 3 + INT(RND*4): REM Number of points
640     P$ = ""
650     FOR J = 1 TO C
660         X = INT(RND*640): Y = INT(RND*480)
670         P$ = P$ + STR$(X) + ";" + STR$(Y)
680         IF J < C THEN P$ = P$ + ";"
690     NEXT J
700     REM Fill and draw path
710     PRINT FNFILLPATH$(P$);
720     PRINT FNPATH$(P$);
730 NEXT I
740 FOR I = 0 TO 120: PRINT FNSCROLL$(-4, 0);: NEXT I
750 REM Clear screen, clear terminal and enable cursor
760 PRINT FNCLR$;FNCLRTERM$;FNCURSORON$;
765 WIDTH 80
770 END
10000 REM
10010 REM ** DEFINE FUNCTIONS **
10020 DEF FNPEN$(R%, G%, B%) = CHR$(27)+"_GPEN"+STR$(R%)+";"+STR$(G%)+";"+STR$(B%)+"$"
10030 DEF FNBRUSH$(R%, G%, B%) = CHR$(27)+"_GBRUSH"+STR$(R%)+";"+STR$(G%)+";"+STR$(B%)+"$"
10040 DEF FNPIXEL$(X%, Y%) = CHR$(27)+"_GPIXEL"+STR$(X%)+";"+STR$(Y%)+"$"
10050 DEF FNDRAW$(X1%, Y1%, X2%, Y2%) = CHR$(27)+"_GLINE"+STR$(X1%)+";"+STR$(Y1%)+";"+STR$(X2%)+";"+STR$(Y2%)+"$"
10060 DEF FNRECT$(X1%, Y1%, X2%, Y2%) = CHR$(27)+"_GRECT"+STR$(X1%)+";"+STR$(Y1%)+";"+STR$(X2%)+";"+STR$(Y2%)+"$"
10070 DEF FNFILLRECT$(X1%, Y1%, X2%, Y2%) = CHR$(27)+"_GFILLRECT"+STR$(X1%)+";"+STR$(Y1%)+";"+STR$(X2%)+";"+STR$(Y2%)+"$"
10080 DEF FNELLIPSE$(X%, Y%, W%, H%) = CHR$(27)+"_GELLIPSE"+STR$(X%)+";"+STR$(Y%)+";"+STR$(W%)+";"+STR$(H%)+"$"
10090 DEF FNFILLELLIPSE$(X%, Y%, W%, H%) = CHR$(27)+"_GFILLELLIPSE"+STR$(X%)+";"+STR$(Y%)+";"+STR$(W%)+";"+STR$(H%)+"$"
10110 DEF FNPATH$(POINTS$) = CHR$(27)+"_GPATH"+POINTS$+"$"
10120 DEF FNFILLPATH$(POINTS$) = CHR$(27)+"_GFILLPATH"+POINTS$+"$"
10130 DEF FNSCROLL$(X%, Y%) = CHR$(27)+"_GSCROLL"+STR$(X%)+";"+STR$(Y%)+"$"
10140 DEF FNCLR$ = CHR$(27)+"_GCLEAR$"
10150 DEF FNCURSORON$ = CHR$(27)+"_E1$"
10160 DEF FNCURSOROFF$ = CHR$(27)+"_E0$"
10170 DEF FNCLRTERM$ = CHR$(27)+"_B$"
10180 RETURN
 