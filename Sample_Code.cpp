#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)

int main()
{
    printf("  Multiplication Table\n");
    // for_loop
    for (int i=1; i<10; ++i) {
        for (int j=1; j<10; ++j) printf("%3d", i*j);
        printf("\n");
    }
    printf("\n");
   
    // macro_rep
    rep(i, 9) {
        rep(j, 9) printf("%3d", (i+1)*(j+1));
        printf("\n");
    }
    printf("\n");
    return 0;
}
