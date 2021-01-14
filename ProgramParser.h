#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include "IValidator.h"
#include "IWorker.h"
#include "Blocks.h"
#include "Blueprint.h"

using namespace std;

class ProgramParser: Blueprint {
private:
    map<string, shared_ptr<IWorker>> blockMap = {{"readfile",  make_shared<ReadFileBlock>()},
                                                 {"writefile", make_shared<WriteFileBlock>()},
                                                 {"grep",      make_shared<GrepBlock>()},
                                                 {"sort",      make_shared<SortBlock>()},
                                                 {"replace",   make_shared<ReplaceBlock>()},
                                                 {"dump",      make_shared<DumpBlock>()}};
    shared_ptr<IWorker> parseBlock(ifstream& workflowFile);
    map<int, shared_ptr<IWorker>> parseBlockPart(ifstream& workflowFile);
public:
    ProgramParser() = default;
    ~ProgramParser() = default;
    blueprint parseProgram(const string& file, const string& inputFile, const string& outputFile);
};
