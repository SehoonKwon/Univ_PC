#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int cnt = 0;
	if (N == 0)
	{
		cout << 1;
		return 0;
	}
	if (N > 0)
	{
		for (int i = 0; i < 31; i++)
		{
			int X = 1 << i;
			if (N >= X) cnt++;
			else
				break;
		}
	}
	else
		cnt = 32;

	cout << cnt;
	return 0;
}
