#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

#include <d3d9.h>
#include <d3dx9.h>


#include <assert.h>
#include <random>

#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <array>
#include <algorithm>
#include <functional>
#include <ctime>
#include <exception>
#include <tchar.h>
#include <process.h>
using namespace std;

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif

#endif // _DEBUG