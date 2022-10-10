#pragma once

class CObj;

class CLevel
{
private:
	vector<CObj*> m_arrLayer[(UINT)ELAYER::END];
	
public:
	CLevel();
	virtual ~CLevel();

public:
	virtual void Init() = 0;
	virtual void Tick();
	virtual void Render(HDC _hDC);

public:
	void AddObject(CObj* _Obj, ELAYER _Layer)
	{
		m_arrLayer[(UINT)_Layer].push_back(_Obj);
	}

	const vector<CObj*>& GetLayer(ELAYER _Layer)
	{
		return m_arrLayer[(UINT)_Layer];
	}
};

