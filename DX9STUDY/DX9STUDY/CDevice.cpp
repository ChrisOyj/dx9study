#include "pch.h"
#include "CDevice.h"

CDevice::CDevice()
{}

CDevice::~CDevice()
{
	Release();
}

HRESULT CDevice::Initialize()
{
	//SDK ��ü ����
	if (NULL == (m_pSDK = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	Set_Parameters(d3dpp);

	// 2. �ϵ���� ����

	D3DCAPS9			DeviceCaps;
	ZeroMemory(&DeviceCaps, sizeof(D3DCAPS9));

	// GetDeviceCaps : ��ġ�� ���� ����(���� ����)�� ������ �Լ�
	// D3DADAPTER_DEFAULT : ������ �������� �⺻ �׷��� ī�带 �ǹ�
	if (FAILED(m_pSDK->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &DeviceCaps)))
	{
		return E_FAIL;
	}

	DWORD		vp = 0;		// ���ؽ� ���μ��� = ������ ��ȯ + ������

	// HAL�� ���� ������ ��ġ�� �ϵ���� ���ؽ� ���μ����� �����Ѵٸ�
	if (DeviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp |= D3DCREATE_HARDWARE_VERTEXPROCESSING;

	else
		vp |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	if (FAILED(m_pSDK->CreateDevice(
		D3DADAPTER_DEFAULT,		// ����� 2�� �̻��� ��� ��� ����Ϳ� ����
		D3DDEVTYPE_HAL,			// �ϵ���� ������ �����ϴ� ����̽� �� ����
		g_hWnd,			
		vp,						// ���̴��� �ϵ������� �� ����Ʈ����� �� �� ����
		&d3dpp,					
		&m_pDevice)))
		return E_FAIL;


	return S_OK;
}

void CDevice::Release()
{
	if (m_pDevice)
		m_pDevice->Release();

	if (m_pSDK)
		m_pSDK->Release();
}

void CDevice::Set_Parameters(D3DPRESENT_PARAMETERS& d3dpp)
{
	d3dpp.BackBufferWidth = WINCX;
	d3dpp.BackBufferHeight = WINCY;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;

	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;

	/*D3DSWAPEFFECT_DISCARD = ����ü�� ���
	D3DSWAPEFFECT_FLIP = ���� �ϳ��� �������鼭 ����ϴ� ���
	D3DSWAPEFFECT_COPY = ���� ���۸��� ������ ���� ���*/

	//���� ü�� : ������ �ø��� ������� �̷��� ������ ���� ���۴� ������ ���, �ĸ� ���۴� ����� ���� ȭ�� ����� ���� �׸��� ���� �д����� ���� ����Ű�� ����� ��ü�Ͽ� �����Ÿ� ���� �� ȭ�� ������ �����ϰ� ������ �� �ִ�.

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;		// ����ü�� ���
	d3dpp.hDeviceWindow = g_hWnd;

	//â ���� ����, ��üȭ�� ����
	d3dpp.Windowed = TRUE;		// TRUE�� ��� â ��� ����

	// Ÿ�� ����(�׸��� ����), ���ٽ� ����(�ݻ簡 �Ǵ� ���� ǥ��), ���� ����(���� ���� ����)
	// �ڵ����� ���ٽ� ���ۿ� ���̹��۸� �����ϰڴٴ� �ɼ�
	d3dpp.EnableAutoDepthStencil = TRUE;
	//���� ���� 24��Ʈ, ���ٽ� ���� 8��Ʈ
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

	// ��üȭ�� �ÿ��� ���Ǵ� �Ű� ������
	// â ��忡���� �ü���� ������� ������
	// ��üȭ�� �ÿ��� �׷��� ī�尡 �����ϰ� �ȴ�.

	// ��üȭ�� �� ���� ����� ��������� ����(���� ����� ������� ���� �˾Ƽ� ����)
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;

	// ������� �ÿ� ���ݼ���
	// D3DPRESENT_INTERVAL_IMMEDIATE  : ��� �ÿ�
	// D3DPRESENT_INTERVAL_DEFAULT : ������ ������ ��ġ�� �˾Ƽ� ����(���� ����� ������� ����)
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}
