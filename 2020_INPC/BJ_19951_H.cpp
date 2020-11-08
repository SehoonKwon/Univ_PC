#include <iostream>
using namespace std;

//누적합 기본 응용문제. 누적합을 이용하기 위해서 첫구간과 마지막+1칸 조작. 마지막+1칸에 상쇄값을 해놓으면 나중에 누적합 구했을 때 영향 X 이므로

int N, M;
int Array[100001];
int sum[100001];

void input()
{
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
		cin >> Array[i];

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		sum[a] += c;
		sum[b + 1] += -c;
	}
}

void solve()
{
	for (int i = 1; i < N + 1; i++)
		sum[i] += sum[i - 1];

	for (int i = 1; i < N + 1; i++)
		cout << Array[i] + sum[i] << " ";
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}
