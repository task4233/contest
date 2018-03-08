#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

#define PI 3.141592653589793
#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define RFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

class Dice{
public:
    Dice()
    {
        face = new int[6];
        move = new int[6];
    }
    ~Dice()
    {
        delete[] face;
        delete[] move;
    }
    void roll(char c)
    {
        REP(i,6) move[i]=face[i];
	if (c == 'L') setLabel(move[0],move[2],move[4],move[1],move[3],move[5]);
	else if (c=='E') setLabel(move[3],move[1],move[0],move[5],move[4],move[2]);
        else if (c=='N') setLabel(move[1],move[5],move[2],move[3],move[0],move[4]);
        else if (c=='S') setLabel(move[4],move[0],move[2],move[3],move[5],move[1]);
        else setLabel(move[2],move[1],move[5],move[0],move[4],move[3]);
    }
    void setLabel(int i,int n) {face[i] = n;}
    void setLabel(int f0,int f1,int f2,int f3,int f4,int f5)
    {
        face[0] = f0;
        face[1] = f1;
        face[2] = f2;
        face[3] = f3;
        face[4] = f4;
        face[5] = f5;
    }
    int getAns() {return face[2];}
  int getLabel(int s) {return face[s];}
  void setDice(int s1,int s2)
  {
    REP(i,4) {
      //cout << "s1/" << face[0] << ":" << face[1] << endl;
      if (face[0]==s1) {
	break;
      } else if (i==3) {
	roll('L');
	i=-1;
      }
      roll('N');
    }
    REP(i,4) {
      //cout << "s2/" << face[0] << ":" << face[1] << endl;
      if (face[1]==s2) break;
      roll('L');
    }
  }
private:
    int *face;
    int *move;
};

int main() {
  Dice d1,d2;
  int n,flag;
    string str;
    flag = 0;
    REP(i,6) {
        cin >> n;
        d1.setLabel(i,n);
    }
    REP(i,6) {
      cin >> n;
      d2.setLabel(i,n);
    }
    REP(i,4) {
      if(d1.getLabel(0) != d1.getLabel(1)) break;
      d1.roll('N');
      if (d1.getLabel(0) == d1.getLabel(1) && i==3) {
	d1.roll('L');
	i = -1;
      }
    }
    d2.setDice(d1.getLabel(0),d1.getLabel(1));
    REP(i,6) if (d1.getLabel(i)!=d2.getLabel(i)) ++flag;
    cout << (flag==0?"Yes":"No") << endl;
    return 0;
}
