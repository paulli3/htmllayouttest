#include "debug.h"

void showDebug(const char * str)
{
    htmlayout::debug_output_console dc;
    dc.printf("%s\n",str);
}

void showDebug(const wchar_t * str)
{
    const char * s = aux::w2a(str);
    htmlayout::debug_output_console dc;
    dc.printf("%s\n",s);
}


void showDebug(int i)
{
    htmlayout::debug_output_console dc;
    dc.printf("%d\n",i);

}
