//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.



int maxrectArea(vector<int>height)
{
    stack<int>stk;
    height.push_back(0);
    
    int rect_area = 0;
    
    for ( int i = 0; i < height.size(); i++)
    {
        while(!stk.empty() && height[i] < height[stk.top()])
        {
            int index = stk.top();
            stk.pop();
            rect_area = max(rect_area, (i-(stk.empty()?-1:stk.top()) -1 )*height[index]);
        }
        
        stk.push(i);
    }
    
    return rect_area;
}


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if ( 0 == matrix.size() || 0 == matrix[0].size())
        {
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size(); 
        vector<int>height(m, 0);
        
        int maxrect = INT_MIN;
        for ( int i = 0; i < n; i++)
        {
            for ( int j = 0; j < m; j++)
            {
                height[j] = (matrix[i][j] == '0')?0:(height[j]+1);
            }
            maxrect = max(maxrect, maxrectArea(height));
        }
        
        return maxrect;

    }
};
