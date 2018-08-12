#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
typedef long long ll;
typedef complex< double > cdouble;

static const double PI = atan(1.0) * 4;

void dft(vector< cdouble >& f, ll N, bool inverse_flag = false) {
  if (N == 1) {
    // 定数値(最後の変換)
    return;
  }
  ll half_N = N / 2;
  vector< cdouble > p(half_N, 0.0), q(half_N, 0.0);
  REP(i, half_N) {
    // p(x)
    p[i] = f[i * 2];
    // q(x)
    q[i] = f[i * 2 + 1];
  }
  dft(p, half_N, inverse_flag);
  dft(q, half_N, inverse_flag);
  // 複素平面上の単位円をN分割する
  double theta = PI * 2.0 / N;
  if (inverse_flag) {
    // 逆変換は単位円上の逆回転
    theta = -theta;
  }
  // N分割の1つ分
  cdouble omega(cos(theta), sin(theta));
  cdouble k(cos(0.0), sin(0.0));

  REP(i, N) {
    f[i] = p[i % half_N] + omega * q[i % half_N];
    k *= omega;
  }
}

void inverse_dft(vector< cdouble >& f, int N) {
  dft(f, N, true);
  REP(i, N) {
    f[i] /= N;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll tmp;
  cin >> tmp;
  ll N = 1ll;
  while (tmp >= N) {
    // Nをtmp以上の2の冪乗にしておく(FFTで1/2していくため)
    N <<= 1;
  }
  vector< cdouble > A(N, 0.0), B(N, 0.0);
  REP(i, tmp) {
    int p, q;
    cin >> p >> q;
    A[i + 1] = p;
    B[i + 1] = q;
  }

  dft(A, N);
  dft(B, N);

  vector< cdouble > f(N, 0.0);
  REP(i, N) {
    f[i] = A[i] * B[i];
  }
  inverse_dft(f, N);

  FOR(i, 1, tmp * 2 + 1) {
    cout << (ll)round(f[i].real()) << endl;
  }
  
  return 0;
}

