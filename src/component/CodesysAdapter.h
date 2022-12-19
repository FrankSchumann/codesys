#pragma once

#include "runtime-sdk/RuntimeIf.h"

class CodesysAdapter : public RuntimeIf
{
	CodesysAdapter();
	~CodesysAdapter();

    virtual void startApplications() override;
    virtual void stopApplications() override;
    virtual std::string getVerison() override;
};
