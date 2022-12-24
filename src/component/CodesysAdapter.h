#pragma once

#include <memory>

#include "copa-pdk/component/ComponentControllerIf.h"
#include "runtime-sdk/RuntimeAdapterIf.h"
#include "runtime-sdk/RuntimeIf.h"

class CodesysAdapter : public RuntimeIf
{
   public:
    CodesysAdapter( std::string const &_type, std::string const &_name );
    CodesysAdapter( std::string const &_type, std::string const &_name, std::shared_ptr< COPA::ComponentControllerIf > _componentController );
    ~CodesysAdapter();

    virtual void subscribe() override;
    virtual void startApplications() override;
    virtual void stopApplications() override;
    virtual std::string getRuntimeVersion() override;

    virtual std::string getType() override;
    virtual std::string getName() override;
    virtual std::string getVersion() override;

   private:
    std::string type;
    std::string name;

    std::shared_ptr< COPA::ComponentControllerIf > componentController;
};
