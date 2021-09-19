/*

Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3


Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.

*/



class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k){
        //code here.
        // Naive Solution : O((n-k)*k*k)  Space : O(1);
        /*vector<int>ans;
        for(int i=0; i<=n-k; i++){
            int count=0;
            for(int j=0; j<k; j++){
                bool flag=false;
                for(int p=0; p<j; p++){
                    if(arr[i+j]==arr[i+p]){
                        // cout<<"Hello world"<<endl;
                        flag=true;
                        break;
                    }
                    
                }
                if(flag==false){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans; */
        
        //Efficient Solution :  Time O(n). Space O(k) (where k is window size)
        //Basic Steps : 1. create a frequence map of first k items.
        //2.print size of frequence map.
        //3. for(int i=k; i<n; i++) lets see implementation: for it:
        
        
        vector<int>res;
        unordered_map<int, int>mp;
        for(int i=0; i<k; i++){
            mp[arr[i]]++;
        }
        res.push_back(mp.size());
        
        for(int i=k; i<n; i++){
            mp[arr[i-k]]--; //decrese the frequence
            if(mp[arr[i-k]]==0){    //if frequence become 0 then erase from map.
                mp.erase(arr[i-k]);
                
            }
            mp[arr[i]]+=1; // insert new element ;
            res.push_back(mp.size()); //push into vector.
        }
        return res;
        
        
        
    }
};
