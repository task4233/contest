// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ABC 081 Non-Decreasing d.cpp
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
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

static const int MOD = 1000000007;

int main()
{
  int N;
  scanf("%d", &N);
  vector< int > A(N);
  int mMax, mMin;
  mMax = mMin = 0;
  REP(i, N) {
    scanf("%d", &A[i]);
    // 最大値と最小値の番号を導出
    mMin = (A[i] < A[mMin] ? i : mMin);
    mMax = (A[i] > A[mMax] ? i : mMax);
  }

  bool positive;
  vector< pair< int, int > > o;
  if (A[mMin] <= 0 and A[mMax] > 0) {
    if (abs(A[mMin]) > abs(A[mMax])) {
      // 全部マイナスに
      REP(i, N) {
	if (i == mMin) continue;
	o.emplace_back(make_pair(mMin, i));
	A[i] += A[mMin];
      }
      positive = false;
    } else {
      // 全部プラスに
      REP(i, N) {
	if (i == mMax) continue;
	o.emplace_back(make_pair(mMax, i));
	A[i] += A[mMax];
      }
      positive = true;
    }
  } else if (A[mMin] >= 0 and A[mMax] >= 0) {
    // 最初から全部プラス
    positive = true;
  } else {
    // 最初から全部マイナス
    positive = false; 
  }

  // ここから確定演出
  if (!positive) {
    // 全部マイナス
    RREP(i, N - 1) {
      //if (A[i] <= A[i + 1]) continue;

      // 前の値に加えられる時
      o.emplace_back(make_pair(i+1, i));
      //A[i] = A[i + 1];
      //++i;
    }
  } else {
    // 全部プラス
    REP(i, N - 1) {
      //if (A[i] <= A[i + 1]) continue;

      // 次の値に加えられる時
      o.emplace_back(make_pair(i, i+1));
      //A[i + 1] += A[i];
      //--i;
    }
  }
  
  printf("%d\n", o.size());
  REP(i, o.size()) {
    printf("%d %d\n", (o[i].first) + 1, (o[i].second) + 1);
  }
  
  return 0;
}

