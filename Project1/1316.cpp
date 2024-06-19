#include <iostream>
#include <set>
#include <string>

using namespace std;
int main(void)
{
	int N, cnt = 0;
	cin >> N;
	while (N--)
	{
		set<char> chars;
		bool isGroup = true;
		string word;
		cin >> word;
		char lastWord = word[0];
		for (char ch : word)
		{
			// 연속이 아닌데 중복 존재
			if (ch != lastWord && chars.find(ch) != chars.end())
			{
				isGroup = false;
				break;
			}
			lastWord = ch;
			chars.insert(ch);
		}
		if (isGroup == true)
		{
			++cnt;
		}
	}
	cout << cnt;
}