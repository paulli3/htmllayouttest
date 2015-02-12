#include "debug.h"

void showDebug(const char * str)
{
    htmlayout::debug_output_console dc;
    dc.printf("%s\n",str);

}




void showDebug(int i)
{
    htmlayout::debug_output_console dc;
    dc.printf("%d\n",i);

}
