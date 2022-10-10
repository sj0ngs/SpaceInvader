#pragma once

class CCollider;

union CollisionID
{
	struct
	{
		UINT LeftID;
		UINT RightID;
	};

	UINT_PTR ID;
};

class CCollisionMgr
{
	SINGLE(CCollisionMgr);
private:
	WORD m_Matrix[(UINT)ELAYER::END];

	map<UINT_PTR, bool> m_mapPrevInfo;

public:
	void Tick();

public:
	void LayerCheck(ELAYER _Left, ELAYER _Right);
	void Clear();
	
private:
	void CollisionBtwLayer(ELAYER _Left, ELAYER _Right);
	bool CollisionBtwCollider(CCollider* _pLeft, CCollider* _pRight);
};

