#include "debug.h"
#ifndef action_html
#define action_html 1
namespace htmlayout{


    class action
    {
        private :
            HWND mhwnd;
        public :
           action(HWND hwnd) : mhwnd(hwnd) {};
           bool buttonClick(HWND hwnd,HELEMENT button);
    };

    
};
namespace doaction
{
    bool show_add_root(HWND hwnd);
    bool show_add_root(HWND hwnd,const wchar_t * type);
    bool showRootList( htmlayout::dom::element root,const wchar_t * parentID,const char * dbName);
    bool showRootList(htmlayout::dom::element root);
}
#endif
