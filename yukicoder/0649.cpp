// ------------------------------------
// Date:2018/ 2/22
// Problem:No.649 Level3 ここでちょっとQK! 0649.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()

using ll = long long;

int main()
{
  int Q,K,num;
  ll v,max = 0;
  vector<ll> S;
  cin >> Q >> K;
  REP(i,Q) {
    cin >> num;
    if (num == 1) {
      flag = true;
      cin >> v;
      max = std::max(v,max);
      S.emplace_back(v);
      if (flag && max != v) sort(ALL(S));
    } else {
      if (S.size() < K) {
        cout << -1 << endl;
        flag = false;
      } else {
        cout << S[K-1] << endl;
        if (S.size() != K-1) S[K-1] = S.back();
        S.pop_back();
        sort(ALL(S));
        flag = false;
      }
    }
    /*
    REP(i,S.size()) cout << S[i];
    cout << endl;
    cout << "s-size -> " << S.size() << endl;
     */
  }
  return 0;
}


