#include "pch.h"
#include "CPlayerMissile.h"

#include "CEngine.h"

CPlayerMissile::CPlayerMissile()
{
}

CPlayerMissile::~CPlayerMissile()
{
}

void CPlayerMissile::Render(HDC _DC)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	HBRUSH hPrevBrush = (HBRUSH)SelectObject(_DC, CEngine::GetInst()->GetBrush(EBRUSH_TYPE::AQUA));

	Rectangle(_DC, (int)(vPos.x - vScale.x / 2),
		(int)(vPos.y - vScale.y / 2),
		(int)(vPos.x + vScale.x / 2),
		(int)(vPos.y + vScale.y / 2));

	SelectObject(_DC, hPrevBrush);

	CObj::Render(_DC);
}
