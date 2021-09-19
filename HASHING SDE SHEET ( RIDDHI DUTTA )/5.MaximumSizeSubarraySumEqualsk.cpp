/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn’t one, return 0 instead.

Note:

The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
*/


#include <bits/stdc++.h>
using namespace std;

/*
 Naive Solution : Time O(n^2) Space O(1)
    
    cheak all Subarray is length is greater than previous then update:
    
    Efficient Solution : Time O(n) Space : O(n).
     Use unordered map and store presum and index as well.
     
     let's see implementation :
*/
//Naive Solution : Time : O(n^2)  Space : O(1);
int maxSizeSubArray(vector<int>& arr, int sum){
	int res=0;
	for(int i=0; i<arr.size(); i++){
		int currSum=0;
		for(int j=i; j<arr.size(); j++){
			currSum+=arr[j];
			if(currSum==sum){
				res=max(res, j-i+1);
			}
		}
	}
	return res;
}

//Efficient Solution : Time O(n)  Space : O(n);

int maxSizeSubArrayO(vector<int>&arr, int sum){
	int res=0;
	unordered_map<int, int>mp;
	int preSum=0;
	for(int i=0; i<arr.size(); i++){
		preSum+=arr[i];
		if(preSum==sum){
			res=i+1;
		}
		if(mp.find(preSum)==mp.end()){
			mp.insert({preSum, i});
		}
		if(mp.find(preSum-sum)!=mp.end()){
			res=max(res, i-mp[preSum-sum]);
		}
	}
	return res;
}

int main()
{
	// std::cout << "Hello, World" << std::endl;
	vector<int>v={3,1,0,1,8,2,3,6};
	cout<<maxLen(v, 5)<<endl;
	cout<<maxLenO(v,5)<<endl;
	return 0;
}
