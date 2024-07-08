# 给定字符串求不同子串数量问题 (SA+LCP or SAM)

> 初探高级字符串问题

## 题目连接

下面两个题的区别在于字符串长度的范围，和单/多测形式

[洛谷 P2408 不同子串个数](https://www.luogu.com.cn/problem/P2408)

[2024 年华为杯广东工业大学程序设计竞赛-牛客同步赛-H](https://ac.nowcoder.com/acm/contest/79664/H)

## 题目描述

给定一个字符串 s, 求 s 有多少个不同的子串。
## SAM 后缀自动机求解

参考连接：[OI Wiki 字符串-后缀自动机 (SAM)](https://oi-wiki.org/string/sam/)

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
string s;
int n;
int sz, last;
ll dp[N];
struct node {
    int son[26];
    int father;
    int len;
}t[N << 1];
void newNode(int length) {
    t[++sz].len = length;
    t[sz].father = -1;
    memset(t[sz].son, 0, sizeof(t[sz].son));
}
void init() {
    sz = -1; last = 0;
    newNode(0);
}
void Insert(int c) {
    newNode(t[last].len + 1);
    int p = last, cur = sz;
    while (p != -1 && !t[p].son[c]) {
        t[p].son[c] = cur, p = t[p].father;
    }
    if (p == -1)
        t[cur].father = 0;
    else {
        int q = t[p].son[c];
        if (t[q].len == t[p].len + 1)
            t[cur].father = q;
        else {
            newNode(t[p].len + 1);
            int nq = sz;
            memcpy(t[nq].son, t[q].son, sizeof(t[q].son));
            t[nq].father = t[q].father;
            t[cur].father = t[q].father = nq;
            while (p >= 0 && t[p].son[c] == q)
                t[p].son[c] = nq, p = t[p].father;
        }
    }
    last = cur;
}
void solve()
{
    cin >> n >> s;
    init();
    for (int i = 0; i < n; i++) {
        Insert(s[i] - 'a');
        dp[i] = dp[i - 1] + t[last].len - t[t[last].father].len;
    }
    cout << dp[n - 1] << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T_T = 1;
    // cin >> T_T;
    while (T_T--)
        solve();
    return 0;
}
```

## SA 后缀数组 + LCP （最长公共前缀） 求解

**利用 height 数组求解**

参考链接：[OI Wiki 字符串-后缀数组简介](https://oi-wiki.org/string/sa/)

子串就是后缀的前缀，所以可以枚举每个后缀，计算前缀总数，再减掉重复。

「前缀总数」其实就是子串个数，为 $ n(n+1)/2 $ 。

如果按后缀排序的顺序枚举后缀，每次新增的子串就是除了与上一个后缀的 LCP 剩下的前缀。这些前缀一定是新增的，否则会破坏 $ lcp(sa[i],sa[j])=\min\{height[i+1..j]\} $ 的性质。只有这些前缀是新增的，因为 LCP 部分在枚举上一个前缀时计算过了。

最终答案：
$$
ans = \frac{n(n+1)}{2} - \sum_{i=2}^{n}height[i]
$$

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
string s;
int n;
ll height[N];
int x[N], y[N], rk[N], c[N], sa[N];
void get_sa() {
    int m = 127;
    // 按照第一关键字排序
    for(int i = 1; i <= m; i++) c[i] = 0;
    for(int i = 1; i <= n; i++)  c[x[i] = s[i]]++;
    for(int i = 2; i <= m; i++) c[i] += c[i - 1];
    for(int i = n; i >= 1; i--) sa[c[x[i]]--] = i;
     
    for(int k = 1; k <= n; k *= 2) {
        // 1. 先按第二关键字排序
        // [n - k + 1, n] 这些后缀没有第二关键字，肯定排在前面
        int cnt = 0;
        for(int i = n; i > n - k; i--) y[++cnt] = i;
        for(int i = 1; i <= n; i++) {    // 排名   
            if(sa[i] > k) {      // 第 i 个后缀的第二关键字为第 i + k 个后缀的第一关键字
                y[++cnt] = sa[i] - k;
            }
        }
         
        // 2. 再按第一关键字排序
        for(int i = 1; i <= m; i++) c[i] = 0;
        for(int i = 1; i <= n; i++) c[x[i]]++;
        for(int i = 2; i <= m; i++) c[i] += c[i - 1];
        for(int i = n; i >= 1; i--) sa[c[x[y[i]]]--] = y[i], y[i] = 0;
         
        // 3. 离散化 [i, i + 2k]
        // swap(x, y);
        y[sa[1]] = 1, cnt = 1;
        for(int i = 2; i <= n; i++) {
            y[sa[i]] = (x[sa[i]] == x[sa[i - 1]] && 
                x[sa[i] + k] == x[sa[i - 1] + k]) ? cnt : ++cnt;
        }
        for(int i = 1; i <= n; i++) x[i] = y[i];
        if(cnt == n) break;
        m = cnt;
    }
}
void get_height() {
    for(int i = 1; i <= n; i++) rk[sa[i]] = i;
    for(int i = 1, k = 0; i <= n; i++) {
        if(rk[i] == 1) continue;
        if(k) k--;
        int j = sa[rk[i] - 1];
        while(i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }   
}
void solve() {
    cin >> n;
    cin >> s;
    s = "(" + s;
    get_sa();
    get_height();
    ll ans = (1LL + n) * n / 2;
    for (int i = 2; i <= n; i++) ans -= height[i];
    cout << ans << '\n';
}
int main()
{
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}
```