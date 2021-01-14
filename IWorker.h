#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "IToolkit.h"

using namespace std;

class IWorker: protected IToolkit {
protected:
    virtual ~IWorker() = default;
public:
    virtual shared_ptr<IWorker> initialize(pair<string, string>&& input) = 0;
    virtual void execute(conveyor& curStage) = 0;
};
