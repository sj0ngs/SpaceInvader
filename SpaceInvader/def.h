#pragma once

#define SINGLE(type) public:\
						static type* GetInst()\
						{\
							static type Inst;\
							return &Inst;\
						}\
					private:\
						type();\
						~type();

#define DELTA_TIME CTimeMgr::GetInst()->GetDeltaTime()

#define	SAFE_DELETE(p) if(nullptr != p) delete p;

#define PI 3.14f

#define IS_TAP(key) CKeyMgr::GetInst()->GetKeyState(key) == EKEY_STATE::TAP
#define IS_PRESSED(key) CKeyMgr::GetInst()->GetKeyState(key) == EKEY_STATE::PRESSED
#define IS_RELEASED(key) CKeyMgr::GetInst()->GetKeyState(key) == EKEY_STATE::RELEASED

enum class ELEVEL_TYPE	:uint8_t
{
	STAGE_01,
	END
};

enum class ELAYER	:uint8_t
{
	DEFAULT,
	PLAYER,
	MONSTER,
	PLAYER_PROJECTILE,
	MONSTER_PROJECTILE,
	DESTROYABLE_OBJECT,
	WALL,

	END = 16
};

enum class EPEN_TYPE :uint8_t
{
	RED,
	GREEN,
	BLUE,
	HOLLOW,
	END
};

enum class EBRUSH_TYPE :uint8_t
{
	BLACK,
	YELLOW,
	AQUA,
	FIREBRICK,
	END
};

enum class EEVENT_TYPE	:uint8_t
{
	CREATE_OBJECT,	// wParam  : Object Address		lParam : Layer Type
	DELETE_OBJECT,	// wParam  : Object Address
	LEVEL_CHANGE	// wParam  : LEVEL_TYPE(Next Level Type)
};