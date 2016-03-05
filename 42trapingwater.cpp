//
//
//
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 
//
//For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
//


class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        vector<int>left_max(n, 0);
        vector<int>right_max(n, 0);
        
        for(int i= 1; i < n; i++)
        {
            left_max[i] = max(left_max[i-1], height[i-1]);
        }
        
        for(int i= n-2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i+1], height[i+1]);
        }
        
        int size = 0;
        for ( int i = 0; i < n; i++)
        {
            int max_height = min(right_max[i], left_max[i]);
            size += (max_height>height[i])?(max_height-height[i]):0;
        }
        
        return size;
    }
};
