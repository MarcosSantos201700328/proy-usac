proy1: proy1.pas
	fpc -g -Mtp proy1.pas
proy1win.exe: proy1win.pas
	fpc -g -Mtp proy1win.pas
clean:
	rm -Rf *.o
proy1linux: proy1.pas
	fpc -O3 -ostatics proy1.pas
proy1win32: proy1.pas
	fpc -o3 -ostatics.exe proy1.pas
