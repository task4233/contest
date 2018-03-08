// ------------------------------------
// Date:2018/ 2/ 3
// Problem:AtCoder Petrozavodsk Contest b.cpp
//
// ------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

int main()
{
    int N,asum,bsum,n,sum;
    vector<int> A;
    vector<int> B;
    asum = bsum = sum = 0;
    cin >> N;
    REP(i,N) {
        cin >> n;
        A.push_back(n);
        asum += A[i];
    }
    REP(i,N) {
        cin >> n;
        B.push_back(n);
        bsum += B[i];
    }
    
    if (asum>bsum) {
        cout << "No" << endl;
        return 0;
    }
    
    REP(i,N) {
        n = B.at(i)-A.at(i);
        //cout << i << ":" << n << endl;
        if (n < 0) {
            sum += n;
        } else if (n >= 2){
            if (n%2==0) {
                sum += n/2;
            } else {
                sum += (n-1)/2;
            }
        }
    }
    if(sum < 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}

