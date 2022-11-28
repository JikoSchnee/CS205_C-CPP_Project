#include <algorithm>
#include "cmath"
#include "Operator.h"
#include "divide_internet.h"

struct number plu(number n1,number n2){
    if (n1.zf == n2.zf){
        int pLoc = n1.pLoc>=n2.pLoc?n1.pLoc:n2.pLoc;
        int cha = abs(n1.pLoc - n2.pLoc);
        number longer = n1.pLoc>=n2.pLoc?n1:n2;
        number shorter = n1.pLoc<n2.pLoc?n1:n2;
        number result;
        result.pLoc = pLoc;
        result.len = pLoc+((n1.len-n1.pLoc)>=(n2.len-n2.pLoc)?(n1.len-n1.pLoc):(n2.len-n2.pLoc));
        result.zf = n1.zf;
        int index_l = 0;
        int index_s = 0;
        for (int i = 0; i < result.len; ++i) {
            if(i<cha){
                result.num[i] = longer.num[index_l++];
            } else{
                result.num[i] = result.num[i]+longer.num[index_l++]+shorter.num[index_s++];
                if(result.num[i]>=10){
                    if(i == result.len-1){
                        result.len++;
                    }
                    result.num[i+1]+=1;
                    result.num[i]-=10;
                }
            }
        }
        return result;
    } else{ //异号转为减法
        if (n1.zf == 1){
            n2.zf = 1;
            return sub(n1,n2);
        } else{
            n1.zf = 1;
            return sub(n2,n1);
        }
    }
}
struct number sub(number n1,number n2){
    if(n1.zf!=n2.zf){//异号转为加法
        if(n1.zf == 1){//正的减负的
            number new2;
            new2 = n2;
            new2.zf = 1;
            return plu(n1,new2);
        }else{//负的减正的
            number new2;
            new2 = n2;
            new2.zf = -1;
            return plu(n1,new2);
        }
    }else{
        number big;
        number small;
        number result;
        if(compareNoZf(n1,n2)==1){           //num n1>n2
            big = n1;
            small = n2;
            result.zf = n1.zf;
        }else if(compareNoZf(n1,n2)==-1){    //num n1<n2
            big = n2;
            small = n1;
            result.zf = -n1.zf;
        }else{                               //num n1=n2
            result.pLoc = -1;
            result.zf = 1;
            result.len = 1;
            return result;
        }
        int cha = big.len - small.len;
        result.len = max(integerBit(n1), integerBit(n2))+max(decimalBit(n1), decimalBit(n2));
        for (int i = result.len-1,j = big.len-1,k = small.len-1,c = 1; i >=0 ; i--) {
            if (c<cha){
                result.num[i] = big.num[j];
                c++;
            }else{
                if (j>=0&&k>=0){
                    result.num[i] = big.num[j--] - small.num[k--];
                }else if (j<0){
                    result.num[i] = result.num[i] - small.num[k--];
                } else if (k<0){
                    result.num[i] = result.num[i] + big.num[j--];
                }
            }
        }
        for (int i = 0; i < result.len; ++i) {
            if (result.num[i]<0){
                result.num[i]+=10;
                result.num[i+1]-=1;
            }
        }
        result.pLoc = max(n1.pLoc,n2.pLoc);
        return cutZero(result);
    }
}
struct number mul(number n1,number n2){
    number result;
    result.len = n1.len+n2.len;
    result.pLoc = n1.pLoc+n2.pLoc+1;
    if (n1.zf == n2.zf){
        result.zf = 1;
    }else{
        result.zf = -1;
    }
    for (int i = 0; i < n1.len; ++i) {
        for (int j = 0; j < n2.len; ++j) {
            result.num[i+j]+=n1.num[i]*n2.num[j];
        }
    }
    int tem = 0;
    for (int i = 0; i < result.len; ++i) {
        result.num[i]+=tem;
        tem = result.num[i]/10;
        result.num[i] = result.num[i]%10;
    }
    return cutZero(result);
}
struct number div(number n1,number n2){
    bn o1,o2;
    int di = 8;
    if (integerBit(n1)< integerBit(n2)){
        di+= integerBit(n2)- integerBit(n1);
    }
    n1 = mul(n1, tenTimes(di));
    o1.len = n1.len;
    o2.len = n2.len;
    for (int i = 0; i < o1.len; ++i) {
        o1.data[i] = n1.num[i];
    }
    for (int i = 0; i < o2.len; ++i) {
        o2.data[i] = n2.num[i];
    }
    bn oResult = bigDivide(o1,o2);
    number result;
    result.len = n1.len;
    result.pLoc = n1.pLoc-n2.pLoc-1;
    if (n1.zf==n2.zf){
        result.zf = 1;
    } else {
        result.zf = -1;
    }
    for (int i = 0,j = 0; j<oResult.len; ++i,++j) {
        result.num[i] = oResult.data[j];
    }
    result.pLoc+=di;
    return cutZero(result);
}
//struct number div(number n1,number n2){
//    number result;
//    int setting = 10000;
//    if (n1.zf == n2.zf){
//        result.zf = 1;
//    }else{
//        result.zf = -1;
//    }
//    for (int i = n1.len,j = setting; i >= 0; i--) {
//        result.num[j--] = n1.num[i];
//    }
//    result.len = setting;
//    result.pLoc = n1.pLoc+(setting-n1.len);
//    int cha = n1.len - n2.len;
//    int counter = 0;
//    number tem = n2;
//    for (int i = cha; i > 0; i--) {
//
//    }
//    return cutZero(result);
//}
struct number exp(number n1,int times){
    number result;
    if (times%2==0){
        result.zf = 1;
    } else {
        result.zf = n1.zf;
    }
    if (times == 0){
        result.len = 1;
        return result;
    }else if (times>0){
        result = n1;
        while (times>1){
            result = mul(result,n1);
            times--;
        }
        return cutZero(result);
    } else{
        result = n1;
        while (times<-1){
            result= mul(result,n1);
            times++;
        }
        number one;
        one.num[0] = 1;
        one.zf = 1;
        one.len = 1;
        return cutZero(div(one,result));
    }
}
struct number tenTimes(int times){
    if (times == 0){
        number zero;
        zero.len=1;
        zero.zf=1;
        return zero;
    } else if (times>0){
        number result;
        result.len = times+1;
        result.num[result.len-1] = 1;
        result.zf = 1;
        return result;
    } else {
        number ten = tenTimes(1);
        number result = exp(ten,times);
        return result;
    }
}