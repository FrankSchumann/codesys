#pragma once

#include "runtime-sdk/RuntimeIf.h"

class CodesysAdapter : public RuntimeIf
{
   public:
    CodesysAdapter( std::string const &_type, std::string const &_name );
    ~CodesysAdapter();

    virtual std::string getType() override;
    virtual std::string getName() override;
    virtual std::string getVersion() override;

    virtual void startApplications() override;
    virtual void stopApplications() override;
    virtual std::string getRuntimeVersion() override;

   private:
    std::string type;
    std::string name;
};
