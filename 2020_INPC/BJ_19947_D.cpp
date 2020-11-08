#include <iostream>
#include <algorithm>
using namespace std;

int H, Y;
int MAX;

void DFS(int val, int year)
{
	if (year > Y)
		return;
	else
		MAX = max(MAX, val);

	DFS((int)(val * 1.05), year + 1);
	DFS((int)(val*1.2), year + 3);
	DFS((int)(val*1.35), year + 5);
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> H >> Y;
	DFS(H, 0);
	cout << MAX;
	return 0;
}
