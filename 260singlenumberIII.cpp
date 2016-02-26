//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. 
//
//For example: 
//
//Given nums = [1, 2, 1, 3, 2, 5], return [3, 5]. 
//
//Note:
//
//1.The order of the result is not important. So in the above example, [5, 3] is also correct.
//2.Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        vector<int>result;
        if ( 0 == nums.size())
        {
            return result;
        }
        
        int temp = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            temp = temp^nums[i];
        }
        
        int lastbit = temp - (temp&(temp-1));
        
        int temp1 = 0, temp2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (( nums[i]&lastbit) != 0)
            {
                temp1 = temp1^nums[i];
            }
            else
            {
                temp2 = temp2^nums[i];
            }
        }
        
        result.push_back(temp1);
        result.push_back(temp2);
        
        return result;
    }
};
