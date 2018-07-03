#include <bits/stdc++.h>

using namespace std;

#define EACH(i, a) for(auto&& i:(a))
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

int N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  unordered_map< int, int > mp;
  REP(i, N) {
    int tmp; cin >> tmp;
    if (mp[tmp - 1]) {
      // 1つ前の要素が繋がっていた時に+1して更新
      mp[tmp] = mp[tmp - 1] + 1;
    } else {
      // 1つ前の要素が虚無の時に1で初期化
      mp[tmp] = 1;
    }
  }


  int mx = -1;
  EACH(x, mp) {
    mx = max(mx, x.second);
  }

  int ans = N - mx;
  cout << ans << endl;

  return 0;
}

