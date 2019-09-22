#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

int h,w,a,b;
void show(vector<string> vv){
  for(int hi=0;hi<h;++hi){
    cout<<vv[hi]<<endl;
  }
}

signed main() {
  cin>>h>>w>>a>>b;

  vector<string> s(h, string(w,'0'));

  if(!((a*h)%w==0 && (b*w)%h==0) && !(a==0 || b==0)) {
    cout << "No" <<endl;
    return 0;
  }

  if (a==0 && b==0){
    show(s);
    return 0;
  } else if(a<b){
    // a=1or2
    if (a==0) {
      if (b==h/2)  {
        for(int hi=0;hi<h;++hi){
          if(hi%2==0) s[hi] = string(w, '0');
          else s[hi] = string(w,'1');
        }
        show(s);
        return 0;
      }
    }else{
      int bb = h/(w/a);
      if (bb==b){
        for(int hi=0;hi<h;++hi){
          int r = a;
          for(int wi=0;wi<w;++wi){
            if (r>0) {
              s[hi][(wi+hi*a)%w] = '0';
              --r;
            } else {
              s[hi][(wi+hi*a)%w] = '1';
            }
          }
        }
        show(s);
        return 0;
      }
    }
  }else {
    if (b==0) {
      if (a==w/2) {
        for(int wi=0;wi<w;++wi){
          char ch;
          if (wi%2==0) ch = '0';
          else ch = '1';
          for(int hi=0;hi<h;++hi){
            s[hi][wi] = ch;
          }
        }
        show(s);
        return 0;
      }
    } else {
      int aa = w/(h/b);
      if(aa==a){
        for(int wi=0;wi<w;++wi){
          int r = b;
          for(int hi=0;hi<h;++hi){
            if (r>0) {
              s[(hi+wi*b)%h][wi] = '0';
              --r;
            } else {
              s[(hi+wi*b)%h][wi] = '1';
            }
          }
        }
        show(s);
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
