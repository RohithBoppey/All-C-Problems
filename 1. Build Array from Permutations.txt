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


vector<int> scanVector(int n){
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    return v;
}

void printVector(vector <int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "" << endl;
}

void solve1(vector<int>& v){
    int n = v.size();

    // idea is to store two numbers in 1 number

    // x and y needs to be stored

    // x + y * n -> combined number

    // c % n = x and c / n = x

    // combining x = v[i] and y = v[v[i]]

    for(int i = 0; i < n; i++){
        v[i] = v[i] + (v[v[i]] % n) * n;
    }

    printVector(v);

    // retrieve y
    for(int i = 0; i < n; i++){
        v[i] = v[i] / n;
    }
}   

void solve2(vector<int>& v){
    int n = v.size();

    // idea is to store the index
    vector<int> res;

    for(int i = 0; i < n; i++){
        res.pb(v[v[i]]);
    }

    for(int i = 0; i < n; i++){
        v[i] = res[i];
    }
}

void Sol(){
    int n;
    cin >> n;
    vector<int> v = scanVector(n);
    solve1(v);
    // solve2(v);
    printVector(v);
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