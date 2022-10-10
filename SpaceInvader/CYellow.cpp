#include "pch.h"
#include "CYellow.h"
#include "CTimeMgr.h"
#include "CResMgr.h"

#include "CCollider.h"
#include "CMissile.h"

#include "CTexture.h"

CYellow::CYellow()
{
	GetCollider()->SetScale(Vec2(40.f, 32.f));
	SetTexture(CResMgr::GetInst()->LoadTexture(L"YellowImage", L"texture\\yellow.bmp"));
}

CYellow::~CYellow()
{
}

void CYellow::Tick()
{
	CMonster::Tick();
}

void CYellow::Render(HDC _hDC)
{
	CMonster::Render(_hDC);
}
