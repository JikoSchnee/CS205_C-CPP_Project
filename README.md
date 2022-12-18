# 2022秋季学期结束后整理所有project


# [CPP_Project1_Multiplycation@Jiko](https://github.com/JikoSchnee/SUSTECH_CS205_C-C-Project/tree/main/Project1/code)

- **Name：纪可鸣**
- **SID：12112813**

仓库网址：https://github.com/JikoSchnee/SUSTECH_CS205_C-C-Project/tree/main/Project1/code

## 目录

[TOC]

## Ⅰ程序启动

### 启动方式

#### 方式一：命令行带输入

情况①：正常输入

```cpp
/mul 1.1234 346435
```

情况②：无输入或输入字符串个数不为2，转到启动方式二

```cpp
/mul 12 34 245
```

#### 方式二：命令行无输入（或不规范）

```cpp
/mul 12 34 245
```

此时程序会输出特定语句，输入语句后的前两个字符串，

```cpp
/mul 12 34 245
Please input two numbers need to be multiply(split by " "):
123 35 123
```

即第一个数为”123“，第二个数为”35“

代码实现：

```cpp
if (argc == 3){        //方式1
        a = argv[1];
        b = argv[2];
    }else{             //方式2
        cout << "Please input two numbers need to be multiply(split by \" \"):" << endl;
        string A,B;
        cin >> A >> B;
        a = const_cast<char*>(A.c_str());//把String转成Char*再存入全局变量a、b中
        b = const_cast<char*>(B.c_str());
    }
```



## Ⅱ数据的输入与处理

### 数据的输入

启动方式1使用`int main(int argc, char* argv[])`直接输入两个数据；启动方式2先使用string存放两个数据再利用`a = const_cast<char*>(A.c_str());`转为char*。

### 数据的存放

> 因为之前只学过java，所以不知道怎么选择最优的存放方式，在经过一段时间的探索之后决定使用两个全局的char*来存放输入的字符串，并在之后直接在此上操作。

### 数据类型的判断

在这一步中使用`int judgeType(char* obj)`来判断输入数据的类型，因为输入的类型是无穷无尽的，所以我仅挑选了其中几个比较常见的典型案例，例如中文（一千一百五十一、陆拾壹）、科学计数法（1e8，1e-5，4e-20）等等，不同类型的数据对应不同的数字输出。

后续有更多的类型只要补充正则以及对应的输出数字就行。

代码实现：

```cpp
int judgeType(string obj){
    int Ecounter = 0;
    for (int i = 0; i < obj.length(); ++i) {
        if (obj[i]>=0 && obj[i]<=127){//在ascii码表内
            if (obj[i]<'0' || obj[i]>'9'){//不为数字
                if (obj[i] == 'e'){//计算e的数量
                    Ecounter++;
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
```

### 不同数据类型的处理

#### 翻译

> ==将所有数据变为只由“0-9”以及小数点“.”和负号“-”组成==，将这一数据定为**标准数据**。

##### return -1：非法输入

使程序直接输出“The input cannot be interpret as numbers!”

例如：

```cpp
/mul 我不是数字 我是汉字
The input cannot be interpret as numbers!
```

```cpp
/mul %*# 2
The input cannot be interpret as numbers!
```

##### return 0：合法字符

即输入数据已经满足为**标准数据**，直接进入下一步的运算。

##### return 1：中文字符

使用了网上的代码进行转换

[https://blog.csdn.net/u010412858/article/details/80354996](https://blog.csdn.net/u010412858/article/details/80354996)

```cpp
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
    chineseNum.insert(pair<wchar_t, int>(L'玖', 100));
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
```

将对应的字赋予对应的值最后相乘相加，在此基础上我加入了其他口语表达习惯例如“俩”“两”。需要注意的是中文输入需要非常遵守规范，十百千万都需说明清楚，否则判为无法转换。例如：

```cpp
/mul 一十 十一
The input cannot be interpret as numbers!
/mul 二百五 二百五十
205 * 250 = 51250
/mul 贰佰 叁佰五十
200 * 350 = 70000
```

转换后再进入下一步计算。

##### return 2：科学计数法

将科学计数法分为两类，一类是+一类是-。

主要思路还是把科学计数法转成**标准数据**，将数据分为两部分，前一部分为part1，后一部分为part2。part2先把后面的数字拼起来然后使用`stoi()`变成int类型，名字叫`Enumber`，如果是正的就开一个长度为Enumber+1的数组，初始化所有格子为0，从前往后填充part1；如果是负的就开一个长度为Enumber+2的数组，初始化所有格子为0，第二位改为小数点，从后往前填充part1。如此一来就可以得到**标准数据**之后再进行下一步计算。

代码实现：

```cpp
else if (type == 2){//科学计数法
            int eLocation = 0;
            for (int i = 0; i < strlen(obj); ++i) {
                if (obj[i] == 'e'){
                    eLocation = i;
                }
            }
            if (obj[eLocation+1] == '-'){
                char* linshi;
                for (int i = eLocation,j=0; i < strlen(obj); ++i) {
                    if (obj[i]>='0'&&obj[i]<='9'){
                        linshi[j++] = obj[i];
                    }
                }
                int Enumber = stoi(linshi);
                char result[Enumber+2] = {0};
                result[1] = '.';
                for (int i = eLocation,j=Enumber+1; i >=0; --i) {
                    if (obj[i]>='0'&&obj[i]<='9'){
                        result[j--] = obj[i];
                    }
                }
                obj = result;
            } else{
                char* linshi;
                for (int i = eLocation,j=0; i < strlen(obj); ++i) {
                    if (obj[i]>='0'&&obj[i]<='9'){
                        linshi[j++] = obj[i];
                    }
                }
                int Enumber = stoi(linshi);
                char result[Enumber+1] = {0};
                for (int i = 0,j=0; i < eLocation; ++i) {
                    if (obj[i]>='0'&&obj[i]<='9'){
                        result[j++] = obj[i];
                    }
                }
                obj = result;
            }
```



## Ⅲ计算

### 数组做乘法

#### 正负判断

翻译之后所有数据将变为只由“0-9”以及小数点“.”和负号“-”，此时再使用函数来处理数据的正负，若为正，则函数返回true，若为负，则函数返回false，并移除负号。在这时候数据变为无符号数，接下来将两数进行计算。最后在打印时如果两数对应的布尔值不一致则先打印一个负号，反之不打印。

#### 小数点处理

先移除小数点，最后在数组乘法结束后再加上。

例如：$346.134613471 * 2313461.234234 = 346134613471 * 2313461234234 /1e15$

#### 数组乘法

在经过前面的**数据处理**、**正负判断**、**小数点处理**后余下的只有0-9共10个数字组成的数，因为可能遇到数据类型无法存放的超大数据，所以我决定采用数组来计算乘法。其原理与列乘法竖式类似，将两数分别存入两个数组，长度分别为`len1`和`len2`，n位数与m位数相乘最大为m+n位数（使用计算器99*999简单验证），因此可以开一个存放结果的数组3，长度为m+n，数1的i位与数2的j位相乘，结果加在数3的i+j位，每次运算后把多于10的部分进位，个位数保留，依此类推可以计算==非常大的数字==。经过小数点处理后也可以处理==高精度的浮点数==。代码实现：

```cpp
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
    revstr(number1);//翻转char
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
```

案例：

```
/mul 12345 457458536589
12345 * 457458536589 = 5647325634191205
/mul 346.134613471 2313461.234234
346.134613471 * 2313461.234234 = 800769010.091728182766214
```

### 掐头去尾

数组乘法结束后头尾会有多余的0，此时需要从头到尾和从尾到头一直去除直到该0的下一位是小数点。

代码实现：

```cpp
void cut(char* solution,int len3){
    for (int i = 0; i < len3; ++i) {
        if ((solution[i] <= '0' || solution[i] > '9' )&& solution[i+1] != '.'){
            solution[i] = '&';
        }else{
            break;
        }
    }
}
```

刚经过数组乘法的结果还没有翻转，此时使用cut()即从尾到头去0。

之后使用revstr翻转结果，此时使用cut()即从头到尾去0。

需要注意的是若存在小数点且小数点后全部为0，会保留十分位的0来说明进行了浮点运算。

例子：

```cpp
/mul 0.2 5
0.2 * 5 = 1.0
/mul 1.23 23.2
1.23 * 23.2 = 28.536
```

## Ⅳ输出

先使用`printAB()`来输出经过`converter()`处理后的两个数据及乘号，接着使用`mul()`（参照数组乘法中的代码，在计算完后会直接输出结果）来输出整个算式：

```cpp
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
```

## Ⅴ一些测试数据

```cpp
/mul 2.1e5 1.1e5
210000 * 110000 = 23100000000
```

```cpp
/mul 345os 029845f
The input cannot be interpret as numbers!
```

```cpp
/mul 134561032451451235 96029436023945620
134561032451451235 * 96029436023945620 = 12921820057112706828443579721840700
```

```cpp
/mul 六千五百一十三 五千两百二十
6513 * 5220 = 33997860
```

```cpp
/mul 1e5 2.5
100000 * 2.5 = 250000.0
```

# [CPP_Project2_Calculator@Jiko](https://github.com/JikoSchnee/SUSTECH_CS205_C-C-Project/tree/main/Project2/code)

- **Name：纪可鸣**
- **SID：12112813**

仓库网址：https://github.com/JikoSchnee/SUSTECH_CS205_C-C-Project/tree/main/Project2/code

## 写在前面

*※：第一次用这个仓库，怕传漏传错了所以把文件也附在blackboard上了，如果有什么问题请于老师直接看blackboard上的代码，谢谢于老师* :)

本次Project分为四个部分，分别为 **数字存储** **基础运算实现** **其他小工具** 和 **数据读入与处理**，分别放在四个对应的.cpp文件中

#### 测试案例

```cpp
x=3
y=6
x+2*y
    
2^2+5
    
2*(1+5)
    
x=99999999999999999999999999.9999
y=0.001
x+y
    
x=99999999999999999999999999.9999
x+x
    
114514.114514*114514.2346
    
2.45/114514
```

## 目录

[TOC]

## Ⅰ数字存储（numberSaver）

### struct number

把数字转为可用于计算的*struct ==**number**==*。

*struct **number***由4个元素组成：

```cpp
struct number{
    int num[10000]; //存储数字
    int len;        //有效数字的长度
    int pLoc;       //小数点的位置
    int zf;         //数字的正负
    number(){
        memset(num, 0, sizeof(num));
        len = 0;
        zf = 1;
        pLoc = -1;
    }
};
```

> *例：*
>
> *数字235.23，*
>
> *zf=1，pLoc=1，len=5，num：32532* 
>
> *数字-114.514*
>
> *zf=-1，pLoc=2，len=6，num：415411*

*※：默认的len为0，数组num从左到右为从低位到高位。*

### cutZero

用于去除头尾无意义的0：

```cpp
struct number cutZero(number key){
    while (key.num[key.len-1] == 0&&key.len-2>key.pLoc){//去掉头部的0
        key.len--;
    }
    int zeroCounter = 0;//去掉尾部的0
    int originLen = key.len;
    int ploc_tem = key.pLoc;
    for (int i = 0; i < key.pLoc+1; ++i) {
        if (key.num[i] == 0){
            key.len--;
            ploc_tem--;
            zeroCounter++;
        }else{
            break;
        }
    }
    key.pLoc = ploc_tem;
    for (int i = zeroCounter,j=0; i < originLen; ++i) {
        key.num[j++] = key.num[i];
    }
    return key;
}
```

> *例：*
>
> *-114.0处理后变为-114；*
>
> *01234.34000处理后变为1234.34。*

### 其他小工具

| 函数名      | 功能                                                         |
| ----------- | ------------------------------------------------------------ |
| charToNum   | 把字符串转为*number*类型，*num*中仅保留数字，将负号和小数点转移到*zf*和*pLoc*中 |
| integerBit  | 返回整数位的个数                                             |
| decimalBit  | 返回小数位的个数                                             |
| compareNoZf | 比较两数绝对值的大小                                         |

## Ⅱ基础运算实现（Operator）

### 加（plu）

> 长度：两数中较大的小数位加两数中较大的整数位加一即为结果的位数（若最后一位没有使用到会在最后使用cutZero除去无意义的0，详见 *数字存储-cutZero*）；
>
> 小数点位置：与较大小数位的数相同；
>
> 正负：若同号则为这一符号，若异号则稍作改变调用*减法（sub）*。

#### 思路

同位相加放到结果的同位上，最后从左至右依次进位。

#### 代码实现

```cpp
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
            return sub(n1,n2);
        } else{
            return sub(n2,n1);
        }
    }
}
```

### 减（sub）

> 长度：两数中较大的小数位加两数中较大的整数位加一即为结果的位数（若最后一位没有使用到会在最后使用cutZero除去无意义的0，详见 *数字存储-cutZero*）；
>
> 小数点位置：与较大小数位的数相同；
>
> 正负：若同号且被减数绝对值大于减数绝对值，正负与被减数相同；若同号且被减数绝对值小于减数绝对值，正负与被减数相反；若异号则稍加处理调用*加法（plu）*。

#### 思路

同位作减法放到结果的同位上，最后从左至右依次借位。

#### 代码实现

```cpp
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
```

### 乘（mul）

> 长度：最长为两数的位数相加
>
> 小数点位置：两数的小数点位置相加减一
>
> 正负：同号为正，异号为负

#### 思路

数1的第*i*位与数2的第*j*位相乘放到结果的第*i+j*位上，最后从左至右进位。

#### 代码实现

```cpp
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
```

### 除（div）

始终没有想到很好的方法，借用了[网络上的代码](https://github.com/wqlC/algorithm-Cpp/blob/master/BigNumber/bigDivide.cpp)，由于改代码仅适用两个整数相除的情况，且小数点后的数全部被舍弃，于是我稍加改动来适配自己的思路。网上代码的部分放到了另一个class “divide_internet”中。其中bigDivide。其中`bigDivide`即为两个整数相除的结果。

#### 代码实现

```cpp
struct number div(number n1,number n2){
    bn o1,o2;
    int di = 8;
    if (integerBit(n1)< integerBit(n2)){
        di+= integerBit(n2)- integerBit(n1);
    }
    n1 = mul(n1, tenTimes(di));
    printInfo(n1);
    printInfo(n2);
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
    for (int i = 0; i < oResult.len; ++i) {
        cout<<oResult.data[i];
    }
    return cutZero(result);
}
```

### 指数运算（exp）

#### 思路

将一个数自乘n次

#### 代码实现

```cpp
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
```

## Ⅲ其他小工具（printTools）

```cpp
void printInfo(number s);      //打印number类型的所有数据（仅用于debug）
void printNumber(number s);    //打印number存放的值的实际数据（最终答案用这个打印）
```

## Ⅳ数据读入与处理（main）

### 读入方式

一行一行读入，含有等号的行即为变量赋值行，最后不含有等号的行为算式行。

#### 变量行处理

*※：为防止与其他算法关键字重叠，目前只开放了**x**，**y**，**z**三个变量的赋值，可以根据需求增加。*

##### 思路

使用两个数组，一个是变量数组，一个是***number***（详见 *数字存储-struct number*）的数组，将等号左的变量名存在变量数组的第i位，将等号右边的数字直接转为***number***形式存入***number***数组的第i位。

##### 代码实现

```cpp
    int index = 0;
    int index_equal = -1;
    while (true){
        cin.getline(input,10000);
        for (int i = 0; i < sizeof input&&input[i]!='\0'; ++i) {
            if (input[i] == '='){
                index_equal = i;
                break;
            }
        }
        if (index_equal <= 0){
            break;
        } else{
            char tem = input[0];
            append(index_value++,tem, charToNum(input,index_equal+1,(sizeof input)-1));
        }
        memset(input,'\0',sizeof (input));
        index_equal = -1;
    }
```

#### 算式行处理

将数据和符号分开存放于两个数组中，一个数组为***char***类型的，一个为***number***（详见 *数字存储-struct number*）类型的。

***char***的空位用‘0’填充，***number***的空位由***zero***填充（***zero***为一个***number***类型，其长度为0）。

> *例：为简便表示number数组中直接显示对应的值，z即zero。*
>
> *算式为：*2+sqrt(4)+5*2
>
> 0 + s q r t ( 0 ) + 0 * 0
>
> 2 z z z z z z 4 z z 5 z 2

接下来根据优先级分步依次使用`calculate0` `calculate1` `calculate2`计算。如果要添加更高优先级的只需要再添加函数`calculaten`（n可为任意后缀）并置于其他之前或根据优先级插入合适位置即可。嵌套规则也可直接在新函数中引用其他函数。

#### 计算

当前有三个不同的优先级

分别为 *指数* 对应`calculate0`，*括号* 对应`calculate1`，*加减乘除* 对应`calculate2`

##### 小工具

```cpp
int findLast(char* deal,number* deal_num,int head,int tail,int key);//找到该符号后一位相邻数
int findPrev(char* deal,number* deal_num,int head,int tail,int key);//找到该符号前一位相邻数
```

##### 指数

###### sqrt()

平方该数并存在s的位置。

###### ^

调用***exp函数***（详见 *基础运算实现-指数运算*）。

用小工具查找前后相邻数实施运算

###### 代码实现

```cpp
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
```

##### 括号

找到括号位置，将括号内的算式看作一个新的算式，先在其中执行加减乘除运算。

##### 加减乘除

###### +-*/

用小工具查找前后相邻数调用基础运算中的加减乘除，将结果存在靠前的***number***位置上。

###### 括号及加减乘除的代码实现

```cpp
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
```

## 写在后面

在cpp的学习中感觉自己已经被java惯坏了，本以为同为流行的编程语言应该差不了多少，却发现cpp需要注意和学习的地方比java多太多。另外在project1的乘法中我使用的是直接在数组上做文章，有点让自己的大脑过载了，这次使用了新学习的结构体一下子方便了好多，之前搞了好几天的乘法现在几个小时就能成功实现了。虽然每次做project都腰酸背痛，眼睛像要冒火，但做完之后看着各个代码各司其职成就感真的爆棚，希望能继续在于老师的课和project上学习更多有趣的新知识~

# [CPP_Project3_Matrix_inC@Jiko](https://github.com/JikoSchnee/SUSTECH_CS205_C-C-Project/tree/main/Project3/code)

- **Name：纪可鸣**
- **SID：12112813**

仓库网址：https://github.com/JikoSchnee/SUSTECH_CS205_C-C-Project/tree/main/Project3/code

## 目录

[TOC]

## ⅠStruct matrix

一个矩阵主要有三个基本信息需要存储，分别为行数、列数以及矩阵每个格子的对应值。另外根据矩阵的特点又分为方阵、对称矩阵、对角矩阵、单位矩阵等等。因此我构建的结构体分为两个部分，一个是基础信息部分，另一个是附加信息部分，基础信息即三个基本信息，实时更新；附加信息即矩阵的特点，可以选择在需要的时候再进行更新（更新详见：*Function for convenience - refreshMatrix()*）。

为使可存储的矩阵尽可能大，我选择了long来存储行数和列数。为方便读取，我选择了一维数组而不是二维数组。因为特征只有是或不是两个可能性，所以使用bool类型来存储。

```c
struct matrix{
    //basic info
    long row;
    long column;
    float * data;
    //addition info
    bool square;      //方阵
    bool diagnose;    //对角矩阵
    bool symmetric;   //对称矩阵
    bool identical;   //单位矩阵
    //...可以继续添加
};
```

## ⅡFunction for users

### ①createMatrix()

```c
struct matrix * createMatrix(const long r,const long c,float * data);
```

#### 思路构建

创建一个矩阵。将数组第n行拼到第n-1行后面，形成一个一维数组，从这一数组的0位开始依次放入data，直到 *行数与列数乘积减一* 位。

#### 错误检查

如果传入的矩阵指针为空、矩阵r和c其中至少有一个小于等于0、data*指向为空则会输出对应错误提示，并返回一个NULL指针。

#### 代码实现

```c
struct matrix *createMatrix(const long r, const long c, float *data) {//一维数组导入
    if (data == NULL) {
        puts("Error in \"createMatrix\": Pointer is NULL.\n");
        return NULL;
    } else if (r * c == 0||data==NULL) {
        puts("Error in \"createMatrix\": Matrix is empty.\n");
        return NULL;
    }
    struct matrix *newMat = (struct matrix *) malloc(1);
    newMat->row = r;
    newMat->column = c;
    float *saveData;
    saveData = (float *) malloc(r * c * sizeof(float));
    for (int i = 0; i < r * c; ++i) {
        saveData[i] = data[i];
    }
    newMat->data = saveData;
    refreshType(newMat);
    return newMat;
}
```

#### 样例展示

<img src="C:\Users\27449\Desktop\学习\typora图片\image-20221030170309864.png" alt="image-20221030170309864" style="zoom:50%;" />

> case0构建时传入了空的指针，因此创建矩阵时打印了`Error in "createMatrix": Pointer is NULL.`，case1、2为正确的传入方式，下面即为打印出来的矩阵1和矩阵2。

### ②deleteMatrix()

```c
void deleteMatrix(struct matrix ** mat);
```

#### 思路构建

传入矩阵指针的地址，先释放其data的内存，再释放这个指针所占用的内存，最后再将这个指针指向NULL。

#### 错误检查

如果传入的地址所指向的指针本身指向的就为NULL，那么除了输出错误提示什么也不会做。

#### 代码实现

```c
void deleteMatrix(struct matrix ** mat_loc){
    if(mat_loc == NULL){
        printf("Error in \"deleteMatrix\": this mat is NULL.\n");
        return;
    }
    free((*mat_loc)->data);
    free(*mat_loc);
    *mat_loc = NULL;
}
```

#### 样例展示

<img src="C:\Users\27449\Desktop\学习\typora图片\image-20221030172552289.png" alt="image-20221030172552289" style="zoom:50%;" />

> case0是一个空的指针，所以delete操作会有错误提示；
>
> case1是一个合法的矩阵指针，删除后再打印会提示矩阵指针已经指向了NULL。

### ③copyMatrix()

```c
struct matrix * copyMatrix(const struct matrix * const mat);
```

#### 思路构建

将要拷贝的数组的所有数据都拷贝一份，然后重新create一个内存位置不同的矩阵。

#### 错误检查

检查这个将要被拷贝的矩阵是否合法，若不合法则错误提示，并返回一个空指针。

#### 代码实现

```c
struct matrix *copyMatrix(const struct matrix *const mat) {
    if (mat == NULL||mat->column<=0||mat->row<=0||mat->data==NULL) {
        printf("Error in \"copyMatrix\": input an invalid matrix.\n");
        printFalse(mat);
        return NULL;
    }
    float array[mat->row * mat->column];
    for (int i = 0; i < mat->row * mat->column; ++i) {
        array[i] = mat->data[i];
    }
    return createMatrix(mat->row, mat->column, array);
}
```

#### 样例展示

<img src="C:\Users\27449\Desktop\学习\typora图片\image-20221030174938811.png" alt="image-20221030174938811" style="zoom: 50%;" />

> case0为空指针，复制时返回出错提示；case1为合法的矩阵指针，打印发现两个矩阵相同。

<img src="C:\Users\27449\Desktop\学习\typora图片\image-20221030175224781.png" alt="image-20221030175224781" style="zoom:50%;" />

> 删掉被拷贝的矩阵后，拷贝的矩阵依然不变，说明二者没有共用内存。

### ④addMatrix()

```c
struct matrix * addMatrix(const struct matrix * const mat1,const struct matrix * const mat2);
```

#### 思路构建

输入两个矩阵指针，两个指针的row和column相同，创建一个新数组，数组的长度为row * column，依次将对应的data存入这一数组，最后再使用这一数组create一个行数为row，列数为column的新矩阵，返回这个矩阵的指针。

#### 错误检查

检查矩阵指针是否指向NULL，是否存在column或row<=0，是否data指向NULL，如果有则输出相应错误提示，最后返回指向NULL的矩阵指针。

#### 代码实现

```c
struct matrix *addMatrix(const struct matrix *const mat1, const struct matrix *const mat2) {
    if (mat1 == NULL||mat1->column<=0||mat1->row<=0||mat1->data==NULL) {
        printf("Error in \"addMatrix\": input an invalid matrix(left).\n");
        printFalse(mat1);
        return NULL;
    }else if (mat2 == NULL||mat2->column<=0||mat2->row<=0||mat2->data==NULL) {
        printf("Error in \"copyMatrix\": input an invalid matrix(right).\n");
        printFalse(mat2);
        return NULL;
    }else if (mat1->column != mat2->column || mat1->row != mat2->row) {
        printf("Error in \"addMatrix\": matrix1 %d columns, matrix1 %d rows\n", mat1->column, mat1->row);
        printf("Error in \"addMatrix\": matrix2 %d columns, matrix2 %d rows\n", mat2->column, mat2->row);
        return NULL;
    }
    int c = mat1->column;
    int r = mat1->row;
    float array[c * r];
    for (int i = 0; i < c * r; ++i) {
        array[i] = mat1->data[i] + mat2->data[i];
    }
    return createMatrix(r, c, array);
}
```

#### 样例展示

<img src="C:\Users\27449\Desktop\学习\typora图片\image-20221030202204312.png" alt="image-20221030202204312" style="zoom:50%;" />

> 第一个case是两个尺寸不同的矩阵相加，因此输出空指针。第二个case合法，输出了正确的矩阵。

### ⑥subMatrix()

```c
struct matrix * subMatrix(const struct matrix * const mat1, const struct matrix * const mat2);
```

#### 思路构建

输入两个矩阵指针，两个指针的row和column相同，创建一个新数组，数组的长度为row * column，依次将对应的data相减存入这一数组，最后再使用这一数组create一个行数为row，列数为column的新矩阵，返回这个矩阵的指针。

#### 错误检查

检查矩阵指针是否指向NULL，是否存在column或row<=0，是否data指向NULL，如果有则输出相应错误提示，最后返回指向NULL的矩阵指针。

#### 代码实现

```c
struct matrix *subMatrix(const struct matrix *const mat1, const struct matrix *const mat2) {
    if (mat1 == NULL||mat1->column<=0||mat1->row<=0||mat1->data==NULL) {
        printf("Error in \"subMatrix\": input an invalid matrix(left).\n");
        printFalse(mat1);
        return NULL;
    }else if (mat2 == NULL||mat2->column<=0||mat2->row<=0||mat2->data==NULL) {
        printf("Error in \"subMatrix\": input an invalid matrix(right).\n");
        printFalse(mat2);
        return NULL;
    }else if (mat1->column != mat2->column || mat1->row != mat2->row) {
        printf("Error in \"subMatrix\": matrix1 %d columns, matrix1 %d rows\n", mat1->column, mat1->row);
        printf("Error in \"subMatrix\": matrix2 %d columns, matrix2 %d rows\n", mat2->column, mat2->row);
        return NULL;
    }
    int c = mat1->column;
    int r = mat1->row;
    float array[c * r];
    for (int i = 0; i < c * r; ++i) {
        array[i] = mat1->data[i] - mat2->data[i];
    }
    return createMatrix(r, c, array);
}
```

#### 样例展示

<img src="C:\Users\27449\Desktop\学习\typora图片\image-20221030203107847.png" alt="image-20221030203107847" style="zoom:50%;" />

> 第一个case是两个尺寸不同的矩阵相减，因此输出空指针。第二个case合法，输出了正确的矩阵。

### ⑦mulMatrix()

```c
struct matrix * mulMatrix(const struct matrix * const mat1,const struct matrix * const mat2);
```

#### 思路构建

mat1的每一行分别乘mat2的每一列，依次放入数组array中。

最终结果的矩阵行数与mat1相同，列数与mat2相同。最后create一个新的矩阵并返回其指针。

#### 错误检查

检查两个矩阵指针是否指向NULL，是否存在column或row<=0，是否data指向NULL，如果有则输出相应错误提示，且返回一个指向NULL的指针。

另外还需检查mat1的列数是否与mat2的行数相等，否则输出相应错误提示，且返回一个指向NULL的指针。

#### 代码实现

```c
struct matrix *mulMatrix(const struct matrix *const mat1, const struct matrix *const mat2) {
    if (mat1 == NULL || mat1->column<=0||mat1->row<=0||mat1->data == NULL) {
        printf("Error in \"mulMatrix\": Input a invalid matrix(left)");
        printFalse(mat1);
        return NULL;
    } else if (mat2 == NULL || mat2->column<=0||mat2->row<=0||mat2->data == NULL) {
        printf("Error in \"mulMatrix\": Input a invalid matrix(right)");
        printFalse(mat2);
        return NULL;
    } else if (mat1->column != mat2->row) {
        printf("Error in \"mulMatrix\": mat1's column(%d) not equal mat2's row(%d).\n", mat1->column, mat2->row);
        return NULL;
    }
    long r = mat1->row;
    long c = mat2->column;
    float array[r * c];
    long indexResult = 0;
    for (int i = 0; i < mat1->row; ++i) {
        for (int j = 0; j < mat2->column; ++j) {
            array[indexResult] = 0;
            for (int k = 0; k < mat1->column; ++k) {
                array[indexResult] += mat1->data[i * mat1->column + k] * mat2->data[j + mat2->column * k];
            }
            indexResult++;
        }
    }
    struct matrix *newMatrix = createMatrix(r, c, array);
    return newMatrix;
}
```

#### 样例展示

<img src="C:\Users\27449\Desktop\学习\typora图片\image-20221030212315177.png" alt="image-20221030212315177" style="zoom:50%;" />

### ⑧addScalar() and subScalar() and mulScalar()

```c
void addScalar(struct matrix * const mat, float scalar);
```

```c
void subScalar(struct matrix * const mat, float scalar);
```

```c
void mulScalar(struct matrix * const mat, float scalar);
```

#### 思路构建

传入矩阵指针以及要加(减/乘)的常数，直接在原矩阵的data上作修改。

#### 错误检查

检查矩阵指针是否指向NULL，是否存在column或row<=0，是否data指向NULL，如果有则输出相应错误提示，除此之外不做任何操作。

#### 代码实现

以加法为例

```c
void addScalar(struct matrix *const mat, float scalar) {
    if (mat == NULL || mat->column<=0||mat->row<=0 || mat->data==NULL) {
        printf("Error in \"addSac\": Invalid input.");
        printFalse(mat);
        return;
    }
    for (int i = 0; i < mat->column * mat->row; ++i) {
        mat->data[i] += scalar;
    }
}
```

#### 样例展示

以加法为例

<img src="C:\Users\27449\Desktop\学习\typora图片\image-20221030204310708.png" alt="image-20221030204310708" style="zoom:50%;" />

### ⑨findMin() and findMax()

```c
float findMin(const struct matrix * const mat);
```

```c
float findMax(const struct matrix * const mat);
```

#### 思路构建

遍历矩阵的data，返回最小(大)的值。

#### 错误检查

检查矩阵指针是否指向NULL，是否存在column或row<=0，是否data指向NULL，如果有则输出相应错误提示，且返回0.0f。

#### 代码实现

以查找最小值为例

```c
float findMin(const struct matrix *const mat) {
    if (mat == NULL || mat->column<=0||mat->row<=0 || mat->data==NULL) {
        printf("Error in \"findMin\": Invalid input.");
        printFalse(mat);
        return 0.0f;
    }
    float min = mat->data[0];
    for (int i = 0; i < mat->row * mat->column; ++i) {
        if (mat->data[i] < min) {
            min = mat->data[i];
        }
    }
    return min;
}
```

#### 样例展示

<img src="C:\Users\27449\Desktop\学习\typora图片\image-20221030210505062.png" alt="image-20221030210505062" style="zoom:50%;" />

> case1是一个非法的矩阵地址，因此有对应的错误提示，case2输出了矩阵中的最大值。

### ⑩transportMatrix()

```c
struct matrix * transportMatrix(const struct matrix * const mat);
```

#### 思路构建

将(n,m)处的值放到(m,n)的地方，把row和column交换，如此create一个新的矩阵，并返回其地址。

#### 错误检查

检查矩阵指针是否指向NULL，是否存在column或row<=0，是否data指向NULL，如果有则输出相应错误提示，且返回一个指向NULL的指针。

#### 代码实现

```c
struct matrix *transportMatrix(const struct matrix *const mat) {
    if (mat == NULL || mat->column<=0||mat->row<=0 || mat->data==NULL) {
        printf("Error in \"transportMatrix\": Invalid input.");
        printFalse(mat);
        return NULL;
    }
    long r = mat->column;
    long c = mat->row;
    long index = 0;
    float array[r * c];
    for (int i = 0; i < mat->column; ++i) {
        for (int j = 0; j < mat->row; ++j) {
            array[index++] = mat->data[i + j * mat->column];
        }
    }
    struct matrix *newMatrix = createMatrix(r, c, array);
    return newMatrix;
}
```

#### 样例展示

<img src="C:\Users\27449\Desktop\学习\typora图片\image-20221030211332607.png" alt="image-20221030211332607" style="zoom:50%;" />

## ⅢFunction for convenience

### refreshType()

```c
void refreshType(struct matrix * const mat); 
```

用于更新矩阵的附加条件的状态。每次create一个新矩阵的时候都会启用。

- 如果后续有函数需要使用到附加条件的时候只要在开头refresh这个矩阵就能正常使用了。
- 如果后续需要添加新的附加条件，只要在头文件中添加新的bool类型，并在refreshType中添加正则即可。

### printMatrix()

```c
void printMatrix(const struct matrix * mat);
```

用于打印矩阵，根据矩阵的数据有效位数可以修改%f的参数使得数据能够向右对齐。

### printFalse()

```c
bool printFalse(struct matrix * mat);
```

根据不同的错误打印不同的错误提示。


# [CPP_Project4_Matrix_inC_SpeedUp@Jiko](https://github.com/JikoSchnee/SUSTECH_CS205_C-C-Project/tree/main/Project4/code)

- **Name：纪可鸣**
- **SID：12112813**

仓库网址：https://github.com/JikoSchnee/SUSTECH_CS205_C-C-Project/tree/main/Project4/code

## 写在前面

一看到要优化速度，我开始便兴致勃勃地先去找有没有优化的算法，一眼相中斯特拉森算法啃了好久，结果却很难使人满意，并且过程中对内存管理的要求非常冗杂，“性价比”不高。做完整个project后发现硬件优化、O3优化、SIMD指令集优化和OpenMP优化都比算法“性价比”高得多，如此一来我发现这几种优化真的非常管用，几乎可以广泛地用在任何的project上，而且在面对数据非常大的运算时能够获得很理想的优化。而啃斯特拉森算法的过程，以及看于老师对这个project点评的视频过程中对内存管理也有了更深刻的认识，可以说此次project受益匪浅了\^_\^。

------

※*为方便比较，以硬件优化后的乘法为基础，为了比较更明显，每个模块不会同时使用所有优化方法。在**综合优化**模块中综合前面提到的优化方法提供一个improved方案。*

------

## 目录

[TOC]

## Ⅰ硬件优化

### CPU访问优化

因为CPU访问内存的速度比CPU计算速度慢得多，所以CPU访问内存的优化尤为重要。

人工计算矩阵，一般地是从左往右，从上到下依次计算出结果矩阵每一位的数，如pro3中的代码：

```cpp
for (size_t i = 0; i < mat1->row; ++i) {
    for (size_t j = 0; j < mat2->column; ++j) {
        array[indexResult] = 0;
        for (size_t k = 0; k < mat1->column; ++k) {
            array[indexResult] += mat1->data[i * mat1->column + k] * mat2->data[j + mat2->column * k];
        }
        indexResult++;
    }
}
```

但是这样使得mat2->data的读取变得不连续，每次读取都需要跳跃至少`column \* sizeof(float)`个字节，那么是否能通过交换顺序使得内存的访问变得更加连续呢？

```cpp
for (int i = 0; i < r; ++i) {
            for (int k = 0; k < r; ++k) {
                tem = mat1->data[i * r + k];
                for (int j = 0; j < r; ++j) {
                    array[i * r + j] += tem * mat2->data[k * r + j];
                }
            }
        }
```

如此一来在mat1和mat2data上的读取相比原先方案更加连续。

#### 数据测试

`matmul_plain`：

|         | 1    | 2    | 3    | 平均     |
| ------- | ---- | ---- | ---- | -------- |
| 128×128 | 8    | 12   | 8    | 9.333333 |
| 1k×1k   | 4325 | 4495 | 4227 | 4349     |

==硬件优化==：

|         | 1    | 2    | 3    | 平均        |
| ------- | ---- | ---- | ---- | ----------- |
| 128×128 | 7    | 8    | 6    | 7           |
| 1k×1k   | 2664 | 2767 | 2613 | 2681.333333 |

**可以看到当矩阵足够大时优化效果非常显著。**

## ⅡO3优化

通过增加编译代码的代码量来换取运行时间的缩短。

### 代码实现

#### cmake

添加`set(CMAKE_C_FLAGS "-O3")`：添加O3编译选项。

#### .c

添加`#pragma gcc optimize(3)`

### 数据测试

硬件优化：

|         | 1    | 2    | 3    | 平均        |
| ------- | ---- | ---- | ---- | ----------- |
| 128×128 | 7    | 8    | 6    | 7           |
| 1k×1k   | 2664 | 2767 | 2613 | 2681.333333 |

==O3优化+硬件优化==：

|         | 1      | 2      | 3      | 平均       |
| ------- | ------ | ------ | ------ | ---------- |
| 128×128 | 1      | 1      | 1      | 1          |
| 1k×1k   | 154    | 147    | 154    | 151.666667 |
| 8k×8k   | 131834 | 151079 | 143843 | 142252     |

可以发现使用O3优化后运行速度是飞一般的增长，并且也是初次在可控时间内跑出了8k级别的矩阵乘法。

## [ⅢOpenMP优化](https://blog.csdn.net/zhongkejingwang/article/details/40350027?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-40350027-blog-53177078.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-40350027-blog-53177078.pc_relevant_default&utm_relevant_index=1)

理论操作起来比较简单，只要`#include "omp.h"`之后再在for上面一行加上`#pragma omp parallel for`即可使多个cpu并行计算，但是实际测速却发现是3.147000左右，明显大于不并行计算，原来是因为多个cpu同时工作使得clock()重复计算了多次时间，因此在这里决定将所有clock()更换为ftime()来计时。

加上OpenMP后发现并没有任何提升，一番查找后才知道原来不仅要在头文件中include，还需要在cmake中调用OpenMP的包：

```cmake
FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
endif()
```

硬件优化：

|         | 1    | 2    | 3    | 平均        |
| ------- | ---- | ---- | ---- | ----------- |
| 128×128 | 7    | 8    | 6    | 7           |
| 1k×1k   | 2664 | 2767 | 2613 | 2681.333333 |

==硬件优化+OpenMP==：

|         | 1    | 2    | 3    | 平均 |
| ------- | ---- | ---- | ---- | ---- |
| 128×128 | 2    | 2    | 2    | 2    |
| 1k×1k   | 528  | 539  | 571  | 546  |

==硬件优化+OpenMP+O3==：

|       | 1     | 2     | 3     | 平均  |
| ----- | ----- | ----- | ----- | ----- |
| 1k×1k | 33    | 34    | 32    | 33    |
| 8k×8k | 52260 | 55465 | 53345 | 53690 |

可以看到使用OpenMP优化后花费时间又降了一大层级。

## ⅣSIMD优化

将第二个矩阵转置，使得寄存器读取数据的时候访问是连续的，然后八个八个地把数据存入寄存器，做乘积，再依次放入存放结果的数组中：

<img src="C:\Users\27449\Desktop\学习\typora图片\4EFF45BAB6665E2F04036DFCF3F9CC60.png" alt="4EFF45BAB6665E2F04036DFCF3F9CC60" style="zoom:50%;" />

```cpp
float * tem= NULL;
tem = malloc(8*sizeof (int ));
__m256 load1 = _mm256_setzero_ps();
__m256 load2 = _mm256_setzero_ps();
__m256 sum = _mm256_setzero_ps();
size_t index = 0;
size_t row = 0;
size_t i = 0,j = 0;
while (i<mat1->row) {
    for (int k = 0; k < mat1->column; k+=8) {
        load1 = _mm256_loadu_ps(&mat1->data[i*mat1->column+k]);
        load2 = _mm256_loadu_ps(&mat3->data[j*mat3->column+k]);
        sum = _mm256_mul_ps(load1,load2);
        _mm256_storeu_ps(tem, sum);
        for (int l = 0; l < 8; ++l) {
            array[i*c+j] += tem[i];
        }
    }
    j++;
    if (j>=mat3->row){
        j = 0;
        i++;
    }
}
```

### 数据测试

`matmul_plain`：

|         | 1    | 2    | 3    | 平均     |
| ------- | ---- | ---- | ---- | -------- |
| 128×128 | 8    | 12   | 8    | 9.333333 |
| 1k×1k   | 4325 | 4495 | 4227 | 4349     |

==avx+O3==：

|         | 1    | 2    | 3    | 平均        |
| ------- | ---- | ---- | ---- | ----------- |
| 128×128 | 7    | 6    | 6    | 6.333333    |
| 1k×1k   | 2641 | 2734 | 2679 | 2684.666667 |

硬件优化+O3+openMP：

|       | 1     | 2     | 3     | 平均  |
| ----- | ----- | ----- | ----- | ----- |
| 1k×1k | 33    | 34    | 32    | 33    |
| 8k×8k | 52260 | 55465 | 53345 | 53690 |

==avx+O3+openMP==（openMP提升不显著）：

|         | 1    | 2    | 3    | 平均        |
| ------- | ---- | ---- | ---- | ----------- |
| 128×128 | 6    | 7    | 6    | 6.333333    |
| 1k×1k   | 2640 | 2643 | 2789 | 2684.666667 |

## Ⅴ算法优化

### Strassen算法

在网上搜索矩阵乘法的优化算法，映入眼帘的首先就是**Strassen算法**。

> *斯特拉森算法把原先普通二阶矩阵相乘需要的8次乘法压缩到7次乘法，而在计算机，乘法运算的耗时远远高于加减运算，所以斯特拉森算法可以将O(d^ 3) 压缩到O(d^2.8)。*
>
> *需要知道的是，斯特拉森算法只是对矩阵分治的算法而不是单独的乘法算法，分治完成时最后使用的还是普通矩阵乘法，在阶数小于等于32（或者64？看过不同的实验结果）时普通的矩阵乘法会有更快的速度，而随着矩阵的阶不断增加，斯特拉森可以提供更快的速度。*

本质为分治思想，将矩阵乘法不断迭代直至目标矩阵阶数小于32或64。

*※拓展到其他矩阵：使用补零法向下向右补零，使得矩阵为偶数阶方阵。*

```cpp
matrix *strassen(const matrix *mat1, const matrix *mat2) {
    if (mat1->row != mat2->column)return matmul_improved(mat1, mat2);
    size_t row1 = mat1->row;
    size_t row2 = mat2->row;
    size_t column1 = mat1->column;
    size_t column2 = mat2->column;
    if (row1 % 2 != 0 || column1 % 2 != 0)return matmul_improved(mat1, mat2);
    if (mat1->column <= 32)return matmul_improved(mat1, mat2);
    size_t newSize = mat1->row / 2;
    size_t rXc = row1 * column2;
    float *data1 = mat1->data;
    float *data2 = mat2->data;
    float *a11 = malloc(rXc * sizeof(float));
    float *a12 = malloc(rXc * sizeof(float));
    float *a21 = malloc(rXc * sizeof(float));
    float *a22 = malloc(rXc * sizeof(float));
    float *b11 = malloc(rXc * sizeof(float));
    float *b12 = malloc(rXc * sizeof(float));
    float *b21 = malloc(rXc * sizeof(float));
    float *b22 = malloc(rXc * sizeof(float));
    matrix *c11 = NULL;
    matrix *c12 = NULL;
    matrix *c21 = NULL;
    matrix *c22 = NULL;

    matrix *m1 = NULL;
    matrix *m2 = NULL;
    matrix *m3 = NULL;
    matrix *m4 = NULL;
    matrix *m5 = NULL;
    matrix *m6 = NULL;
    matrix *m7 = NULL;


    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            a11[i * newSize + j] = data1[i * newSize + j];
            a12[i * newSize + j] = data1[i * newSize + j + newSize];
            a21[i * newSize + j] = data1[(i + newSize) * newSize + j];
            a22[i * newSize + j] = data1[(i + newSize) * newSize + j + newSize];
            b11[i * newSize + j] = data2[i * newSize + j];
            b12[i * newSize + j] = data2[i * newSize + j + newSize];
            b21[i * newSize + j] = data2[(i + newSize) * newSize + j];
            b22[i * newSize + j] = data2[(i + newSize) * newSize + j + newSize];
        }
    }
    matrix *A11 = createMatrix(newSize, newSize, a11);
    free(a11);
    matrix *A12 = createMatrix(newSize, newSize, a12);
    free(a12);
    matrix *A21 = createMatrix(newSize, newSize, a21);
    free(a21);
    matrix *A22 = createMatrix(newSize, newSize, a22);
    free(a22);
    matrix *B11 = createMatrix(newSize, newSize, b11);
    free(b11);
    matrix *B12 = createMatrix(newSize, newSize, b12);
    free(b12);
    matrix *B21 = createMatrix(newSize, newSize, b21);
    free(b21);
    matrix *B22 = createMatrix(newSize, newSize, b22);
    free(b22);

    matrix *tem1 = NULL, *tem2 = NULL;

    tem1 = addMatrix(A11, A22);
    tem2 = addMatrix(B11, B22);
    m1 = strassen(tem1, tem2);
    deleteMatrix(tem1);
    deleteMatrix(tem2);

    tem1 = addMatrix(A21, A22);
    m2 = strassen(tem1, B11);
    deleteMatrix(tem1);

    tem1 = subMatrix(B12, B22);
    m3 = strassen(tem1, A11);
    deleteMatrix(tem1);

    tem1 = subMatrix(B21, B11);
    m4 = strassen(tem1, A22);
    deleteMatrix(tem1);

    tem1 = addMatrix(A11, A12);
    m5 = strassen(tem1, B22);
    deleteMatrix(tem1);

    tem1 = subMatrix(A21, A11);
    tem2 = subMatrix(B11, B12);
    m6 = strassen(tem1, tem2);
    deleteMatrix(tem1);
    deleteMatrix(tem2);

    tem1 = subMatrix(A12, A22);
    tem2 = addMatrix(B21, B22);
    m7 = strassen(tem1, tem2);
    deleteMatrix(tem1);
    deleteMatrix(tem2);

    deleteMatrix(A11);
    deleteMatrix(A12);
    deleteMatrix(A21);
    deleteMatrix(A22);
    deleteMatrix(B11);
    deleteMatrix(B12);
    deleteMatrix(B21);
    deleteMatrix(B22);
    c11 = addMatrix(addMatrix(m1, m4), subMatrix(m7, m5));
    c12 = addMatrix(m3, m5);
    c21 = addMatrix(m2, m4);
    c22 = addMatrix(addMatrix(m1, m3), subMatrix(m6, m2));
    deleteMatrix(m1);
    deleteMatrix(m2);
    deleteMatrix(m3);
    deleteMatrix(m4);
    deleteMatrix(m5);
    deleteMatrix(m6);
    deleteMatrix(m7);
    float *resultData = malloc(rXc * sizeof(float));
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            resultData[i * newSize + j] = c11->data[i * newSize + j];
            resultData[i * newSize + j + newSize] = c12->data[i * newSize + j];
            resultData[(i + newSize) * newSize + j] = c21->data[i * newSize + j];
            resultData[(i + newSize) * newSize + j + newSize] = c22->data[i * newSize + j];
        }
    }
    matrix *result = createMatrix(mat1->row, mat2->column, resultData);
    deleteMatrix(c11);
    deleteMatrix(c12);
    deleteMatrix(c21);
    deleteMatrix(c22);
    free(resultData);
    return result;
}
```

### 数据测试

*※其中小于3的矩阵乘法直接使用硬件优化+O3+OpenMP后的乘法*

斯特拉森算法（32）：

|         | 1     | 2     | 3     | 平均       |
| ------- | ----- | ----- | ----- | ---------- |
| 128×128 | 396   | 424   | 394   | 404.666667 |
| 1k×1k   | 67218 | 68163 | 68772 | 68051      |

但是该算法存在精度丢失过大的问题，且在矩阵没有非常大时优化的时间并没有前面的几个方法来得显著，而矩阵非常大的时候又容易爆内存，得不偿失，因此最终没有把该算法加入综合优化中。

## Ⅵ`matmul_improved`综合优化

### 代码

综合使用了**硬件优化**、**O3优化**以及**OpenMP**优化：

```cpp
matrix *matmul_improved(const matrix *mat1, const matrix *mat2) {
    if (mat1 == NULL || mat1->column <= 0 || mat1->row <= 0 || mat1->data == NULL) {
        fprintf(stderr, "Error in \"mulMatrix\": Input a invalid matrix(left)");
        printFalse(mat1);
        return NULL;
    } else if (mat2 == NULL || mat2->column <= 0 || mat2->row <= 0 || mat2->data == NULL) {
        fprintf(stderr, "Error in \"mulMatrix\": Input a invalid matrix(right)");
        printFalse(mat2);
        return NULL;
    } else if (mat1->column != mat2->row) {
        fprintf(stderr, "Error in \"mulMatrix\": mat1's column(%d) not equal mat2's row(%d).\n", mat1->column,
                mat2->row);
        return NULL;
    }
    size_t r = mat1->row;
    size_t c = mat2->column;
    float *array = NULL;
    array = malloc(r * c * sizeof(float));
    if (array == NULL) {
        fprintf(stderr, "Error in \"mulMatrix\": Fail to malloc space for data.\n", mat1->column, mat2->row);
        return NULL;
    }
    float tem = 0;

#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < r; ++k) {
                tem = mat1->data[i * r + k];
                for (int j = 0; j < r; ++j) {
                    array[i * r + j] += tem * mat2->data[k * r + j];
                }
            }
        }
    }

    matrix *newMatrix = createMatrix(r, c, array);
    return newMatrix;
}
```

### 数据测试

|         | 1     | 2     | 3     | 平均  |
| ------- | ----- | ----- | ----- | ----- |
| 16×16   |       |       |       | 0     |
| 128×128 |       |       |       | 0.01  |
| 1k×1k   | 33    | 34    | 32    | 33    |
| 8k×8k   | 52260 | 55465 | 53345 | 53690 |

## Ⅷ数据生成与测试

### 数据生成

为方便测试，我将生成的例子直接存在`data.c`文件中，只要调用其中函数就能得到对应的一维数组。

```java
public class float随机生成 {
    public static void main(String[] args) throws IOException {
        int size = (int) Math.pow(8000,2);
        Random rdm = new Random();
        File matrix1 = new File("C:\\Users\\27449\\IdeaProjects\\lab8e_A\\src\\8k");
        FileWriter fl = new FileWriter(matrix1);
        for (int i = 0;i<size;i++){
            fl.write(rdm.nextFloat(100000)+"f,");
        }
        fl.close();
    }
}
```

但是64kX64k实在太大了，我的cpu好像不支持创建这么大的数组。因此暂时先生成了以下几个例子的函数：

```cpp
float * data16X16();
float * data128X128();
float * data1kX1k();
float * data8kX8k();
```

最后发现貌似只需要最大的8kX8k就不需要前面的了，只需要改变size就行。

```cpp
int main() {
    size_t size = 8000;
    matrix * a = NULL;
    float * data = data8kX8k();
    a = createMatrix(size,size,data);
    struct matrix * m1 = NULL;
    //----要测试的函数----//(预编译)
    
    //------------------//
    deleteMatrix(m1);
    struct timeb tb;
    ftime(&tb);
    long start_time= tb.time*1000+tb.millitm;
    //----要测试的函数----//
    
    //------------------//
    ftime(&tb);
    long end_time= tb.time*1000+tb.millitm;
    double rs=end_time-start_time;
    printf("rs=%f\n",rs);
    return 0;
}
```

### 数据测试

因为会用到openMP，所以clock()并不能适用于所有情况，因此统一使用ftime()来测函数的运行时间。

为了避免编译器**“太聪明”**自动优化了函数，所以每次测试都先跑一遍函数，然后计算接下来三次跑函数的时间取平均值作为该函数的使用时长。

```cpp
    m1 = matmul_plain(a,a);
    deleteMatrix(m1);
    struct timeb tb;
    ftime(&tb);
    long start_time= tb.time*1000+tb.millitm;
    m1 = matmul_plain(a,a);
    ftime(&tb);
    long end_time= tb.time*1000+tb.millitm;
    double rs=end_time-start_time;
    printf("rs=%f\n",rs);
```

## Ⅶ[OpenBlas数据比较](https://github.com/xianyi/OpenBLAS)

| 单位：ms        | 16×16 | 128×128 | 1k×1k | 8k×8k | 10k×10k |
| --------------- | ----- | ------- | ----- | ----- | ------- |
| matmul_improved | 0     | 1       | 32    | 53690 | 111500  |
| OpenBlas        | 10    | 13      | 33    | 9095  | 16545   |

可以看到在矩阵较小时openBlas会稍慢些，但矩阵超过1k阶之后openBlas慢慢显现出优势，到10k阶的时候已经差了近10倍。

## Ⅸ(附)对pro3中的函数进行的小优化

### 结构体

`long row `----->`size_t row`

`size_t`有更好的兼容性，并且没有正负号，而row和column必须为非负数。



`struct matrix{};`----->`typedef struct matrix{}matrix;`

更方便，不冗杂。

### 打印错误

`printf`----->`fprint(stderr,"...")`

打印错误

### createMatrix

更改后：

```cpp
matrix *createMatrix(const size_t r, const size_t c, float * data) {
    if (data == NULL) {
        fprintf(stderr,"Error in \"createMatrix\": Pointer is NULL.\n");
        return NULL;
    } else if (r * c == 0 || data == NULL) {
        fprintf(stderr,"Error in \"createMatrix\": Matrix is empty.\n");
        return NULL;
    }
    matrix *newMat = NULL;
    newMat = (matrix *) malloc(sizeof (matrix));
    if(newMat == NULL){
        fprintf(stderr,"Error in \"createMatrix\": Fail to malloc space for mat pointer.\n");
        return NULL;
    }
    newMat->row = r;
    newMat->column = c;
    float *saveData = NULL;
    saveData = (float *) malloc(r * c * sizeof(float));
    if(saveData == NULL){
        fprintf(stderr,"Error in \"createMatrix\": Fail to malloc space for data pointer.\n");
        free(newMat);
        return NULL;
    }
    for (size_t i = 0; i < r * c; ++i)saveData[i] = data[i];
    newMat->data = saveData;
    refreshType(newMat);
    return newMat;
}
```

增加了对两次内存申请失败的判断，且第二次申请失败后，释放之前申请成功的内存。如此构成一个更加**“稳健”**的函数

### 内存申请

许多函数存在类似`float array[r*c]`的申请，这样内存管理会出现纰漏，正确做法应该是：

`float * array = NULL;`

新建指针时需要指向NULL，方便后续判断错误来源。

`array = malloc(r*c*(typeof(float)));`

分配动态内存

`if (!array){...}`

判断是否为空指针，若空了就是申请失败了

==后面如果还有其他判断，离开函数之前要把已申请的内存释放==


# CPP_Project5_Matrix_Class@Jiko

- **Name：纪可鸣**
- **SID：12112813**

仓库网址：https://github.com/JikoSchnee/SUSTECH_CS205_C-CPP_Project/tree/main/Project5

## 写在前面

本次project因为在有限时间内没有找到很好地能兼顾`兼容性强`(譬如两个不同数据类型的矩阵做运算)和`代码简便`(尽量减少重复的工作)的方法，因此分别使用非模板类和模板类两种方法来实现。

※*受篇幅限制，Project4中已出现过的错误处理、乘法加速等会一笔带过或者只在代码演示中呈现，并不会单独拎出来一个板块介绍。*

※*因为很多的思路是及其相似的，因此相同思路的仅挑选部分来介绍。*

## A.非类模板Matrix

### 写在前面

> #### 优点：
>
> 兼容性更强(可以自动地在类型之间进行切换)；适合编程水平较低的用户，大部分情况下需要考虑的东西少，等等。
>
> #### 缺点：
>
> 代码冗长而重复；更新其他数据或其他函数工作量大；不规范使用可能存在精度丢失，等等。

#### 核心思想

因为矩阵所需的数据类型的个数是在可控范围内可数的，例如本题要求的`unsigned char, short, int, float, double`仅5个，因此考虑让五个类型的指针都存在，但同时只有一个指针根据矩阵的类型(`type`)被分配内存，后续根据`type`的变化会同时更新指针的分配：

```cpp
    size_t rows;
    size_t cols;
    size_t type;
    unsigned char * ucP;    //type1
    short * shortP;         //type2
    int * intP;             //type3
    float * floatP;         //type4
    double * doubleP;       //type5
```

#### 函数一览

```cpp
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
unsigned char getUCData(size_t row,size_t col);
short getShortData(size_t row,size_t col);
int getIntData(size_t row,size_t col);
float getFloatData(size_t row,size_t col);
double getDoubleData(size_t row,size_t col);
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
JChannel & operator=(JChannel const &Mat);
bool operator==(JChannel const &Mat) const;
JChannel operator+=(JChannel const &Mat) = delete;
JChannel operator-=(JChannel const &Mat) = delete;
```

### 部分演示

#### Constructor

##### 思路详解

五个类型分别对应五个构造器，根据传入数组的指针类型自动进行选择。例如传入的是一个double类型的指针，那么定义`size_t type`为对应的`5`(对应数字参考 *C.零散的点---类型之间的转换*)，根据`type`来判定需要分配内存的指针是哪一个，分配内存并赋值。

##### 代码演示

以double类型为例

```cpp
JChannel::JChannel(size_t ROW, size_t COL, double *dataP) {
    rows = ROW;
    cols = COL;
    if (ROW == 0 || COL == 0) {
        std::cerr << "Error: Invalid size." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!dataP) {
        std::cerr << "Error: Input a nullptr data pointer." << std::endl;
        if (abortIfError)std::abort();
    }
    type = 5;
    try {
        if (type == 1) {
            ucP = new unsigned char[ROW * COL * sizeof(unsigned char)];
        } else if (type == 2) {
            shortP = new short[ROW * COL * sizeof(short)];
        } else if (type == 3) {
            intP = new int[ROW * COL * sizeof(int)];
        } else if (type == 4) {
            floatP = new float[ROW * COL * sizeof(float)];
        } else if (type == 5) {
            doubleP = new double[ROW * COL * sizeof(double)];
        } else {
            std::cerr << "Error: Invalid data type." << std::endl;
            if (abortIfError)std::abort();
        }
    }
    catch (std::bad_alloc &ba) {
        std::cerr << ba.what() << std::endl;
    }
    try {
        if (type == 1) {
            memcpy(ucP, dataP, ROW * COL * sizeof(unsigned char));
        } else if (type == 2) {
            memcpy(shortP, dataP, ROW * COL * sizeof(short));
        } else if (type == 3) {
            memcpy(intP, dataP, ROW * COL * sizeof(int));
        } else if (type == 4) {
            memcpy(floatP, dataP, ROW * COL * sizeof(float));
        } else if (type == 5) {
            memcpy(doubleP, dataP, ROW * COL * sizeof(double));
        } else {

        }
    }
    catch (std::exception e) {
        std::cerr << e.what() << std::endl;
        delete[] dataP;
    }
}
```

#### Getter and Setter

##### 思路详解

对应的矩阵需要对应的getter，如果对一个double类型的矩阵使用了int类型的get，那么会返回错误提示(并终止程序)，反之才会返回正确的值。

对应矩阵的setter跟构造器思路类似，先检测输入的类型是否与矩阵匹配，而后再对其对应位置赋值。

##### 代码演示

以double为例

```cpp
double JChannel::getDoubleData(size_t row, size_t col) {
    if (type != 5) {
        std::cerr << "Error: The matrix type is not double." << std::endl;
        if (abortIfError)std::abort();
        return 0;
    }
    return doubleP[(row - 1) * cols + (col - 1)];
}
```

#### Operator*

##### 思路详解

通过获取结果矩阵的类型(详见 *C.零散的点---类型之间的转换*)，根据不同的类型获得结果矩阵的数组，并依次创建矩阵。

##### 代码演示

省略了重复的部分

```cpp
JChannel JChannel::operator*(const JChannel &Mat) const {
    if (rows != Mat.cols || cols != Mat.rows) {
        std::cerr << "Error: Invalid to multiply this two matrix." << std::endl;
        if (abortIfError)std::abort();
    }
    size_t r = rows;
    size_t c = Mat.cols;
    size_t resultType = type > Mat.type ? type : Mat.type;
    if (type == 1) {
        unsigned char *data = nullptr;
        try {
            data = new unsigned char[r * c * sizeof(unsigned char)];
        } catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
        }
        unsigned char tem = 0;
#pragma omp parallel for num_threads(16)
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < r; ++k) {
                tem = this->ucP[i * r + k];
                for (int j = 0; j < r; ++j) {
                    data[i * r + j] += tem * Mat.ucP[k * r + j];
                }
            }
        }
        JChannel result = JChannel(r, c, data);
        delete[] data;
        return result;
    }
    //...
    } else {
        std::cerr << "Error: Multiplying an unknown type matrix." << std::endl;
        if (abortIfError)std::abort();
    }
}
```

#### Operator+

##### 思路详解

获取结果矩阵的类型，开一个tem来存放单个数据，一个结果数组来存放所有数据，最后根据两个矩阵的类型分别加上对应的数据，再根据这一数组来创建矩阵并返回。

##### 代码演示

省略了重复部分

```cpp
JChannel JChannel::operator+(const JChannel &Mat) const {
    if (rows != Mat.rows || cols != Mat.cols) {
        std::cerr << "Error: Adding two matrix whose rows and cols are not match." << std::endl;
        if (abortIfError)std::abort();
    }
    if (type != Mat.type && accuracyWarning) {
        std::cerr << "Warning: Adding two different types of matrix may cause accuracy loss." << std::endl;
    }
    size_t resultType = 0;
    resultType = type > Mat.type ? type : Mat.type;
    if (resultType == 0) {
        std::cerr << "Error: Adding result is an unknown type matrix." << std::endl;
        if (abortIfError)std::abort();
    }
    if (resultType == 1) {
        unsigned char *data = nullptr;
        try {
            data = new unsigned char[rows * cols * sizeof(unsigned char)];
        }
        catch (std::bad_alloc &ba) {
            std::cerr << ba.what() << std::endl;
            if (abortIfError)std::abort();
        }
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0;
        }
        if (type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += ucP[i];
            }
        } else {
            //...
        }
        if (Mat.type == 1) {
            for (int i = 0; i < rows * cols; ++i) {
                data[i] += Mat.ucP[i];
            }
        } else {
            //...
        }
        JChannel result = JChannel(rows, cols, data);
        delete[] data;
        return result;
    }
    } else {
        //...
    }
}
```

## B.类模板Matrix

> #### 优点：
>
> 通过类模板可以直接适用更多数据类型，例如long、char等等；优化与更新方便，等等。
>
> #### 缺点：
>
> 在速度优化以及遇到两个不同类型矩阵做运算的时候所需的工作量特别大，实现难度也大，等等。

### 写在前面

#### 核心思想

在正规的操作中，不同类型的矩阵之间的运算是不应该存在的(存在精度丢失)，因此在保证使用者水平的情况下，并不需要兼容两个不同类型的矩阵之间运算的情况的，因此在模板类Matrix中并没有考虑这种情况，而是将经理集中在模板上。

### 操作符重载

#### operator=

使用了`std::shared_ptr`来避免`hardcopy`

```cpp
JChannel2 &operator=(const JChannel2 &mat) {
        auto sp = std::shared_ptr<JChannel2<T>>(mat);
        return sp;
    }
```

#### operator==

```cpp
bool operator==(const JChannel2 &mat) {
    if (row != mat.row||column!=mat.column)return false;
    for (int i = 0; i < row*column; ++i) {
        if (this->data[i]!=mat.data[i])return false;
    }
    return true;
}
```

#### operator<<

##### Problem Occured:

由于矩阵类是一个模板类，所以其函数也需要使用模板，但在重载`<<`时函数又应为友元函数，在这样神奇的组合下会出现错误提示：

`friend declaration 'std::ostream& operator<<(std::ostream&, const JMatrix<dataType>&)' declares a non-template function [-Wnon-template-friend]`

##### Problem Solving:

> [这类友元函数通常带有参数，并且参数中**含有模板类定义的类型变量，**例如：friend void Fn(MyClass<T> &n)。由于我们不将该函数视为模板函数，因此**对模板类的每个实例化版本都需要提供该函数的一个重载版本**。](https://blog.csdn.net/liujun3512159/article/details/123039906)

```cpp
std::ostream &operator<<(std::ostream &os, const JMatrix<int> &t) {
    os<< typeid(t.data[0]).name()<<" int"<<" matrix with "<<t.row<<" rows and "<<t.column<<" columns and "<<t.channel<<" channels.";
    return os;
}
```

~~以int类型为例，一个打印最基本信息的函数这样生成，其他n-1种类型如法炮制，但这样如果要修改文字内容的话就需要修改n次太过繁杂，因此这里使用了一个`toString()`函数来把基本信息转换为string类型。(由于不会被用户使用到，因此`toString()`并没有在头文件中声明)~~

**但是**我发现不把函数的声明和定义分开到`.cpp`和`.h`中，直接在类里面写就不会出现这个问题(?)，仔细一想貌似一些比较短的函数也没有分开写的必要，所以自此决定把大部分函数例如运算符重载以及一些简单的`get`函数都直接写在类里面了。

## C.零散的点

### 通道

根据[网页](https://blog.csdn.net/MRZHUGH/article/details/83538805)的解读，我的理解是以往理解的矩阵是一个二维平面，而通道数描述了平面的个数，构成一个三维的矩阵，因此将以往理解的矩阵称为JChannel，将矩阵用另一个类JMatrix嵌套JChannel实现：

```cpp
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
```

调用JChannel的函数例子：

```cpp
double JMatrix::getDoubleData(size_t channel, size_t row, size_t col) {
    if (channel<1||channel>chans){
        std::cerr << "Error: Getting channel out of index." << std::endl;
        if (abortIfError)std::abort();
    }
    if (!channels[channel-1]){
        std::cerr << "Error: Getting channel that is empty." << std::endl;
        if (abortIfError)std::abort();
    }
    return channels[channel-1]->getDoubleData(row,col);
}
```

### 类型之间的转换

遵循c++自带的隐式转换原则，利用auto得到5个数据的10个不同组合转换后的结果：

`auto type = type1 a + type2 b;`

```c++
unsigned char + short = i
unsigned char + int = i
unsigned char + float = f
unsigned char + double = d
short + int = i
short + float = f
short + double = d
int + float = f
int + double = d
float + double = d
```

五个类型对应的type数字分别为1，2，3，4，5，因此刚好在两个矩阵运算时，取type较大的那一个作为结果的type即可。（如int+float=float，int为3，float为4，即在3和4中取最大值4，也就是float作为结果的类型）

### 错误流提示

```cpp
        std::cerr << "Error: ..." << std::endl;
        if (abortIfError)std::abort();
```

```cpp
std::cerr << "Warning: Adding two different types of matrix may cause accuracy loss." 
          << std::endl;
```

使用了标准错误流输出来报错，并且仿照`assert`的形式(虽然不显示assert是在编译层面而这里是在运行层面)，可以通过把全局变量`abortIfError`改成`false`来让程序即使遇到错误也会继续运行下去；同理可以把`accuracyWarning`改成`false`来让程序不提示存在精度丢失的情况。

### try catch

在申请内存的时候均使用了`try catch`函数

```cpp
    try {
        if (type == 1) {
            ucP = new unsigned char[ROW * COL * sizeof(unsigned char)];
        } else if (type == 2) {
            shortP = new short[ROW * COL * sizeof(short)];
        } else if (type == 3) {
            intP = new int[ROW * COL * sizeof(int)];
        } else if (type == 4) {
            floatP = new float[ROW * COL * sizeof(float)];
        } else if (type == 5) {
            doubleP = new double[ROW * COL * sizeof(double)];
        } else {
            std::cerr << "Error: Invalid data type." << std::endl;
            if (abortIfError)std::abort();
        }
    }
    catch (std::bad_alloc &ba) {
        std::cerr << ba.what() << std::endl;
    }
```

## D.总结

类模板虽然能隐式地实现更多种情况，但是在不同模板类之间的交互和乘法的加速就变得非常困难，而不使用类模板在除了交互之外的函数实现都需要许多重复，仅适用情况少的时候(例如本题要求的五个数据类型)。也许嵌套的类模板能够结合二者的优点，但经过多次尝试仍然没有办法实现在一个类中含两个或以上typename的情况，因此最终决定两个方法都写一遍体会一下差别。

最终使用类模板的代码仅几百行，不使用类模板的已经近千行，~~而且写完不使用类模板的完全不想再看再碰了~~，希望能在未来的学习中能解决这个问题。

转眼一学期过去已经是最后一次Project了，想当初听闻于老师CPP课的“恐怖”以及第一次project的洗礼几度欲放弃，幸好最后坚持下来了，在后来的日子里不仅深刻感受到于老师课程的有趣，同时也学到了很多非常有用的东西。总之非常感谢于老师这一学期的教导！






