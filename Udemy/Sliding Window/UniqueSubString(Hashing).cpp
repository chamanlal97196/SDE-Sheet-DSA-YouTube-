/*
 Problem : UniQue characters string :
 ip : str : chamalal
      op : cham 
      
      
 
*/

#include <bits/stdc++.h>
using namespace std;

/*
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
    //int lengthOfLongestSubstring(string s) {
        
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

// Efficient Solution :
string uniqueChar(string &str){
	int n=str.length();
	unordered_map<char, int>m;
	int i=0,j=0;
	int window_len=0;
	int max_window_len=0;
	int start_window=0;
	
	while(i<n and j<n){
		char ch=str[j];
		if(m.count(ch) and m[ch]>=i){
			i=m[ch]+1;
			window_len=j-i;
		}
		// insert into hashmap
		m[ch]=j;
		window_len++;
		j++;
		
		//udate sliding window at every step :
		if(window_len>max_window_len){
			max_window_len=window_len;
			start_window=i;
		}
	}
	return str.substr(start_window, max_window_len);
}
int main()
{
	// std::cout << "Hello, World" << std::endl;
	string str="chamanlal";
	cout<<uniqueChar(str);
	return 0;
}
