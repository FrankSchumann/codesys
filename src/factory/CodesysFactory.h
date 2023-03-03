#pragma once

#include <memory>
#include <string>

#include <core/component/ComponentControllerIf.h>
#include <core/component/ComponentIf.h>
#include <core/factory/FactoryIf.h>

class CodesysFactory : public core::FactoryIf
{
   public:
    CodesysFactory();
    CodesysFactory( std::shared_ptr< core::ComponentControllerIf > _componentController );

    virtual std::shared_ptr< core::ComponentIf > create( std::string const &name ) const override;
    virtual std::string getType() const override;
    virtual std::vector<std::string> getDependencies() const override;

    void cleanup( std::string const &name );

   private:
    const std::string type = std::string( "CodesysAdapter" );

    std::shared_ptr< core::ComponentControllerIf > componentController;
};
