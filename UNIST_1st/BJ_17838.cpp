#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		if (s.size() != 7) cout << 0 << "\n";
		else
		{
			if ((s[0] == s[1] && s[1] == s[4]) && (s[0] != s[2] && s[2] == s[3] && s[3] == s[5] && s[5] == s[6])) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
	return 0;
}
