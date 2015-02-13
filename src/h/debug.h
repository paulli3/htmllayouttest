#ifndef DEBUGH_INCLUDE

#define DEBUGH_INCLUDE 1
#include "stdio.h"
#include "html/res.h"
#include "htmlayout.h"
#include "windows.h"
#include <string>
#include "root.h"
#include "window.h"
#include "action.h"

//#include "Include_behavior.cpp"
#include "Include_const.h"

void showDebug(const char * str);

void showDebug(int i);

void showDebug(LPCSTR str);

void showDebug(const wchar_t * str);
#endif
