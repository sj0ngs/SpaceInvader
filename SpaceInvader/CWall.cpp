#include "pch.h"
#include "CWall.h"

#include "CCollider.h"
	
CWall::CWall()
{
	SetLayer(ELAYER::WALL);

	CreateCollider();
	GetCollider()->SetOffset(Vec2(0.f, 0.f));
}

CWall::~CWall()
{
}

void CWall::Tick()
{
	CObj::Tick();
}

void CWall::Render(HDC _hDC)
{
	CObj::Render(_hDC);
}
