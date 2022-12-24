#include "CodesysAdapter.h"

#include "copa-pdk/component/ComponentController.h"

CodesysAdapter::CodesysAdapter( std::string const &_type, std::string const &_name )
    : CodesysAdapter( _type, _name, std::make_shared< COPA::ComponentController >() )
{
}

CodesysAdapter::CodesysAdapter( std::string const &_type, std::string const &_name, std::shared_ptr< COPA::ComponentControllerIf > _componentController )
    : type( _type ), name( _name ), componentController( _componentController )
{
}

CodesysAdapter::~CodesysAdapter()
{
}


void CodesysAdapter::subscribe()
{
    auto const runtimeAdapterTmp = componentController->get( "RuntimeAdapter", "Mickey Mouse" );
    auto const selfCodesysAdapterTmp = componentController->get( "CodesysAdapter", "Goofy" );

    auto const runtimeAdapter = std::reinterpret_pointer_cast< RuntimeAdapterIf >( runtimeAdapterTmp );
    auto const myself = std::reinterpret_pointer_cast< RuntimeIf >( selfCodesysAdapterTmp );

    runtimeAdapter->subscribe(name, myself);
}

void CodesysAdapter::startApplications()
{
}

void CodesysAdapter::stopApplications()
{
}

std::string CodesysAdapter::getRuntimeVersion()
{
    return std::string( "3.5.18.0" );
}

std::string CodesysAdapter::getType()
{
    return type;
}

std::string CodesysAdapter::getName()
{
    return name;
}

std::string CodesysAdapter::getVersion()
{
    return std::string( "0.0.0.1" );
}
