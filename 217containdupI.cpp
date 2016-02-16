

//Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        if ( nums.size() < 2 )
        {
            return 0;
        }
        unordered_map<int, int>hash_map;
        
        for( int i = 0; i < nums.size(); i++)
        {
            hash_map[nums[i]]++;
            if (hash_map[nums[i]] >= 2)
            {
                return 1;
            }
        }
        
        return 0;
    }
};
