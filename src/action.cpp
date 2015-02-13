#include "action.h"
namespace htmlayout
{
    bool action::buttonClick(HWND hwnd,HELEMENT button)
    {
       MessageBox(hwnd,"1","1",0); 
       return true;
    }
}
