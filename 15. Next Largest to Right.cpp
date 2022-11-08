#include <bits/stdc++.h>
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

vector<int> findLargestToRight(vector<int> v){
    vector<int> res;    
    stack<int> s;

    int n = v.size();
 
    for(int i = n - 1; i >= 0; i--){
        if(s.empty()){
            res.pb(-1);
        }

        if(!s.empty()){
            if(s.top() > v[i]){
                // already greater is there
                res.pb(s.top());
            }else{
                // s.top() <= v[i]
                // pop until match is found
                while(!s.empty() && s.top() <= v[i]){
                    s.pop();
                }
                s.empty() ? res.pb(-1) : res.pb(s.top());
            }
        }

        s.push(v[i]);
    }

    reverse(res.begin(), res.end());
    return res;
}



void Sol(){
    int n;
    cin >> n;
    vector<int> v = scanVector(n);
    printVector(findLargestToRight(v));
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


/*

    LEETCODE SOLUTION: https://leetcode.com/problems/next-greater-element-i/submissions/


#define pb push_back

class Solution {
public:
    
    vector<int> solve(vector<int> v){
        vector<int> res;    
        stack<int> s;

        int n = v.size();

        for(int i = n - 1; i >= 0; i--){
            if(s.empty()){
                res.pb(-1);
            }

            if(!s.empty()){
                if(s.top() > v[i]){
                    // already greater is there
                    res.pb(s.top());
                }else{
                    // s.top() <= v[i]
                    // pop until match is found
                    while(!s.empty() && s.top() <= v[i]){
                        s.pop();
                    }
                    s.empty() ? res.pb(-1) : res.pb(s.top());
                }
            }

            s.push(v[i]);
        }

        reverse(res.begin(), res.end());
        return res;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int> v = solve(nums2);
        for(int i = 0; i < nums1.size(); i++){
            int ind = 0;
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            ind = it - nums2.begin();
            res.push_back(v[ind]);
        }
        return res;
    }
};




*/