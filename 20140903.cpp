#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 105
char str[MAXN][MAXN];
char cpy[MAXN][MAXN];

int main(void)
{
    int flag, n;
    while(scanf("%s", str[0]) != EOF) {
	scanf("%d %d", &flag, &n);
	for(int i = 1; i <= n; i++) {
	    scanf("%s", str[i]);
	    strcpy(cpy[i], str[i]);
	}
	if(!flag) {
	    for(int i = 0; i <= n; i++) {
		strlwr(str[i]);
	    }
	}
	for(int i = 1; i <= n; i++) {
	    if(strstr(str[i], str[0])) {
		printf("%s\n", cpy[i]);
	    }
	}
    }
    return 0;
}
