#include <iostream>
#include "JChannel2.h"

using namespace std;
int main() {

    static int int_Data[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    JChannel2<int> int_Matrix = JChannel2<int>(3, 4, int_Data);
    cout<<int_Matrix<<endl;

    static int int_Data2[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    JChannel2<int> int_Matrix2 = int_Matrix;
    cout<<int_Matrix<<endl;

    static float float_data[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    JChannel2<float> float_Matrix = JChannel2<float>(4, 3, float_data);
    cout<<float_Matrix<<endl;

    cout<<int_Matrix.get(2,3);
    JChannel2<int> result = int_Matrix + int_Matrix;
    cout<<result<< endl;
    cout<<result.get(1,1)<<" "<<int_Matrix.get(1,1)<<endl;
//    std::cerr << "Type Error: Matrix + Matrix" << std::endl;
//    std::cerr << "            ^" <<"        ^" <<std::endl;
    cout<<"end";
    return 0;
}

