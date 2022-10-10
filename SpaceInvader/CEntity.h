#pragma once
class CEntity
{
private:
	static UINT g_iNextID;

private:
	wstring m_strName;	
	const UINT m_ID;

public:
	void SetName(const wstring& _Str) { m_strName = _Str; }
	const wstring& GetName() { return m_strName; }
	UINT GetID() { return m_ID; }

public:
	CEntity();
	CEntity(const CEntity& _Origin);
	~CEntity();
};

