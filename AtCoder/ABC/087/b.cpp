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
    int A,B,C,X,cnt;
    cin >> A >> B >> C >> X;
    X /= 50;
    cnt = 0;
    REP(i,A+1) {
        REP(j,B+1) {
            REP(k,C+1) {
                if (10*i+2*j+k == X) {
                    ++cnt;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
