
/*
 Problem : Housing Problem :
 
 
 ip : plots[]={1,3,2,1,4,1,3,2,1,1,2};
      sum : k=8;
 op : 2 5 (2,1,4,1) //which is equal to 8;
      4 6 
      5 9
*/
#include <bits/stdc++.h>
using namespace std;

//Naive Solution : 
int isSubArray(vector<int>& arr, int k){
	for(int i=0; i<arr.size(); i++){
		int curr_sum=0;
		for(int j=i; j<arr.size(); j++){
			curr_sum+=arr[j];
			if(curr_sum==k){
				cout<<i<<" "<<j<<endl;
			}
			
		}
	}
}

int isSubArrays(vector<int>&arr, int k){
	int j=0;
	int curr_sum=arr[0];
	
	for(int i=1; i<arr.size(); i++){
		
		//Remove the j th element(from the left) from curr_sum : 
		while(k<curr_sum and j<i-1){
			curr_sum-=arr[j];
			j++;
		}
		//if curr_sum is equal to k then print the index;
		if(curr_sum==k){
			cout<<j<<" "<<i-1<<endl;
		}
		//Add the element :
		if(i<arr.size()){
			curr_sum+=arr[i];
		}
	}
}

int main()
{
	// std::cout << "Hello, World" << std::endl;
	vector<int>v={1,3,2,1,4,1,3,2,1,1,2};
	int k=8;
	isSubArray(v, k);
	cout<<endl;
	isSubArrays(v, k);
	return 0;
}
