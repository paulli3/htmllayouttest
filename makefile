cc=cl
baseDir=D:\Program Files (x86)\Microsoft Visual Studio 12.0\VC
baseInclude="$(baseDir)\include"

baseLib=$(baseDir)\lib
includeDir=F:\program\Cygwin\usr\include
sourceDir=D:/code/c/htmllayouttest/src
DEBUG=/GA /MD /Ox /Ot /W3 /c  /EHsc #/link  /INCREMENTAL:no /NODEFAULTLIB:libcmt.lib  

#$@         当前target的名称
main:main.exe

main.exe:main.obj main.res
	$(cc) lib/main.obj /Fe:"eee" user32.lib gdi32.lib lib/HTMLayout.lib lib/main.res 

main.obj:
	$(cc) $(sourceDir)/main.cpp  $(DEBUG) /Fo:"lib/main.obj" /I"include" 
#	$(cc) lib/*.obj /Fetest.exe

main.res:
	cd src/html
	windres a.rc ../../lib/main.res
	cd ../../
