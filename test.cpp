#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int nex[N];
char s1[N]; //文本串 
char s2[N]; //模式串 
int n, m;//文本串和模式串的长度 
//下标从1开始
void getnex() {
    nex[1] = 0;
    int i, j = 0;
    for (i = 2; i <= m; i++) {
        while (j > 0 && s2[j + 1] != s2[i])j = nex[j];
        //如果回跳到第一个字符就不 用再回跳了
        if (s2[j + 1] == s2[i])j++;
        nex[i] = j;
    }
}
int kmp() {
    int i, j = 0;
    getnex();
    for (i = 1; i <= n; i++) {
        while (s1[i] != s2[j + 1] && j > 0)j = nex[j];
        //如果失配 ，那么就不断向回跳，直到可以继续匹配
        if (s1[i] == s2[j + 1])j++;
        //如果匹配成功，那么对应的模式串位置++ 
        if (j == m) {
            //输出所有出现位置的起始下标
            printf("%d ", i - m + 1);
            //注意下标，是从0还是1
            j = nex[j];//继续匹配 
        }
    }
}
