#include "Blocks.h"

string DumpBlock::isValid(const conveyor &curStage) {
    if (!curStage.haveInput){
        return "logic_error: Null input on Dump! Block index: " + to_string(curStage.idx);
    }
    if (!outputFile.good()){
        return "invalid_argument: Bad output file: " + filename;
    }
    return "";
}

void DumpBlock::errorHandler(string &&messages) {
    throw runtime_error(messages);
}

void DumpBlock::execute(conveyor &curStage) {
    string&& verdict = isValid(curStage);
    if(!verdict.empty()){
        errorHandler(move(verdict));
    }
    curStage.haveOutput = true;
    curStage.output = curStage.input;
    for (const auto& str: curStage.input){
        outputFile << str;
    }
}

string GrepBlock::isValid(const conveyor &curStage) {
    if(!curStage.haveInput){
        return "Null input on grep! Block index: " + to_string(curStage.idx);
    }
    return "";
}

void GrepBlock::errorHandler(string &&messages) {
    throw logic_error(messages);
}

void GrepBlock::execute(conveyor &curStage) { 
    string&& verdict = isValid(curStage);
    if(!verdict.empty()){
        errorHandler(move(verdict));
    }
    curStage.haveOutput = true;
    if (curStage.input.empty()){
        curStage.output = curStage.input;
        return;
    }
    curStage.output = vector<string>();
    for (const auto& str: curStage.input){
        if (str.find(word) != string::npos){
            curStage.output.push_back(str);
        }
    }
}

string ReadFileBlock::isValid(const conveyor &curStage) {
    if (curStage.haveInput){
        return "logic_error: We can't have input here! Block index: " + to_string(curStage.idx);
    }
    if (!inputFile.good()){
        return "invalid_argument: Bad input file " + filename;
    }
    return "";
}

void ReadFileBlock::errorHandler(string &&messages) {
    throw runtime_error(messages);
}

void ReadFileBlock::execute(conveyor &curStage) {
    string&& verdict = isValid(curStage);
    if(!verdict.empty()){
        errorHandler(move(verdict));
    }
    string nextLine;
    curStage.haveOutput = true;
    curStage.output = vector<string>();
    while (getline(inputFile, nextLine)){
        curStage.output.push_back(nextLine);
    }
}

string ReplaceBlock::isValid(const conveyor& curStage) {
    if (!curStage.haveInput){
        return "Null data input on text replace! Block index: " + to_string(curStage.idx);
    }
    return "";
}

void ReplaceBlock::errorHandler(string &&messages) {
    throw logic_error(messages);
}

void ReplaceBlock::execute(conveyor& curStage) {
    string&& verdict = isValid(curStage);
    if(!verdict.empty()){
        errorHandler(move(verdict));
    }
    curStage.haveOutput = true;
    curStage.output = curStage.input;
    if(curStage.input.empty()){
        return;
    }
    for (auto& curStr: curStage.output){
        size_t entry;
        while ((entry = curStr.find(word1)) != string::npos){
            curStr.replace(entry, word1.size(), word2);
        }
    }
}

string SortBlock::isValid(const conveyor &curStage) {
    if (!curStage.haveInput){
        return "Null input on sort! Block index: " + to_string(curStage.idx);
    }
    return "";
}

void SortBlock::errorHandler(string &&messages) {
    throw logic_error(messages);
}

void SortBlock::execute(conveyor& curStage) {
    string&& verdict = isValid(curStage);
    if(!verdict.empty()){
        errorHandler(move(verdict));
    }
    curStage.haveOutput = true;
    curStage.output = curStage.input;
    if (curStage.input.empty()) {
        return;
    }
    sort(curStage.input.begin(), curStage.input.end());
}

string WriteFileBlock::isValid(const conveyor &curStage) {
    if (!curStage.haveInput){
        return "logic_error: Null input on Dump! Block index: " + to_string(curStage.idx);
    }
    if (!outputFile.good()){
        return "invalid_argument: Bad output file: " + filename;
    }
    return "";
}

void WriteFileBlock::errorHandler(string &&messages) {
    throw runtime_error(messages);
}

void WriteFileBlock::execute(conveyor &curStage) {
    string&& verdict = isValid(curStage);
    if(!verdict.empty()){
        errorHandler(move(verdict));
    }
    curStage.haveOutput = false;
    for (const auto& str: curStage.input){
        outputFile << str;
    }
}
