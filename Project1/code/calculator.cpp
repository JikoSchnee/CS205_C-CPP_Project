#include <iostream>
#include <cstring>
#include <map>
#include <valarray>
#include <stringapiset.h>
#include <sstream>

using namespace std;

char* a;
char* b;
bool ifPoint = false;//判断存不存在小数点
bool Chinese = true;
bool Sci = true;
void revstr(char *str) //字符串反转
{
    int i=0,m,n;
    m = n = strlen(str) - 1;
    char *p=str,c;
    while(i <= m / 2)
    {
        c =* (p + i);
        *(p + i) = *(p + n);
        *(p + n)=c;
        i++;
        n--;
    }
}
int findPoint(char* number1,int len1){//查找小数点在第几位
    for (int i = 0; i < len1; ++i) {
        if (number1[i] == '.'){
            return i;
        }
    }
    return 0;
}
void cut(char* solution,int len3){
    for (int i = 0; i < len3; ++i) {
        if ((solution[i] <= '0' || solution[i] > '9' )&& solution[i+1] != '.'){
            solution[i] = '&';
        }else{
            break;
        }
    }
}
void mul(char* number1,char* number2){
    int len1 = strlen(number1);
    int len2 = strlen(number2);
    int len3 = len1+len2;
    bool n1 = true;
    bool n2 = true;
    if (number1[0] == '-'){
        number1[0] = '0';
        n1 = false;
    }
    if (number2[0] == '-'){
        number2[0] = '0';
        n2 = false;
    }
    revstr(number1);
    revstr(number2);

    //查找小数点位置
    int point = 0;
    point = findPoint(number1,len1) + findPoint(number2,len2);
    if (point == 0){
        ifPoint = false;
    }else{
        ifPoint = true;
    }

    int first[len1] = {0};
    int second[len2] = {0};
    int result[len3] = {0};
    for (int i = 0,j = 0; i < len1; ++i) {
        if (number1[i] != '.'){
            first[j++] = number1[i] - '0';
        }
    }
    for (int i = 0,j = 0; i < len2; ++i) {
        if (number2[i] != '.'){
            second[j++] = number2[i] - '0';
        }
    }

    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            result[i+j] += first[i] * second[j];
        }
    }
    int up = 0;
    for (int i = 0; i < len3; ++i) {
        result[i] += up;
        up = result[i] / 10;
        result[i] = result[i]%10;
    }

    char solution[len3];//最终结果的数组
    for (int i = 0,j = 0; i < len3; ++i) {
        if (point == 0){
            solution[i] = result[j++] + '0';
        }else{
            if (i!=point){
                solution[i] = result[j++] + '0';
            }else{
                solution[i] = '.';
            }
        }
    }
    //掐头去尾
    if (ifPoint){
        cut(solution,len3);
    }
    revstr(solution);
    cut(solution,len3);
    if (n1 != n2){
        cout << "-";
    }
    for (int i = 0; i < strlen(solution); ++i) {
        if (solution[i]>='0' && solution[i]<='9' ){
            cout << solution[i];
        } else if (solution[i] == '.'){
            cout << solution[i];
        }
    }
    cout << endl;
    revstr(number1);
    revstr(number2);
    return;
}
int judgeType(string obj){
    int Ecounter = 0;
    for (int i = 0; i < obj.length(); ++i) {
        if (obj[i]>=0 && obj[i]<=127){//在ascii码表内
            if (obj[i]<'0' || obj[i]>'9'){//不为数字
                if (obj[i] == 'e'){
                    Ecounter++;
                }else if (obj[i] != '.'){
                    return -1;
                }
            }
        } else{//含全角字符
            return 1;
        }
    }
    if (Ecounter == 1){
        return 2;
    }
    return 0;
}

void printAB(){
    for (int i = 0; i < strlen(a); ++i) {
        cout << a[i];
    }
    cout << " * ";

    for (int i = 0; i < strlen(b); ++i) {
        cout << b[i];
    }
    cout << " = ";
}


//converter
//中文转换这步使用了网上的代码：https://blog.csdn.net/u010412858/article/details/80354996
int chineseToInt(wstring s)
{
    map<wchar_t, int> chineseNum;
    chineseNum.insert(pair<wchar_t, int>(L'零', 0));
    chineseNum.insert(pair<wchar_t, int>(L'一', 1));
    chineseNum.insert(pair<wchar_t, int>(L'二', 2));
    chineseNum.insert(pair<wchar_t, int>(L'两', 2));
    chineseNum.insert(pair<wchar_t, int>(L'俩', 2));
    chineseNum.insert(pair<wchar_t, int>(L'三', 3));
    chineseNum.insert(pair<wchar_t, int>(L'四', 4));
    chineseNum.insert(pair<wchar_t, int>(L'五', 5));
    chineseNum.insert(pair<wchar_t, int>(L'六', 6));
    chineseNum.insert(pair<wchar_t, int>(L'七', 7));
    chineseNum.insert(pair<wchar_t, int>(L'八', 8));
    chineseNum.insert(pair<wchar_t, int>(L'九', 9));
    chineseNum.insert(pair<wchar_t, int>(L'十', 10));
    chineseNum.insert(pair<wchar_t, int>(L'百', 100));
    chineseNum.insert(pair<wchar_t, int>(L'千', 1000));
    chineseNum.insert(pair<wchar_t, int>(L'万', 10000));
    chineseNum.insert(pair<wchar_t, int>(L'亿', 100000000));
    chineseNum.insert(pair<wchar_t, int>(L'壹', 1));
    chineseNum.insert(pair<wchar_t, int>(L'贰', 2));
    chineseNum.insert(pair<wchar_t, int>(L'叁', 3));
    chineseNum.insert(pair<wchar_t, int>(L'肆', 4));
    chineseNum.insert(pair<wchar_t, int>(L'伍', 5));
    chineseNum.insert(pair<wchar_t, int>(L'陆', 6));
    chineseNum.insert(pair<wchar_t, int>(L'柒', 7));
    chineseNum.insert(pair<wchar_t, int>(L'捌', 8));
    chineseNum.insert(pair<wchar_t, int>(L'玖', 9));
    chineseNum.insert(pair<wchar_t, int>(L'拾', 10));
    chineseNum.insert(pair<wchar_t, int>(L'佰', 100));
    chineseNum.insert(pair<wchar_t, int>(L'仟', 1000));
    chineseNum.insert(pair<wchar_t, int>(L'萬', 10000));
    chineseNum.insert(pair<wchar_t, int>(L'億', 100000000));

    int result=0, tmp = 0, hnd_mln=0;
    wchar_t curr_char;
    int curr_digit;
    for (int i = 0; i < s.length(); ++i)
    {
        curr_char = s.at(i);
        if (chineseNum.find(curr_char) == chineseNum.end())
            return NULL;
        curr_digit = chineseNum.at(curr_char);

        if (curr_digit == pow(10, 8))//meet 「亿」 or 「億」
        {
            result = result + tmp;
            result = result * curr_digit;
            //get result before 「亿」 and store it into hnd_mln
            //reset `result`
            hnd_mln = hnd_mln * pow(10, 8) + result;
            result = 0;
            tmp = 0;
        }
        else
        {
            if (curr_digit == pow(10, 4))//meet 「万」 or 「萬」
            {
                result = result + tmp;
                result = result * curr_digit;
                tmp = 0;
            }
            else
            {
                if (curr_digit >= 10)//meet 「十」, 「百」, 「千」 or their traditional version
                {
                    if (tmp == 0)
                        tmp = 1;
                    result = result + curr_digit * tmp;
                    tmp = 0;
                }
                else
                {
                    tmp = tmp * 10 + curr_digit;
                    /*if (curr_digit != NULL)

                    else
                    {
                        return result;
                    }*/
                }
            }
        }
    }
    result = result + tmp;
    result = result + hnd_mln;
    return result;
}
double sciToDuble(const string & str)
{
    stringstream ss(str);
    double d = 0;
    ss >> d;
    if (ss.fail())

    {
        string s = "Unable to format";
        s += str;
        s  += "as s number!";
        throw(s);
    }
    return(d);
}
string doubleToString(double d){
    ostringstream os;
    if(os << d) return os.str();
    return "invalid conversion";
}
std::wstring stringToWstring(const std::string& str)
{
    LPCSTR pszSrc = str.c_str();
    int nLen = MultiByteToWideChar(CP_ACP, 0, pszSrc, -1, NULL, 0);
    if (nLen == 0)
        return std::wstring(L"");

    wchar_t* pwszDst = new wchar_t[nLen];
    if (!pwszDst)
        return std::wstring(L"");

    MultiByteToWideChar(CP_ACP, 0, pszSrc, -1, pwszDst, nLen);
    std::wstring wstr(pwszDst);
    delete[] pwszDst;
    pwszDst = NULL;

    return wstr;
}

void converter(char* obj,int type){
    if (type != 0){
        if (type == 1){//中文
            string ob = obj;
            wstring o = stringToWstring(ob);
            int i = chineseToInt(o);
            if (i == 0){
                Chinese = false;
            }
            itoa(i,obj,10);
//            cout << "ob=" << ob << endl;
//            cout << "i=" <<i << endl;

        }else if (type == 2){//科学计数法
            int eLocation = 0;
            for (int i = 0; i < strlen(obj); ++i) {
                if (obj[i] == 'e'){
                    eLocation = i;
                }
            }
            if (obj[eLocation+1] == '-'){
                char* linshi = new char;
                for (int i = eLocation,j=0; i < strlen(obj); ++i) {
                    if (obj[i]>='0'&&obj[i]<='9'){
                        linshi[j++] = obj[i];
                    }
                }
                int Enumber = stoi(linshi);
                char result[Enumber+2] = {0};
                for (int i = 0; i < Enumber+2; ++i) {
                    result[i] = '0';
                }
                result[1] = '.';
                for (int i = eLocation,j=Enumber+1; i >=0; --i) {
                    if (obj[i]>='0'&&obj[i]<='9'){
                        result[j--] = obj[i];
                    }
                }
                for ( int i = 0; i < sizeof(obj);  i++ ) {
                    obj[i] = (char)0;
                }
                for (int i = 0; i < sizeof(result); ++i) {
                    obj[i] = result[i];
                }
            }else if (obj[eLocation+1] == '+'||(obj[eLocation+1]>='0'&&obj[eLocation+1]<='9')){
                char* linshi = new char;
                for (int i = eLocation+1,j=0; i < strlen(obj); ++i) {
                    if (obj[i]>='0'&&obj[i]<='9'){
                        linshi[j++] = obj[i];
                    }
                }
                int Enumber = stoi(linshi);
                char result[Enumber+1] = {0};
                for (int i = 0; i < Enumber+1; ++i) {
                    result[i] = '0';
                }
                for (int i = 0,j=0; i < eLocation; ++i) {
                    if (obj[i]>='0'&&obj[i]<='9'){
                        result[j++] = obj[i];
                    }
                }
                for ( int i = 0; i < sizeof(obj);  i++ ) {
                    obj[i] = (char)0;
                }
                for (int i = 0; i < sizeof(result); ++i) {
                    obj[i] = result[i];
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc == 3){
        a = argv[1];
        b = argv[2];
    }else{
        cout << "Please input two numbers need to be multiply(split by \" \"):" << endl;
        string A,B;
        cin >> A >> B;
        a = const_cast<char*>(A.c_str());
        b = const_cast<char*>(B.c_str());
    }
    if (judgeType(a)<0 || judgeType(b)<0){
        cout << "The input cannot be interpret as numbers!" <<endl;
    }
//    else if (judgeType(a)==2 && judgeType(b)==2){
//        printAB();
//        cout << sciToDuble(a) * sciToDuble(b) << endl;
//    }
    else{
        converter(a, judgeType(a));
        converter(b, judgeType(b));
        //print
        if (Chinese){
            printAB();
            mul(a,b);
        } else {
            cout << "The input cannot be interpret as numbers!" << endl;
        }
    }
    return 0;
}
