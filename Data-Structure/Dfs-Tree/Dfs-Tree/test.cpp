#include<iostream>
#include<vector>
using namespace std;
const int N = 1e6 + 10;
vector<int>edges[N];
bool st[N];
void dfs(int u)
{
	st[u] = true;
	cout << u << ' ';
	for (auto v : edges[u])
	{
		if (!st[v])
			dfs(v);
	}
}
int main()
{
	cout << "����n�Ĵ�С" << endl;
	int n;
	cin >> n;
	int h;
	for (int i = 0; i < n - 1; i++)//n���ڵ�n����
	{
		int a, b;
		cin >> a >> b;
		if (i == 0)
			h = a;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(h);
}