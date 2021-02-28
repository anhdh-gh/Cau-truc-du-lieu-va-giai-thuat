#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;

double wt[105][105];
int n;
double res = 0;
int father[105];

struct edge
{
    int u, v;
    double w;
    edge(int U, int V, double W)
    {
        u = U;
        v = V;
        w = W;
    }
};
vector<edge> graph;

double Chiphi(pair<double, double> a, pair<double, double> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

bool comp(edge u, edge v)
{
    return u.w < v.w;
}

int Cha(int u)
{
    while (father[u] > 0)
    {
        u = father[u];
    }
    return u;
}

void Hopnhat(int x, int y)
{
    x = Cha(x);
    y = Cha(y);
    if (x == y)
    {
        return;
    }
    if (father[x] < father[y])
    {
        father[x] += father[y];
        father[y] = x;
    }
    else
    {
        father[y] += father[x];
        father[x] = y;
    }
}

void Kruskal()
{
    sort(graph.begin(), graph.end(), comp);
    for (int i = 0; i < graph.size(); i++)
    {
        int u = Cha(graph[i].u);
        int v = Cha(graph[i].v);
        if (u != v)
        {
            Hopnhat(u, v);
            res += graph[i].w;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(father, -1, sizeof(father));
        vector<pair<double, double>> a(n + 5);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        graph.clear();
        res = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                wt[i][j] = Chiphi(a[i], a[j]);
                graph.push_back(edge(i, j, wt[i][j]));
            }
        }
        Kruskal();
        printf("%6lf\n", res);
    }
    return 0;
}