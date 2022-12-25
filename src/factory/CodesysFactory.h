#pragma once

#include <memory>
#include <string>

#include "copa-pdk/component/ComponentControllerIf.h"
#include "copa-pdk/component/ComponentIf.h"
#include "copa-pdk/factory/FactoryIf.h"

class CodesysFactory : public COPA::FactoryIf
{
   public:
    CodesysFactory();
    CodesysFactory( std::shared_ptr< COPA::ComponentControllerIf > _componentController );
    virtual ~CodesysFactory();

    virtual std::shared_ptr< COPA::ComponentIf > create( std::string const &name ) override;
    virtual std::string getType() override;

   private:
    std::string type;
    std::shared_ptr< COPA::ComponentControllerIf > componentController;
};
