#pragma once
#include "CLevel.h"

class CStage_01 :
    public CLevel
{
public:
    CStage_01();
    ~CStage_01();

public:
    virtual void Init() override;
};

