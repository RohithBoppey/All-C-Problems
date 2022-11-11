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

void addingSpaces(string &s, set<string> &res, int i){

    int n = s.size();

    if(i == n - 1){
        res.insert(s);
        return;
    }

    // to add and to not add

    // to not add
    addingSpaces(s, res, i + 1);

    // to add
    s.insert(i + 1, " ");
    addingSpaces(s, res, i + 2);
    s.erase(i + 1, 1);
    return;

}

void Sol(){
    set<string> res;
    string s;
    cin >> s;   
    addingSpaces(s, res, 0);
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