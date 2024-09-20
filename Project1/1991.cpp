#include<iostream>
#include<map>
#include <vector>

using namespace std;

map<char, vector<char>> tree;
void preorder(char cur)
{
	if (tree.find(cur) == tree.end())
	{
		return;
	}
	cout << cur;
	if (tree[cur][0] != '.')
	{
		preorder(tree[cur][0]);
	}
	if (tree[cur][1] != '.')
	{
		preorder(tree[cur][1]);
	}
}
void inorder(char cur)
{
	if (tree.find(cur) == tree.end())
	{
		return;
	}
	if (tree[cur][0] != '.')
	{
		inorder(tree[cur][0]);
	}
	cout << cur;
	if (tree[cur][1] != '.')
	{
		inorder(tree[cur][1]);
	}
}
void postorder(char cur)
{
	if (tree.find(cur) == tree.end())
	{
		return;
	}
	if (tree[cur][0] != '.')
	{
		postorder(tree[cur][0]);
	}
	if (tree[cur][1] != '.')
	{
		postorder(tree[cur][1]);
	}
	cout << cur;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char parent, leftChild, rightChild;
		cin >> parent >> leftChild >> rightChild;
		tree[parent] = vector<char> { leftChild, rightChild };
	}
	char cur = 'A';
	preorder(cur);
	cout << "\n";
	inorder(cur);
	cout << "\n";
	postorder(cur);
}