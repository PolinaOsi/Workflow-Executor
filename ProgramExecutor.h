#pragma once

#include "IWorker.h"
#include "Blueprint.h"
#include <map>
#include <memory>
#include <list>
//#include <vector>
//#include <string>


class ProgramExecutor: Blueprint, IToolkit {
public:
    ProgramExecutor() = default;
    ~ProgramExecutor() = default;
    void executeWorkflow(blueprint&& workflow);
};
