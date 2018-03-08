// ------------------------------------
// Date:2018/ 2/11
// Problem:ABC 001 : d.cpp
//
// ------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

// ----------------------------------------------
vector<int> split_input(const string str, const char delimiter)
{
    vector<int> returnTime;
    string tmp;
    for (char ch : str) {
        if (ch == delimiter) {
            returnTime.emplace_back(stoi(tmp));
            tmp.clear();
        } else {
            tmp += ch;
        }
    }
    if (!tmp.empty())
        returnTime.emplace_back(stoi(tmp));
    return returnTime;
}

void solve(const int N,vector<vector<int>> uniqueTime)
{
    int timeTable[288];
    int startTime, endTime;
    bool isPositive;
    REP(i,288) timeTable[i] = 0;
    REP(i,N) {
        timeTable[(uniqueTime.at(i)[0]/100)*12 + uniqueTime.at(i)[0]%100]++;
        timeTable[(uniqueTime.at(i)[1]/100)*12 + uniqueTime.at(i)[1]%100]++;
    }
    isPositive = false;
    REP(i,288) if (0<i) timeTable[i] += timeTable[i-1];
    REP(i,288) {
        cout << i << ":" << timeTable[i] << endl;
        if (timeTable[i] > 0) {
            isPositive = true;
            startTime = (i/12)*100+(i%12)*5;
        } else {
            if (isPositive) {
            endTime = i*100/12+i%12;
            cout << startTime << "-" << endTime << endl;
            }
            isPositive = false;
        }
    }
}

// -----------------------------------------------------
// アホな解法
// -----------------------------------------------------
/*
void solve(const int N,vector<vector<int>> uniqueTime)
{
    bool checkFlag[30000],firstTrial,loopable;
    int earlyTime,tmp,startTime,endTime,restCnt,elseCnt,cnt;
    vector<array<int,2>> rainingTime;
    array<int,2> elem;
    restCnt = N;
    firstTrial = true;
    cnt = 0;
    
    REP(i,N) {
        checkFlag[i] = true;
    }
    
    if (N == 1) printf("%04d-%04d\n", uniqueTime[0][0],uniqueTime[0][1]);
    while(restCnt-->=0) {
        loopable = false;
        earlyTime = 2400;
        endTime = 0;
        REP(h,restCnt) {
            elseCnt = 0;
            //cout << endl << "earlyTime=" << earlyTime << "/endTime=" << endTime << endl;
            REP(i,N) {
                if (!checkFlag[i]) continue;
                ++elseCnt;
                //cout << i << ":" << uniqueTime[i][0] << "," << uniqueTime[i][1] << endl;
                if (uniqueTime[i][0] <= earlyTime) {
                    earlyTime = uniqueTime[i][0];
                    if (uniqueTime[i][1] > endTime) endTime = uniqueTime[i][1];
                    tmp = i;
                } else {
                    --elseCnt;
                }
            }
            if (firstTrial) {
                startTime = uniqueTime[tmp][0];
                endTime = uniqueTime[tmp][1];
                elem[0] = startTime;
                firstTrial = false;
                //cout << "firstTrial[" << tmp << "]->" << startTime << endl;
            }
            if (elseCnt==0 || h==restCnt-1)  {
                elem[1] = endTime;
                rainingTime.emplace_back(elem);
                //cout << "Push->" << rainingTime.at(cnt)[0] << "-" << rainingTime.at(cnt)[1] << endl;
                firstTrial = true;
                ++cnt;
            }
            checkFlag[tmp] = false;
            earlyTime = uniqueTime[tmp][1];
        }
        REP(h,N) if(checkFlag[h]) loopable = true;
        if (!loopable) break;
    }
    
    REP(i,rainingTime.size()) printf("%04d-%04d\n", rainingTime.at(i)[0], rainingTime.at(i)[1]);
}
*/
// ----------------------------------------------

int main()
{
    int N;
    int s, e, dataSize;
    string str;
    vector<int> returnTime;
    vector<vector<int>> uniqueTime;
    bool pushable;
    cin >> N;
    dataSize = 0;
    REP(i,N) {
        pushable = true;
        cin >> str;
        returnTime = split_input(str, '-');
        // 丸め込み
        s = returnTime.at(0);
        e = returnTime.at(1);
        s = s-s%5;
        e = e-e%5+(e%5==0?0:5);
        returnTime[0] = s;
        returnTime[1] = e;
        REP(j,dataSize) {
            if (uniqueTime.empty()) break;
            if (uniqueTime[j].at(0)==s && uniqueTime[j].at(1)==e) pushable=false;
        }
        if (pushable) {
            uniqueTime.emplace_back(returnTime);
            //cout << "push" << endl;
            ++dataSize;
        }
    }
    solve(dataSize,uniqueTime);
    return 0;
}
