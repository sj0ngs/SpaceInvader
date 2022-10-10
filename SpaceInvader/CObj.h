#pragma once

class CCollider;
class CTexture;

class CObj
{
private:
	Vec2 m_vPos;
	Vec2 m_vScale;

	bool m_bDead;

	ELAYER m_Layer;

	CTexture* m_pTexture;

private:
	CCollider* m_pCollider;

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	Vec2 GetPos() { return m_vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	Vec2 GetScale() { return m_vScale; }

	void SetLayer(ELAYER _Layer) { m_Layer = _Layer; }
	ELAYER GetLayer() { return m_Layer; }

	void CreateCollider();
	CCollider* GetCollider() { return m_pCollider; }

	void SetTexture(CTexture* _pTexture) { m_pTexture = _pTexture; }
	CTexture* GetTexture() { return m_pTexture; }

public:
	bool IsDead() { return m_bDead; }
	void SetDead();
	void Instantiate(CObj* _pNewObj, Vec2 _vPos, ELAYER _Layer);

public:
	CObj();
	virtual ~CObj();

	friend class CEventMgr;

public:
	virtual void Tick();
	virtual void Render(HDC _hDC);

public:
	virtual void BeginOverlap(CCollider* _pOther);
	virtual void OnOverlap(CCollider* _pOther);
	virtual void EndOverlap(CCollider* _pOther);
};

