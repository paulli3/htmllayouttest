#include "debug.h"

class root{
    public :
        root();
        root(HWND hwnd)
        {
            //MessageBox(hwnd,"1","1",MB_OK);
            this->hwnd = hwnd;
        }
        void show(int resID);            
    private :
        HWND hwnd ;
}
;

