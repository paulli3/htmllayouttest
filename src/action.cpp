#include "action.h"

bool doaction::show_add_root(HWND hwnd,const wchar_t * type)
{
    // return show_add_root(hwnd);
    ::root dlg(hwnd);
    if (wcscmp(type,L"rootedit") == 0)
    {
        dlg.show(IDR_ROOT_EDIT);
    }
    else if (wcscmp(type,L"dbedit") == 0)
    {
        dlg.show(IDR_DB_EDIT);
    }
    // json::value val(type);
    // ::root a(hwnd);
    // htmlayout::dom::element _root = htmlayout::dom::root_element(hwnd);
    // a.show(IDR_ROOT_EDIT);
    //$D(_root.find_first("#value")).set_value(val);
    return true;
}


bool doaction::showRootList(htmlayout::dom::element root)
{
   return showRootList(root,L"#rootbox","db/123");
}

bool doaction::showRootList(htmlayout::dom::element root,const wchar_t * parentID/* = L "#rootList"*/,const char * dbNam/* = "db/123"*/)
{

    sql * PSQL = &sql::getInstance();
    std::string html ="";
    Record * precode;
    PSQL->query("SELECT * FROM root order by id desc");
    while ( (precode = PSQL->RESCULT()->getone() )){
        //debug(precode->get("id").c_str());
        /* int d = precode->get("title").length(); */
        // char len[25]="";
        // sprintf(len,"%d",d);
        // std::string c(len);
        /* std::string b(precode->get("title") +"<--->"+ c); */
        /* MessageBox(NULL,b.c_str(),"1",0); */
        /* MessageBoxW(NULL,aux::a2w( b.c_str()),L"1",0); */
        html = html + "<li action=\"alert:"+precode->get("id")+"\">" + ::ToUTF8(aux::a2w(precode->get("title").c_str())) + "</li>";
        // html = html + "<li action=\"alert:dbedit\">" + precode->get("title") + "</li>";
    }
    const unsigned  char chtml[102000]="";
    strcpy((char*)chtml,html.c_str());
    htmlayout::dom::element rootList = $D(root.find_first(parentID));
    if (rootList.is_valid())
    {
        rootList.set_html(chtml,sizeof(chtml));
    }
    return true;
}

bool doaction::show_add_root(HWND hwnd)
{
    ::root a(hwnd); 
    htmlayout::named_values values;

    if (a.input(IDR_ROOT_EDIT,values) == IDOK)
    {
      /*   std::wstring s; */
      // for ( htmlayout::named_values::const_iterator it = values.begin(); it != values.end() ; ++it )
      // {
        // s += (*it).first;
        // s += L"=";
        // s += (*it).second.to_string();
        // s += L"\n";
      // }
      /* ::MessageBoxW(hwnd,s.c_str(),L"values are:", MB_OK); */
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
