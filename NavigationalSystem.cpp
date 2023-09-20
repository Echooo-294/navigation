
#include"Graph.h"
using namespace std;
void Time(Edge* E, Graph G)
{

    for (int i = 0; i < G.GetEdgeNums(); i += 2) {
        if (E[i].flow <= E[i].capacity) E[i].reallength = double(E[i].length / 50);
        else
        {
            double x = E[i].flow / E[i].capacity;
            E[i].reallength = double(E[i].length / 50 * (1 + exp(x)));
        }

    }
}


vector<int> dij(int start, int end, Graph* Gp)
{
    vector<int> path;
    auto G = Gp->GraphHead();
    int n = Gp->GetPointNums();
    vector<double> d(n + 1);

    priority_queue<pair<double, int>>hp;
    hp.push({ 0,start });
    vector<int>fa(n + 1);
    vector<bool>vis(n + 1);
    while (!hp.empty()) {
        auto [len, now] = hp.top();
        hp.pop();
        if (vis[now]) continue;
        d[now] = -len;
        vis[now] = 1;
        if (now == end) {
            while (now != start) {
                path.push_back(now);
                now = fa[now];
            }
            path.push_back(start);
            return path;
        }
        for (auto [to, e] : G[now]) {
            if (vis[to]) continue;
            double ll = len - Gp->E[e].reallength;
            hp.push({ ll,to });
            if (ll < d[to]) fa[to] = now;
            d[to] = min(d[to], -ll);
        }
    }
    return path;
}





