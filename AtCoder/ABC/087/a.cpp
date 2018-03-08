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
    int X,A,B;
    cin >> X >> A >> B;
    cout << (X - A)%B << endl;
    return 0;
}
