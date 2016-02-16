//Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k. 

int loopsearch(vector<int>& nums, int k, int t)
{
    if ( nums.size() < 2)
    {
        return 0;
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if ( j == i)
            {
                continue;
            }
            if ( abs(nums[j] - nums[i]) <= t && abs(i-j) <= k)
            {
                return 1;
            }
        }
    }
    return 0;
}

int bstsearch(vector<int>& nums, int k, int t)
{
    if ( nums.size() < 2)
    {
        return 0;
    }

    multiset<long long>bst;
    
    for ( int i = 0; i < nums.size(); i++)
    {
        if ( bst.size() == k+1)
        {
            bst.erase(bst.find(nums[i-k-1]));
        }
        
        multiset<long long>::iterator it;
        
        it = bst.lower_bound(nums[i]);
        if ( it != bst.end() && abs(*it - nums[i]) <= t)
        {
            return 1;
        }
        
        it = bst.upper_bound(nums[i]);
        if ( it != bst.begin() && abs(*(--it) - nums[i]) <= t)
        {
            return 1;
        }
        bst.insert(nums[i]);
    }
    return 0;    
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        //return loopsearch(nums, k, t);
        return bstsearch( nums,  k, t);
    }
};
