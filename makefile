cc=cl
baseDir=D:\Program Files (x86)\Microsoft Visual Studio 12.0\VC
baseInclude="$(baseDir)\include"

baseLib=$(baseDir)\lib
includeDir=/I"include" /I"include/behaviors" /I"src/h"
sourceDir=./src
DEBUG=/GA /MD /Ox /Ot /W3 /c /nologo  /EHsc #/link  /INCREMENTAL:no /NODEFAULTLIB:libcmt.lib  
OUTOBJ=/Fo:$@

SOURCES=bin/main.obj bin/main.res bin/debug.obj
OUTDIR="bin/"

.SUFFIXES : .cpp
#CSTRS=$(wildcard src/*.cpp )
#$@         当前target的名称
main:main.exe

main.exe:$(SOURCES)
	$(cc) /nologo  /Fe:"$@" user32.lib shell32.lib  kernel32.lib Advapi32.lib gdi32.lib lib/HTMLayout.lib $(SOURCES)

bin/main.obj:src/main.cpp
#	echo $?
#	echo $(@D) $(@F)
	$(cc) $(?)  $(DEBUG) $(OUTOBJ)  $(includeDir)
#	$(cc) lib/*.obj /Fetest.exe

bin/debug.obj:src/debug.cpp src/h/debug.h
	$(cc) $?  $(DEBUG) $(OUTOBJ)  $(includeDir)

bin/main.res:src/html/default.htm src/html/dialog.htm
	cd src/html
	windres a.rc ../../bin/main.res
	cd ../../
clear:
	rm $(SOURCES)
