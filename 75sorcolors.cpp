//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue. 
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. 
//
//Note:
// You are not suppose to use the library's sort function for this problem
//
//
void swap(vector<int>& nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int start = 0, end = nums.size()-1;
        
        int index = -1;
        while ( start <= end)
        {
            if ( nums[start] == 1)
            {
                start++;
            }
            else if ( nums[start] == 0)
            {
                swap(nums, start++, ++index);
            }
            else 
            {
                swap(nums, start, end--);
            }
        }
    }
};
