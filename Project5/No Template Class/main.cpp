#include <iostream>
#include "JChannel.h"
using namespace std;
int main() {
    unsigned char uc[12] = {2,4,2,6,8,3,2,1,8,3,1,9};
    short st[12] = {2,4,2,6,8,3,2,1,8,3,1,9};
    int it[12] = {2,4,2,6,8,3,2,1,8,3,1,9};
    float ft[12] = {2,4,2,6,8,3,2,1,8,3,1,9};
    double de[12] = {2,4,2,6,8,3,2,1,8,3,1,9};
    JChannel test1 = JChannel(3, 4, de);
    JChannel test3 = JChannel(3, 4, it);
    char type1 = test1.getType();
    cout<<type1<<endl;
//    cout<<test1.getUCData(1,1)<<endl;
    cout<<test1.getDoubleData(1,1)<<endl;
    JChannel test2 = test1 + test3;

    return 0;
}
