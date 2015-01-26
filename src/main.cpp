#include "stdio.h"
#include "htmlayout.h"
#include "windows.h"
#include <string>
using namespace std;


#include "Include_behavior.cpp"
#include "Include_const.h"
#include "debug.h"

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
                          800,              // initial x size   CW_USEDEFAULT
                          500,              // initial y size   CW_USEDEFAULT
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

void OnButtonClick(HELEMENT button);
struct DOMEventsHandlerType: htmlayout::event_handler
{
      DOMEventsHandlerType(): event_handler(0xFFFFFFFF) {}
      virtual BOOL handle_event (HELEMENT he, BEHAVIOR_EVENT_PARAMS& params ) 
      { 
        switch( params.cmd )
        {
        case BUTTON_CLICK:              OnButtonClick(params.heTarget); break;// click on button
        case BUTTON_PRESS:              break;// mouse down or key down in button
        case BUTTON_STATE_CHANGED:      break;
        case EDIT_VALUE_CHANGING:       break;// before text change
        case EDIT_VALUE_CHANGED:        break;//after text change
        case SELECT_SELECTION_CHANGED:  break;// selection in <select> changed
        case SELECT_STATE_CHANGED:      break;// node in select expanded/collapsed, heTarget is the node
        case POPUP_REQUEST: 
                                        break;// request to show popup just received, 
                                              //     here DOM of popup element can be modifed.
        case POPUP_READY:               break;// popup element has been measured and ready to be shown on screen,
                                              //     here you can use functions like ScrollToView.
        case POPUP_DISMISSED:           break;// popup element is closed,
                                              //     here DOM of popup element can be modifed again - e.g. some items can be removed
                                              //     to free memory.
        case MENU_ITEM_ACTIVE:                // menu item activated by mouse hover or by keyboard
             break;
        case MENU_ITEM_CLICK:                 // menu item click 
             break;


            // "grey" event codes  - notfications from behaviors from this SDK 
        case HYPERLINK_CLICK:           break;// hyperlink click
        case TABLE_HEADER_CLICK:        break;// click on some cell in table header, 
                                              //     target = the cell, 
                                              //     reason = index of the cell (column number, 0..n)
        case TABLE_ROW_CLICK:           break;// click on data row in the table, target is the row
                                              //     target = the row, 
                                              //     reason = index of the row (fixed_rows..n)
        case TABLE_ROW_DBL_CLICK:       break;// mouse dbl click on data row in the table, target is the row
                                              //     target = the row, 
                                              //     reason = index of the row (fixed_rows..n)

        case ELEMENT_COLLAPSED:         break;// element was collapsed, so far only behavior:tabs is sending these two to the panels
        case ELEMENT_EXPANDED:          break;// element was expanded,

        }
//        htmlayout::debug_output_console dc;
//        dc.printf("tagName=%s",$D(he).get_attribute_name(1));
        return FALSE; 
      }
 
} DOMEventsHandler;
 // HTMLayout specific notification handler.
LRESULT CALLBACK HTMLayoutNotifyHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, LPVOID vParam)
{
  // all HTMLayout notification are comming here.
  NMHDR*  phdr = (NMHDR*)lParam;
  //MessageBox(NULL,"1","1",MB_OK);
  switch(phdr->code)
  {
      case HLN_CREATE_CONTROL:    break; //return OnCreateControl((LPNMHL_CREATE_CONTROL) lParam);
      case HLN_CONTROL_CREATED:   break; //return OnControlCreated((LPNMHL_CREATE_CONTROL) lParam);
      case HLN_DESTROY_CONTROL:   break; //return OnDestroyControl((LPNMHL_DESTROY_CONTROL) lParam);
      case HLN_LOAD_DATA:         break; //return OnLoadData((LPNMHL_LOAD_DATA) lParam);
      case HLN_DATA_LOADED:       break; //return OnDataLoaded((LPNMHL_DATA_LOADED)lParam);
      case HLN_DOCUMENT_COMPLETE: 
                                  //MessageBox(NULL,"1","1",MB_OK);

                                 break; //return OnDocumentComplete();

      case HLN_ATTACH_BEHAVIOR:   return OnAttachBehavior((LPNMHL_ATTACH_BEHAVIOR)lParam );
  }
  return 0;
}


void OnButtonClick(HELEMENT button)
{
  showDebug($D(button).get_attribute_name(0));
  string a;
  a="jjjjjjjj<b>哈</b>j<i>j</i>jjjjjjjjjjj";
  unsigned char aa[128]="";
  strcpy((char*)aa,a.c_str());
  $D(button).set_html(aa,128);
	//::MessageBoxW(NULL,L"My name is demo1.",L"Demo",0);
    //button->get_attribute_name();
}




LRESULT OnAttachBehavior(LPNMHL_ATTACH_BEHAVIOR lpab )
{
    // attach custom behaviors GetHtmlResource
    //MessageBox(NULL,lpab->behaviorName,"1",MB_OK);
    htmlayout::event_handler *pb = htmlayout::behavior::find(lpab->behaviorName, lpab->element);
       
    htmlayout::debug_output_console dc;
      dc.printf("behave: %s\n", lpab->behaviorName );

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
        HTMLayoutSetCallback(hwnd,&HTMLayoutNotifyHandler,0);//通知函数
        htmlayout::attach_event_handler(hwnd, &DOMEventsHandler);//事件处理函数
        PBYTE pb; DWORD cb;
        if(GetHtmlResource("DEFAULT",pb,cb))
          HTMLayoutLoadHtml(hwnd,pb,cb);
        return 0;
      }
      break;


     }
     return DefWindowProc (hwnd, message, wParam, lParam) ;
}

HINSTANCE hInst;
BOOL GetHtmlResource(LPCSTR pszName, /*out*/PBYTE& pb, /*out*/DWORD& cb)
{
  // Find specified resource and check if ok

  HRSRC hrsrc = ::FindResource(hInst, a2t(pszName), MAKEINTRESOURCE(RT_HTML));

  if(!hrsrc) 
    return false;

  // Load specified resource and check if ok
  
  HGLOBAL hgres = ::LoadResource(hInst, hrsrc);
  if(!hgres) return FALSE;

  // Retrieve resource data and check if ok

  pb = (PBYTE)::LockResource(hgres); if (!pb) return FALSE;
  cb = ::SizeofResource(hInst, hrsrc); if (!cb) return FALSE;

  return TRUE;
}

