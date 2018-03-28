// ------------------------------------
// Date:2018/ 3/17
// Problem:./ ./ ./ ans_c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int INF = 1e9 + 1;
static const int MAX_N = 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector< pair< int, int > > red(N);
  REP(ri, N) {
    int a, b;
    cin >> a >> b;
    red[ri] = make_pair(a, b);
  }
  vector< pair< int, int > > blue(N);
  REP(bi, N) {
    int c, d;
    cin >> c >> d;
    blue[bi] = make_pair(c, d);
  }

  sort(ALL(red), [](pair< int, int > x, pair< int, int > y) { return x.first < y.first; } );
  sort(ALL(blue), [](pair< int, int > x, pair< int, int > y) { return x.first < y.first; } );

  int ans = 0;
  int mx, my, selectedRed, selectedBlue;
  REP(bi, blue.size()) {
    mx = my = -1;
    REP(ri, red.size()) {
      if (red[ri].first < blue[bi].first and red[ri].second < blue[bi].second) {
	// 制約を満たすとき
	if (red[ri].second > my) {
	  // 最もbiが大きいものを選ぶ
	  my = red[ri].second;
	  mx = red[ri].first;
	  selectedRed = ri;
	  selectedBlue = bi;
	} else if (red[ri].second == my) {
	  // 同じ条件の点があったとき、よりaiが大きいものを選ぶ
	  if (red[ri].first > mx) {
	    my = red[ri].second;
	    mx = red[ri].first;
	    selectedRed = ri;
	    selectedBlue = bi;
	  }
	}
      }
    }
    if (my > -1) {
      // 制約を満たす点が見つかったとき
      // 選択した点をvectorから削除する
      red[selectedRed] = red.back();
      red.pop_back();
      blue[selectedBlue] = blue.back();
      blue.pop_back();
      sort(ALL(red), [](pair< int, int > x, pair< int, int > y) { return x.first < y.first; });
      sort(ALL(blue), [](pair< int, int > x, pair< int, int > y) { return x.first < y.first; });
      ans++;
      // biを削除してしまったので最初からまたやり直す
      bi = -1;
    }
  }

  cout << ans << endl;
  

  return 0;
}

