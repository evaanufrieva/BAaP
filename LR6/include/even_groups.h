#pragma once
#include <cstddef>
class BinaryGroups{    
public:
    char* input;
    size_t length;
    char** groups;
    int count;
    BinaryGroups();
    ~BinaryGroups();
    bool setInput(const char* str);
    bool readInput();
    void findEvenGroups();
    void printGroups() const;

};