#include <iostream>
using namespace std;

int main()
{
	// your code goes herev
	int t;
	cin >> t;
	while (t--)
	{
		// int p;
		// cin>>p;
		string s1;
		string s2;
		cin >> s1;
		cin >> s2;
		int zeroes1 = 0;
		int zeroes2 = 0;
		int p = 0;
		for (auto i : s1)
		{
			if (i == '0')
			{
				zeroes1++;
			}
			p++;
		}
		for (auto i : s2)
		{
			if (i == '0')
			{
				zeroes2++;
			}
		}
		int one1 = p - zeroes1;
		int one2 = p - zeroes2;
		string s = "";
		int count = 0;
		while (zeroes1-- && one2--)
		{
			s += '1';
			count++;
		}
		while (zeroes2-- && one1--)
		{
			s += '1';
			count++;
		}
		while (count < p)
		{
			s += '0';
			count++;
		}
		cout << s << endl;
	}
	return 0;
}
