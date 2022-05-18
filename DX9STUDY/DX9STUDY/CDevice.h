#pragma once
#include "Include.h"

class CDevice
{
	SINGLE(CDevice)

public:
	IDirect3DDevice9* Get_Device() { return m_pDevice; }

public:
	HRESULT		Initialize();
	void		Release();

private:
	void		Set_Parameters(D3DPRESENT_PARAMETERS& d3dpp);

private:
	IDirect3D9*			m_pSDK;
	IDirect3DDevice9*	m_pDevice;
};

