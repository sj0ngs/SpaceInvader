#pragma once

#include "CObj.h"
class CEffect :
    public CObj
{
private:
    float m_fLifeSpan;
public:
    CEffect();
    ~CEffect();

public:
    virtual void Tick() override;
    virtual void Render(HDC _hDC)   override;
};

