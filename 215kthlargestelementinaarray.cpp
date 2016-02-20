//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element. 
//
//For example,
// Given [3,2,1,5,6,4] and k = 2, return 5. 
//

void swap(vector<int>& nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

int part_index(vector<int>& nums, int start, int end)
{
    int pviot_index = start;
    int pivot_value = nums[pviot_index];
    
    for ( int i = start+1; i <= end; i++)
    {
        if ( nums[i] > pivot_value)
        {
            swap( nums, i, ++pviot_index);
        }
    }
    
    swap(nums, pviot_index, start);
    
    return pviot_index+1;
}


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int index = part_index(nums, 0, nums.size()-1);
        
        while( index != k)
        {
            if ( index > k)
            {
                index = part_index(nums, 0, index-1);
            }
            else
            {
                index = part_index(nums, index, nums.size()-1);
            }
        }
        
        return nums[index-1];
        
    }
}; 
