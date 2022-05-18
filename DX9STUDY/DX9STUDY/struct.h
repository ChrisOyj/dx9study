#pragma once

typedef struct tag_Transform
{
	Vec3		vPos;
	Vec3		vScale;		// 크기 비율
	Vec3		vSize;
	Vec3		vRotate; // 이미지 돌릴 때 사용할 각도
	Vec3		vDir;
	Vec3		vLook;

	D3DXMATRIX	matWorld;

}TRANSFORM;

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

