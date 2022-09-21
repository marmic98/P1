wolm.exe: wolm.o radio.o
	gcc wolm.o radio.o -o wolm.exe 
	
radio.o: radio.c 
	gcc -c radio.c
	
wolm.o: wolm.c radio.o
	gcc -c wolm.c radio.o 
	 
clean:
	del .f *o *.exe