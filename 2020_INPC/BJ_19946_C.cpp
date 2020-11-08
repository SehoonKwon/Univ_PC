#include <iostream>
using namespace std;

//아이디어를 못내서 못풀었음. 해설 참조함(오차는 반드시 2^k 형태로 존재한다)

#define ll unsigned long long

int main()
{
	ll N, d = (1 << 64) - 1;
	cin >> N;

	d -= N;

	int cnt = 0;
	while (d > 0)
	{
		d /= 2;
		cnt++;
	}

	cout << 64 - cnt;

	return 0;
}
