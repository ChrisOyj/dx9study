#pragma once

enum class OBJ_TYPE
{
	DEFAULT = 0,
	PLAYER,
	PLAYER_ATTACK,
	MONSTER,
	MONSTER_ATTACK,
	SIGHT,
	RANGE,
	MOUSE,
	END

};

enum class MOB_TYPE
{
	GOBLIN = 0,
	END,
};

enum class ITEM_TYPE
{
	DIAMOND = 0,
	END,
};

enum class SKILL_TYPE
{
	UPPER_SLASH = 0,
	END,
};

//������Ʈ ����������
enum class COMPONENT_TYPE
{
	SCRIPTABLE = 0,
	CONDITION,

	PHYSICSINFO,
	PHYSICS,

	COLLIDER,
	TRANSFORM,
	GRAPHICS,
	ANIMATOR,
	END,
};

enum class LAYER
{
	FIRST = 0,
	END,
};

enum class STATE_TYPE // �� ������Ʈ�� �ش��ϴ� �̹����� ��� �־����
{
	IDLE = 0,
	WALK,
	RUN,
	ATTACK,
	JUMP,
	HIT,
	DOWN,
	DEATH,
	STANDING,
	SKILL,
	ETC,
	END
};

enum class BATTLE_STATE_TYPE
{
	DEFAULT = 0,
	SUPERARMOR,
	DOWN,
	HIT,
	AIRHIT,
	END
};

enum class CONDITION_TYPE
{
	BLEEDING = 0,
	ICED,
	POISONED,
	END
};


enum class COMMAND_TYPE
{
	IDLE = 0,
	RUN,
	ATTACK,
	JUMP,
	HIT,
	DOWN,
	DEATH,
	STANDING,
	END
};


enum class SCENE_TYPE
{
	MAINMENU = 0,
	DUNGEON,
	VILLAGE,
	END
};

enum class KEY
{
	LEFT = 0,
	RIGHT,
	UP,
	DOWN,
	NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9, NUM0,
	F1, F2, F3, F4,
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	ALT,
	LSHIFT,
	SPACE,
	CTRL,
	ENTER,
	ESC,
	TAB,
	LBUTTON,
	RBUTTON,
	BACKSPACE,
	DELETEKEY,
	LAST,
};


enum class CHANNELID
{
	BGM = 0,
	ENV_CH1,
	ENV_CH2,
	ENV_CH3,
	ENV_CH4,
	ENV_CH5,
	ENV_CH6,
	ENV_CH7,
	ENV_CH8,
	ENV_CH9,
	ENV_CH10,
	FX_CH1,
	FX_CH2,
	FX_CH3,
	FX_CH4,
	FX_CH5,
	FX_CH6,
	FX_CH7,
	FX_CH8,
	FX_CH9,
	FX_CH10,
	FX_CH11,
	FX_CH12,
	FX_CH13,
	FX_CH14,
	FX_CH15,
	FX_CH16,
	FX_CH17,
	FX_CH18,
	FX_CH19,
	FX_CH20,
	CH_END,
};

enum TEXTYPE { TEX_SINGLE, TEX_MULTI, TEX_END };

enum class TRANSFORMTYPE { TRANS_ZERO, TRANS_IDENTITY, TRANS_END};