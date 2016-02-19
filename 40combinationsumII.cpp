//
//
//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
//
//Each number in C may only be used once in the combination. 
//
//Note:
//
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, ¡ , ak) must be in non-descending order. (ie, a1 ¡ a2 ¡ ¡ ¡ ak).
//The solution set must not contain duplicate combinations.
//
//
//For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
// A solution set is: 
// [1, 7] 
// [1, 2, 5] 
// [2, 6] 
// [1, 1, 6] 



void combinationSum2_helper(vector<int>&candidates, int target, int index, vector<vector<int>>&result, vector<int> set, int sum)
{
    if ( sum == target)
    {
      
       result.push_back(set);
       return;
    }
    if ( sum > target)
    {
        return;
    }
    
    for ( int  i = index; i < candidates.size(); i++)
    {
        if (( i > index) && candidates[i] == candidates[i-1])
        {
            continue;
        }
        sum += candidates[i];
        set.push_back(candidates[i]);
        combinationSum2_helper(candidates, target, i+1, result, set, sum);
        sum -= candidates[i];
        set.pop_back();
    }
    
}


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>result;
        vector<int>set;
        
        int sum = 0;
        combinationSum2_helper(candidates, target, 0, result, set, sum);
        
        return result;
        
    }
};
