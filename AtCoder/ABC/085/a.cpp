#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define RFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int main()
{
    char S[11];
    scanf("%s", S);
    REP(i, 3) cout << S[i];
    cout << 8;
    FOR(i, 4, 10) cout << S[i];
    cout << endl;
    return 0;
}
