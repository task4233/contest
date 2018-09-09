#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  vector< int > a(N);
  REP(i, N) {
    cin >> a[i];
  }

  // (i + 1)という数字が左から何番目に存在しているか
  vector< int > num_spot(N);
  vector< int > t(N);
  REP(i, N) {
    num_spot[a[i] - 1] = i;

    // 以下のようにも書けるが、上の方がスマート
    /*
    int tmp = i + 1;
    REP(j, N) {
      if (a[j] == tmp) {
	t[tmp - 1] = j; 
      }
    }
    */
  }

  set< int > st;
  st.insert(-1);
  st.insert(N);

  ll ans = 0ll;
  REP(i, N) {

    // 以下のiterの型はstd::set< int >::iterator
    // 重複がないため、lower_boundでもupper_boundでもどちらでも良い
    auto iter = st.upper_bound(num_spot[i]);

    ll right = (*iter) - num_spot[i];

    // num_spot[i]よりも左に存在し、かつ(i + 1)よりも大きい数の場所に移る
    iter--;

    ll left = num_spot[i] - (*iter);

    ans += left * right * (i + 1);

    st.insert(num_spot[i]);
  }

  cout << ans << endl;

  

  return 0;
}

