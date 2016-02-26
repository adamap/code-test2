//Given an array of integers, every element appears three times except for one. Find that single one. 
//
//Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
//

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        //vector<int>bitflag(32, 0);
        int bitcount  = 0;
        int start = 1;
        int result = 0;
        for ( int j = 0; j < 32; j++)
        {
            bitcount = 0;
            start = 0x01<<j;
            for ( int i = 0; i < nums.size(); i++)
            {
                if ( (start&nums[i]) != 0)
                {
                    bitcount++; 
                }
            }
            
            if ((bitcount %3) != 0)
            {
                result |= start;
            }
            
        }
        return result;        
    }
};
