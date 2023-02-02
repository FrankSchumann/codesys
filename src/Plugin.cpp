#include <iostream>
#include <memory>

#include "config.h"
#include <factory/FactoryController.h>
#include <component/ComponentController.h>
#include "factory/CodesysFactory.h"

extern "C" void subscribePlugin()
{
    std::cout << "codesys - subscribePlugin" << std::endl;

    std::shared_ptr< COPA::FactoryController > factoryController = std::make_shared< COPA::FactoryController >();

    std::shared_ptr< COPA::FactoryIf > codesysFactory = std::make_shared< CodesysFactory >();

    factoryController->subscribe( codesysFactory );

    std::cout << std::endl;
}

extern "C" void unsubscribePlugin()
{
    std::cout << "codesys - unsubscribePlugin" << std::endl;

    std::shared_ptr< COPA::ComponentController > componentController = std::make_shared< COPA::ComponentController >();

    std::shared_ptr< COPA::FactoryController > factoryController = std::make_shared< COPA::FactoryController >();

    std::shared_ptr< COPA::FactoryIf > codesysFactory = std::make_shared< CodesysFactory >();

    auto const type = codesysFactory->getType();
    componentController->erase( type );

    factoryController->unsubscribe( type );

    std::cout << std::endl;
}

extern "C" const char* getName()
{
    return PLUGIN_NAME.c_str();
}

extern "C" const char* getVersion()
{
    return PLUGIN_VERSION.c_str();
}
