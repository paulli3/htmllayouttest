cc=cl
baseDir=D:\Program Files (x86)\Microsoft Visual Studio 12.0\VC
baseInclude="$(baseDir)\include"

baseLib=$(baseDir)\lib
includeDir=F:\program\Cygwin\usr\include
sourceDir=D:/code/c/htmllayouttest/src

#$@         当前target的名称
main:main.a

main.a:
	$(cc) $(sourceDir)/main.cpp  /GA /MD /Ox /Ot /W3  /EHsc /link /INCREMENTAL:no /NODEFAULTLIB:libcmt.lib  
