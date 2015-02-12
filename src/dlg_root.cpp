#include "debug.h"


BOOL root::handle_key (HELEMENT he, KEY_PARAMS& params ) 
{

    if (params.cmd == KEY_DOWN)
    {
        return htmlayout::dialog::handle_key(he,params);
    }
    if (params.cmd != 1){ //过滤非KEY_UP模式
       return false;
/*     char a[255]="cmd=%d,char=%d,VK_CODE=%d,keyup=%06x"; */
    /* showDebug(printf(a,params.cmd,params.key_code,VK_RETURN,KEY_UP)); */
    }
/*     if(params.cmd != KEY_DOWN) */
         /* return FALSE; */


    switch (params.key_code)
    {
        case VK_RETURN :
        {
            LPCSTR  a;
            HTMLayoutGetElementType(he,&a);
            showDebug(a);
            LPBYTE value;
            HTMLayoutGetElementHtml(he,&value,true);
            showDebug(printf("%b",*value));
            return TRUE;
        }
    }

} 


//void root::show(int resID)
//{
    //showDebug(resID);
    //htmlayout::dialog dlg(hwnd);

//}
//;
