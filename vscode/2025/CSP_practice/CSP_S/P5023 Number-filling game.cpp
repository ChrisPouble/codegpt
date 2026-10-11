#include <iostream>
#include <cstdio>

using namespace std;

const int N=100;

bool check(int x,int y);
void dfs(int sum);

int n,m,a[N][N],ans;

int main()
{
	cin>>n>>m;
	
	dfs(2);
	
	cout<<ans;
	system("pause");
	return 0;
}

void dfs(int sum)
{
	int i,j;
	if (sum>n+m)
	{
		for (i=1;i<n;++i)
		{
			for (j=1;j<m;++j)
			{
				if (!check(i,j))
				{
					return;
				}
			}
		}
		++ans;
		return;
	}
	dfs(sum+1);
	for (i=n;i>=1;--i) //将左下填成1
	{
		if (sum-i>=1&&sum-i<=m)
		{
			a[i][sum-i]=1;
			dfs(sum+1);
		}
	}
	for (i=n;i>=1;--i) //回溯时复原
	{
		if (sum-i>=1&&sum-i<=m)
		{
			a[i][sum-i]=0;
		}
	}
}

bool check(int x,int y)
{
	int rx=x,ry=y+1,dx=x+1,dy=
    y;
	while (rx+ry<=n+m)
	{
		if (a[rx][ry]!=a[dx][dy])
		{
			return a[rx][ry]<a[dx][dy];
		}
		if (rx<n)
		{
			++rx;
		}
		else
		{
			++ry;
		}
		if (dy<m)
		{
			++dy;
		}
		else
		{
			++dx;
		}
	}
	return true;
}
