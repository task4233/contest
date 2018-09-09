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
    while (i <= N) {
      bit[i] += x;
      i += i & -i;
    }
  }

  Abel sum(int i) {
    Abel sm = 0;
    while (i > 0) {
      sm += bit[i];
      i -= i & -i;
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
  int N;
  cin >> N;

  vector< int > a(N), b(N);
  map< int, int > mp;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  for (int i = 0; i < N; ++i) {
    cin >> b[i];
    // 既にあればi番目の要素なので、その数を入れておく
    b[i] = mp[b[i]];
  }

  BIT< int > bit(N + 1);

  vector< int64 > inv(N + 1);
  int64 res = 0LL;
  for (int i = N - 1; i >= 0; --i) {
    inv[b[i]] = bit.sum(b[i]);
    
  }
  
  return 0;
}
