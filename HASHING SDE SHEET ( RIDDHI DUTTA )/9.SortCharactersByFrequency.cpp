/*
Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

*/

class Solution {
public:
    
   static bool cmp(pair<char,int> a, pair<char,int> b){
            return a.second > b.second;
      }      
    string frequencySort(string s) {
        
        map<char,int> m;
        for(char c: s) m[c]++;
        vector<pair<char,int>> v;
        for(auto x: m) v.push_back({x.first,x.second});
        sort(v.begin(),v.end(),cmp);
        s="";
        for(auto x: v){
            while(x.second--){
                s+=x.first;    
            }
        }
        return s;
        
        
        //Other Solution :
        /*
        unordered_map<char,int> freq;           //for frequency of characters
        priority_queue<pair<int,char>> maxheap; //maxheap according to frequency of characters
        for(char c: s)
            freq[c]++;
        for(auto it: freq)
            maxheap.push({it.second,it.first}); //heap will be constructed on the basis of frequency
        s="";   
        while(!maxheap.empty()){
            s+=string(maxheap.top().first,maxheap.top().second); //frequency times the character
            maxheap.pop();
        }
        return s;
        */
    }
};
