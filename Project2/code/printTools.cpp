#include <iostream>
#include <cstdio>
#include "printTools.h"

using namespace std;

void printInfo(number s){
    printf("zf:%d pLoc:%d len:%d",s.zf,s.pLoc,s.len);
    cout<<endl;
    for (int i = 0; i < s.len; ++i) {
        cout<<s.num[i];
    }
    cout<<" ";
    printNumber(s);
    cout<<endl;
}
void printNumber(number s){
    if (s.zf == -1){
        cout<<"-";
    }
    for (int i = s.len-1; i >= 0; i--) {
        if (i == s.pLoc){
            cout<<".";
        }
        cout<<s.num[i];
    }
    return;
}