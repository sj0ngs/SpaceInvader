#pragma once

enum class EKEY : UINT8
{
	UP,
	DOWN,
	LEFT,
	RIGHT,

	SPACE,
	ENTER,
	ESC,
	LALT,
	LCTRL,
	LSHIFT,
	TAB,

	LBTN,
	RBTN,

	Q,
	W,
	E,
	R,

	END
};

enum class EKEY_STATE :	UINT8
{
	TAP,
	PRESSED,
	RELEASED,
	NONE
};

struct tKeyInfo
{
	EKEY Key;
	EKEY_STATE State;
	bool bPrev;
};

class CKeyMgr
{
	SINGLE(CKeyMgr);
private:
	vector<tKeyInfo> m_vecKey;

public:
	void Init();
	void Tick();

public:
	EKEY_STATE GetKeyState(EKEY _Key) { return m_vecKey[(UINT)_Key].State; }
};

