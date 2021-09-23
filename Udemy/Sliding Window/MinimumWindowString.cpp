/*Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

class Solution {
public:
    string minWindow(string s, string t) {
    /* vector<int>fs(256);
        vector<int>ft(256);
        
        int m=s.length();
        int n=t.length();
        
        if(n>m){
            minWindow(t, s);
        }
        
        for(int i=0; i<n; i++){
            ft[t[i]]++;
        }
        int count=0;
        int start=0;
        int start_idx=-1;
        int window_size=0;
        int min_so_far=INT_MAX;
        
        
        for(int i=0; i<m; i++){
            char ch=s[i];//insert into vector.
            fs[ch]++;
            
            if(ft[ch]!=0 and fs[ch]<=ft[ch]){
                count++;
            }
            if(count==n){
                //Removing unwanted characters.
                if(ft[s[start]]==0 and fs[s[start]]>ft[s[start]]){
                    fs[s[start]]--;
                    start++;
                }
                //note window size:
                window_size=i-start+1;
                if(window_size<min_so_far){
                    min_so_far=window_size;//we want to min window size;
                    start_idx=start;
                }
            }
        }
        if(start_idx==-1){
            return "";
        }
        return s.substr(start_idx, min_so_far);
      */
        if (s.size() == 0 || t.size() == 0) return "";
        vector<int> remaining(128, 0);
        int required = t.size();
        for (int i = 0; i < required; i++) remaining[t[i]]++;
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while(i <= s.size() && start < s.size()) {
            if(required) {
                if (i == s.size()) break;
                remaining[s[i]]--;
                if (remaining[s[i]] >= 0) required--;
                i++;
            } else {
                if (i - start < min) {
                    min = i -start;
                    left = start;
                }
                remaining[s[start]]++;
                if (remaining[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};
