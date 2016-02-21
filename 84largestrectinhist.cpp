//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram. 
//Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//


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
    int largestRectangleArea(vector<int>& heights) 
    {
        return maxrectArea(heights);
    }
};
