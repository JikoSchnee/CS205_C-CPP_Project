#include <iostream>
#include "numberSaver.h"
#include "printTools.h"
#include "Operator.h"

using namespace std;

char var[100];
char dealed[100];
number value[100];
number dealed_num[100];
int index_value = 0;
void calculate2(char* deal,number* deal_num,int head,int tail);
void append(int loc,char va,number n){
    var[loc] = va;
    value[loc] = n;
}
int findLast(char* deal,number* deal_num,int head,int tail,int key){
    for (int i = key+1; i <= tail; ++i) {
        if (deal_num[i].len != 0){
            return i;
        }
    }
    return -1;
}
int findPrev(char* deal,number* deal_num,int head,int tail,int key){
    for (int i = key-1; i >= head; --i) {
        if (deal_num[i].len != 0){
            return i;
        }
    }
    return -1;
}
void calculate0(char* deal,number* deal_num,int head,int tail){
    number zero;
    for (int i = head; i < tail; ++i) {
        if (deal[i] == 's'&&deal[i+1] == 'q'&&deal[i+2]=='r'&&deal[i+3]=='t'){
            for (int j = i; j <= i+4; ++j) {
                deal[j] = '0';
            }
            deal[i+6] = '0';
            deal_num[i] = exp(deal_num[findLast(deal,deal_num,head,tail,i)],2);
            deal_num[findLast(deal,deal_num,head,tail,i)] = zero;
        }
    }
    for (int i = head; i < tail; ++i) {
        if (deal[i] == '^'){
            deal[i] = '0';
            int last = findLast(deal,deal_num,head,tail,i);
            int prev = findPrev(deal,deal_num,head,tail,i);
            deal_num[prev] = exp(deal_num[prev],deal_num[last].getValue());
        }
    }
}
void calculate1(char* deal,number* deal_num,int head,int tail){
    int counterK = 0;
    int indexL = -1;
    int indexR = -1;
    number zero;
    for (int i = head; i <= tail; ++i) {
        if (indexL == -1&&deal[i] == '('){
            indexL = i;
            counterK ++;
            deal[i] = '0';
        } else if (deal[i] == ')'){
            counterK --;
            if (counterK == 0){
                indexR = i;
                deal[i] = '0';
            }
        }
        if (indexL!=-1&&indexR!=-1){
            calculate2(deal,deal_num,indexL,indexR);
        }
    }
}
void calculate2(char* deal,number* deal_num,int head,int tail){
    number zero;
    for (int i = head; i <= tail; ++i) {
        if (deal[i] == '*'||deal[i] == '/'){
            if (deal[i] == '*'){
                int prev = findPrev(deal,deal_num,head,tail,i);
                int last = findLast(deal,deal_num,head,tail,i);
                deal[i] = '0';
                deal_num[prev] = mul(deal_num[prev],deal_num[last]);
                deal_num[last] = zero;
            } else if(deal[i] == '/'){
                int prev = findPrev(deal,deal_num,head,tail,i);
                int last = findLast(deal,deal_num,head,tail,i);
                deal[i] = '0';
                deal_num[prev] = div(deal_num[prev],deal_num[last]);
                deal_num[last] = zero;
            }
        }
    }
    for (int i = head; i <= tail; ++i) {
        if (deal[i] == '+' || deal[i] == '-') {
            if (deal[i] == '+') {
                int prev = findPrev(deal, deal_num, head, tail, i);
                int last = findLast(deal, deal_num, head, tail, i);
                deal[i] = '0';
                deal_num[prev] = plu(deal_num[prev], deal_num[last]);
//                printInfo(deal_num[prev]);
                deal_num[last] = zero;
            } else if (deal[i] == '-') {
                int prev = findPrev(deal, deal_num, head, tail, i);
                int last = findLast(deal, deal_num, head, tail, i);
                deal[i] = '0';
                deal_num[prev] = sub(deal_num[prev], deal_num[last]);
                deal_num[last] = zero;
            }
        }
    }
    return;
}
int main() {
    cout<<"Enter 0 to end calculator."<<endl;
    while (true){
        char input[1000];
        memset(input, '\0', sizeof(input));
        memset(var, '\0', sizeof(var));
        memset(value, '\0', sizeof(value));

        //变量设置
        int index = 0;
        int index_equal = -1;
        bool stop = false;
        while (true) {
            cin.getline(input, 10000);
            if (input[0] == '0'){
                stop = true;
                break;
            }
            for (int i = 0; i < sizeof input && input[i] != '\0'; ++i) {
                if (input[i] == '=') {
                    index_equal = i;
                    break;
                }
            }
            if (index_equal <= 0) {
                break;
            } else {
                char tem = input[0];
                append(index_value++, tem, charToNum(input, index_equal + 1, (sizeof input) - 1));
            }
            memset(input, '\0', sizeof(input));
            index_equal = -1;
        }
        if (stop){
            cout<<"Calculator is ended successfully.";
            break;
        }
        //把算式分别存入两个数组中

        int save_index = 0;
        char *input_loc = &input[0];
        memset(dealed, '0', sizeof dealed);
        memset(dealed_num, '0', sizeof dealed);

        for (int i = 0; i < sizeof input && input[i] != '\0'; ++i) {
            if (input[i] >= 48 && input[i] <= 57 || input[i] == '-' && (input[i - 1] < 48 || input[i - 1] > 57) ||
                input[i] == '-' && i == 0) {
                for (int j = i; j < sizeof input; ++j) {
                    if (j == i) {
                        continue;
                    }
                    if ((input[j] < 48 || input[j] > 57) && input[j] != '.') {
                        number tem = charToNum(input_loc, i, j - 1);
                        dealed_num[save_index++] = tem;
                        i = j - 1;
                        break;
                    }
                }
            } else {
                dealed[save_index++] = input[i];
            }
        }
        for (int i = 0; i < save_index; ++i) {
            for (int j = 0; j < 3 && var[j] != '\0'; ++j) {
                if (dealed[i] == var[j]) {
                    dealed[i] = '0';
                    dealed_num[i] = value[j];
                    break;
                }
            }
        }



        //计算
        calculate0(dealed, dealed_num, 0, save_index - 1);
        calculate1(dealed, dealed_num, 0, save_index - 1);
        calculate2(dealed, dealed_num, 0, save_index - 1);
//    for (int i = 0; i < save_index; ++i) {
//        cout<<i<<":";
//        printNumber(dealed_num[i]);
//        cout<<"  ";
//    }
//    for (int i = 0; i < save_index; ++i) {
//        cout<<dealed[i];
//    }
//    cout<<endl;
        printNumber(dealed_num[0]);
        cout<<endl;
    }
    return 0;
}
