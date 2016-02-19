//
//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//Ensure that numbers within the set are sorted in ascending order.
//
//
//
//Example 1:
//
//Input: k = 3, n = 7
//
//Output: 
//
//[[1,2,4]]
//
//
//
//
//Example 2:
//
//Input: k = 3, n = 9
//
//Output: 
//
//[[1,2,6], [1,3,5], [2,3,4]]
//


void combinationSum3_helper(int k, int n, int index, vector<int>set, vector<vector<int>>&result, int sum)
{
    if (sum == n && set.size() == k)
    {
        result.push_back(set);
        return;
    }
    if ( sum > n || set.size() > k)
    {
        return;
    }
    
    for ( int i = index; i <= 9; i++)
    {
        set.push_back(i);
        sum += i;
        combinationSum3_helper(k, n, i+1, set, result, sum);
        set.pop_back();
        sum -= i;
    }
    
}


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        
        vector<vector<int>>result;
        vector<int>set;
        int sum = 0;
        
        combinationSum3_helper(k, n, 1, set, result, sum);
        return result;      
    }
};
