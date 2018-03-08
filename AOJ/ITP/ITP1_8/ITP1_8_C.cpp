#include <stdio.h>
#include <ctype.h>
char c[1200];
int cnt[27];
int main()
{
    char ch;
    int n;
    while(scanf("%s", c) != EOF) {
        for (int i = 0; c[i] != '\0'; ++i) {
            ch = tolower(c[i]);
            n = ch - '0';
            if (n < 49 || n > 74) continue;
            ++cnt[n-49];
        }
    }
    for (int i = 0; i < 26; ++i) printf("%c : %d\n", i + 97, cnt[i]);
    return 0;
}
