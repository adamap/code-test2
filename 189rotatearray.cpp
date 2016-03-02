//
//
//
//
//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 
//



void shiftbyone(vector<int>&nums)
{
    int tem = nums[nums.size()-1];
    
    int i = nums.size()-1;
    while(i>0)
    {
        nums[i] = nums[i-1];
        i--;
    }
    nums[0] = tem;
}

void rev(vector<int>&nums, int beg, int end) 
{
    while(beg < end) 
    {
        int tmp = nums[beg];
        nums[beg] = nums[end];
        nums[end] = tmp;
        beg++;
        end--;
    }    
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k =  k%nums.size();
        if (k == 0)
        {
            return;
        }
        
        //for ( int i = 0; i < k; i++)
        //{
        //    shiftbyone(nums);
        //}
        
        rev(nums, 0, nums.size()-1);
        rev(nums, 0, k-1);
        rev(nums, k, nums.size()-1);
    }
};
