#include <list>
#include <iostream>

using namespace std;
int main(void)
{
	string input;
	int num;
	cin >> num;
	while (num--)
	{
		list<char> cases;
		auto iter = cases.begin();
		cin >> input;
		for (char c : input)
		{
			if (c == '<' && iter != cases.begin())
			{
				--iter;
			}
			else if (c == '>' && iter != cases.end())
			{
				++iter;
			}
			else if (c == '-' && iter != cases.begin())
			{
				--iter;
				iter = cases.erase(iter);
			}
			else if(c != '<' && c != '>' && c != '-')
			{
				iter = cases.insert(iter, c);
				++iter;
			}
		}
		for (char c : cases)
		{
			cout << c;
		}
		cout << endl;
	}
}