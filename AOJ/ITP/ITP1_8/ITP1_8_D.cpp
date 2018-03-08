#include <stdio.h>
// s: a raw text, p: a pattern text
// p in s ? true:false
char s[101];
char p[101];
int main()
{
    int i, n, j, flag, pflag;
    scanf("%s", s);
    scanf("%s", p);
    for (i=0; s[i]!='\0'; ++i) {
        pflag = 0;
        for (n=i, flag=0; s[n==0?0:n-1]!='\0'&& pflag == 0;) {
            for (j=0; p[j]!='\0' && pflag == 0; ++j) {
                //printf("%d!!%d:%d, %c:%c\n",i, n, j, s[n], p[j]);
                if (s[n] == '\0') {
                    //printf("loop%d:%d, %c:%c\n", n, j, s[n], p[j]);
                    if (flag != 0) {
                        pflag = 1;
                    }
                    flag++;
                    n = 0;
                    j--;
                    continue;
                }
                if (s[n++] != p[j]) break;
                if (p[j+1] == '\0') {
                    printf("Yes\n");
                    return 0;
                }
            }
            if (j!=0) {
                --n;
            } else {
                
            }
        }
    }
    printf("No\n");
    return 0;
}
