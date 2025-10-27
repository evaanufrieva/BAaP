#pragma once
#include <cstddef>
class SubStr{    
public:
    char* input;
    char* substr;
    char symbol;
    size_t textLength;
    size_t substringLength;
    SubStr();
    ~SubStr();
    bool readInput();
    void placeSubStr();
    void printNewStr() const;

};