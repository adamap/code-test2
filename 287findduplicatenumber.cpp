//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one. 
//
//Note:
//
//1.You must not modify the array (assume the array is read only).
//2.You must use only constant, O(1) extra space.
//3.Your runtime complexity should be less than O(n2).
//4.There is only one duplicate number in the array, but it could be repeated more than once.
//
wap(vector<int>& nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

int findDuplicatebs(vector<int>& nums)
{
    for ( int i = 0; i < nums.size(); i++)
    {
        if ( nums[i] == i+1)
        {
            continue;
        }
        
        while( nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != i+1 )
        {
            if ( nums[nums[i]-1] == nums[i])
            {
                return nums[i];
            }
            swap(nums, nums[i]-1, i);
        }
    }
    
    return 0;
}

//binary search
int findDuplicatebsearch(vector<int>& nums)
{
    int min = 0, max = nums.size()-1;
    
    while(min <= max)
    {
        int mid = min+(max-min)/2;
        
        int cnt = 0;
        
        for ( int i = 0; i < nums.size(); i++)
        {
            if ( nums[i] <= mid)
            {
                cnt++;
            }
        }
        
        if ( cnt > mid)
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    
    return min;    
}

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        if ( 0 == nums.size())
        {
            return 0;
        }
        
        //return findDuplicatebs( nums);
        return findDuplicatebsearch(nums);
    }
};
