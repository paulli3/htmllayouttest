#include "debug.h"
#include "htmlayout_queue.h"
HINSTANCE hInst;
//using namespace std;


#define MAX_LOADSTRING 100

// Global Variables:
TCHAR szWindowClass[] = "MySkinnedApp";               // The title bar text

// Foward declarations of functions included in this code module:
BOOL              InitInstance(HINSTANCE, int);


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
  // TODO: Place code here.
  MSG msg;
  HACCEL hAccelTable;

  //CoInitialize(0); // for Shell Icons

  // Initialize global strings
  htmlayout::window::register_class(hInstance);

  // Perform application initialization:
  if (!InitInstance (hInstance, nCmdShow)) 
  {
    return FALSE;
  }

  hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_SKIN);

  // Main message loop:
  while (GetMessageW(&msg, NULL, 0, 0)) 
  {
    // execute asynchronous tasks in GUI thread.
    htmlayout::queue::execute();

    if (!TranslateAcceleratorW(msg.hwnd, hAccelTable, &msg)) 
    {
      TranslateMessage(&msg);
      DispatchMessageW(&msg);
    }
  }

  return msg.wParam;
}


//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable
   RECT rc;
   GetWindowRect(GetDesktopWindow(), &rc);
   int clientHeight=800;
   int clientWidth=800;
   int x = (rc.right - rc.left) / 2 - clientHeight / 2;
   int y = (rc.bottom - rc.top) / 2 - clientWidth / 2; 
   if (x < 0)x = 0;
   if (y < 0)y = 0;
   htmlayout::window* pwnd = htmlayout::window::create( x, y, clientHeight, clientWidth, L"Hello world!" );

   //hWnd = CreateWindowEx(WS_EX_APPWINDOW, szWindowClass, szWindowClass, WS_POPUP | WS_SYSMENU | WS_CLIPCHILDREN | WS_VISIBLE,
   //   0, 0, 300, 300, NULL, NULL, hInstance, NULL);

   if (!pwnd->hwnd)
   {
      return FALSE;
   }

   ShowWindow(pwnd->hwnd, nCmdShow);
   UpdateWindow(pwnd->hwnd);

   return TRUE;
}

