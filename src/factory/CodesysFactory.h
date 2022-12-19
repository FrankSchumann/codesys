#pragma once

#include <string>

#include "copa-pdk/factory/FactoryIf.h"

class CodesysFactory : public COPA::FactoryIf
{
   public:
	CodesysFactory();
    virtual ~CodesysFactory();

    virtual void create() override;
    virtual std::string getType() override;

   private:
    std::string type;
};
