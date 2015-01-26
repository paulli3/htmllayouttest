#include "debug.h"

void showDebug(const char * str)
{
    htmlayout::debug_output_console dc;
    dc.printf("%s",str);

}


void showDebug(int i)
{
    htmlayout::debug_output_console dc;
    dc.printf("%d",i);

}
