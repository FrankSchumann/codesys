#include <iostream>
#include <memory>

#include "copa-pdk/factory/FactoryController.h"
#include "config.h"
#include "factory/CodesysFactory.h"

extern "C" void subscribePlugin()
{
    std::cout << "Codesys - subscribePlugin" << std::endl;

    std::shared_ptr< COPA::FactoryController > factoryController = std::make_shared< COPA::FactoryController >();

    std::shared_ptr< COPA::FactoryIf > codesysFactory = std::make_shared< CodesysFactory >();

    factoryController->subscribe( codesysFactory );

}

extern "C" const char* getName()
{
	return PLUGIN_NAME.c_str();
}

extern "C" const char* getVersion()
{
	return PLUGIN_VERSION.c_str();
}
