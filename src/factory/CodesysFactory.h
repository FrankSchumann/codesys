#pragma once

#include <string>

#include "copa-pdk/factory/FactoryIf.h"
#include "copa-pdk/component/ComponentIf.h"

class CodesysFactory : public COPA::FactoryIf
{
   public:
	CodesysFactory();
    virtual ~CodesysFactory();

    virtual std::shared_ptr< COPA::ComponentIf > create( std::string const &name ) override;
    virtual std::string getType() override;

   private:
    std::string type;
};
