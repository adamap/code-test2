//
//
//
//Given an integer array nums, find the sum of the elements between indices i and j (i<= j), inclusive.
//
//Example:
//
//Given nums = [-2, 0, 3, -5, 2, -1]
//
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> -1
//sumRange(0, 5) -> -3
//
//
//
//





class NumArray {
    vector<int> presums;
public:
    NumArray(vector<int> &nums) 
    {
        int n = nums.size();
        int presum = 0;
        for (int i = 0; i < n; i ++)
        {
            presum += nums[i];
            presums.push_back(presum);
        }
        
    }

    int sumRange(int i, int j) 
    {
        int rangesum = presums[j]-((i>0)?presums[i-1]:0);
        return rangesum;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);


