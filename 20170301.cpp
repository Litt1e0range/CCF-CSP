#include <stdio.h>
#define MAXN 1005

int arr[MAXN];
int main(void) {
    int n,k;
    while(scanf("%d %d",&n,&k) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int tot = 0;//ÿ�����ѷֵ��ĵ���
        int cnt = 0;//�Ѿ��ֵ��㹻�������������
        for(int i = 0; i < n;) {
            while(tot < k) {
                tot += arr[i++];
            }
            cnt++;
            tot = 0;//��ձ������ֵ��ĵ���
        }
        printf("%d\n",cnt);
    }
    return 0;
}
