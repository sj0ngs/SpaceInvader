#include "pch.h"
#include "CObj.h"

#include "CEventMgr.h"

#include "CCollider.h"

void CObj::CreateCollider()
{
	m_pCollider = new CCollider(this);
}

void CObj::SetDead()
{
	tEvent evn = {};
	evn.eType = EEVENT_TYPE::DELETE_OBJECT;
	evn.wParam = (DWORD_PTR)this;
	CEventMgr::GetInst()->AddEvent(evn);
}

void CObj::Instantiate(CObj* _pNewObj, Vec2 _vPos, ELAYER _Layer)
{
	_pNewObj->SetPos(_vPos);

	tEvent _evn = {};
	_evn.eType = EEVENT_TYPE::CREATE_OBJECT;
	_evn.wParam = (DWORD_PTR)_pNewObj;
	_evn.lParam = (DWORD_PTR)_Layer;
	CEventMgr::GetInst()->AddEvent(_evn);
}

CObj::CObj()	:
	m_vPos{},
	m_vScale{},
	m_pCollider(nullptr),
	m_bDead(false),
	m_Layer(ELAYER::DEFAULT),
	m_pTexture(nullptr)
{
}

CObj::~CObj()
{
	SAFE_DELETE(m_pCollider);
}

void CObj::Tick()
{
	m_pCollider->Tick();
}

void CObj::Render(HDC _hDC)
{
	m_pCollider->Render(_hDC);
}

void CObj::BeginOverlap(CCollider* _pOther)
{
}

void CObj::OnOverlap(CCollider* _pOther)
{
}

void CObj::EndOverlap(CCollider* _pOther)
{
}
