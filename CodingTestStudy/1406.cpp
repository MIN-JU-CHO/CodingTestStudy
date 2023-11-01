#include <list>
#include <iostream>

using namespace std;
int main(void)
{
	list<char> array;
	string input;
	cin >> input;
	for (char a : input)
	{
		array.push_back(a);
	}
	int num;
	cin >> num;
	auto iter = array.end();
	for (int i = 0; i < num; ++i)
	{
		cin >> input;
		if (input[0] == 'L' && iter != array.begin())
		{
			--iter;
		}
		else if (input[0] == 'D' && iter != array.end())
		{
			++iter;
		}
		else if (input[0] == 'B' && iter != array.begin())
		{
			--iter;
			iter = array.erase(iter);
		}
		else if (input[0] == 'P')
		{
			char word;
			cin >> word;
			array.insert(iter, word);
		}
	}
	for (char a : array)
	{
		cout << a;
	}
}