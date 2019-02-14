#include <iostream>
#include <vector>

struct Edge {
  double to, dist, speed;
};

int main() {
  int n, m, c, f;
  double t, d, s;
  std::cin >> n >> m >> c;
  std::vector< int > a(m);
  for (int i=0; i<m; ++i) {
    std::cin >> a[i];
    --a[i]; 
  } 
  std::vector< Edge > e[10101];
  for (int i=0; i<c; ++i) {
    std::cin >> f >> t >> d >> s;
    e[f-1].push_back((Edge){t-1.0, d, s});
  }

  //  checking formula is \sum(d_i) - \sum(d[i]/s[i])*x <= 0 (i \in R)
  // \sum(d_i) and \sum(d[i]/s[i]) can derive using DP.
  auto check = [=](double x) {
    std::vector< double > dp(n, 1e9);
    for (int i=0; i<m; ++i) dp[a[i]] = 0;
    for (int i=0; i<n-1; ++i) {
      for (auto &&ee: e[i]) {
        double v = ee.dist - x*ee.dist/ee.speed;
        dp[ee.to] = std::min(dp[ee.to], dp[i] + v);
      }
    }
    return dp[n-1] <= 0; 
  };
  
  // Target is the minimum value of the average(10^5 is obviously ok)
  // Thus, [ng, ok). Now, I wanna get "ok".
  // if (check(mid)) ok = mid; else ng = mid;
  // check(mid) true 
  // The initial range is 10^5, and the final range is 10^-1
  // Thus, log2(10^5/10^-1) = n, n = log2(10^6): 100 times is enough.
  double ng = 0.0, ok = 101010.0;
  for (int i=0; i<100; ++i) {
    double mid = (ng+ok)/2.0;
    if (check(mid)) ok = mid;
    else ng = mid;
  }

  int ans = ok + 0.5;
  std::cout << ans << std::endl;
  
  return 0;
}
