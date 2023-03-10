#include "CodesysFactory.h"

#include <iostream>
#include <memory>

#include "../component/CodesysAdapter.h"
#include <copa/component/ComponentController.h>
#include <runtime/RuntimeControllerIf.h>

CodesysFactory::CodesysFactory() : CodesysFactory( std::make_shared< COPA::ComponentController >() )
{
}

CodesysFactory::CodesysFactory( std::shared_ptr< COPA::ComponentControllerIf > _componentController ) : componentController( _componentController )
{
}

std::shared_ptr< COPA::ComponentIf > CodesysFactory::create( std::string const &name ) const
{
    std::cout << "CodesysFactory::create" << std::endl;

    std::shared_ptr< RuntimeIf > codesysAdapter = std::make_shared< CodesysAdapter >( type, name );

    auto const runtimeControllerTmp = componentController->get( "RuntimeController", "Mickey Mouse" );
    auto const runtimeController = std::reinterpret_pointer_cast< RuntimeControllerIf >( runtimeControllerTmp );

    runtimeController->subscribe( name, codesysAdapter );

    return codesysAdapter;
}

std::string CodesysFactory::getType() const
{
    return type;
}

std::vector< std::string > CodesysFactory::getDependencies() const
{
    std::vector< std::string > result{ "RuntimeController" };

    return result;
}
