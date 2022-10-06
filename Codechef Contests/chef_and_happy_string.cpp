#include <iostream>
using namespace std;
bool vowel(char a)
{
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
	{
		return true;
	}
	else
		return false;
}
bool test(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (i == s.size() - 2)
		{
			return false;
		}
		if (vowel(s[i]) && vowel(s[i + 1]) && vowel(s[i + 2]))
		{
			return true;
		}
	}
};
int main()
{
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		bool check = test(s);
		if (check)
		{
			cout << "Happy" << endl;
		}
		else
		{
			cout << "Sad" << endl;
		}
	}
	return 0;
}
