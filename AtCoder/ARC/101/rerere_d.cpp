/*
struct BIT {
  int N;
  using TYPE = int;
  vector<TYPE> bit;
  BIT() : N(0) {}
  BIT(int n) : N(n), bit(N + 1, 0) {}
  BIT(int n, TYPE init) : N(n), bit(N + 1, init) {}

  void add(int i, TYPE x) {
    for (int t = ++i; t < N; t += t & -t) bit[t] += x;
  }

  TYPE sum(int i) {
    TYPE res = 0;
    for (int t = i; t > 0; t -= t & -t) res += bit[t];
    return res;
  }

  TYPE sum(int i, int j) {
    return sum(j) - sum(i);
  }
};
*/
