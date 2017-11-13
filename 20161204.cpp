#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#define MAXN 1005

using namespace std;

int dp[MAXN][MAXN];
int sum[MAXN],arr[MAXN];

int main(void) {
    int n;
    while(scanf("%d",&n) != EOF) {
        memset(sum,0,sizeof(sum));
        for(int i = 1; i <= n; i++) {
            scanf("%d",&arr[i]);
            sum[i] = sum[i - 1] + arr[i];
        }
        memset(dp,0,sizeof(dp));
        for(int t = 1; t < n; t++) {
            for(int i = 1; i <= n - t; i++) {
                int j = i + t;
                dp[i][j] = INT_MAX;
                for(int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
                }
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
