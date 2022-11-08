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

vector<int> findSmallerToLeft(vector<int> v){
    int n = v.size();

    vector<int> ans;
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(st.empty()){
            ans.pb(-1);
        }
        else{
            if(v[st.top()] < v[i]){
                ans.pb(st.top());
            }else{
                // <=
                while(!st.empty() && v[st.top()] >= v[i]){
                    st.pop();
                }

                if(st.empty()){
                    ans.pb(-1);
                }else{
                    ans.pb(st.top());
                }

            }
        }

        // storing index
        st.push(i);
    }


    return ans;
}


// slightly modified to have psuedoindex on extreme right -> n is the final index
vector<int> findSmallerToRight(vector<int> v){
    int n = v.size();

    vector<int> ans;
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
        if(st.empty()){
            ans.pb(n);
        }
        else{
            if(v[st.top()] < v[i]){
                ans.pb(st.top());
            }else{
                // <=
                while(!st.empty() && v[st.top()] >= v[i]){
                    st.pop();
                }

                if(st.empty()){
                    ans.pb(n);
                }else{
                    ans.pb(st.top());
                }

            }
        }

        st.push(i);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int maxAreaOfHistogram(vector<int> v){

    int n = v.size();
    vector<int> left = findSmallerToLeft(v);
    vector<int> right = findSmallerToRight(v);
    
    // printVector(left);
    // printVector(right);

    // once left and right are calculated, we can find width

    vector<int> width;
    vector<int> area;
    
    int mx = 0;
    
    for(int i = 0; i < n; i++){
        width.pb(right[i] - left[i] - 1);
        area.pb(v[i] * width[i]);
        mx = max(mx, area[i]);
    }  

    return mx;
}


/*

    4
    0 1 1 0
    1 1 1 1
    1 1 1 1
    1 1 0 0 

*/

int findMaxBinaryAreaPossible(vector<vector<int>> v){
    int ans = 0;

    int n = v.size();
        
    // allocating memory is needed

    // reason: index based retrieval without proper initialisation

    vector<int> modified(n);


    // we need to add the vertical weights and we need to modify it to be 0 because
    // we cant accept building in air
    // so keeping it to 0

    // and after one row is completed, we need to find max area -> coz could be anywhere

    /*
    
       0 1 1 0
    -> 1 1 1 1
       1 1 1 1 <-
       1 1 0 0 
    
    Hence 8 is the area

    */

    /*
        The configurations are:

        0 1 1 0
        1 2 2 1
        2 3 3 2
        3 4 0 0

        Finding max area of each modified row
        coz max area could be in any of the configuration
    */


    // row iteration
    for(int i = 0; i < n; i++){
        // col iteration
        for(int j = 0; j < n; j++){
            if(v[i][j] == 0){
                // directly keep 0 in the modified array
                modified[j] = 0;
            }else{
                // add to prev configuration
                modified[j] += v[i][j];
            }
        }
        ans = max(ans, maxAreaOfHistogram(modified));
    }

    // printVector(modified);


    return ans;
}

void Sol(){
    int n;
    cin >> n;
    vector<vector<int>> v;
    // cout << n << endl;
    for(int i = 0; i < n; i++){
        vector<int> temp = scanVector(n);
        v.pb(temp);  
    }
    // for(int i = 0; i < n; i++){
    //     printVector(v[i]);  
    // }

    cout << findMaxBinaryAreaPossible(v) << endl;   
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
    // RepSolution();
    Sol();
    return 0;
}