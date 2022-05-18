#include "pch.h"
#include "CCore.h"

#include "CDevice.h"

CCore::CCore()
{
}

CCore::~CCore()
{
}

HRESULT CCore::Initialize()
{
	if (E_FAIL == CDevice::Get_Instance()->Initialize())
	{
		ErrorMessage(L"디바이스 초기화 실패");
		return E_FAIL;
	}
	
	return S_OK;
}

void CCore::Progress()
{
	CDevice::Get_Instance()->Get_Device()->Clear(0, NULL, D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	if (SUCCEEDED(CDevice::Get_Instance()->Get_Device()->BeginScene()))
	{



		CDevice::Get_Instance()->Get_Device()->EndScene();
	}

	CDevice::Get_Instance()->Get_Device()->Present(0, 0, 0, 0);

}
