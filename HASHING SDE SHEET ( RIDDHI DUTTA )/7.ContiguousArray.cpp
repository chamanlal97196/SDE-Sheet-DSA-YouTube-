/*
Problem : Longest Contiguous Array: 

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        //we need to find the longest subsequence in the form of 
        //x,x+1, x+2, x+3......x+i;
        //with these elements appearing in any order .
        
        //Naive Solution : Time : O(nlogN) space :O(1);
        
        // Hint : Sorting :
        /*
        sort(nums.begin(), nums.end());
        int res=1;
        int curr=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]+1){
                // cout<<"hello World"<<endl;
                curr++;
            }
            else {
                res=max(res, curr);
                curr=1;
            }    
        }
        res=max(res, curr);
        return res;
        
        */
        
        /*Efficient Solution : Time : O(n) Space : O(n);
        
        We first insert all elements into a hash table.
            Then with 2n look ups we find the result   
            Let's see the implementation:: 
        */
        
        /* This solution is not working duplicate like this test case :[0,1,0,1] op : 4;
        unordered_set<int>h(nums.begin(), nums.end());
        int res=1;
        for(auto x : h){
            if(h.find(x-1)==h.end()){
                int curr=1;
                while(h.find(x+curr)!=h.end()){
                    curr++;
                }
                res=max(res, curr);
            }
        }
        return res;  
        */
       int sum=0;
       unordered_map<int,int> m;
       unsigned int longestContArray = 0;
       
        for(int i=0;i<nums.size();i++){
           sum += (nums[i]==0)?-1:1;
           
           auto it = m.find(sum);
           
           if(sum == 0){
              if(longestContArray < i+1)
               longestContArray = i+1;
           }
           else if(it != m.end()){
              if(longestContArray < i-it->second)
               longestContArray = i-it->second;
           }
           else if(it == m.end())
                m.insert({sum,i});
       }
        return longestContArray;
    }
};
