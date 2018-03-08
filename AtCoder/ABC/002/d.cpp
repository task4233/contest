// ------------------------------------
// Date:2018/ 2/12
// Problem:ABC 002 派閥 d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

// ---------------------------------------------------
struct Relationship {
    int x;
    int y;
};

void solve(const int N,const int M,const vector<Relationship> net)
{
    int maxBond;
    bool makable;
    bool netData[12][12];
    
    maxBond = 1;
    REP(i,12) REP(j,12) netData[i][j] = false;
    REP(ni,M) {
        // netDataのxとyの相手としてそれぞれ登録
        netData[net.at(ni).x - 1][net.at(ni).y - 1] = true;
        netData[net.at(ni).y - 1][net.at(ni).x - 1] = true;
    }
    
    FOR(bit,1,(1<<N)) {
        // 12ビット(人数の最大値)でbitを表した時の1の数をtに代入。
        // tには作れる派閥の最大値が代入される。
        int bondNum = bitset<12>(bit).count();
        if (bondNum <= maxBond) continue;
        makable = true;
        REP(xi,N) {
            REP(yi, xi) {
                // netData[xi][yi]がfalseの時かつ、
                // 下からxiビット目およびyiビット目がそれぞれ1の時flagをfalseにする。
                if (!netData[xi][yi] && (bit>>xi & bit>>yi)%2==1) {
                    makable = false;
                }
            }
        }
        if (makable) maxBond = bondNum;
    }
    cout << maxBond << endl;

}
// ---------------------------------------------------

int main()
{
    Relationship r;
    int N, M;
    vector<Relationship> net;
    cin >> N >> M;
    REP(i,M) {
        cin >> r.x >> r.y;
        net.emplace_back(r);
    }
    solve(N,M,net);
    return 0;
}

