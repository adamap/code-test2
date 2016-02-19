//
//Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
//
//The same repeated number may be chosen from C unlimited number of times. 
//
//Note:
//
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, ¡ , ak) must be in non-descending order. (ie, a1 ¡ a2 ¡ ¡ ¡ ak).
//The solution set must not contain duplicate combinations.
//
//
//For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 



void combinationSum_helper( vector<int>& candidates, int target, int index, vector<int>set, vector<vector<int>>&results, int sum)
{
    if ( sum == target)
    {
        //sort(set.begin(), set.end());
        results.push_back(set);
        return;
    }
    if ( sum > target)
    {
        return;
    }
    
    
    for ( int i = index; i < candidates.size(); i++)
    {
        if ( i > index && candidates[i] == candidates[i-1])
        {
            continue;
        }
        set.push_back(candidates[i]);
        sum += candidates[i];
        combinationSum_helper(candidates, target, i, set, results, sum);
        set.pop_back();
        sum -= candidates[i];
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>results;
        vector<int>set;
        int sum=0;
        combinationSum_helper( candidates, target, 0, set, results, sum);
        
        return results;
    }
};
