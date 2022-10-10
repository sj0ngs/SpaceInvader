#pragma once
#include "CObj.h"

class CWall :
    public CObj
{
private:

public:
    CWall();
    ~CWall();

public:
    virtual void Tick() override;
    virtual void Render(HDC _hDC)   override;
};

