#pragma once



typedef struct tag_Transform
{
	float		fZ;		//가상의 z축
	float		fCZ;	//z축 크기..
	Vec3		vPos;
	Vec3		vScale;		// 크기 비율
	Vec3		vSize;
	Vec3		vRotate; // 이미지 돌릴 때 사용할 각도
	Vec3		vDir;
	Vec3		vLook;

	D3DXMATRIX	matWorld;

	tag_Transform()
	{
		ZeroMemory(this, sizeof(tag_Transform));
		vScale = { 1.f, 1.f, 1.f };
	}

	tag_Transform(TRANSFORMTYPE _type)
	{
		if (_type == TRANSFORMTYPE::TRANS_IDENTITY)
		{
			ZeroMemory(this, sizeof(tag_Transform));
			vScale = { 1.f, 1.f, 1.f };
		}
	}

	static D3DXMATRIX CalculateWorld(tag_Transform _Transform)
	{
		D3DXMATRIX matScale, matTrans;
		D3DXMATRIX matRot;
		D3DXQUATERNION QautRot;

		//짐벌락 방지
		D3DXQuaternionRotationYawPitchRoll(&QautRot, _Transform.vRotate.y, _Transform.vRotate.x, _Transform.vRotate.z);

		//-1, 0, 0 or 1, 0, 0
		//
		//월드매트릭스
		D3DXMatrixScaling(&matScale, _Transform.vScale.x, _Transform.vScale.y, _Transform.vScale.z);
		//D3DXMatrixRotationX(&matRotX, m_tTransform.vRotate.x);
		//D3DXMatrixRotationY(&matRotY, m_tTransform.vRotate.y);
		//D3DXMatrixRotationZ(&matRotZ, m_tTransform.vRotate.z);
		D3DXMatrixRotationQuaternion(&matRot, &QautRot);

		D3DXMatrixTranslation(&matTrans, _Transform.vPos.x, _Transform.vPos.y - _Transform.fZ, _Transform.vPos.z); // 좌표 하나씩 회전

		return matScale * matRot * matTrans;
	}

}TRANSFORM;

typedef struct tag_TileInfo
{
	tag_Transform	Transform;
	UINT	iIndex;
	UINT	iPrevIndex;	// 이전 타일의 인덱스 정보

	bool	bOpen;
	//인접 타일 인덱스
	vector<UINT>	vecAdjIdx;

	tag_TileInfo()
		: iIndex(0)
		, bOpen(true)
	{
	}

	~tag_TileInfo()
	{}

}TILE;


//얘는 존재가치가 있는가?
typedef struct tag_SceneObjInfo
{
	OBJ_TYPE	eType;
	TRANSFORM	tTransformInfo;
}SCENEOBJINFO;

typedef		struct tag_Texture
{
	LPDIRECT3DTEXTURE9	pTexture;	// 객체, 이미지와 관련된 각종 기능을 제공하는 클래스

	D3DXIMAGE_INFO		tImgInfo;	// 구조체, 이미지와 관련된 실제적인 데이터를 저장하는 구조체
	Vec3				vOffset;
}TEXINFO;


typedef		struct tag_Vertex
{
	float x, y, z;
	D3DCOLOR c;

	tag_Vertex(const float& _x = 0.f, const float& _y = 0.f, const float& _z = 0.f, const D3DCOLOR& _c = D3DCOLOR_RGBA(255,255,255,255))
	{
		x = _x;
		y = _y;
		z = _z;
		c = _c;
	}

}D3DVERTEX, Vertex;

//typedef		struct tag_Vertex
//{
//	float x, y, z;
//
//	tag_Vertex(const float& _x = 0.f, const float& _y = 0.f, const float& _z = 0.f)
//	{
//		x = _x;
//		y = _y;
//		z = _z;
//	}
//
//}D3DVERTEX, Vertex;


typedef		struct tag_vRect
{
	D3DVERTEX Vertex[4];

	tag_vRect()
	{
		ZeroMemory(Vertex, sizeof(Vertex) * 4);
	}

	tag_vRect(const Vec3& _Pos, const float& _X, const float& _Z, const D3DCOLOR& _C)
	{
		for (auto& elem : Vertex)
		{
			elem.x = _Pos.x;
			elem.y = _Pos.y;
			elem.z = _Pos.z;
			elem.c = _C;
		}

		Vertex[0].x -= _X;
		Vertex[0].z += _Z;

		Vertex[1].x += _X;
		Vertex[1].z += _Z;

		Vertex[2].x -= _X;
		Vertex[2].z -= _Z;

		Vertex[3].x += _X;
		Vertex[3].z -= _Z;




	}

}VRECT;
//
//typedef		struct tag_vBox
//{
//	D3DVERTEX Vertex[4];
//
//	tag_vBox()
//	{
//		ZeroMemory(Vertex, sizeof(Vertex) * 4);
//	}
//
//	tag_vBox(const Vec3& _Pos, const float& _X, const float& _Y, const float& _Z, const D3DCOLOR& _C)
//	{
//		for (auto& elem : Vertex)
//		{
//			elem.x = _Pos.x;
//			elem.y = _Pos.y;
//			elem.z = _Pos.z;
//			elem.rhw = 1.f;
//			elem.c = _C;
//		}
//
//		Vertex[0].x -= _X;
//		Vertex[0].y -= _Y;
//		Vertex[0].z -= _Z;
//
//		Vertex[1].x += _X;
//		Vertex[1].y -= _Y;
//
//		Vertex[2].x -= _X;
//		Vertex[2].y += _Y;
//
//		Vertex[3].x += _X;
//		Vertex[3].y += _Y;
//
//
//
//
//	}
//
//}VBOX;

typedef struct tag_SceneObjEnableInfo
{
}SCEN;


typedef struct tag_UnitStatus
{
	float		fMaxHP;
	float		fMaxMP;

	float		fCurHP;
	float		fCurMP;

	float		fRecoverHP;
	float		fRecoverMP;

	float		fAttack;
	float		fDefense;

	float		fCritical;
	float		fCriticalRate;

	float		fAttackSpeed;
	float		fCastingSpeed;
	float		fMoveSpeed;

	float		fHitRate;
	float		fAvoidanceRate;

	float		fMaxEXP;
	float		fCurEXP;
	int			iLevel;

	float		fResistance;

	int			iSkillPoint;

	int			iMoney;


	tag_UnitStatus() { ZeroMemory(this, sizeof(tag_UnitStatus)); }

public:
	void operator += (tag_UnitStatus _vOther)
	{
		fMaxHP += _vOther.fMaxHP;
		fMaxMP += _vOther.fMaxMP;

		fCurHP += _vOther.fCurHP;
		fCurMP += _vOther.fCurMP;

		fRecoverHP += _vOther.fRecoverHP;
		fRecoverMP += _vOther.fRecoverMP;

		fAttack += _vOther.fAttack;
		fDefense += _vOther.fDefense;

		fCritical += _vOther.fCritical;
		fCriticalRate += _vOther.fCriticalRate;

		fAttackSpeed += _vOther.fAttackSpeed;
		fCastingSpeed += _vOther.fCastingSpeed;
		fMoveSpeed += _vOther.fMoveSpeed;

		fHitRate += _vOther.fHitRate;
		fAvoidanceRate += _vOther.fAvoidanceRate;

		fMaxEXP += _vOther.fMaxEXP;
		fCurEXP += _vOther.fCurEXP;
		iLevel += _vOther.iLevel;

		fResistance += _vOther.fResistance;

		iSkillPoint += _vOther.iSkillPoint;

		iMoney += _vOther.iMoney; ;
	}

	tag_UnitStatus operator - ()
	{
		fMaxHP *= -1.f;
		fMaxMP *= -1.f;

		fCurHP *= -1.f;
		fCurMP *= -1.f;

		fRecoverHP *= -1.f;
		fRecoverMP *= -1.f;

		fAttack *= -1.f;
		fDefense *= -1.f;

		fCritical *= -1.f;
		fCriticalRate *= -1.f;

		fAttackSpeed *= -1.f;
		fCastingSpeed *= -1.f;
		fMoveSpeed *= -1.f;

		fHitRate *= -1.f;
		fAvoidanceRate *= -1.f;

		fMaxEXP *= -1.f;
		fCurEXP *= -1.f;
		iLevel *= -1;

		fResistance *= -1.f;

		iSkillPoint *= -1;

		iMoney *= -1;

		return *this;
	}

}UNITSTATUS;

