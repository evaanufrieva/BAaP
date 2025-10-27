#pragma once
#include <cstddef>
class InPlace{    
public:
    char* input;
    size_t lenArray;
    InPlace();
    ~InPlace();
    bool readInput();
    void inplaceWords();
    void printNewStr() const;
private:
    void reverce(int start, int end);
};