//
//
//Given an array and a value, remove all instances of that value in place and return the new length. 
//
//The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
//



void swap(vector<int>& nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        if ( nums.size() == 0)
        {
            return 0;
        }
        int start = 0, end = nums.size()-1;
        while ( start <= end)
        {
            if ( nums[start] == val)
            {
                swap(nums, start, end--);
            }
            else
            {
                start++;
            }
        }
        return end+1;        
    }
};
