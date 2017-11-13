#include <stdio.h>
#define MAXN 1005
int arr[MAXN][MAXN];
int main(void) {
    int n,m;
    while(scanf("%d %d", &n, &m) != EOF) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d",&arr[i][j]);
            }
        }
        for(int j = m - 1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
