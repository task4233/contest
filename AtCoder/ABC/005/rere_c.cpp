#include <bits/stdc++.h>

#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define P pair<int,int>
#define Abs(a,b) max(a,b)-min(a,b)
#define YES(condition) if(condition){cout << "YES" << endl;}else{cout << "NO" << endl;}
#define Yes(condition) if(condition){cout << "Yes" << endl;}else{cout << "No" << endl;}
#define Cout(x) cout<<(x)<<endl

typedef long long ll;

using namespace std;

const int INF = 1e9,MOD = 1e9 + 7;
const ll LINF = 1e18;

//while(x!=0){
//sum+=x%10;
// x/=10;
//}
//各桁の和

//pair<int,int> p[100000];
//P r[100000];
//cin >> tmp;
//p[i]=make_pair(tmp,i);
//cout << p[i].second+1 << endl;//ペアの右側つまりiを出力

//s.find(w[i])==string::npos
//findの使い方

//for(int i=0;i<n;i++){
// b[i]=x%2;
//x/=2;
//}二進数

long long int n,cnt=0,ans=0,a[100000],b[100000],c,cmp,cmpp,data,m,h,t,w,x,y,xcmp,ycmp,sum=0;

string s;

vector<int> z;

int main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // t: 制限時間 / n: たこ焼きの総数
  // a[i]: たこ焼きができるまでの時間
  // m: 客の人数
  // b[i]: 客が来るまでの時間
  cin >> t >> n;
  // 客が来てくれたこと
  bool fl=false;
  rep(i,n){
    cin >> a[i];
  }
  cin >> m;
  rep(i,m){
    cin >> b[i];
  }
  sort(a, a+n);
  sort(b, b+m);
  int trueCnt = 0;
  rep(i,m){
    // kyakuにi人目の客が来る時間を入れる(b[i])
    long long int kyaku=b[i];
    rep(j,n){
      // takoyakiにj個目のたこ焼きが焼ける時間を入れるa[j]
      long long int takoyaki=a[j];
      // 客が来るか、カウントがギリギリになるまでたこ焼きを放置する
      while(cnt < t && takoyaki != kyaku){
        takoyaki++;
        cnt++;
      }
      cnt=0;
      if(takoyaki == kyaku){
        // たこ焼きが客に提供できるとき
        fl=true;
        //Cout(a[j]);
        // たこ焼きが焼けるまでの時間をinfにする
        // -> これで選択肢から弾く
        a[j] = INF;
        //done[j] = true;
        //Cout(a[4]);
        break;
      } else{
        // たこ焼きが客に提供できない時
        fl=false;
        //a[j]=0;
      }
      if (j == n - 1) {
        // n人の客を全員調べて1人にも渡せなかった時
        // ->たこ焼きが売りきれなかったとき
        Cout("no");
        return 0;
      }
    }
  }
  if(n<m){
    Cout("no");
  }
  else if(fl){
    Cout("yes");
  }
  else{
    Cout("no");
  }
  return 0;
}
