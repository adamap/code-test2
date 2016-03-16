//
//
//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees (clockwise).
//
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        
        int start = 0, end = n-1;
        
        while( start < end)
        {
            for (int i = start;  i< end; i++)
            {
                int temp = matrix[start][i];
                matrix[start][i] = matrix[end-(i-start)][start];
                matrix[end-(i-start)][start] = matrix[end][end-(i-start)];
                matrix[end][end-(i-start)] = matrix[i][end];
                matrix[i][end] = temp;
            }
            start++;
            end--;
        }
    }
};
