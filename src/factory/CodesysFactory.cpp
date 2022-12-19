#include "CodesysFactory.h"

#include <iostream>
#include <memory>

#include "../component/CodesysAdapter.h"

CodesysFactory::CodesysFactory() : type( "CodesysAdapter" )
{
}

CodesysFactory::~CodesysFactory()
{
}

std::shared_ptr< COPA::ComponentIf > CodesysFactory::create( std::string const &name )
{
    std::cout << "CodesysFactory::create" << std::endl;

    return std::make_shared< CodesysAdapter >( type, name );
}

std::string CodesysFactory::getType()
{
    return type;
}
