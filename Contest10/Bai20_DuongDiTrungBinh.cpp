#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> ke[105];
int dist[105];
int dinh, canh;

void ReInit()
{
    for (int i = 0; i < 105; i++)
    {
        ke[i].clear();
        dist[i] = -1;
    }
}

void BFS(int s)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < ke[u].size(); i++)
        {
            int v = ke[u][i];
            if (dist[v] == -1)
            {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> dinh >> canh;
        ReInit();
        while (canh--)
        {
            int u, v;
            cin >> u >> v;
            ke[u].push_back(v);
        }
        double sum = 0, count = 0;
        for (int i = 1; i <= dinh; i++)
        {
            memset(dist, -1, sizeof(dist));
            BFS(i);
            for (int j = 1; j <= dinh; j++)
            {
                if (dist[j] > 0)
                {
                    sum += dist[j];
                    count++;
                }
            }
        }
        printf("%.2lf\n", sum / count);
    }
    return 0;
}