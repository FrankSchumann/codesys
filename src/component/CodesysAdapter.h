#pragma once

#include <memory>

#include "copa-pdk/osal/semaphore/SemaphoreFactory.h"
#include "runtime-sdk/RuntimeAdapterIf.h"
#include "runtime-sdk/RuntimeIf.h"

class CodesysAdapter : public RuntimeIf
{
   public:
    CodesysAdapter( std::string const &_type, std::string const &_name );
    CodesysAdapter( std::string const &_type, std::string const &_name, std::shared_ptr< COPA::SemaphoreFactoryIf > semaphoreFactory );
    ~CodesysAdapter();

    virtual void startApplications() const override;
    virtual void stopApplications() const override;
    virtual std::string getRuntimeVersion() const override;

    virtual std::string getType() const override;
    virtual std::string getName() const override;
    virtual std::string getVersion() const override;

   private:
    std::string type;
    std::string name;

    std::shared_ptr< COPA::SemaphoreIf > semaphore;
};
