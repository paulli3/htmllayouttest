#ifndef DEBUGH_INCLUDE

#define DEBUGH_INCLUDE 1
#include "stdio.h"
#include "html/res.h"
#include "htmlayout.h"
#include "windows.h"
#include <string>
//#include "root.h"
#include "window.h"
//#include "action.h"

#include <codecvt>
//#include "sql.hpp"
//#include "Include_behavior.cpp"
//#include "Include_const.h"

void showDebug(const char * str);

void showDebug(int i);

void showDebug(LPCSTR str);

void showDebug(const wchar_t * str);

std::string ToUTF8(const wchar_t* wideStr);
/* std::string ToUTF8(const wchar_t* wideStr) */
/* { */
    /* std::wstring_convert<std::codecvt_utf8<wchar_t>> conv; */
    /* return conv.to_bytes(wideStr); */
/* } */

/* BOOL StringToWString(const std::string &str,std::wstring &wstr) */
 /* {     */
     /* int nLen = (int)str.length();     */
     /* wstr.resize(nLen,L' '); */
 
     /* int nResult = MultiByteToWideChar(CP_ACP,0,(LPCSTR)str.c_str(),nLen,(LPWSTR)wstr.c_str(),nLen); */
 
     /* if (nResult == 0) */
     /* { */
         /* return FALSE; */
     /* } */
 
     /* return TRUE; */
 /* } */
 /* //wstring高字节不为0，返回FALSE */
 /* BOOL WStringToString(const std::wstring &wstr,std::string &str) */
 /* {     */
     /* int nLen = (int)wstr.length();     */
     /* str.resize(nLen,' '); */
 
     /* int nResult = WideCharToMultiByte(CP_ACP,0,(LPCWSTR)wstr.c_str(),nLen,(LPSTR)str.c_str(),nLen,NULL,NULL); */
 
     /* if (nResult == 0) */
     /* { */
         /* return FALSE; */
     /* } */
 
     /* return TRUE; */
 /* } */
/* BOOL FindFirstFileExists(LPCTSTR lpPath, DWORD dwFilter) */
/* { */
    /* WIN32_FIND_DATA fd; */
    /* HANDLE hFind = FindFirstFile(lpPath, &fd); */
    /* BOOL bFilter = (FALSE == dwFilter) ? TRUE : fd.dwFileAttributes & dwFilter; */
    /* BOOL RetValue = ((hFind != INVALID_HANDLE_VALUE) && bFilter) ? TRUE : FALSE; */
    /* FindClose(hFind); */
    /* return RetValue; */
/* } */

/* BOOL file_exists(LPCTSTR lpPath) */
/* { */
    /* return FindFirstFileExists(lpPath, FALSE); */
/* } */

/* BOOL dir_exists(LPCTSTR lpPath) */
/* { */
    /* return FindFirstFileExists(lpPath, FILE_ATTRIBUTE_DIRECTORY); */
/* } */

/* char * get_dir() */
/* { */
   /* static char g_cmd_path[MAX_PATH]; */
   /* if (g_cmd_path[0]!='\0') return g_cmd_path; */
    /* memset( g_cmd_path, 0, MAX_PATH*sizeof(char)); */
    /* GetCurrentDirectory( MAX_PATH, g_cmd_path ); */
    /* // showDebug((g_cmd_path)); */
    /* return g_cmd_path; */
/* } */

#endif
