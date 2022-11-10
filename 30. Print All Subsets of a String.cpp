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

void printVector(set<string> a){
    for(auto x : a){
        cout << x << endl;
    }
}

void generateAllSubsets(string &s, set<string>& res, int i, string &curr){
    int n = s.length();
    
    if(i == n){
        res.insert(curr);
        return;
    }

    // to take and to not take
    // to not take
    generateAllSubsets(s, res, i + 1, curr);
    // to take
    curr.pb(s[i]);
    generateAllSubsets(s, res, i + 1, curr);
    curr.pop_back();
    return;
}


void Sol(){
    set<string> res;
    string s;
    cin >> s;   
    string curr = "";
    generateAllSubsets(s, res, 0, curr);
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