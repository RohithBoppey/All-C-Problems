//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

#define pb push_back
#define ll long long int

using namespace std;

/*-------------------------------------------
--------------Rohith's Solution--------------
---------------------------------------------*/

#define maxX(a,b) (a>b?a:b)
#define minX(a,b) (a<b?a:b)
#define isEven(a) ((a%2==0)?1:0)
#define isOdd(a) ((a%2==0)?0:1)
#define isNeg(a) ((a<0)?1:0)
#define loop(n) for(int i = 0; i < n; i++)
#define loop2(n) for(int j = 0; j < n; j++)
#define abs(a) ((a<0)?-a:a)

void printVector(vector<string> a){
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;
}


void generateAllValidParanthesis(int n, vector<string> &res, string &curr, int close, int open){
    if(close == 0 && open == 0){
        res.pb(curr);
        return;
    }

    // check if close > open

    // always open > close

    if(open != 0){
        curr += '(';
        generateAllValidParanthesis(n, res, curr, close, open - 1);
        curr.pop_back(); 
    }

    if(close > open){
        curr += ')';
        generateAllValidParanthesis(n, res, curr, close - 1, open);
        curr.pop_back(); 
    }
}

void Sol(){
    int n;
    cin >> n;
        vector<string> res;
        string init = "";
        generateAllValidParanthesis(n, res, init, n, n);
        printVector(res);
}

void RepSolution(){
    int t;
    cin >> t;
    while(t!=0){
        Sol();
        t--;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //RepSolution();
    Sol();
    return 0;
}