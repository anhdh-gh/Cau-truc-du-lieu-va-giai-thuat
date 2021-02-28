#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

vector<pair<int, int>> graph[100005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> min_heap;

ll dist[100005];
ll f[100005];
int n, m;

void Init()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1e12;
    }
    dist[1] = 0;
    f[1] = 1;
}

void Dijkstra(int u)
{
    min_heap.push(make_pair(0, u));
    while (!min_heap.empty())
    {
        long long min_w = min_heap.top().first;
        int u = min_heap.top().second;
        min_heap.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            if (dist[v] == min_w + graph[u][i].second)
            {
                f[v] += f[u];
            }
            else if (dist[v] > min_w + graph[u][i].second)
            {
                dist[v] = min_w + graph[u][i].second;
                f[v] = f[u];
                min_heap.push(make_pair(dist[v], v));
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    Init();
    Dijkstra(1);
    cout << dist[n] << " " << f[n] << endl;
    return 0;
}