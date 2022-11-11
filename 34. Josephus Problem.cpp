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


void solve(vector<int>& v, int n, int k, int& ans, int index){
    if(n == 1){
        ans = v[0];
        return;
    }

    // kill every ((k - 1) + index % n) person
    int ind = ((k - 1) + index) % n;
    v.erase(v.begin() + ind);
    solve(v, n - 1, k, ans, ind);
    return;
}

int tellPos(int n, int k){
    // generate array of indices

    vector<int> v;
    for(int i = 0; i < n; i++){
        v.pb(i+1);
    }

    int ans = 0;
    solve(v, n, k, ans, 0);
    return ans;
}

/*

2
40 7
5 2

*/

    void Sol(){
    int n, k;
    cin >> n >> k;
    cout << tellPos(n, k) << endl;
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