#include "debug.h"



BOOL root::handle_key (HELEMENT he, KEY_PARAMS& params )
{
    BOOL flag=FALSE;
    if (! (flag=htmlayout::dialog::handle_key(he,params)))
    {
        showDebug(params.key_code);
        switch (params.key_code)
        {
            case 1 :{
                   MessageBox(NULL,"1","1",1); 
                    }
        }
    }
    return flag;
}


//void root::show(int resID)
//{
    //showDebug(resID);
    //htmlayout::dialog dlg(hwnd);

//}
//;
