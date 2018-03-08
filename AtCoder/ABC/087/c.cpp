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
    int N;
    int A[2][100];
    int B[2][101];
    int S[101];
    int sum1,sum2,ans,num;
    cin >> N;
    num = N;
    REP(i,2) {
        REP(j,N) {
            cin >> B[i][j];
        }
    }
    REP(i,2) {
        REP(j,N) {
            if ((i==0&&j==0) || (i==1&&j==N-1)) {
                continue;
            } else if (i == 0) {
                A[0][N-j-1] = B[i][j+1];
            } else {
                A[1][N-j-1] = B[i][j];
            }
        }
    }
    REP(i,N) {
        sum1 = sum2 = 0;
        REP(j,N-1) {
            //cout << j << endl;
            sum1 += A[0][j];
            sum2 += A[1][j];
        }
        //cout << i << ":sum," << sum1 << ":" << sum2 << endl;
        S[i] = sum1>=sum2?0:1;
        //cout << i << ":" << S[i-1] << endl;
    }
    ans = B[0][0] + B[1][N-1];
    REP(i,N-1) {
        //cout << i << ":" << ans << endl;
        if (S[i]==0) {
            ans += B[0][i+1];
        } else {
            ans += B[1][i];
            num = i;
            break;
        }
    }
    //cout << "num" << num << endl;
    for(int i=num+1;i<N-1;++i) {
        //cout << i << ":" << ans << endl;
        ans += B[1][i];
    }
    cout << ans << endl;
    return 0;
}
