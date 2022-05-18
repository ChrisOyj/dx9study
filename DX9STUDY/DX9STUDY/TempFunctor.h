#pragma once

static D3DXVECTOR3	Get_MousePos(void)
{
	POINT pt{};

	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	return D3DXVECTOR3(float(pt.x), float(pt.y), 0.f);
}

static void ErrorMessage(const TCHAR* _strMessage)
{
#ifdef _DEBUG
	MessageBoxW(nullptr, _strMessage, L"error", MB_OK);
#endif
}

template <typename T>
void Safe_Delete(T& type)
{
	if (type)
	{
		delete type;
		type = nullptr;
	}
}

template <typename T>
void Safe_Delete_Array(T& type)
{
	for (int i = 0; i < sizeof(type) / sizeof(T); ++i)
		Safe_Delete(type[i]);
}

template<typename T>
inline void Safe_Delete_Vec(vector<T>& _vec)
{
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		if (nullptr != _vec[i])
			delete _vec[i];
	}
	_vec.clear();
}

template<typename T1, typename T2>
inline void Safe_Delete_Map(map<T1, T2>& _map)
{
	typename map<T1, T2>::iterator iter = _map.begin(); // 이넘클래스 쓰려면 앞에 타입네임 붙이래

	for (; iter != _map.end(); ++iter)
	{
		delete iter->second;
		iter->second = nullptr;
	}

	_map.clear();
}

class CTagFinder
{
public:
	CTagFinder(const wchar_t* pTag) : m_pTag(pTag) {}

	template <typename T>
	bool operator () (T Pair)
	{
		return !lstrcmp(Pair.first, m_pTag);
	}

private:
	const wchar_t* m_pTag = nullptr;

};

template<typename T>
unsigned long Safe_Release(T& Temp)
{
	unsigned long dwRefCnt = 0;

	if (Temp)
	{
		dwRefCnt = Temp->Release();
		Temp = nullptr;
	}

	return dwRefCnt;
}