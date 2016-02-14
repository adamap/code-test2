//Given a set of distinct integers, nums, return all possible subsets. 
//
//Note:
//
//Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.
//
//
//For example,
// If nums = [1,2,3], a solution is: 
// [
//   [3],
//     [1],
//       [2],
//         [1,2,3],
//           [1,3],
//             [2,3],
//               [1,2],
//                 []
//                 ]
//


void subsets_it(vector<int>& nums, vector<vector<int>>&result)
{
    vector<int>set;
    int n = nums.size();
    int setnums = 1<<n;
    result.push_back(set);
    
    for (int i = 1; i < setnums; i++)
    {
        set.clear();
        
        long long index = 1;
        int pos = 0;
        while(index <= i)
        {
            if ( (index&i) > 0)
            {
                set.push_back(nums[pos]);
            }
            index <<= 1;    
            pos++;
        }
        result.push_back(set);
    }
    

}


void subsets_helper(vector<int>& nums, int index, vector<int>set, vector<vector<int>>&result)
{
    result.push_back(set);

    for (int i = index; i < nums.size(); i++)
    {
        set.push_back(nums[i]);
        subsets_helper(nums, i+1, set, result);
        set.pop_back();
    }

}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        
        vector<int>set;
        
        //subsets_helper( nums, 0, set, result);
        subsets_it( nums, result);       
        return result;
    }
};


