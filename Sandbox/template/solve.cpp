#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef vector<char> vc;
typedef vector<vector<char> > vvc;

//換字式暗号を解く

bool ischar(char c){
    if(c >= 'a' && c <= 'z') {
        return true;
    } else if(c >= 'A' && c <= 'Z'){
        return true;
    } else {
        return false;
    }
}

char InputFileName[] = "input.txt";
int main(void){
    vector<char> str;
    char c;
    FILE *fp;
    fp = fopen(InputFileName, "r");

    while((c = fgetc(fp)) != EOF) {
        str.push_back(c);
    }
    vvc trans(2, vc());


/*
    for(int i = 0; i < str.size(); i++) {
        if(ischar(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
*/
    for(int i = 0; i < str.size(); i++) {
        cout << str[i];
    }
    cout << endl;

    while(1){

        char from, to;
        cout << "from: ";
        cin >> from;
        cout << "to: ";
        cin >> to;

        from = tolower(from);
        to = tolower(to);
        
        trans[0].push_back(from);
        trans[1].push_back(to);

        bool ch;
        for(int i = 0; i < str.size(); i++) {
            ch = false;
            for(int j = 0; j < trans[0].size(); j++) {
                if(str[i] == trans[0][j]) {
                    ch = true;
                    str[i] = toupper(trans[1][j]);
                    break;
                }
            }
        }

        for(int i = 0; i < str.size(); i++) {
            cout << str[i];
        }
        cout << endl;

        cout << "\n------------------------\n\n";
    }

    fclose(fp);
}