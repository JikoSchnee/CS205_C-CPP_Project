#ifndef NOTEMPLATEJMATRIX_JCHANNEL_H
#define NOTEMPLATEJMATRIX_JCHANNEL_H

#include <cstdio>
#include "JChannel.h"

class JChannel {
private:
    size_t rows;
    size_t cols;
    size_t type;
    unsigned char *ucP;    //type1
    short *shortP;         //type2
    int *intP;             //type3
    float *floatP;         //type4
    double *doubleP;       //type5
public:
    //Constructor
    explicit JChannel(size_t ROW = 1, size_t COL = 1, unsigned char *dataP = nullptr);

    explicit JChannel(size_t ROW = 1, size_t COL = 1, short *dataP = nullptr);

    explicit JChannel(size_t ROW = 1, size_t COL = 1, int *dataP = nullptr);

    explicit JChannel(size_t ROW = 1, size_t COL = 1, float *dataP = nullptr);

    explicit JChannel(size_t ROW = 1, size_t COL = 1, double *dataP = nullptr);

    //Destructor
    ~JChannel();

    //Getter And Setter
    size_t getRow();

    size_t getCol();

    char getType();

    unsigned char getUCData(size_t row, size_t col);

    short getShortData(size_t row, size_t col);

    int getIntData(size_t row, size_t col);

    float getFloatData(size_t row, size_t col);

    double getDoubleData(size_t row, size_t col);

    void setData(size_t row, size_t col, unsigned char key);

    void setData(size_t row, size_t col, short key);

    void setData(size_t row, size_t col, int key);

    void setData(size_t row, size_t col, float key);

    void setData(size_t row, size_t col, double key);

    //Operator
    JChannel operator+(JChannel const &Mat) const;

    JChannel operator-(JChannel const &Mat) const;

    JChannel operator*(JChannel const &Mat) const;

    JChannel operator/(JChannel const &Mat) = delete;

    JChannel &operator=(JChannel const &Mat);

    bool operator==(JChannel const &Mat) const;

    JChannel operator+=(JChannel const &Mat) = delete;

    JChannel operator-=(JChannel const &Mat) = delete;
};

#endif //NOTEMPLATEJMATRIX_JCHANNEL_H
