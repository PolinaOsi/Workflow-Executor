#pragma once

#include "IToolkit.h"
#include <string>

class IValidator: protected IToolkit {
protected:
    virtual ~IValidator() = default;
public:
    virtual std::string isValid(const conveyor& curStage) = 0;
    virtual void errorHandler(std::string&& messages) = 0;
};
