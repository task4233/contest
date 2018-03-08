// ------------------------------------
// Date:2018/ 2/20
// Problem:7thJOI main darts c.cpp
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

int main()
{
  FILE *fp;
  int N,M,ans = 0,tmp;
  string output = "output.txt";
  fp = fopen("input.txt", "r");
  if (fp == NULL) return -1;
  tmp = fscanf(fp,"%d %d",&N, &M);
  vector<int> P(N);
  REP(i,N) tmp = fscanf(fp,"%d", &P[i]);
  fclose(fp);
  sort(ALL(P));
  REP(i,4) {
    REP(j,4) {
      if (P[i]+P[j]>=M) {
	ans = max(P[i],ans);
	break;
      }
      REP(k,4) {
	if (P[i]+P[j]+P[k]>=M) {
	  ans = max(P[i]+P[j],ans);
	  break;
	}
	REP(l,4) {
	  ans = max(P[i]+P[j]+P[k]+P[l]>=M?0:P[i]+P[j]+P[k]+P[l],ans);
	}
      }
    }
  }
  fp = fopen(output.c_str(), "w");
  if (fp == NULL) return -1;
  fprintf(fp, "%d", ans);
  fclose(fp);
  return 0;
}

