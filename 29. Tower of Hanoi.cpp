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


void PrintStepsForTowerOfHanoi(int n, int source, int destination, int helper){
    if(n == 1){
        // removing plate from source to destination safely
        cout << "Moving " << n << " from " << source << " to " << destination << endl;
        return;
    }

    // else
    
    // use the helper to shift the first n - 1 plates

    PrintStepsForTowerOfHanoi(n - 1, source, helper, destination);

    cout << "Moving " << n << " from " << source << " to " << destination << endl;

    PrintStepsForTowerOfHanoi(n - 1, helper, destination, source);

    return;

}

void Sol(){
    int n;
    cin >> n;
    int source = 1;
    int helper = 2;
    int destination = 3;
    PrintStepsForTowerOfHanoi(n, source, destination, helper);
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