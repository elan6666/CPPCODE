#include<iostream>
#include<queue>
using namespace std;
const int N = 1e6 + 10;
int l[N], r[N], n;
//根节点为1
//bfs
void bfs()
{
	queue<int> q;
	q.push(1);

	while (q.size())
	{
		auto u = q.front();
		q.pop();
		cout << u << " ";
		if (l[u])q.push(l[u]);
		if (r[u])q.push(r[u]);
	}
	cout << endl;
}
//dfs
void dfs1(int p)//先序
{
	if (p == 0)
		return;
	cout << p << ' ';
	dfs1(l[p]);
	dfs1(r[p]);
}
//后序中序同理
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	bfs();
	return 0;
}

