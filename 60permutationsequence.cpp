//The set [1,2,3,¡,n] contains a total of n! unique permutations.
//
//By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3): 
// 1."123"
// 2."132"
// 3."213"
// 4."231"
// 5."312"
// 6."321"
//
//
// Given n and k, return the kth permutation sequence.
// 

class Solution {
public:
    string getPermutation(int n, int k) 
    {
        string result;
        vector<int>nums(n);
    vector<int>factorial(n+1, 1);
    for ( int i = 1; i <= n; i++)
    {
        factorial[i] = factorial[i-1]*i;
        nums[i-1] = i;
    }

    if ( k > factorial[n])
    {
        return result;
    }

    k--;
    for ( int i = n; i >= 1; i--)
    {
        int j = k/factorial[i-1];
        k = k%factorial[i-1];
        result.push_back(nums[j]+'0');
            nums.erase(nums.begin()+j);
        }
        
        return result;
    }
};
