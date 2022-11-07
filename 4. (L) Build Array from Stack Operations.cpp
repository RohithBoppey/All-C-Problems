https://leetcode.com/problems/build-an-array-with-stack-operations/submissions/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int k = 0;
//         k means length
        
        vector<string> res;
        for(int i = 0; i < n; i++){
            if(k >= target.size()){
                return res;
            }
            
            if(target[k] == i + 1){
                res.push_back("Push");
                k++;
            }else{
                res.push_back("Push");
                res.push_back("Pop");
            }
        }  
        
        
        return res;
    }
};