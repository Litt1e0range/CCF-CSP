#include <stdio.h>
#define MAXN 1005

int arr[MAXN];
int main(void) {
    int n,k;
    while(scanf("%d %d",&n,&k) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int tot = 0;//每个朋友分到的蛋糕
        int cnt = 0;//已经分到足够蛋糕的朋友数量
        for(int i = 0; i < n;) {
            while(tot < k) {
                tot += arr[i++];
            }
            cnt++;
            tot = 0;//清空本次所分到的蛋糕
        }
        printf("%d\n",cnt);
    }
    return 0;
}
