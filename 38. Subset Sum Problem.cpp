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

int SubsetSumPossible(vector<int> v, int sum, int n){
    // initialise a 2d array
    int t[100][100];

    // int t[n+1][sum+1]

    for(int i = 0; i < n + 1; i++){
        t[i][0] = 1;
    }
    for(int i = 0; i < sum + 1; i++){
        t[0][i] = 0;
    }

    t[0][0] = 1;


    // after initialsing, we need to iterate from 1 to end
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < sum + 1; j++){

            // check if sum can be updated or not
            if(v[i-1] <= j){
                // can be updated or not
                t[i][j] = t[i-1][j - v[i-1]] || t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }   

        }
    }

    // for(int i = 0; i < n + 1; i++){
    //     for(int j = 0; j < sum + 1; j++){
    //         cout << t[i][j] << ' '; 
    //     }
    //     cout << "" << endl;
    // }

    return t[n][sum];
}

/*

5
2 3 7 8 10
11

-> 1

*/

void Sol(){
    int n;
    cin >> n;
    vector<int> v = scanVector(n);
    int sum;
    cin >> sum;
    cout << SubsetSumPossible(v, sum, n) << endl;
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