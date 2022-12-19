#include "CodesysFactory.h"

CodesysFactory::CodesysFactory() : type( "CODESYS" )
{
}

CodesysFactory::~CodesysFactory()
{
}

void CodesysFactory::create()
{
}

std::string CodesysFactory::getType()
{
    return type;
}
