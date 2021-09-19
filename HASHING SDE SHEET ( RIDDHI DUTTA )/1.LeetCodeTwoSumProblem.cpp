/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        
       /* //Naive Solution : Time : O(n^2)  Space : O(1)
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    return {i, j};
                }
            }
            
        }
        return {-1,-1};
        */
        
        // Efficient Solution: Time : O(n)  space : O(n)
        int n = nums.size();
        int a,b;
        
        unordered_map<int, int>mp;
        // for(int i=0; i<n; i++){
        //     mp.insert({nums[i], i}); //This is failed  suppose we have array : 
                                        // arr[]={2,3,8,11};
                                        // target=6;
                                        // now at conditon : (6-3) we serach in hashmp and find 
                                        // find (3 ) in array but its not ture;
        // }
        for(int i=0; i<n; i++){
            auto it = mp.find(target -nums[i]);
            if(it!=mp.end() and i!=it->second){
                a =i;
                b = it->second;
            }
            mp.insert({nums[i], i});
        }
        return {b,a};  
        
    }
};
