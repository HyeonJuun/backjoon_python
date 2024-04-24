#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

// 문제
// 지도가 주어지면 모든 지점에 대해서 목표지점까지의 거리를 구하여라.
// 문제를 쉽게 만들기 위해 오직 가로와 세로로만 움직일 수 있다고 하자.
// -------------------------------------------------
// 입력
// 지도의 크기 n과 m이 주어진다. n은 세로의 크기, m은 가로의 크기다.(2 ≤ n ≤ 1000, 2 ≤ m ≤ 1000)
// 다음 n개의 줄에 m개의 숫자가 주어진다. 0은 갈 수 없는 땅이고 1은 갈 수 있는 땅, 2는 목표지점이다. 입력에서 2는 단 한개이다.
// -------------------------------------------------
// 출력
// 각 지점에서 목표지점까지의 거리를 출력한다.
// 원래 갈 수 없는 땅인 위치는 0을 출력하고, 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1을 출력한다.
// -------------------------------------------------

const int MAX = 1000 + 1;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int map[MAX][MAX];
bool visited[MAX][MAX];
int sx, sy, n, m;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 0)
            {
                continue;
            }
            if (!visited[nx][ny])
            {
                map[nx][ny] = map[curx][cury] + 1;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                sx = i, sy = j;
                map[i][j] = 0;
            }
        }
    }

    bfs(sx, sy);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && visited[i][j] == false)
            {
                map[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}