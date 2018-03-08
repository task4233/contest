// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 045 ManyFormulas c.cpp
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
  string S;
  int N;
  cin >> S;
  N = S.size();
  
  ll ans = 0ll;
  // '+'を入れられる部分はN-1で、入れるor入れないなので、2^(N-1)
  for (int i = 0; i < (1<<(N-1)); ++i) {
    ll sum = 0ll;
    // +を入れられるか判断するのはN-1桁で十分
    for (int j = 0; j <= N-1; ++j) {
      sum = sum*10 + (S[j] - '0');
      // j桁目を1にした時とiのANDがtrueの時は、それをansに加える
      if (i & (1<<j)) {
        ans += sum;
        sum = 0;
      }
    }
    // 最後にsumに溜まってる分をansに吐き出す
    ans += sum;
  }
  cout << ans << endl;
  return 0;
}

