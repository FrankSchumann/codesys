#pragma once

#include <memory>
#include <string>

#include "component/ComponentControllerIf.h"
#include "component/ComponentIf.h"
#include "factory/FactoryIf.h"

class CodesysFactory : public COPA::FactoryIf
{
   public:
    CodesysFactory();
    CodesysFactory( std::shared_ptr< COPA::ComponentControllerIf > _componentController );

    virtual std::shared_ptr< COPA::ComponentIf > create( std::string const &name ) const override;
    virtual std::string getType() const override;
    virtual std::vector<std::string> getDependencies() const override;

   private:
    const std::string type = std::string( "CodesysAdapter" );

    std::shared_ptr< COPA::ComponentControllerIf > componentController;
};
