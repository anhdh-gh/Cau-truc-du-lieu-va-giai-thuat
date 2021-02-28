#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

bool pos[105][105];         // Vi tri cuu vui ve
vector<ii> block[105][105]; // Cap vi tri bi chia cat

int n, m, k;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int del = 0; //So chu cua bi xoa sau khi tim duoc 1 TPLT
int res = 0;

bool Check(int u, int v)
{
    if (u < 1 || u > n || v < 1 || v > n)
    {
        return false;
    }
    return true;
}

bool Check_block(int x, int y, ii tmp)
{
    for (int i = 0; i < block[x][y].size(); i++)
    {
        if (block[x][y][i] == tmp)
        {
            return false;
        }
    }
    return true;
}

void BFS(ii s)
{
    queue<ii> q;
    bool vs[105][105] = {false};
    q.push(s);
    vs[s.first][s.second] = true;
    pos[s.first][s.second] = false; //Delete
    int count = 1;                  //So luong cuu trong TPLT
    while (!q.empty())
    {
        ii t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        for (int i = 0; i < 4; i++)
        {
            int u = x + dx[i];
            int v = y + dy[i];
            if (Check(u, v) && vs[u][v] == false && Check_block(x, y, ii(u, v)))
            {
                q.push(ii(u, v));
                vs[u][v] = true;
                if (pos[u][v])
                {
                    pos[u][v] = false; //Xoa cuu u,v
                    count++;
                }
            }
        }
    }
    del += count;
    res += count * (k - del);
}

int main()
{
    cin >> n >> k >> m;
    while (m--)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        block[u][v].push_back(ii(x, y));
        block[x][y].push_back(ii(u, v));
    }
    int tmp = k;
    while (tmp--)
    {
        int x, y;
        cin >> x >> y;
        pos[x][y] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pos[i][j])
            {
                BFS(ii(i, j));
            }
        }
    }
    cout << res << endl;
    return 0;
}
