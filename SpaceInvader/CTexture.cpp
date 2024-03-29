#include "pch.h"
#include "CTexture.h"

#include "CEngine.h"

CTexture::CTexture() :
	m_hBit(nullptr),
	m_hDC(nullptr),
	m_tBitMapInfo{}
{
}

CTexture::~CTexture()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hBit);
}

int CTexture::Load(const wstring& _strFilePath)
{
	// Bitmap 로딩
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(m_hBit, sizeof(BITMAP), &m_tBitMapInfo);

	// Bitmap 과 연결 시킬 DC 생성
	m_hDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
	HBITMAP hPrevBitmap = (HBITMAP)SelectObject(m_hDC, m_hBit);
	DeleteObject(hPrevBitmap);

	return S_OK;
}
