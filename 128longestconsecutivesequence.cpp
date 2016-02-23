//Given an unsorted array of integers, find the length of the longest consecutive elements sequence. 
//
//For example,
// Given [100, 4, 200, 1, 3, 2],
//  The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4. 
//
//  Your algorithm should run in O(n) complexity. 
//


class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int, int>hash_map;
        for ( int i = 0; i < nums.size(); i++)
        {
            hash_map[nums[i]] = i;
        }
        
        int maxlen = 0;
        for ( int i = 0; i < nums.size(); i++)
        {
            if ( hash_map.find(nums[i]-1) == hash_map.end())
            {
                int count  = 1;
                int nextelement = nums[i]+1;
                while(hash_map.find(nextelement) != hash_map.end())
                {
                    count++;
                    nextelement++;
                }
                
                maxlen = max(maxlen, count);
            }
        }
        
        return maxlen;
    }
};
