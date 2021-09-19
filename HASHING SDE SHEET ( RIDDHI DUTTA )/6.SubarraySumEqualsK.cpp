/*

Subarray Sum Equals K :
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        //Naive Solution : Time O(n^2) Space : O(1);
        /*
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            int currSum=0;
            for(int j=i; j<nums.size(); i++){
                currSum+=nums[j];
                if(currSum==k){
                    ans++;
                }
            }
        }
        return ans;
        */
        
        //Efficient Solution: Time : O(n)  Space O(n);
        
        int ans=0,sum=0;
        unordered_map<int,int>mp;
       
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) ans++;
            if(mp.find(sum-k)!=mp.end())
                ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};
