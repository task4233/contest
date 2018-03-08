#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define RFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)


int main()
{
    int m,N,MAX;
    // A[i][j]はi行j列
    int A[2][100];
    cin >> N;
    MAX = 0;
    REP(i,2) {
        REP(j,N) {
            cin >> A[i][j];
        }
    }
    
    REP(i,N) {
        m = 0;
        REP(j,i+1) {
            m += A[0][j];
            //cout << j << ":" <<  m << ",";
        }
        REP(j,N-i) {
            m += A[1][j+i];
            //cout << m << ",";
        }
        //cout << m << endl;
        MAX = max(m,MAX);
    }
    
    cout << MAX << endl;
    return 0;
}
