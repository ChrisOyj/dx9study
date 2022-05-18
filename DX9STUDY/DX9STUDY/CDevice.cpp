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
	//SDK 객체 생성
	if (NULL == (m_pSDK = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));

	Set_Parameters(d3dpp);

	// 2. 하드웨어 조사

	D3DCAPS9			DeviceCaps;
	ZeroMemory(&DeviceCaps, sizeof(D3DCAPS9));

	// GetDeviceCaps : 장치에 대한 정보(지원 수준)를 얻어오는 함수
	// D3DADAPTER_DEFAULT : 정보를 얻으려는 기본 그래픽 카드를 의미
	if (FAILED(m_pSDK->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &DeviceCaps)))
	{
		return E_FAIL;
	}

	DWORD		vp = 0;		// 버텍스 프로세싱 = 정점의 변환 + 조명연산

	// HAL을 통해 조사한 장치가 하드웨어 버텍스 프로세싱을 지원한다면
	if (DeviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp |= D3DCREATE_HARDWARE_VERTEXPROCESSING;

	else
		vp |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	if (FAILED(m_pSDK->CreateDevice(
		D3DADAPTER_DEFAULT,		// 모니터 2개 이상인 경우 어디 모니터에 할지
		D3DDEVTYPE_HAL,			// 하드웨어 가속을 지원하는 디바이스 할 계층
		g_hWnd,			
		vp,						// 셰이더를 하드웨어로할 지 소프트웨어로 할 지 결정
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

	/*D3DSWAPEFFECT_DISCARD = 스왑체인 방식
	D3DSWAPEFFECT_FLIP = 버퍼 하나를 뒤집으면서 사용하는 방식
	D3DSWAPEFFECT_COPY = 더블 버퍼링과 유사한 복사 방식*/

	//스왑 체인 : 페이지 플리핑 기법으로 이뤄져 있으며 전면 버퍼는 오로지 출력, 후면 버퍼는 지우고 다음 화면 출력할 것을 그리는 역할 분담으로 서로 가리키는 대상을 교체하여 깜빡거림 방지 및 화면 갱신을 수월하게 진행할 수 있다.

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;		// 스왑체인 방식
	d3dpp.hDeviceWindow = g_hWnd;

	//창 모드로 실행, 전체화면 실행
	d3dpp.Windowed = TRUE;		// TRUE인 경우 창 모드 설정

	// 타겟 버퍼(그리기 버퍼), 스텐실 버퍼(반사가 되는 물질 표현), 깊이 버퍼(깊이 값을 저장)
	// 자동으로 스텐실 버퍼와 깊이버퍼를 관리하겠다는 옵션
	d3dpp.EnableAutoDepthStencil = TRUE;
	//깊이 버퍼 24비트, 스텐실 버퍼 8비트
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

	// 전체화면 시에만 사용되는 매개 변수들
	// 창 모드에서는 운영체제가 재생률을 관리함
	// 전체화면 시에는 그래픽 카드가 개입하게 된다.

	// 전체화면 시 현재 모니터 재생률과의 관계(현재 모니터 재생율을 토대로 알아서 수행)
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;

	// 재생률과 시연 간격설정
	// D3DPRESENT_INTERVAL_IMMEDIATE  : 즉시 시연
	// D3DPRESENT_INTERVAL_DEFAULT : 적절한 간격을 장치가 알아서 결정(보통 모니터 재생율을 따라감)
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}
