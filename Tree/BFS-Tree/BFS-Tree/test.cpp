#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e6 + 10;
vector<int> edges[N];
bool st[N];
void bfs(int h)
{
	queue<int> q;
	q.push(h);
	st[h] = true;
	while (q.size())
	{
		auto u = q.front();
		q.pop();
		cout << u << ' ';
		for (auto v : edges[u])
		{
			if (!st[v])
			{
				q.push(v);
				st[v] = true;
			}
		}
	}
}
int main()
{
	int h;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		if (i == 0)
			h = a;
		edges[a].push_back(b);
		edges[b] .push_back(a);
	}
	bfs(h);
	return 0;
}