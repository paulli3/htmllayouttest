#include "debug.h"
#ifdef _DEBUG
htmlayout::debug_output_console _debug_stream;
#endif

namespace htmlayout
{

  HINSTANCE window::hinstance = 0;

  const wchar_t CLASSNAME[] = L"htmlayout::window";

  // register window class

  ATOM  window::register_class(HINSTANCE hInstance)
  {
    hinstance = hInstance;

    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX); 

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = (WNDPROC)win_proc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, (LPCTSTR)IDI_SKIN);
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = 0;
    wcex.lpszClassName  = CLASSNAME;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SKINSMALL);

    return RegisterClassExW(&wcex);
  }

#ifndef WS_EX_LAYERED
#define WS_EX_LAYERED           0x00080000
#endif

  // create window instance

  window* window::create( int x, int y, int width, int height, const wchar_t* caption ) 
  {
    window* pw = new window();

    UINT style = WS_POPUP | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SYSMENU | WS_SIZEBOX;
    pw->hwnd = CreateWindowExW( WS_EX_LAYERED, CLASSNAME, NULL, style ,
                                x, y, width, height, NULL, NULL, hinstance, NULL);
//    pw->hwnd = CreateWindowExW( 0, CLASSNAME, NULL, style ,
//                                x, y, width, height, NULL, NULL, hinstance, NULL);
    self(pw->hwnd,pw);
    HTMLayoutSetCallback(pw->hwnd,&callback,pw);

    //attach_event_handler(pw->hwnd, &DOMEventsHandler);//事件处理函数
    PBYTE pb; DWORD cb;
    if(load_resource_data(L"DEFAULT",pb,cb))
    {
      HTMLayoutLoadHtml(pw->hwnd,pb,cb);
    // const char * mcss="html{behavior:accesskeys tests;font:10pt Verdana;overflow:hidden;background-color:transparent;background-image:url(res:back1.png);background-repeat:expand;background-position:15 15 15 15}body{padding:3px;margin:0;width:100%%;height:100%%}#topbar widget[type=\"button\"]{width:1em;height:1em;background-image:none;padding:1px;font-family:marlett;font-size:10pt;color:#FFF;border:1px solid #FFF;text-align:center;vertical-align:center;margin:0}#topbar widget[type=\"button\"]:hover{color:orange;border-color:orange;background-color:#B0CFD1;outline:2px glow orange 4px}#topbar widget[type=\"button\"]:active{background-color:#274749}#topbar #minimize,#topbar #maximize{margin-right:2px}#topbar #icon{foreground-image:url(res:back.png);foreground-repeat:no-repeat;foreground-position:50% 50%}#topbar{flow:horizontal;padding:4px 10px 5px}#topbar #caption{color:#FFF;padding:0 4px;outline:3px glow #274749}#bottombar{flow:horizontal}#bottombar #corner{margin-top:100%%;font-family:marlett;font-size:10pt;color:#274749;width:min-intrinsic}#bottombar #status{color:#274749;font-size:9pt}";
      // HTMLayoutAppendMasterCSS((LPCBYTE)mcss,strlen(mcss));
      dom::element r = pw->root();

      pw->body            = r.find_first("body");
      pw->caption         = r.get_element_by_id("caption");
      pw->button_min      = r.get_element_by_id("minimize");
      pw->button_max      = r.get_element_by_id("maximize");
      pw->button_icon     = r.get_element_by_id("icon");
      pw->button_close    = r.get_element_by_id("close");
      pw->corner          = r.get_element_by_id("corner");

      attach_event_handler(pw->hwnd, pw);

      pw->set_caption(caption);

    }
    return pw;
  }
  
/*   LRESULT CALLBACK callback(UINT uMsg, WPARAM wParam, LPARAM lParam, LPVOID vParam)  */
  // {
      // // all HTMLayout notification are comming here.
      // NMHDR*  phdr = (NMHDR*)lParam;
      // //MessageBox(NULL,"1","1",MB_OK);
      // switch(phdr->code)
      // {
          // case HLN_CREATE_CONTROL:    break; //return OnCreateControl((LPNMHL_CREATE_CONTROL) lParam);
          // case HLN_CONTROL_CREATED:   break; //return OnControlCreated((LPNMHL_CREATE_CONTROL) lParam);
          // case HLN_DESTROY_CONTROL:   break; //return OnDestroyControl((LPNMHL_DESTROY_CONTROL) lParam);
          // case HLN_LOAD_DATA:         break; //return OnLoadData((LPNMHL_LOAD_DATA) lParam);
          // case HLN_DATA_LOADED:       break; //return OnDataLoaded((LPNMHL_DATA_LOADED)lParam);
          // case HLN_DOCUMENT_COMPLETE: 
                                      // //MessageBox(NULL,"1","1",MB_OK);

                                      // break; //return OnDocumentComplete();

          // case HLN_ATTACH_BEHAVIOR:   break;//htmlayout::window::OnAttachBehavior((LPNMHL_ATTACH_BEHAVIOR)lParam );break;
      // }
      // return 0;
  /* }  */

  static LRESULT OnAttachBehavior(LPNMHL_ATTACH_BEHAVIOR lpab )
  {
      // attach custom behaviors GetHtmlResource
      //MessageBox(NULL,lpab->behaviorName,"1",MB_OK);
      htmlayout::event_handler *pb = htmlayout::behavior::find(lpab->behaviorName, lpab->element);

      //   htmlayout::debug_output_console dc;
      //     dc.printf("behave: %s\n", lpab->behaviorName );

      if(pb) 
      {
          lpab->elementTag  = pb;
          lpab->elementProc = htmlayout::behavior::element_proc;
          lpab->elementEvents = pb->subscribed_to;
      }
      return 0;
  } 
  void window::set_caption( const wchar_t* text )
  {
    if(text)
    {
      ::SetWindowTextW(hwnd,text);
      if( caption.is_valid() )
      {
        caption.set_text(text);
        //caption.update(true);
      }
    }
  }


  HELEMENT  window::root()
  {
    return dom::element::root_element(hwnd);
  }

  int       window::hit_test( int x, int y )
  {
    
    POINT pt; pt.x = x; pt.y = y;
    ::MapWindowPoints(HWND_DESKTOP,hwnd,&pt,1);

    if( caption.is_valid() && caption.is_inside(pt) )
      return HTCAPTION;

    if( button_icon.is_valid() && button_icon.is_inside(pt) )
      return HTSYSMENU;

    if( corner.is_valid() && corner.is_inside(pt) )
      return HTBOTTOMRIGHT;

    RECT body_rc = body.get_location(ROOT_RELATIVE | CONTENT_BOX);

    if( PtInRect(&body_rc, pt) )
      return HTCLIENT;

    if( pt.y < body_rc.top + 10 ) 
    {
      if( pt.x < body_rc.left + 10 ) 
        return HTTOPLEFT;
      if( pt.x > body_rc.right - 10 ) 
        return HTTOPRIGHT;
    }
    else if( pt.y > body_rc.bottom - 10 ) 
    {
      if( pt.x < body_rc.left + 10 ) 
        return HTBOTTOMLEFT;
      if( pt.x > body_rc.right - 10 ) 
      {
//        htmlayout::debug_output_console dc;
//        dc.printf("HTBOTTOMRIGHT\n");

        return HTBOTTOMRIGHT;
      }
    }

    if( pt.y < body_rc.top ) 
      return HTTOP;
    if( pt.y > body_rc.bottom ) 
      return HTBOTTOM;
    if( pt.x < body_rc.left ) 
      return HTLEFT;
    if( pt.x > body_rc.right ) 
      return HTRIGHT;


    return HTCLIENT;
   
  }

  BOOL window::on_event (HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason )
  {
    if (type == EDIT_VALUE_CHANGED)
    {
       // showDebug(1);
    }
    if( type != BUTTON_CLICK)
      return FALSE; // handling only button clicks here. 
    if( target == button_min)
    {
      ::ShowWindow(hwnd,SW_MINIMIZE); 
      return TRUE;
    }
    if( target == button_max)
    {
      if( is_maximized())
        ::ShowWindow(hwnd,SW_RESTORE); 
      else
        ::ShowWindow(hwnd,SW_MAXIMIZE); 
      
      return TRUE;
    }
    if( target == button_close)
    {
      ::PostMessage(hwnd, WM_CLOSE, 0,0); 
      return TRUE;
    }

    // click on some other button
    dom::element button = target;
    //::MessageBoxW(button.get_element_hwnd(true) ,button.get_attribute("id"), L"Click on the button with id:", MB_OK);
    //::MessageBox(button.get_element_hwnd(true) ,"test", "Click on the button with id:", MB_OK);
    OnButtonClick(hwnd,target);
    return TRUE;
  }

  bool window::is_minimized() const
  {
      WINDOWPLACEMENT wp;
      GetWindowPlacement(hwnd,&wp);
      return wp.showCmd == SW_SHOWMINIMIZED;
  }

  bool window::is_maximized() const
  {
      WINDOWPLACEMENT wp;
      GetWindowPlacement(hwnd,&wp);
      return wp.showCmd == SW_SHOWMAXIMIZED;
  }
  
  

  LRESULT CALLBACK window::win_proc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
  {
    LRESULT lResult;
    BOOL    bHandled;

  // HTMLayout +
    // HTMLayout could be created as separate window 
    // using CreateWindow API.
    // But in this case we are attaching HTMLayout functionality
    // to the existing window delegating windows message handling to 
    // HTMLayoutProcND function.
    lResult = HTMLayoutProcND(hwnd,message,wParam,lParam, &bHandled);
    if(bHandled)
      return lResult;
  // HTMLayout -

    window* me = self(hwnd);
    switch (message) 
    {
      
      case WM_NCHITTEST:
        if(me)
          return me->hit_test( GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) );
        break;

      case WM_NCCALCSIZE:  return 0; // we have no non-client areas.
      case WM_NCPAINT:     return 0; // we have no non-client areas.
      case WM_NCACTIVATE:  return (wParam == 0)? TRUE : FALSE; // we have no non-client areas.

      case WM_GETMINMAXINFO:
        {
          LRESULT lr = DefWindowProcW(hwnd, message, wParam, lParam);
          MINMAXINFO* pmmi = (MINMAXINFO*)lParam;
          pmmi->ptMinTrackSize.x = ::HTMLayoutGetMinWidth(hwnd);
          RECT rc; GetWindowRect(hwnd,&rc);
          pmmi->ptMinTrackSize.y = ::HTMLayoutGetMinHeight(hwnd, rc.right - rc.left);
          return lr;
        }

      case WM_CLOSE:
        ::DestroyWindow(hwnd);
        return 0;

      case WM_DESTROY:
        delete me; // delete window instance!
        self(hwnd,0);
        PostQuitMessage(0);
        return 0;

     }
     return DefWindowProcW(hwnd, message, wParam, lParam);
  }

}
void htmlayout::window::OnButtonClick(HWND hwnd,HELEMENT button)
{
    
    htmlayout::action act(hwnd);
    act.buttonClick(hwnd,button);
    /* ::root a(hwnd); */
    // htmlayout::named_values values;

    // if (a.input(IDR_ROOT_EDIT,values) == IDOK)
    // {
        // std::wstring s;
      // for ( htmlayout::named_values::const_iterator it = values.begin(); it != values.end() ; ++it )
      // {
        // s += (*it).first;
        // s += L"=";
        // s += (*it).second.to_string();
        // s += L"\n";
      // }
      // ::MessageBoxW(hwnd,s.c_str(),L"values are:", MB_OK);
    /* } */
}


  LRESULT CALLBACK callback(UINT uMsg, WPARAM wParam, LPARAM lParam, LPVOID vParam)  
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

          case HLN_ATTACH_BEHAVIOR:   break;//htmlayout::window::OnAttachBehavior((LPNMHL_ATTACH_BEHAVIOR)lParam );break;
      }
      return 0;
  }  


