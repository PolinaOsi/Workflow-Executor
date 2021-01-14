#include <iostream>
#include <memory>
#include <fstream>
#include "ProgramParser.h"
#include "ProgramExecutor.h"

using namespace std;

inline void checkInput(int argc, char** argv, string& inputFile, string& outputFile){
    bool haveInputFile = false;
    bool haveOutputFile = false;
    for (int i = 2; i < argc; ++i) {
        if ((string)argv[i] == "-i" && i != argc && !haveInputFile) {
            haveInputFile = true;
            inputFile = argv[++i];
        } else if ((string)argv[i] == "-o" && i != argc && !haveOutputFile) {
            haveOutputFile = true;
            outputFile = argv[++i];
        } else {
            throw std::invalid_argument("Wrong console input!");
        }
    }
    if (haveInputFile && inputFile.empty() || haveOutputFile && outputFile.empty()){
        throw std::invalid_argument("Wrong console input!");
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        throw std::invalid_argument("Wrong console haveInput! not enough!");
    }
    string workflowFile = argv[1];
    string inputFile, outputFile;
    if (argc > 2){
        checkInput(argc, argv, inputFile, outputFile);
    }

    ProgramExecutor().executeWorkflow(ProgramParser().parseProgram(workflowFile, inputFile, outputFile));
}
