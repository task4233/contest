// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 003 SimplifiedMahjong b.cpp
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
#define debug(x) cerr << #x << ": " << x << '\n';

using ll = long long;

#define MOD 1000000007

int main()
{
  int N;
  ll ans = 0ll;
  cin >> N;
  vector<int> A(N);
  REP(i,N) cin >> A[i];
  REP(i,N) {
    // 小さい方からペアを組み、余る場合は上書き
    ans += A[i]/2;
    A[i] = A[i]%2;
    // 上書きして余りがり1大きいカードと先にペアを組める場合は組む
    if (i<N-1 && A[i]>0 && A[i+1]>0) {
      --A[i];
      --A[i+1];
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}

