#include <iostream>
#include <memory>

#include "config.h"
#include <core/factory/FactoryController.h>
#include <core/component/ComponentController.h>
#include "factory/CodesysFactory.h"

extern "C" void subscribePlugin()
{
    std::cout << "codesys - subscribePlugin" << std::endl;

    auto factoryController = std::make_shared< core::FactoryController >();

    std::shared_ptr< core::FactoryIf > codesysFactory = std::make_shared< CodesysFactory >();

    factoryController->subscribe( codesysFactory );

    std::cout << std::endl;
}

extern "C" void unsubscribePlugin()
{
    std::cout << "codesys - unsubscribePlugin" << std::endl;

    auto componentController = std::make_shared< core::ComponentController >();

    auto factoryController = std::make_shared< core::FactoryController >();

    auto codesysFactory = std::make_shared< CodesysFactory >();

    auto const type = codesysFactory->getType();

    // std::cout << "codesysComponents" << std::endl;
    // std::cout << "type " << type << std::endl;
    // auto codesysComponents = componentController->get( type );
    // std::cout << "codesysComponents2" << std::endl;

    // for (auto const& [name, component] : codesysComponents)
    // {
    //     std::cout << name << std::endl;
    //     codesysFactory->cleanup( name );
    // }

    componentController->erase( type );

    factoryController->unsubscribe( type );

    std::cout << "codesys - unsubscribePlugin finished" << std::endl;
}

extern "C" const char* getName()
{
    return PLUGIN_NAME.c_str();
}

extern "C" const char* getVersion()
{
    return PLUGIN_VERSION.c_str();
}
