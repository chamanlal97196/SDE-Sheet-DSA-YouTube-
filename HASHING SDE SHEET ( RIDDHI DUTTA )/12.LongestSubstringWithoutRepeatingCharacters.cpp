/*
 Problem : Longest Substring Without Repeating Characters :
 
 Description : 
 Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


class Solution {
public:
    
    /*bool areDistinct(string &str, int i, int j){
        vector<bool>visited(256);
        for(int k=i; k<=j; k++){
            if(visited[str[k]]==true){
                return false;
            }
            visited[str[i]]=true;
        }
        return true;
    }
    */
    int lengthOfLongestSubstring(string s) {
        
        // Very Naive Solution : Time O(n^3) Space: O(256);
        
        /*int n=s.length();
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(areDistinct(s, i, j)){
                    res=max(res, j-i+1);
                }
            }
        }
        return res;
        */
        
        // Better Solution : time : O(n^2) Space : O(256);
        /*int n=s.length();
        if(n==0 || n==1) return n;
        int res=0;
        for(int i=0; i<n; i++){
            vector<bool> visited(256);
            for(int j=i; j<n; j++){
                if(visited[s[j]]==true) break;
                else{
                    res=max(res, j-i+1);
                    visited[s[j]]=true;
                }
            }
        }
        return res;
        */
        
        //Efficient Solution : Time O(n);
        /*
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
        */
		
		//Time Complexity: O(n)
		/*
Space Complexity: O(min of a,b) for the unordered set. a, is the upper bound of the space complexity.
Where a: Size of the string
b: Size of the number of characters in the character-set
	*/
        unordered_set<char> set;
    
		int i = 0, j = 0, n = s.size(), ans = 0;
    
		while( i<n && j<n)
		{
			if(set.find(s[j]) == set.end()) //If the character does not in the set
			{
				set.insert(s[j++]); //Insert the character in set and update the j counter
				ans = max(ans, j-i); //Check if the new distance is longer than the current answer
			}
			else
			{
				set.erase(s[i++]); 
				/*If character does exist in the set, ie. it is a repeated character, 
				we update the left side counter i, and continue with the checking for substring. */
			}
		}
    
		return ans;
    }
};
