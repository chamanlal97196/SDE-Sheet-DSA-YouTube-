/*
Problem : SubArray Sums Divisible by K :
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0

*/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        //Naive Solution Time : O(n^2) space: O(1)
        /*
        A simple solution for this problem is to one by one calculate sum of all sub-arrays             possible and check divisible by K. The time complexity for this approach will be O(n^2).
        */
        
        int n = nums.size();
        if(n==0) return 0;
        
        int i = 0, count = 0;
        int curr_sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;// this is done because initial cumulative sum = 0 and that sum%k will be equal to 0 always
        
        while(i<n)
        {
            curr_sum+= nums[i++];
            int rem = curr_sum % k;
            if(rem<0) rem += k;
            
            if(mp.find(rem)!=mp.end())
                count+=mp[rem];
            
            mp[rem]++;
            
        }
        return count;
    }
};
