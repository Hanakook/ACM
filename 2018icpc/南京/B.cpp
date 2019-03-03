#include <stdio.h>
#include <string.h>
#define nn 0
#define mm 1
#define ll long long
int T;
bool map[100005][105];
long long dp[100005][105][2];
ll tx, ty;
ll n, m, t;
int main()
{
	scanf("%d", &T);
	for(int cases = 1; cases <= T; cases ++)
	{
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		scanf("%lld%lld%lld", &n, &m, &t);
		while(t --)
		{
			scanf("%lld%lld", &tx, &ty);
			map[tx][ty] = 1;
		}
		ll cnt = 0;
		for(ll i = 1; i <= n; i ++)
			for(ll j = 1; j <= m; j ++)
			{
				if(!map[i][j])
					dp[i][j][nn] = dp[i - 1][j][nn] + 1, dp[i][j][mm] = dp[i][j - 1][mm] + 1;
				else
					dp[i][j][nn] = dp[i][j][mm] = 0;
				
				ll les = dp[i][j][nn];
				for(ll k = 0; k < dp[i][j][mm]; k ++)
				{
					if(dp[i][j - k][nn] < les) les = dp[i][j - k][nn];
					cnt += les;
				}
			}
			
		printf("Case #%d: %lld\n", cases, cnt);
	}
	return 0;
}
