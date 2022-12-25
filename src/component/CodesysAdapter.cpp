#include "CodesysAdapter.h"

#include <iostream>

CodesysAdapter::CodesysAdapter( std::string const &_type, std::string const &_name )
{
}

CodesysAdapter::~CodesysAdapter()
{
}

void CodesysAdapter::startApplications() const
{
	std::cout << "CodesysAdapter::startApplications" << " type: " << type << " name: " << name << std::endl;
}

void CodesysAdapter::stopApplications() const
{
}

std::string CodesysAdapter::getRuntimeVersion() const
{
    return std::string( "3.5.18.0" );
}

std::string CodesysAdapter::getType() const
{
    return type;
}

std::string CodesysAdapter::getName() const
{
    return name;
}

std::string CodesysAdapter::getVersion() const
{
    return std::string( "0.0.0.1" );
}
