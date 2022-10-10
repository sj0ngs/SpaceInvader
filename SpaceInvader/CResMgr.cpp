#include "pch.h"
#include "CResMgr.h"

#include "CPathMgr.h"

#include "CTexture.h"

CResMgr::CResMgr()
{
}

CResMgr::~CResMgr()
{
	map<wstring, CTexture*>::iterator iter, iterEnd = m_mapTex.end();
	for (iter = m_mapTex.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(iter->second);
	}
}

void CResMgr::Init()
{
}

CTexture* CResMgr::FindTexture(const wstring& _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);

	if (iter == m_mapTex.end())
		return nullptr;

	return iter->second;
}

CTexture* CResMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	CRes* pTexture = FindTexture(_strKey);

	if (nullptr != pTexture)
		return (CTexture*)pTexture;

	wstring strFilePath = CPathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;

	pTexture = new CTexture;
	pTexture->Load(strFilePath);
	pTexture->SetKey(_strKey);
	pTexture->SetRelativePath(_strRelativePath);

	m_mapTex.insert(make_pair(_strKey, (CTexture*)pTexture));

	return (CTexture*)pTexture;
}
