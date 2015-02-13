#include "action.h"
bool doaction::show_add_root(HWND hwnd)
{
    ::root a(hwnd); 
    htmlayout::named_values values;

    if (a.input(IDR_ROOT_EDIT,values) == IDOK)
    {
        std::wstring s;
      for ( htmlayout::named_values::const_iterator it = values.begin(); it != values.end() ; ++it )
      {
        s += (*it).first;
        s += L"=";
        s += (*it).second.to_string();
        s += L"\n";
      }
      ::MessageBoxW(hwnd,s.c_str(),L"values are:", MB_OK);
    }
    return true;
}
namespace htmlayout
{
    bool action::buttonClick(HWND hwnd,HELEMENT button)
    {
      // const wchar_t * action;
      // action = $D(button).get_attribute("action");
      //showDebug($D(button).get_attribute_name(0));
       LPCWSTR  action;
       HTMLayoutGetAttributeByName(button,"act",&action); 
       if (wcscmp(action,L"show_add_root") == 0)
       {
           doaction::show_add_root(hwnd);
       }

       return true;
    }
}
