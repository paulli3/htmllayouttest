#include "stdio.h"
#include "htmlayout.h"
#include "windows.h"


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
BOOL        GetHtmlResource(LPCSTR pszName, /*out*/PBYTE& pb, /*out*/DWORD& cb);
LRESULT     HandleHyperlink( HWND hWnd, NMHL_HYPERLINK *pHL);
LRESULT CALLBACK HTMLayoutNotifyHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, LPVOID vParam);
LRESULT OnAttachBehavior(LPNMHL_ATTACH_BEHAVIOR lpAB );



int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,PSTR szCmdLine, int iCmdShow)
{
     static TCHAR szAppName[] = TEXT ("HelloWin") ;
     HWND         hwnd ;
     MSG          msg ;
     WNDCLASS     wc ;
     wc.style         = CS_HREDRAW | CS_VREDRAW ;
     wc.lpfnWndProc   = WndProc ;
     wc.cbClsExtra    = 0 ;
     wc.cbWndExtra    = 0 ;
     wc.hInstance     = hInstance ;
     wc.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wc.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH) ;
     wc.lpszMenuName  = NULL ;
     wc.lpszClassName = szAppName ;
     if (!RegisterClass (&wc))
     {
          MessageBox (NULL, TEXT ("This program requires Windows NT!"), szAppName, MB_ICONERROR) ;
          return 0 ;
     }
     hwnd = CreateWindow (szAppName,                  // window class name
                          TEXT ("hello!"), // window caption
                          WS_OVERLAPPEDWINDOW,        // window style
                          CW_USEDEFAULT,              // initial x position
                          CW_USEDEFAULT,              // initial y position
                          100,              // initial x size   CW_USEDEFAULT
                          100,              // initial y size   CW_USEDEFAULT
                          NULL,                       // parent window handle
                          NULL,                       // window menu handle
                          hInstance,                  // program instance handle
                          NULL) ;                     // creation parameters
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;//翻译消息
          DispatchMessage (&msg) ;//撤去消息
     }
     return msg.wParam ;

}

 // HTMLayout specific notification handler.
LRESULT CALLBACK HTMLayoutNotifyHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, LPVOID vParam)
{
  // all HTMLayout notification are comming here.
  NMHDR*  phdr = (NMHDR*)lParam;

  switch(phdr->code)
  {
      case HLN_CREATE_CONTROL:    break; //return OnCreateControl((LPNMHL_CREATE_CONTROL) lParam);
      case HLN_CONTROL_CREATED:   break; //return OnControlCreated((LPNMHL_CREATE_CONTROL) lParam);
      case HLN_DESTROY_CONTROL:   break; //return OnDestroyControl((LPNMHL_DESTROY_CONTROL) lParam);
      case HLN_LOAD_DATA:         break; //return OnLoadData((LPNMHL_LOAD_DATA) lParam);
      case HLN_DATA_LOADED:       break; //return OnDataLoaded((LPNMHL_DATA_LOADED)lParam);
      case HLN_DOCUMENT_COMPLETE: break; //return OnDocumentComplete();
      case HLN_ATTACH_BEHAVIOR:   return OnAttachBehavior((LPNMHL_ATTACH_BEHAVIOR)lParam );
  }
  return 0;
}

LRESULT OnAttachBehavior(LPNMHL_ATTACH_BEHAVIOR lpab )
{
    // attach custom behaviors
    htmlayout::event_handler *pb = htmlayout::behavior::find(lpab->behaviorName, lpab->element);
    if(pb) 
    {
      lpab->elementTag  = pb;
      lpab->elementProc = htmlayout::behavior::element_proc;
      lpab->elementEvents = pb->subscribed_to;
    }
    return 0;
} 

 

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     HDC         hdc ;
     PAINTSTRUCT ps ;
     RECT        rect ;
     BOOL        flag;
     LRESULT    lResult;
     lResult = HTMLayoutProcND(hwnd,message,wParam,lParam, &flag);
     if(flag){
        //return false;
        return lResult;
        //MessageBox(NULL,"1","2",MB_OK);
     }
     switch (message)
     {
     case WM_PAINT:
          hdc = BeginPaint (hwnd, &ps) ;
          GetClientRect (hwnd, &rect) ;
          DrawText (hdc, TEXT ("world"), -1, &rect,
                    DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;
          EndPaint (hwnd, &ps) ;
          return 0 ;
     case WM_DESTROY:
          PostQuitMessage (0) ;
          return 0 ;
      case WM_CREATE:
      {
        // Normally HTMLayout sends its notifications
        // to its parent. 
        // In this particular case we are using callback function to receive and
        // and handle notification. Don't bother the desktop window (parent of this window)
        // by our notfications.
        HTMLayoutSetCallback(hwnd,&HTMLayoutNotifyHandler,0);

        PBYTE pb; DWORD cb;
        if(GetHtmlResource("DEFAULT",pb,cb))
          HTMLayoutLoadHtml(hwnd,pb,cb);
        return 0;
      }
      break;


     }
     return DefWindowProc (hwnd, message, wParam, lParam) ;
}
