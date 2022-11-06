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


string solve(string s, char k){
    int i = 0, j = 0;
    int n = s.length();

    for(i = 0; i < n; i++){
        // check for first substring after removing
        if(i == n - 1 && s[i] == k){
            return s.erase(i, 1);
        }

        if(s[i] == k and s[i+1] > k){
            return s.erase(i, 1);
        }
        if(s[i] == k){
            j = i;
        }
    }

    // remove last occurance occurance
    return s.erase(j, 1);
}



void Sol(){
    string s;
    char k;   
    cin >> s >> k;
    cout << solve(s, k) << endl;
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