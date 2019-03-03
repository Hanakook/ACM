#include <stdio.h>
#define ll long long
ll room, buy;
ll t, mon;
ll r[100005];
ll got[100005];
ll maxn = 0;
ll over = 2016166136;
ll left = 0;
ll ro[100005];
ll le[100005];
int main()
{
	scanf("%lld%lld", &room, &buy);
	for(ll i = 1; i <= room; i ++)
		scanf("%lld", r + i);

	scanf("%lld", &t);
	
	while(t --)
	{
		
		scanf("%lld", &mon);
		if(mon >= over) printf("%lld %lld\n", room, left + (mon - over) * buy);
		else
		{
			if(mon <= maxn) printf("%lld %lld\n", ro[mon], le[mon]);
			else
			{
				for(ll i = maxn + 1; i <= mon; i ++)
				{
					int pre = 0;
					ro[i] = ro[i - 1];
					ll nd = le[i - 1] + buy;
					for(ll j = 1; j <= room && nd; j = got[j]? got[j]: j + 1)
					{
						if(r[j] && r[j] <= nd)
						{
							nd -= r[j], r[j] = 0, ro[i] ++;
							got[pre] = 0;
						}
						if(r[j] > r[pre] && r[j] && !got[pre]) got[pre] = j, pre = j;
						if(j == room && !got[pre]) got[pre] = j;
					}
					le[i] = nd;
					if(ro[i] == room) over = i, left = nd;
				}
				printf("%lld %lld\n", ro[mon], le[mon]);
				maxn = mon;
			}
		}
	}
	
	return 0;
}
