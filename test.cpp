#include <bits/stdc++.h>
using namespace std;
const int INF = 0x2a2a2a2a;
int dis[105][105], val[105][105];
int n, m;
int floyd() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) dis[i][j] = val[i][j];  //初始化最短路矩阵
    }
    int ans = INF;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i < k; ++i) {
            for (int j = 1; j < i; ++j)
                ans = min(ans, dis[i][j] + val[i][k] + val[k][j]);  //更新答案
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);  //floyd 更新最短路矩阵
        }
    }
    return ans;
}
int main()
{
    memset(val, INF, sizeof(val));
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        val[u][v] = val[v][u] = w;
    }
    int ans = floyd();
    if (ans == INF) cout << "No solution.";
    else cout << ans;
}