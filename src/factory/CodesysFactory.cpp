#include "CodesysFactory.h"

#include <iostream>
#include <memory>

#include "../component/CodesysAdapter.h"
#include "copa-pdk/component/ComponentController.h"

CodesysFactory::CodesysFactory() : CodesysFactory( std::make_shared< COPA::ComponentController >() )
{
}

CodesysFactory::CodesysFactory( std::shared_ptr< COPA::ComponentControllerIf > _componentController )
    : type( "CodesysAdapter" ), componentController( _componentController )
{
}

CodesysFactory::~CodesysFactory()
{
}

std::shared_ptr< COPA::ComponentIf > CodesysFactory::create( std::string const &name ) const
{
    std::cout << "CodesysFactory::create" << std::endl;

    std::shared_ptr< RuntimeIf > codesysAdapter = std::make_shared< CodesysAdapter >( type, name );

    auto const runtimeAdapterTmp = componentController->get( "RuntimeAdapter", "Mickey Mouse" );
    auto const runtimeAdapter = std::reinterpret_pointer_cast< RuntimeAdapterIf >( runtimeAdapterTmp );

    runtimeAdapter->subscribe( name, codesysAdapter );

    return codesysAdapter;
}

std::string CodesysFactory::getType() const
{
    return type;
}
