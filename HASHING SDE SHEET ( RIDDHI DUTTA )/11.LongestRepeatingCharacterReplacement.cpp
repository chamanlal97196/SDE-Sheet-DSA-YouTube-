/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

*/

// You can take help from this video : https://www.youtube.com/watch?v=gqXU1UyA8pk

// Main concept use in this problem is : sliding Window and hashing : 

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        /*int maxf=0, i=0, n=s.length();
        
        vector<int>count(26);
        
        for(int j=0; j<n; j++){
            maxf=max(maxf, ++count[s[j]-'A']);
            if(j-i+1>maxf+k){
                --count[s[i++]-'A'];
            }
            
        }
        return n-i;
        
        */
        
        /*
        we can replace maxf with max(count.values()),
it's easier to understand and only O(26N).
Now I improve it using a variable maxf so that it's O(N).

Time O(N)
Space O(26)
        */
        int res = 0, maxf = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < s.length(); ++i) {
            maxf = max(maxf, ++count[s[i]]);
            if (res - maxf < k)
                res++;
            else
                count[s[i - res]]--;
        }
        return res;
    }
};
