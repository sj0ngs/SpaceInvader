#include "pch.h"
#include "CEffect.h"

#include "CTimeMgr.h"
#include "CResMgr.h"

#include "CTexture.h"

CEffect::CEffect()	:
	m_fLifeSpan(0.f)
{
	SetLayer(ELAYER::DEFAULT);
	SetTexture(CResMgr::GetInst()->LoadTexture(L"Explosion", L"texture\\explosion.bmp"));
}

CEffect::~CEffect()
{
}

void CEffect::Tick()
{
	if (0.2f <= m_fLifeSpan)
		SetDead();

	m_fLifeSpan += DELTA_TIME;
}

void CEffect::Render(HDC _hDC)
{
	Vec2 vPos = GetPos();

	Vec2 vLeftTop = Vec2(vPos.x - GetTexture()->GetWidth() / 2.f,
		vPos.y - GetTexture()->GetHeight() / 2.f);

	TransparentBlt(_hDC, (int)vLeftTop.x, (int)vLeftTop.y,
		(int)GetTexture()->GetWidth(), (int)GetTexture()->GetHeight(),
		GetTexture()->GetDC(), 0, 0,
		(int)GetTexture()->GetWidth(), (int)GetTexture()->GetHeight(),
		RGB(0, 0, 0));
}
