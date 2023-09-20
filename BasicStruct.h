/*
 * 地图的三种基础类:
 * vector向量运算类
 * point点类,内含距离计算和向量计算成员函数
 * edge类,数据成员为边链接的两点编号,路的长度和真实长度,可容纳数目capacity以及当前车流量flow,内有构造函数
*/
#include<cmath>

struct Vector{
    double x, y;
    Vector() {x = y = 0;}
    Vector(double x, double y): x(x), y(y) {};

    // 向量相减
    friend Vector operator -(Vector a, Vector b) {
        return Vector(a.x - b.x, a.y - b.y);
    }
    // 向量相加
    friend Vector operator +(Vector a, Vector b) {
        return Vector(a.x + b.x, a.y + b.y);
    }
    // 叉积, 返回的是z轴方向的double量
    friend double operator *(Vector a, Vector b) {
        return a.x * b.y - a.y * b.x;
    }
};

struct Point{
    double x, y;
    // 两点之间的距离
    friend double distance(Point a, Point b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }
    // 两点相减得到一个向量
    friend Vector operator -(Point a, Point b) {
        return Vector(a.x - b.x, a.y - b.y);
    }
};

struct Edge{
    int P1, P2;
    double length, reallength;
    unsigned capacity, flow;
    Edge() {flow = length = 0;}
    Edge(int a, int b, double dis, int cap, int f = 0):P1(a), P2(b), length(dis), capacity(cap), flow(f) {}
};
