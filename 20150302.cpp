#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1005

typedef struct {
    int num;
    int cnt;
} Cnt;
Cnt cnt[MAXN];

void init() {
    for(int i = 0; i < MAXN; i++) {
        cnt[i].num = i;
        cnt[i].cnt = 0;
    }
}

int cmp(const void* a, const void* b) {
    Cnt* x = (Cnt*)a;
    Cnt* y = (Cnt*)b;
    if(x->cnt == y->cnt) return x->num - y->num;
    else                 return y->cnt - x->cnt;
}

int main(void) {
    int n, m;
    while(scanf("%d", &n) != EOF) {
        init();
        for(int i = 0; i < n; i++) {
            scanf("%d",&m);
            cnt[m].cnt++;
        }
        //注意这里，输入的数可能比n大，所以不能写成qsort(cnt, n, sizeof(Cnt), cmp);
        qsort(cnt, MAXN, sizeof(Cnt), cmp);
        for(int i = 0; i < n && cnt[i].cnt > 0; i++) {
            printf("%d %d\n",cnt[i].num, cnt[i].cnt);
        }
    }
    return 0;
}
