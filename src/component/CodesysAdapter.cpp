#include "CodesysAdapter.h"

CodesysAdapter::CodesysAdapter( std::string const &_type, std::string const &_name ) : type( _type ), name( _name )
{
}

CodesysAdapter::~CodesysAdapter()
{
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
