/*
 * @Description: 请填写简介
 * @Author: FLself (1483531320@qq.com)
 * @Date: 2022-03-16 12:00:20
 * @LastEditors: FLself (1483531320@qq.com)
 * @LastEditTime: 2022-04-09 15:22:16
 */
#include <bits/stdc++.h>
#include"Graph.h"
#define int long long
#define mp make_pair
#define pb push_back


using namespace std;
const int maxn = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

long long read() {
    long long ret = 0, flg = 1;
    char ch = getchar();
    while (!isdigit(ch) && ch != '-') ch = getchar();
    if (ch == '-') flg = -1, ch = getchar();
    while(isdigit(ch)) ret = ret * 10 + ch - '0', ch = getchar();
    return ret * flg;
}
// nb
// 输入起始点, 
double dij(int start, int End, Graph *Gp, vector<int>& path) {
    auto G = Gp->GraphHead();
    int n = Gp->GetPointNums();
    vector<double> d(n + 1);
     
    priority_queue<pair<double, int> > hp; // hp.top().first 存储的是start到点 hp.top().second 的距离
    hp.push({0, start});
    vector<int> fa(n + 1);
    vector<bool> vis(n + 1);

    while (!hp.empty()) {
        auto [len, now] = hp.top();
        hp.pop();
        if (vis[now]) continue;
        d[now] = -len;
        vis[now] = 1;

        if (now == End) {
            while (now != start) {
                path.push_back(now);
                now = fa[now];
            }
            path.push_back(start);
            return (-len);
        }
    
        for (auto [to, e]: G[now]) {
            if (vis[to]) continue;
            double ll = len - Gp->E[e].length;
            hp.push({ll, to});
            if (ll < d[to]) fa[to] = now;
            d[to] = min(d[to], -ll);
        }
    }
    return 1. * INF;
}

void solv() {
    Graph test(100);
    test.StartRandFlow();
    Sleep(1000);
    test.dfsshow();
}
signed main() {
    
        solv();
    return 0;
}
