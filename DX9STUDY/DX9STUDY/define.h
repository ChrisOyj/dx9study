#pragma once

#define TILECX		2.f
#define TILECY		2.f

#define WINCX 800
#define WINCY 600

#define SINGLE(type) public:\
					static type* Get_Instance() {\
						static type mgr;\
						return &mgr;\
					}\
					private:\
					explicit type();\
					~type();

#define CLONE(type)				type* Clone() { return new type(*this); }

#define MGR(type)  type::Get_Instance()

#define KEY(key, state) CKeyMgr::Get_Instance()->Get_KeyState(KEY::key) == KEY_STATE::state

#define fDT CTimeMgr::Get_Instance()->Get_fDT()
#define DT CTimeMgr::Get_Instance()->Get_DT()

#define FRICTION	1000.f
#define AIRFRICTION	100.f

#define TCHARSIZE(szArr) sizeof(szArr)/sizeof(TCHAR)

#define		MIN_STR			64
#define		MAX_STR			256

#define		HASHCODE(type)	typeid(type).hash_code()



typedef		D3DXVECTOR3		Vec3;


extern		HWND			g_hWnd;
