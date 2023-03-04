#include "CodesysFactory.h"

#include <iostream>
#include <memory>

#include "../component/CodesysAdapter.h"
#include <core/component/ComponentController.h>
#include <runtime/RuntimeControllerIf.h>

CodesysFactory::CodesysFactory() : CodesysFactory( std::make_shared< core::ComponentController >() )
{
}

CodesysFactory::CodesysFactory( std::shared_ptr< core::ComponentControllerIf > _componentController ) : componentController( _componentController )
{
}

std::shared_ptr< core::ComponentIf > CodesysFactory::create( std::string const &name ) const
{
    std::cout << "CodesysFactory::create" << std::endl;

    std::shared_ptr< RuntimeIf > codesysAdapter = std::make_shared< CodesysAdapter >( name );

    auto const runtimeControllerTmp = componentController->get( "RuntimeController", "Mickey Mouse" );
    auto const runtimeController = std::reinterpret_pointer_cast< RuntimeControllerIf >( runtimeControllerTmp );

    runtimeController->subscribe( codesysAdapter );

    return codesysAdapter;
}

void CodesysFactory::cleanup( std::string const &name )
{
    std::cout << "CodesysFactory::delete" << std::endl;

    auto const runtimeControllerTmp = componentController->get( "RuntimeController", "Mickey Mouse" );
    auto const runtimeController = std::reinterpret_pointer_cast< RuntimeControllerIf >( runtimeControllerTmp );

    runtimeController->unsubscribe( name );
}

std::string CodesysFactory::getType() const
{
    return CodesysAdapter::type;
}

std::vector< std::string > CodesysFactory::getDependencies() const
{
    std::vector< std::string > result{ "RuntimeController" };

    return result;
}
