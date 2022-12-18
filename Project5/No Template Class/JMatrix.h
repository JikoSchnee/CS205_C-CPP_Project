#ifndef NOTEMPLATEJMATRIX_JMATRIX_H
#define NOTEMPLATEJMATRIX_JMATRIX_H


#include <cstdio>
#include <iostream>
#include "JChannel.h"

class JMatrix {
private:
    size_t rows;
    size_t cols;
    size_t chans;
    size_t type;
    JChannel * channels[4] = {nullptr, nullptr, nullptr, nullptr};
public:
    JMatrix(size_t row = 1,size_t col = 1,size_t channel = 1,size_t type = 5){
        rows = row;
        cols = col;
        chans = channel;
        this->type = type;
    }
    void setChannel(size_t num, JChannel * channel){
        if(num > chans||num < 1){
            std::cerr << "Error: Setting channel out of index." << std::endl;
            return;
        }
        if(rows!=channel->getRow()||cols!=channel->getCol()){
            std::cerr << "Error: Setting channel whose rows of columns are not match." << std::endl;
            return;
        }
        if(type!=channel->getType()){
            std::cerr << "Error: Setting channel whose type is not match." << std::endl;
            return;
        }
        channels[num-1] = channel;
    }
    unsigned char getUCData(size_t channel, size_t row,size_t col);
    short getShortData(size_t channel, size_t row,size_t col);
    int getIntData(size_t channel, size_t row,size_t col);
    float getFloatData(size_t channel, size_t row,size_t col);
    double getDoubleData(size_t channel, size_t row,size_t col);
    void setData(size_t channel, size_t row, size_t col, unsigned char value);
    void setData(size_t channel, size_t row, size_t col, short value);
    void setData(size_t channel, size_t row, size_t col, int value);
    void setData(size_t channel, size_t row, size_t col, float value);
    void setData(size_t channel, size_t row, size_t col, double value);
};


#endif //NOTEMPLATEJMATRIX_JMATRIX_H
