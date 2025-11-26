## 作业题
```
int a[10];          // [一维数组]定义一个int型数组，长度为10
int b[][3]={...};   // [二维数组]列数为3，行数由初始化列表自动推导
int *p[];           // [指针数组]p是一个数组，数组中的每个元素都是int*类型的指针
int(*q)[];          // [数组指针]是一个指针，指向一个int类型的数组


/*
优先级：[] 的优先级高于 *。
q[]：q 先与 [] 结合，确立了它是数组的身份。
int *：剩下的部分说明数组里装的是什么——指向整数的指针。
*/

int(*u)(int,int);   // [函数指针]u是一个指针，指向一个接受一对(int,int)传入并返回int的函数
int*v(int,int);     // [指针函数]v是一个函数(声明)，接受(int,int)并返回int*类型的指针
int*(*w)(int,int);  // [函数指针]w是一个指
针，指向一个接受(int,int)并返回int*的函数
```
```
char *strpos(char *s, char *t) {
    char *j, *k;
    for (; *s; s++) { 
        for (j = s, k = t; *k && *j == *k; j++, k++); 
        if (k != t && *k == '\0') {
            return s; // 找到了，返回s当前的地址
        }
    }
    return NULL;//遍历完 还没找到，返回空指针
}
```
//在字符串s中查找另一字符串t即子串第一次出现的位置对应位置的指针

预测输出:

In main(1):a=2,c=37
In main(2):a=128,c=37

注：static int c = 20; 只会在程序开始运行时执行一次。

ABC
BAC
ACB
CAB
CBA
BCA

注：这里采用了dfs+回溯的思想
## 补充题
```
int min(int x, int y);
int (*p)(int, int)=min;
d=(*p)((*p)(a, b),c);

```