#include "behavior_aux.h"
#include "sql.hpp"

namespace htmlayout 
{

/*
BEHAVIOR: actions
  
  Simplistic action interpretter.

  on button clicks exectues actions described by 'action' attribute.

TYPICAL USE CASE:
   < div style="behavior:actions" >
        ....
        <button action="alert: Hello world!" >
        .... 
   </div>
*/

static bool parse_args( aux::wchars a, aux::wchars& arg );
static bool parse_args( aux::wchars a, aux::wchars& arg1, aux::wchars& arg2 );
static bool parse_args( aux::wchars a, aux::wchars& arg1, aux::wchars& arg2, aux::wchars& arg3, aux::wchars& arg4 );

// parse dtring "checked" or "!checked" to int STATE_CHECKED, etc.
static int parse_state( aux::wchars sst );

BOOL FindFirstFileExists(LPCTSTR lpPath, DWORD dwFilter)
{
    WIN32_FIND_DATA fd;
    HANDLE hFind = FindFirstFile(lpPath, &fd);
    BOOL bFilter = (FALSE == dwFilter) ? TRUE : fd.dwFileAttributes & dwFilter;
    BOOL RetValue = ((hFind != INVALID_HANDLE_VALUE) && bFilter) ? TRUE : FALSE;
    FindClose(hFind);
    return RetValue;
}

BOOL file_exists(LPCTSTR lpPath)
{
    return FindFirstFileExists(lpPath, FALSE);
}

BOOL dir_exists(LPCTSTR lpPath)
{
    return FindFirstFileExists(lpPath, FILE_ATTRIBUTE_DIRECTORY);
}

char * get_dir()
{
   static char g_cmd_path[MAX_PATH];
   if (g_cmd_path[0]!='\0') return g_cmd_path;
    memset( g_cmd_path, 0, MAX_PATH*sizeof(char));
    GetCurrentDirectory( MAX_PATH, g_cmd_path );
    // showDebug((g_cmd_path));
    return g_cmd_path;
}

#define __DIR__ get_dir()

/*
 * 检查一个  路径 是否存在（绝对路径、相对路径，文件或文件夹均可）
 * 存在则返回 1 (TRUE)
 */
BOOL FilePathExists(LPCTSTR lpPath)
{
    return FindFirstFileExists(lpPath, FALSE);
}
struct tests: public behavior
{

    // ctor
    tests(): behavior(HANDLE_BEHAVIOR_EVENT | HANDLE_KEY, "tests") {}

/*     virtual BOOL handle_key    (HELEMENT he, KEY_PARAMS& params )  */
    // {
        // showDebug(1);
        // return true;
    /* } */
    virtual BOOL on_key    (HELEMENT he, HELEMENT target, UINT event_type, UINT code, UINT keyboardStates ) { 
        if (event_type != KEY_UP){return FALSE;}
        if (code == VK_RETURN)
        {
            dom::element btn = target;
            dom::element root = btn.root();
            // root.get_element_by_id("value")
            //json::value a;
            //a=get_value($D(root.get_element_by_id("value")));
            const wchar_t* value = $D(root.find_first("#value")).get_value().to_string().c_str();
            std::string sPath = __DIR__;
            std::string sDir(sPath + "/db");
            if (!dir_exists(sDir.c_str()))CreateDirectory(sDir.c_str(),NULL);
            sDir = sPath +"/db/"+ std::string(aux::w2a(value));
            PSQL->connect(sDir);
            //sql db(sDir.c_str());
            PSQL->createTable();
            //showDebug(aux::w2a(a.to_string()));
            // MessageBoxW(root.get_element_hwnd(true),a.to_string(),a.to_string(),0);
            ::PostMessage(root.get_element_hwnd(true), WM_CLOSE, 0,0 );
        }
        return FALSE; 
    }

    virtual BOOL on_event (HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason ) 
    { 
      if (type == EDIT_VALUE_CHANGED)
      {
        return FALSE;
      }
      if( type != BUTTON_CLICK )
        return FALSE;
      
      dom::element btn = target;
      const wchar_t* action = btn.get_attribute("action");
      if( !action )
        return FALSE;  // it is not a button we know about
      if(interpret_action( btn.root(), action) )
        return TRUE;
      return FALSE;
    }

    // Just an idea: here should go some simple interpretter.
    // If you know one - let me know.
    // For a while it is just dumb thing like this:
    bool interpret_action( dom::element root, const wchar_t* action )
    {
      aux::wchars a = aux::chars_of(action);

      if( a.like(L"alert:*"))
      {
        aux::wchars msg;
        if(parse_args(a,msg))
          ::MessageBoxW(root.get_element_hwnd(true),msg.start,L"alert!",MB_OK);
        return true;
      }
      else if (a.like(L"showdialog:*"))
      {
          doaction::show_add_root(root.get_element_hwnd(true));
          //htmlayout::doactions();
          return true;

      }
      else if (a.like(L"showRootList:*"))
      {
          // ::MessageBoxW(root.get_element_hwnd(true),L"xx",L"alert!",MB_OK);
        aux::wchars msg;
        if(parse_args(a,msg)){
          doaction::show_add_root(root.get_element_hwnd(true),msg.start);
        }
          return true;
      }
      else if (a.like(L"saveRoot:*"))
      {
      
      }
      else if (a.like(L"saveTitle:*"))
      {
      
      }

      else if( a.like(L"copy-value:*")) // copy-value: dst selector , src selector
      {
        aux::wchars src_sel, dst_sel;
        if(!parse_args(a,dst_sel,src_sel))
          return true;
        MessageBox(NULL,(const char*)aux::w2a(src_sel),(const char*)aux::w2a(dst_sel),0);
        dom::element src = root.find_first((const char*)aux::w2a(src_sel));
        dom::element dst = root.find_first((const char*)aux::w2a(dst_sel));
        if(!src.is_valid() || !dst.is_valid())
        {
          assert(0); // not found!
          return false;
        }
        json::value v = src.get_value();
        dst.set_value(v);
        dst.set_state(STATE_FOCUS);
        return true;
      }
      else if( a.like(L"copy-state:*")) 
        return action_copy_state( root, a);
      
      return false;
    }

    struct Actor: dom::callback 
    {
      int  state_to_set;
      int  state_to_clear;
      Actor():state_to_set(0),state_to_clear(0) {}
      virtual bool on_element(HELEMENT he) 
      {
         htmlayout::dom::element el = he; 
         el.set_state(state_to_set,state_to_clear); 
         return false; /*continue enumeration*/ }
      virtual ~Actor() {}
    };

    // copy-state: dst-state, dst-selector, src-state, src-selector
    bool action_copy_state( dom::element root, aux::wchars cmd)
    {
      aux::wchars src_state, src_sel, dst_state, dst_sel;
      if(!parse_args(cmd,dst_state, dst_sel, src_state, src_sel))
        return true;
      dom::element src = root.find_first((const char*)aux::w2a(src_sel));
      if(!src.is_valid())
        return true;

      Actor actor;

      bool v = src.get_state( parse_state(src_state) );
      if(src_state[0] == '!') v = !v;
      
      actor.state_to_set = 0; actor.state_to_clear = 0;
      if(v) { actor.state_to_set = parse_state( dst_state ); actor.state_to_clear = 0; }
      else  { actor.state_to_set = 0; actor.state_to_clear = parse_state( dst_state ); }
      
      // walk through all dst_sel elements.
      root.find_all(&actor, (const char*)aux::w2a(dst_sel));

      return true;

    }
};

// instantiating and attaching it to the global list
tests tests_instance;


bool parse_args( aux::wchars a, aux::wchars& arg )
{
  aux::wtokens wt( a, L":" );
  aux::wchars t;
  for(int n = 0; n < 2; ++n)
    if(!wt.next(t))
    {
      assert(0); // wrong format!
      return false;
    }
    else if( n == 1) 
      arg = t;
  return true;
}

bool parse_args( aux::wchars a, aux::wchars& arg1, aux::wchars& arg2 )
{
  aux::wtokens wt( a, L":," );
  aux::wchars t;
  for(int n = 0; n < 3; ++n)
    if(!wt.next(t))
    {
      assert(0); // wrong format!
      return false;
    }
    else switch( n ) 
    {
      case 1: arg1 = aux::trim(t); break;
      case 2: arg2 = aux::trim(t); break;
    }
  return true;
}

bool parse_args( aux::wchars a, aux::wchars& arg1, aux::wchars& arg2, aux::wchars& arg3, aux::wchars& arg4 )
{
  aux::wtokens wt( a, L":," );
  aux::wchars t;
  for(int n = 0; n < 5; ++n)
    if(!wt.next(t))
    {
      assert(0); // wrong format!
      return false;
    }
    else switch( n ) 
    {
      case 1: arg1 = aux::trim(t); break;
      case 2: arg2 = aux::trim(t); break;
      case 3: arg3 = aux::trim(t); break;
      case 4: arg4 = aux::trim(t); break;
    }
  return true;
}

int parse_state( aux::wchars sst )
{
  if( sst[0] == '!' )
  {
    ++sst.start;
    --sst.length; 
  }
  if( sst == const_wchars("checked") ) return STATE_CHECKED;
  if( sst == const_wchars("active") ) return STATE_ACTIVE;
  if( sst == const_wchars("focus") ) return STATE_FOCUS;
  if( sst == const_wchars("current") ) return STATE_CURRENT;
  if( sst == const_wchars("checked") ) return STATE_CHECKED;
  if( sst == const_wchars("disabled") ) return STATE_DISABLED;
  if( sst == const_wchars("readonly") ) return STATE_READONLY;
  if( sst == const_wchars("expanded") ) return STATE_EXPANDED;
  if( sst == const_wchars("collapsed") ) return STATE_COLLAPSED;
  if( sst == const_wchars("anchor") ) return STATE_ANCHOR;
  if( sst == const_wchars("tabfocus") ) return STATE_TABFOCUS;
  if( sst == const_wchars("busy") ) return STATE_BUSY;
  assert(0); // sst is not recognized 
  return 0;
}



} // htmlayout namespace

