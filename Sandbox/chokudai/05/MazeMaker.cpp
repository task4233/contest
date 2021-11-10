// ------------------------------------
// Date:2018/ 2/19
// Problem:SRM452.5 Div2 Level2 MazeMaker.cpp
//
// ------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

class MazeMaker {
public:
  int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<moveCol)
  {
    int max = 0;
    int width = maze[0].size();
    int height = maze.size();
    int board[50][50];
    
    REP(i,height) {
      REP(j,width) {
        board[i][j] = -1;
      }
    }
    
    board[startRow][startCol];
    queue<int> queueX;
    queue<int> queueY;
    queueX.push(startCol);
    queueY.push(startRow);
    
    while(queueX.size() > 0) {
      int x = queueX.front();
      int y = queueY.front();
      queueX.pop();
      queueY.pop();
      REP(i,moveRow.size()) {
        int nextX = x + moveCol[i];
        int nextY = y + moveRow[i];
        
        if (0 <= nextX && nextx < width &&
            0 <= nextY && nextY < height &&
            board[nextY][nextX] == -1 &&
            maze[nextY].substr(nextX,1) == ".") {
          board[nextY][nextX] = board[y][x] + 1;
          queueX.push(nextX);
          queueY.push(nextY);
        }
      }
    }
    REP(i,height) {
      REP(j,width) {
        if (maze[i].substr(j,1) == "." && board[i][j] == -1)
          return -1;
        max = max(max,board[i][j]);
      }
    }
    return max;
  }
};

int main()
{
  MazeMaker m;
  return 0;
}

