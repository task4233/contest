// --------------------------------
// makefile.cpp
// Usage:
// Input the information. That's all.
//
// --------------------------------

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  FILE *fp;
  time_t timer;
  struct tm *local;
  char fileName[32];
  char p1[256],p2[256],p3[256];
  timer = time(NULL);
  // convert to localtime.
  local = localtime(&timer);
  printf("Please input the filename:");
  scanf("%27s", fileName);
  strcat(fileName,".cpp");
  printf("Please input the name of Problem:");
  scanf("%s", p1);
  scanf("%s", p2);
  scanf("%s", p3);
  
  // file open
  if ((fp = fopen(fileName, "w")) == NULL) {
    printf("Opening failed...\n");
    return 0;
  }
  
  fprintf(fp,"// ------------------------------------\n");
  fprintf(fp,"// Date:%4d/%2d/%2d\n",local->tm_year+1900,local->tm_mon+1,local->tm_mday);
  fprintf(fp,"// Problem:%s %s %s %s\n",p1,p2,p3,fileName);
  fprintf(fp,"//\n");
  fprintf(fp,"// ------------------------------------\n\n");
  fprintf(fp,"#include <bits/stdc++.h>\n\n");
  fprintf(fp,"using namespace std;\n\n");
  fprintf(fp,"#define EACH(i,a) for (auto& i : a)\n");
  fprintf(fp,"#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)\n");
  fprintf(fp,"#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)\n");
  fprintf(fp,"#define REP(i,n) FOR(i,0,n)\n");
  fprintf(fp,"#define RREP(i,n) RFOR(i,0,n)\n");
  fprintf(fp,"#define ALL(a) (a).begin(),(a).end()\n");
  fprintf(fp,"#define debug(x) cerr << #x << \":\" << x << endl;\n");
  fprintf(fp,"#define OK(ok) cout << (ok ? \"Yes\" : \"No\") << endl;\n");
  fprintf(fp,"typedef long long ll;\n\n");
  fprintf(fp,"void CINT(){}\n");
  fprintf(fp,"template <class Head,class... Tail>\n");
  fprintf(fp,"void CINT(Head&& head,Tail&&... tail) {\n  cin >> head; CINT(move(tail)...);\n}\n");
  fprintf(fp,"#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)\n");
  fprintf(fp,"#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)\n");
  fprintf(fp,"#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)\n\n");
  fprintf(fp,"const int INF = 1e9 + 1;\n");
  fprintf(fp,"const int MOD = 1e9 + 7;\n");
  fprintf(fp,"const int MAX_N = 1e5 + 1;\n\n");
  fprintf(fp,"int main()\n");
  fprintf(fp,"{\n");
  fprintf(fp,"  cin.tie(0);\n");
  fprintf(fp,"  ios::sync_with_stdio(false);\n\n");
  fprintf(fp,"  \n\n");
  fprintf(fp,"  return 0;\n");
  fprintf(fp,"}\n\n");
  fclose(fp);
  return 0;
}
