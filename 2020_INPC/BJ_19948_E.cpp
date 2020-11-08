#include <iostream>
#include <string>
using namespace std;

int Alpha[27];
string s;
int sp;

void input()
{
	getline(cin, s);
	cin >> sp;

	for (int i = 0; i < 26; i++)
	{
		int x;
		cin >> x;
		Alpha[i] = x;
	}
}

void solve()
{
	string ans = "";
	int len = s.size();
	int sp_cnt = 0, flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			if (s[i - 1] == ' ') continue;
			else
				sp_cnt++;

			if (sp_cnt > sp)
			{
				cout << -1;
				return;
			}
			flag = 0;
		}
		else
		{
			if (i != 0 && s[i - 1] == s[i]) continue;
			else
			{
				char temp = s[i];
				if (s[i] >= 'a' && s[i] <= 'z')
					temp = s[i] - 'a' + 'A';
				
				Alpha[temp-'A']--;

				if (flag == 0)
				{
					if (s[i] >= 'a' && s[i] <= 'z') ans += (s[i] - 'a' + 'A');
					else ans += s[i];
					Alpha[temp - 'A']--;
					flag = 1;
				}
				if (Alpha[temp - 'A'] < 0)
				{
					cout << -1;
					return;
				}
			}
		}
	}

	cout << ans;
}

int main()
{
	input();
	solve();
	return 0;
}
