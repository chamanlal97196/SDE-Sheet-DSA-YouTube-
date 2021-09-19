/*
Given an array of distinct integers, print all the pairs having positive value and negative value of a number that exists in the array. We need to print pairs in order of their occurrences. A pair whose any element appears first should be printed first.

Examples:  

Input  :  arr[] = { 1, -3, 2, 3, 6, -1 }
Output : -1 1 -3 3

Input  :  arr[] = { 4, 8, 9, -4, 1, -1, -8, -9 }
Output : -1 1 -4 4 -8 8 -9 9
*/

#include <bits/stdc++.h>
using namespace std;
 
// Print pair with negative and positive value
void printPairs(int arr[], int n)
{
    vector<int> v;
 
    // For each element of array.
    for (int i = 0; i < n; i++)
 
        // Try to find the negative value of
        // arr[i] from i + 1 to n
        for (int j = i + 1; j < n; j++)
 
            // If absolute values are equal print pair.
            if (abs(arr[i]) == abs(arr[j]))
                v.push_back(abs(arr[i]));     
 
    // If size of vector is 0, therefore there is no
    // element with positive negative value, print "0"
    if (v.size() == 0)
       return;
 
    // Sort the vector
    sort(v.begin(), v.end());
 
    // Print the pair with negative positive value.
    for (int i = 0; i < v.size(); i++)
        cout << -v[i] << " " << v[i];   
}
 
// Driven Program
int main()
{
    int arr[] = { 4, 8, 9, -4, 1, -1, -8, -9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printPairs(arr, n);
    return 0;
}


// Hashing Solution : :

#include <bits/stdc++.h>
using namespace std;
 
// Print pair with negative and positive value
void printPairs(int arr[], int n)
{
    vector<int> v;
    unordered_map<int, bool> cnt;
 
    // For each element of array.
    for (int i = 0; i < n; i++) {
 
        // If element has not encounter early,
        // mark it on cnt array.
        if (cnt[abs(arr[i])] == 0)
            cnt[abs(arr[i])] = 1;
 
        // If seen before, push it in vector (
        // given that elements are distinct)
        else {
            v.push_back(abs(arr[i]));
            cnt[abs(arr[i])] = 0;
        }
    }
 
    if (v.size() == 0)
        return;
 
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << -v[i] << " " << v[i] << " ";
}
 
// Driven Program
int main()
{
    int arr[] = { 4, 8, 9, -4, 1, -1, -8, -9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printPairs(arr, n);
    return 0;
}
