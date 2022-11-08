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

void insertIntoRightPos(vector<int> &v, int t){
    
    int n = v.size();
    if(n == 0 || v[n-1] <= t){
        v.pb(t);
        return;
    }

    int last = v[n-1];
    v.pop_back();
    insertIntoRightPos(v, t);
    v.pb(last);

}

void sortVectorWithRecursion(vector<int> &v){
    
    int n = v.size();
    if(n == 1){
        // sorted
        return;
    }

    int t = v[n-1];
    v.pop_back();
    sortVectorWithRecursion(v);
    insertIntoRightPos(v, t);
}

/*
    2
    12
    0 1 0 2 1 0 1 3 2 1 2 1
    7
    2 3 7 5 4 6 9
*/


void Sol(){
    int n;   
    cin >> n;
    vector<int> v = scanVector(n);
    sortVectorWithRecursion(v);
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
    RepSolution();
    // Sol();
    return 0;
}