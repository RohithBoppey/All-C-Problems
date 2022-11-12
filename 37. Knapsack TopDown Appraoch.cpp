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

int KnapsackTopDownApproach(vector<int> val, vector<int> weights, int n, int capacity, int (&t)[100][100]){
    
    // base case would simply be checking with n == 0 or w == 0

    // no recursion in this
    // just iteration

    for(int i = 0; i < n + 1; i++){
        t[i][0] = 0;        
    }
    
    for(int j = 0; j < capacity + 1; j++){
            t[0][j] = 0;
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < capacity + 1; j++){
            
            // check for weights

            // make sure to understand why j is there here

            // because if the weight is less than the current capacity
            // which is j

            // MAIN MISTAKE HERE
            if(weights[i-1] <= j){
                // to take and to not take

                t[i][j] = max(
                    val[i-1] + t[i - 1][j - weights[i-1]],
                    t[i - 1][j]
                    );

            }
            else{

                // directly decrement i value and capacity doesnt change
                t[i][j] = t[i - 1][j];
            }

        }
    }

    return t[n][capacity];

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

    int t[100][100];
    cout << KnapsackTopDownApproach(val, weights, n, capacity, t) << endl;
    
    // for(int i = 0; i < n + 1; i++){
    //     for(int j = 0; j < capacity + 1; j++){
    //         cout << t[i][j] << ' ';
    //     }
    //     cout << "" << endl;
    // }
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