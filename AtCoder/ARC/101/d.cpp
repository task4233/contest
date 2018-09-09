#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

template< class Abel > class BIT {
public:
  BIT(int _n) : N(_n) { init(); }

  void init() {
    // [1, N]の範囲なので、+1する必要がある
    bit.clear();
    bit.resize(N + 1, 0);
  }

  void add(int i, Abel x) {
    while (++i < N) {
      bit[i] += x;
      i += (i & -i);
    }
  }

  Abel sum(int i) {
    Abel sm = 0;
    while (i > 0) {
      sm += bit[i];
      i -= (i & -i);
    }
    return sm;
  }

  Abel getSum(int _x, int _y) {
    return sum(_y) - sum(_x - 1);
  }

private:
  int N;
  vector< Abel > bit;
};


int main()
{
  int64 N;
  cin >> N;
  vector< int64 > a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];

  if (N == 1) {
    cout << a[0] << endl;
    return 0;
  }
  
  int lb = 0, ub = 1e9 + 1;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;

    int cnt = N * (N + 1) / 2;
    {
      vector< int > b(N);
      for (int i = 0; i < N; ++i) {
	b[i] = (a[i] >= mid) ? 1 : -1;
      }
      
      vector< int > sm(N + 1, N);
      for (int i = 0; i < N; ++i) {
	sm[i + 1] = sm[i] + b[i];
      }
      
      BIT< int > bit(2 * N);
      
      for (int i = N; i >= 0; --i) {
	cnt += bit.sum(2 * N) - bit.sum(sm[i]);
	debug(i);
	debug(sm[i]);
	bit.add(sm[i], 1);
      }
    }
    if (cnt >= (N * (N + 1) / 2 + 1) / 2) lb = mid;
    else ub = mid;
  }

  int ans = lb;
  cout << ans << endl;
  
  return 0;
}
