#include <bits/stdc++.h>
using namespace std;

long long dp[1 << 20], a[20], b[20];
int pre[20];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int s;
        scanf("%lld%lld%d", &a[i], &b[i], &s);
        for (int j = 0; j < s; j++) {
            int k;
            scanf("%d", &k);
            k--;
            pre[i] |= (1 << k);
        }
    }
    long long ans = 0;
    memset(dp, 0x80, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        int cnt = __builtin_popcount(i) + 1;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0 && ((i & pre[j]) == pre[j])){
                dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + cnt * a[j] + b[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
