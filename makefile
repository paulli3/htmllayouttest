cc=cl
baseDir=D:\Program Files (x86)\Microsoft Visual Studio 12.0\VC
baseInclude="$(baseDir)\include"

baseLib=$(baseDir)\lib
includeDir=/I"include" /I"include/behaviors" /I"src/h"
sourceDir=./src
DEBUG=/GA /MD /Ox /Ot /W3 /c /nologo  /EHsc #/link  /INCREMENTAL:no /NODEFAULTLIB:libcmt.lib  
OUTOBJ=/Fo:$@

SOURCES=bin/main.obj bin/main.res bin/debug.obj  bin/window.obj 
OUTDIR="bin/"

.SUFFIXES : .cpp
#CSTRS=$(wildcard src/*.cpp )
#$@         当前target的名称
main:main.exe

main.exe:$(SOURCES)
	$(cc) /nologo  /Fe:"$@" user32.lib shell32.lib  kernel32.lib Advapi32.lib gdi32.lib lib/HTMLayout.lib lib/sqlite3.lib $(SOURCES)
	main.exe

bin/main.obj:src/main.cpp include/behaviors/behavior_tests.cpp src/h/sql.hpp include/behaviors/behavior_accesskeys.cpp
#	echo $?
#	echo $(@D) $(@F)
	$(cc) src/main.cpp  $(DEBUG) $(OUTOBJ)  $(includeDir)
#	$(cc) lib/*.obj /Fetest.exe

bin/debug.obj:src/debug.cpp
	$(cc) $?  $(DEBUG) $(OUTOBJ)  $(includeDir)

bin/root.obj:src/dlg_root.cpp
	$(cc) $?  $(DEBUG) $(OUTOBJ)  $(includeDir)

bin/window.obj:src/window.cpp
	$(cc) $?  $(DEBUG) $(OUTOBJ)  $(includeDir)

bin/action.obj:src/action.cpp
	$(cc) $?  $(DEBUG) $(OUTOBJ)  $(includeDir)

bin/main.res:src/html/default.htm src/html/dialog.htm src/html/a.rc src/html/rootedit.htm
	cd src/html
#	windres a.rc ../../bin/main.res
	"C:\Program Files (x86)\Windows Kits\8.1\bin\x86\rc.exe" /D _DEBUG   /nologo /fo"../../bin/main.res" a.rc
	cd ../../

clear:
	rm $(SOURCES)
