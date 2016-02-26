//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). 
//
//The replacement must be in-place, do not allocate extra memory. 
//
//Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//1,2,3 --> 1,3,2
//3,2,1 --> 1,2,3
//1,1,5 --> 1,5,1


void swap(vector<int>&permutation, int a, int b)
 {
int temp = permutation[a];
permutation[a] = permutation[b];
permutation[b] = temp;
 }
 
 void reverseArr(vector<int>&permutation, int a, int b)
 {
while ( a < b)
{
    int temp = permutation[a];
    permutation[a] = permutation[b];
    permutation[b] = temp;
    a++;
    b--;
}
 }

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if ( nums.size() <= 1)
        {
            return;
        }
        
        int len = nums.size();
     int i = len-2;
     while( i >= 0)
    {
        if ( nums[i] < nums[i+1])
        {
            break;
        }
        i--;
    }
 
     if ( i == -1)
    {
        reverseArr(nums, 0, len-1);
            return;
    }
 
     int j = len-1;
     while( nums[j] <= nums[i])
    {
        j--;
    }

    swap(nums, i, j);
    reverseArr(nums, i+1, len-1);
    }
};
