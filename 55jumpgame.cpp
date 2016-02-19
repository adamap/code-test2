//Given an array of non-negative integers, you are initially positioned at the first index of the array. 
//
//Each element in the array represents your maximum jump length at that position. 
//
//Determine if you are able to reach the last index. 
//
//For example:
// A = [2,3,1,1,4], return true. 
//
// A = [3,2,1,0,4], return false. 

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        if ( 0 == nums.size())
        {
            return 0;
        }
        
        int n = nums.size();
        vector<int>canjump(n, 0);
        
        canjump[0] = 1;
        
        for ( int i = 1; i < n; i++)
        {
            for ( int j = i-1; j >= 0; j--)
            {
                if (1 == canjump[j] && j+nums[j] >= i )
                {
                   canjump[i] = 1;
                   break;
                }
            }
        }
        
        return canjump[n-1];
    }
};
