#include "CodesysAdapter.h"

#include <iostream>

CodesysAdapter::CodesysAdapter( std::string const &_type, std::string const &_name )
{
}

CodesysAdapter::~CodesysAdapter()
{
}

void CodesysAdapter::startApplications()
{
	std::cout << "CodesysAdapter::startApplications" << " type: " << type << " name: " << name << std::endl;
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
