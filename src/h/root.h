#include "debug.h"

class root : public htmlayout::dialog
{
    public :
        root();
        root(HWND hwnd) : htmlayout::dialog(hwnd)
        {
            //MessageBox(hwnd,"1","1",MB_OK);
            //this->hwnd = hwnd;
        }
        //void show(int resID);            
        BOOL handle_key (HELEMENT he, KEY_PARAMS& params ); 
        /* unsigned int show( UINT html_res_id ); */


    private :
        HWND hwnd ;
        
}
;

