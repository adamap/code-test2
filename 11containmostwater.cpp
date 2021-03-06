//
//
//
//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water. 
//
//Note: You may not slant the container. 

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int i = 0, j = height.size()-1;
        
        int max_area = INT_MIN; 
        while ( i < j)
        {
            max_area = max(max_area, (j-i)*min(height[i],height[j]));
            
            if ( height[i] < height[j])
            {
                i++;
            }
            else if ( height[i] > height[j])
            {
                j--;
            }
            else
            {
                i++;
                j--;
            }
        }
        
        return max_area;
    }
};
