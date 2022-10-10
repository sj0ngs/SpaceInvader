#pragma once
#include "CRes.h"
class CTexture :
    public CRes
{
private:
    HBITMAP m_hBit;
    HDC m_hDC;

    BITMAP m_tBitMapInfo;

public:
    UINT GetWidth() { return m_tBitMapInfo.bmWidth; }
    UINT GetHeight() { return m_tBitMapInfo.bmHeight; }

    HDC GetDC() { return m_hDC; }
public:
    CTexture();
    ~CTexture();

private:
    virtual int Load(const wstring& _strFilePath) override;
};

