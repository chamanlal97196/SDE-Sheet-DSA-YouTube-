/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        //Naive Solution : run four Loop and cheak with target : 
        // Time : O(n^4) Space O(1)
        
        
        
        //Efficient Solution:  Time : O(n^3) Space : (n^2) //store resultant values:
        /*sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        int n=nums.size();
        
        int left, right;
        
        for(int i=0; i<n-3; i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 and nums[j]==nums[j-1]){
                    continue;
                }
                left=j+1, right=n-1;
                
                while(left<right){
                    long long int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum>target){
                        right--;
                    }
                    else if(sum<target){
                        left++;
                    }
                    else{
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        do{
                            left++;
                        }while(nums[left]==nums[left-1] and left<right);
                        
                        do{
                            right--;
                        }while(nums[right]==nums[right+1] and left<right);
                    }
                }
                
            }
            
        }
        return res;
        */
        
        // A Bit Efficient Solution: 
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
        
    }
};
