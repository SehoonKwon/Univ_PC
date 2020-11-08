#include <iostream>
using namespace std;

int Array[11];
int visit[11];
int cnt;

void DFS(int idx)
{
	if (idx == 10)
	{
		int k = 0;
		for (int i = 0; i < 10; i++)
			if (Array[i] == visit[i])
				k++;

		if (k >= 5) cnt++;
		return;
	}

	for (int i = 1; i < 6; i++)
	{
		if (idx >= 2)
		{
			if (visit[idx - 1] == visit[idx - 2] && visit[idx - 2] == i)
				continue;
			else
			{
				visit[idx] = i;
				DFS(idx + 1);
				visit[idx] = false;
			}
		}
		else
		{
			visit[idx] = i;
			DFS(idx + 1);
			visit[idx] = false;
		}

	}
}

int main()
{
	for (int i = 0; i < 10; i++)
		cin >> Array[i];

	DFS(0);
	cout << cnt;
	return 0;
}
