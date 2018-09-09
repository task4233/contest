#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

int main()
{
  int N, K;
  cin >> N >> K;
  vector< int > x(N);
  for (int i = 0; i < N; ++i) {
    cin >> x[i];
  }

  int ans = 1e9 + 1;
  for (int i = 0; i <= N - K; ++i) {
    int l = abs(x[i]);
    int r = abs(x[i + K - 1]);
    int tmp;

    if (x[i + K - 1] <= 0) {
      // 一番右の要素が0以下の場合、全て0よりも右に存在している
      tmp = l;
    } else if (x[i] >= 0) {
      // 一番左の要素が0以上の場合、全て0よりも左に存在している
      tmp = r;
    } else {
      // それ以外の要素は0を挟んで左右に存在している
      tmp = l + r + min(l, r);
      // debug(min(l, r));
    }
    // debug(tmp);
    ans = min(ans, tmp);
  }

  cout << ans << endl;
  
  return 0;
}
