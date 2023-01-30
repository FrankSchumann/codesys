#include "CodesysAdapter.h"

#include <iostream>

CodesysAdapter::CodesysAdapter( std::string const &_type, std::string const &_name )
    : CodesysAdapter( _type, _name, std::make_shared< osal::SemaphoreFactory >() )
{
}

CodesysAdapter::CodesysAdapter( std::string const &_type, std::string const &_name, std::shared_ptr< osal::SemaphoreFactoryIf > semaphoreFactory )
    : type( _type ), name( _name )
{
    semaphore = semaphoreFactory->create();
}

void CodesysAdapter::startApplications() const
{
    std::cout << "CodesysAdapter::startApplications"
              << " type: " << type << " name: " << name << std::endl;
    semaphore->acquire();
}

void CodesysAdapter::stopApplications() const
{
    std::cout << "CodesysAdapter::stopApplications"
              << " type: " << type << " name: " << name << std::endl;
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
