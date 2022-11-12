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


int solve(vector<int> val, vector<int> weights, int n, int capacity, int (&t)[100][100]){
    
    // understand that we are passing by reference by int (&t)[100][100]
    
    // almost similar to previous version

    // we check if we did not recompute for that n value and capacity

    // hence this check
    
    if(t[n][capacity] != -1){
        return t[n][capacity];
    }


    // else we need to compute the information and then store it inside the 
    // current configuration

    // like t[n][capacity] = // some value solved //

    if(weights[n-1] <= capacity){
        // can and cannot include
        t[n][capacity] = max(
            val[n-1] + solve(val, weights, n - 1, capacity - weights[n-1], t),
            solve(val, weights, n - 1, capacity, t)
            );
    }
    else{
        t[n][capacity] = solve(val, weights, n - 1, capacity, t);
    }

    // at the end of computation, we return the freshly solved value
    return t[n][capacity];
}

int KnapsackMemoized(vector<int> val, vector<int> weights, int n, int capacity){
    // initialize the array
    int t[100][100];

    // if n == 0 -> -1 cannot add any terms no weights 
    // if capacity == 0 -> -1 no weights further can be added

    // initialising with -1 for all

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < capacity+1; j++){
            t[i][j] = -1;
        }
    }

    // for(int i = 1; i < n+1; i++){
    //     for(int j = 1; j < capacity+1; j++){
    //         cout << t[i][j] << ' ';
    //     }
    // }

    return solve(val, weights, n, capacity, t);

}


/*
    2
    4
    1 4 5 7
    1 3 4 5
    7
    3
    60 100 120
    10 20 30
    50

*/

void Sol(){
    int n;
    cin >> n;
    vector<int> val = scanVector(n);
    vector<int> weights = scanVector(n);   
    int capacity;
    cin >> capacity;
    cout << KnapsackMemoized(val, weights, n, capacity) << endl;
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