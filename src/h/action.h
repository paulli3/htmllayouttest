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

    class doaction
    {
        public:
            bool addroot();
    };

};
#endif
