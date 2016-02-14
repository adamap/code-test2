//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//
//[
//     [2],
//         [3,4],
//            [6,5,7],
//              [4,1,8,3]
//              ]
//
//
//
//              The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        if ( 0 == triangle.size() || 0 == triangle[0].size())
        {
            return 0;
        }
        int m = triangle.size();
        int n = triangle[0].size();
        

        for ( int i = m-2; i >= 0; i--)
        {
            for ( int j = 0; j <= i; j++)
            {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);                
            }
        }
        
        return triangle[0][0];
    }
};
