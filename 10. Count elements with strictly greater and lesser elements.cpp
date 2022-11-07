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

int findStrictGreaterCount(vector<int> v){
    // find min and max
    int mx = INT_MIN;
    int mn = INT_MAX;

    int n = v.size();

    for(int i = 0; i < n; i++){
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        if(v[i] > mn & v[i] < mx){
            count++;
        }
    } 

    return count;   
}

void Sol(){
    int n;
    cin >> n;
    vector<int> v = scanVector(n);
    cout << findStrictGreaterCount(v) << endl;
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