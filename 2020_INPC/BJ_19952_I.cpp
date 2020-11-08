#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int H, W, O, F;
int SX, SY, DX, DY;
int Array[101][101];
int visit[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct point
{
	int x;
	int y;
	int power;
};

void input()
{
	cin >> H >> W >> O >> F >> SX >> SY >> DX >> DY;
	for (int i = 0; i < O; i++)
	{
		int x, y, l;
		cin >> x >> y >> l;
		Array[x][y] = l;
	}
}

int BFS()
{
	queue<point> q;
	q.push({ SX, SY, F });
	visit[SX][SY] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int p = q.front().power;
		q.pop();

		if (x == DX && y == DY)
			return 1;

		if (p == 0) continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > 0 && nx <= H && ny > 0 && ny <= W)
			{
				if (visit[nx][ny] == 0)
				{
					int nowH = Array[x][y];
					if (Array[nx][ny] < nowH && p > 0)
					{
						visit[nx][ny] = true;
						q.push({ nx, ny, p - 1 });
					}
					else if (Array[nx][ny] - nowH  <= p && p > 0)
					{
						visit[nx][ny] = true;
						q.push({ nx, ny, p - 1 });
					}
				}
			}
		}
	}

	return 0;
}

void solve()
{
	int ans = BFS();
	if (ans)
		cout << "잘했어!!\n";
	else
		cout << "인성 문제있어??\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		memset(visit, 0, sizeof(visit));
		memset(Array, 0, sizeof(Array));
		input();
		solve();
	}
	return 0;
}
