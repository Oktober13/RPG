#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Setup.h"

class CThings
{
public:
	CThings(CSetup* Passed_Setup, float *Passed_CamX, float *Passed_CamY);
	~CThings();

private:
	CSetup* csetup;
};

