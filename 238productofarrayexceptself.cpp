//
//
//Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
//Solve it without division and in O(n).
//
//For example, given [1,2,3,4], return [24,12,8,6]. 
//
//Follow up:
// Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
//
vector<int> productExceptSelf1(vector<int>& nums) 
{
    vector<int>product(nums.size(), 1);
    vector<int>productl(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++)
    {
        productl[i] = productl[i-1]*nums[i-1];
    }
        
    vector<int>productr(nums.size(), 1);
    for (int i = nums.size()-2; i >= 0; i--)
    {
        productr[i] = productr[i+1]*nums[i+1];
    }
        
    for (int i = 0; i < nums.size(); i++)
    {
        product[i] = productl[i]*productr[i];
    }
    
    return product;
}

vector<int> productExceptSelf2(vector<int>& nums)
{
    vector<int>product(nums.size(), 1);
    int left = 1;
    
    for ( int i = 0; i < nums.size()-1; i++)
    {
        left *= nums[i];
        product[i+1] *=left;
    }
    
    int right = 1;
    for ( int i = nums.size()-1; i > 0; i--)
    {
        right *=nums[i];
        product[i-1] *= right;
    }
    return product;
}
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        return productExceptSelf2(nums);
    }
};
