// ------------------------------------
// Date:2018/ 2/ 3
// Problem:AtCoder Petrozavodsk Contest c.cpp
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

void kds(int last,int n,string s2) {
    string s1,s2;
    int l;
    cin >> s1;
    if (s1==s2) {
        cout << n <<
    } else {
        cout << 1/pow(2,n) << endl;
        l = 1/pow(2,n);
        cin >> s2;
        kds(n+1,s2);
    }
}

int main()
{
    int N;
    string s1,s2="t";
    cin >> N;
    cout << 0 << endl;
    while(cin >> s1) {
        if (s1 == s2) {
            
        } else {
            
        }
        s2 = s1;
    }
    return 0;
}

