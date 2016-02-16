//Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 
//
//
//
//Subscribe to see which companies asked this question
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        if ( nums.size() < 2)
        {
            return 0;
        }
        unordered_map<int, vector<int>>hash_map;
        
        for (int i = 0; i < nums.size(); i++)
        {
            hash_map[nums[i]].push_back(i);
            
            if (hash_map[nums[i]].size() >= 2)
            {
                if ((hash_map[nums[i]][hash_map[nums[i]].size()-1] - hash_map[nums[i]][hash_map[nums[i]].size()-2]) <= k)
                {
                    return 1;
                }
            }
        }
        return 0;
        
    }
};


