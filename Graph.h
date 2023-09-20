//随机函数,kd树主体,最短路函数等
// #include<bits/stdc++.h>
// #include<bits/extc++.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <map>
#include <windows.h>
#include <queue>
#include <random>
#include "BasicStruct.h"

// 也许并不需要
unsigned long long myrand(unsigned range = 0)
{
    static std::mt19937 rd(time(0));
    if (!range) return rd();
    return rd() % range;
}

namespace Solution{
    bool KDflg;
    void KDTree(std::vector<Point> &p, int l, int r)
    {
        if (l == r)
            return;
        int mid = l + (r - l) / 2;
        std::nth_element(p.begin() + l, p.begin() + mid, p.begin() + r, [](Point a, Point b) {
            if (KDflg) return a.x < b.x;
            else return a.y < b.y; });
        bool nowflg = KDflg;
        KDflg = nowflg ^ 1;
        KDTree(p, l, mid);
        KDflg = nowflg ^ 1;
        KDTree(p, mid + 1, r);
    }
}

class Graph
{
    bool Randflg;
    unsigned int PointNums;
    HANDLE RandFlowThread;
public:
    std::vector<std::vector<std::pair<int, int>>> G; // 这里记录两个数: first记录其目的点标号, second记录该边标号
    std::vector<Point> P; // 点池, 用来存放点的信息, 标号从1开始
    std::vector<Edge> E;  // 边池, 用来存放边的信息, 标号从0开始
    // 感觉不太需要这个构造函数. 可以设定为构造的时候一定要制定点数.
    // Graph() {}
private:
    // 辅助函数, 增加边
    void AddEdge(int u, int v)
    {
        double _dis = distance(P[u], P[v]);
        int _cap = (int)(myrand(RAND_MAX) * 1.0 / RAND_MAX + 1) * (int)(_dis) / 20 + myrand(37) + 79;
        E.push_back(Edge(u, v, _dis, _cap, _cap * 2 / 5));
        G[u].push_back({v, (int)E.size() - 1});
        E.push_back(Edge(v, u, _dis, _cap, _cap * 2 / 5));
        G[v].push_back({u, (int)E.size() - 1});
    }

    // 测试最短路
    // n是当前结点, f是n的父节点.
    std::vector<bool> dfsvis;
    void dfshp(int n, int f)
    {
        dfsvis[n] = 1;
        std::cout << n << ' ' << f << '\n';
        for (auto [to, e] : G[n])
        {
            if (dfsvis[to])
                continue;
            printf("%d ---> %d : %d/%d (%lf)\n", n, to, E[e].flow, E[e].capacity, 1.0 * E[e].flow / E[e].capacity);
            dfshp(to, n);
        }
    }

public:
    // 构造一个点数为n的图, 要求尽量合理
    Graph(int __n)
    {
        int row = sqrt(__n), col = __n / row;
        __n = row * col; // 分块后重置__n大小
        PointNums = __n;
        int sqn = pow(__n, 0.6);
        srand(time(0));    // 设置随机种子
        G.resize(__n + 1); // 给图分配邻接链表空间
        P.resize(__n + 1); // 给点分配空间

        // 按照行列分块, 初始化各个点的整型值
        int rlimit = RAND_MAX / row, climit = RAND_MAX / col;
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                int now = j + (i - 1) * col;
                P[now].x = myrand(rlimit) + (i - 1) * rlimit;
                P[now].y = myrand(climit) + (j - 1) * climit;
            }
        }
        // 初始化各个点的浮点值
        for (int i = 1; i <= __n; ++i)
        {
            P[i].x += 1.0 * myrand(RAND_MAX) / ((int)RAND_MAX), P[i].y += 1.0 * myrand(RAND_MAX) / ((int)RAND_MAX);
        }

        // 利用KD树, 将这棵树进行一些划分, 便于后面的s_t前粗调跳转.
        Solution::KDTree(P, 1, __n);
        int Max_dis = std::max({distance(P[1], P[__n]), distance(P[__n / 2], P[__n]), distance(P[1], P[__n / 2])});
        Max_dis = pow(Max_dis, 0.8);

        for (int i = 2; i <= __n; ++i)
        {
            std::vector<std::pair<int, int>> __qq;
            int s_t = std::max(1, i - (int)pow(__n, 0.7));
            for (int j = 1; j < i; ++j)
            {
                if (__qq.size() < 2)
                    __qq.push_back({(int)distance(P[i], P[j]), j}); // 设置当前点向前连边最多2条
                else
                { // 这里进行选取最短边, 然后1/sqn的概率不把较小边放入选择, 1/sqn的概率把待选的最大边放回去
                    int _dis = distance(P[i], P[j]);
                    if (_dis < __qq.front().first && myrand(__n) < sqn)
                        continue;
                    std::pair<int, int> now = {_dis, j};
                    for (int k = 0; k < (int)__qq.size(); ++k) // 挑选较小边.
                    {
                        if (__qq[k].first > _dis) // 一定程度保留较大边.
                            swap(__qq[k], now);
                    }
                    if (myrand(__n) < sqn)
                        swap(now, __qq.back());
                }
                if (!__qq.empty() && (myrand(__n) < sqn))
                    __qq.pop_back();
                if (j < s_t)
                    j += pow(__n, 0.2); // 在sqn的范围之前进行粗调跳跃
            }

            for (auto [_dis, t_o] : __qq)
            {
                if (_dis > Max_dis && myrand(__n) > sqn) // 一定程度减少加边.
                    continue;
                AddEdge(i, t_o);
            }
        }
    }
    ~Graph() {}

    // 返回输入点附近的100个点的标号
    std::vector<int> GetClosestPoints(Point Now_p)
    {
        std::vector<int> ret;
        std::priority_queue<std::pair<double, int> > pq; // 存放100个点的堆.

        for (int i = 1; i <= (int)PointNums; ++i) {
            pq.push({distance(P[i], Now_p), i}); // priority_queue默认大顶堆
            if (pq.size() > 100) pq.pop();
        }

        // 把最近的至多100个点放入ret返回.
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            ret.push_back(x.second);
        }
        return ret;
    }

    // 返回邻接链表的头指针
    std::vector<std::vector<std::pair<int, int>>>::iterator GraphHead()
    {
        return G.begin();
    }
    // 返回点池的首指针
    std::vector<Point>::iterator PointHead()
    {
        return P.begin();
    }
    // 返回边池的首指针
    std::vector<Edge>::iterator EdgeHead()
    {
        return E.begin();
    }
    // 返回图中点的数目
    unsigned GetPointNums()
    {
        return PointNums;
    }
    // 返回图中边的数目
    unsigned GetEdgeNums()
    {
        return (unsigned)E.size();
    }

    // 随机函数进行随机的流的分配
    DWORD WINAPI static RandFlow(LPVOID lpParameter)
    {
        // 将无类型指针 lpParameter 转换为所需要的 Graph 指针. 然后在图上进行随机修改
        Graph *This = (Graph *)lpParameter;
        while (This->Randflg)
        {
            // 遍历所有的边进行随机修改.
            for (int i = 0; i < (int)This->E.size(); i += 2)
            {
                // 先进行一个至多 0.76 次方的随机上下浮动
                This->E[i].flow += ((int)myrand() - (int)myrand()) % ((int)pow(This->E[i].flow, 0.76) + 1);

                // 处理向下溢出的情况(flow 是 unsigned 的)
                if (This->E[i].flow > 100000000)
                    This->E[i].flow = std::max(0u, This->E[i].flow + std::min(0u, (unsigned int)sqrt(This->E[i].capacity)));
                // 处理 flow 超出2倍的 capacity 的情况.
                if (This->E[i].flow > This->E[i].capacity * 2)
                    This->E[i].flow = std::min(This->E[i].capacity * 2, This->E[i].flow - (int)sqrt(This->E[i].capacity * 2));
                // 处理无向图的另一条对应的边.
                This->E[i + 1].flow = This->E[i].flow;
            }
            Sleep(1000);
        }
    }
    // 创建一个进程来改变flow
    void StartRandFlow()
    {
        Randflg = 1;
        // 把线程id放在类里, 到时候看一下怎么搞这个线程.
        RandFlowThread = CreateThread(NULL, 0, RandFlow, this, 0, NULL);
    }

    void StopRandFlow()
    {
        Randflg = 0;
    }

    //实际最短路转换函数

    void Time(std::vector<Edge>::iterator E, Graph *G)
    {

        for (int i = 0; i < (int)G->GetEdgeNums(); i += 1)
        {
            if (E[i].flow <= E[i].capacity)
                E[i].reallength = E[i].length / 50;
            else
            {
                double x = (double)E[i].flow / E[i].capacity;
                E[i].reallength = E[i].length / 50 * (1 + exp(x));
            }
        }
    }

    // dij（起点点号，终点点号，图指针）
    // bool类型用来确定计算时间还是距离true表示计算时间即reallength false表示物理距离length，引用参数totallength表示最短路径的通行所需时间或距离根据bool决定）
    //返回最短路路径；
    std::vector<int> dij(int start, int end, Graph *Gp, bool time, double &distance, double &tim)
    {
        tim = 0;
        distance = 0;
        auto E = Gp->EdgeHead();
        std::vector<int> path;
        auto G = Gp->GraphHead();
        int n = Gp->GetPointNums();
        Time(E, Gp);
        std::vector<double> d(n + 1, 1000000000);
        std::priority_queue<std::pair<double, std::pair<int, int>>> hp;
        hp.push({0, {start, 0}});
        std::vector<int> fa(n + 1);
        std::vector<bool> vis(n + 1);
        while (!hp.empty())
        {
            auto [len, nowe] = hp.top();
            auto [now, fae] = nowe;
            hp.pop();
            if (vis[now])
                continue;
            d[now] = -len;
            fa[now] = fae;
            vis[now] = 1;
            for (auto [to, e] : G[now])
            {
                if (vis[to])
                    continue;
                double ll = 0;
                if (time)
                    ll = len - E[e].reallength;
                else
                    ll = len - E[e].length;
                hp.push({ll, {to, e}});
            }
            if (now == end)
            {
                while (now != start)
                {

                    path.push_back(fa[now]);
                    now = E[fa[now]].P1;
                }

                for (int i = 0; i < (int)path.size(); i++)
                {

                    tim += E[path[i]].reallength;

                    distance += E[path[i]].length;
                }

                return path;
            }
        }

        return path;
    }

    void dfsshow()
    {
        dfsvis.resize(PointNums + 1, 0);
        dfshp(1, 0);
    }
};
