#pragma once

#include "IWorker.h"
#include "IValidator.h"
#include <fstream>
#include <algorithm>

class DumpBlock: public IWorker, IValidator {
private:
    string filename;
    ofstream outputFile;
public:
    DumpBlock() = default;
    explicit DumpBlock(const string& filename) {
        this->filename = filename;
        outputFile.open(filename);
    };
    ~DumpBlock() override {
        outputFile.close();
    };
    shared_ptr<IWorker> initialize(pair<string, string>&& input) override{
        return make_shared<DumpBlock>(input.first);
    };
    void execute(conveyor& curStage) override;
    string isValid(const conveyor& curStage) override;
    void errorHandler(string&& messages) override;
};

class GrepBlock: public IWorker, IValidator {
private:
    string word;
public:
    GrepBlock() = default;
    explicit GrepBlock(const string& word) {
        this->word = word;
    };
    ~GrepBlock() override = default;
    shared_ptr<IWorker> initialize(pair<string, string>&& input) override{
        return make_shared<GrepBlock>(input.first);
    };
    void execute(conveyor& curStage) override;
    string isValid(const conveyor& curStage) override;
    void errorHandler(string&& messages) override;
};

class ReadFileBlock: public IWorker, IValidator {
private:
    string filename;
    ifstream inputFile;
public:
    ReadFileBlock() = default;
    explicit ReadFileBlock(const string& filename){
        this->filename = filename;
        inputFile.open(filename);
    };
    ~ReadFileBlock() override {
        inputFile.close();
    };
    shared_ptr<IWorker> initialize(pair<string, string>&& input) override{
        return make_shared<ReadFileBlock>(input.first);
    };
    string isValid(const conveyor& curStage) override;
    void errorHandler(string&& messages) override;
    void execute(conveyor& curStage) override;
};

class ReplaceBlock: public IWorker, IValidator {
private:
    string word1;
    string word2;
public:
    ReplaceBlock() = default;
    ReplaceBlock(const string& word1, const string& word2){
        this->word1 = word1;
        this->word2 = word2;
    };
    ~ReplaceBlock() override = default;
    shared_ptr<IWorker> initialize(pair<string, string>&& input) override{
        return make_shared<ReplaceBlock>(input.first, input.second);
    };
    void execute(conveyor& curStage) override;
    string isValid(const conveyor& curStage) override;
    void errorHandler(string&& messages) override;
};

class SortBlock: public IWorker, IValidator {
public:
    SortBlock() = default;
    ~SortBlock() override = default;
    shared_ptr<IWorker> initialize(pair<string, string>&& input) override{
        return make_shared<SortBlock>();
    };
    void execute(conveyor& curStage) override;
    string isValid(const conveyor& curStage) override;
    void errorHandler(string&& messages) override;
};

class WriteFileBlock: public IWorker, IValidator {
private:
    string filename;
    ofstream outputFile;
public:
    WriteFileBlock() = default;
    explicit WriteFileBlock(const string& filename) {
        this->filename = filename;
        outputFile.open(filename);
    };
    ~WriteFileBlock() override {
        outputFile.close();
    };
    shared_ptr<IWorker> initialize(pair<string, string>&& input) override{
        return make_shared<WriteFileBlock>(input.first);
    };
    void execute(conveyor& curStage) override;
    string isValid(const conveyor& curStage) override;
    void errorHandler(string&& messages) override;
};
