//
//An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
//
//For example, given the following image: 
//[
//  "0010",
//  "0110",
//  "0100"
// ]
//
//      and x = 0, y = 2, 
//
//      Return 6. 
//
//

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) 
    {
        int left = y, right = y, up = x, down = x;

        for (int i = 0; i < image.size(); ++i) 
        {
            for (int j = 0; j < image[i].size(); ++j) 
            {
                if (image[i][j] == '1') 
                {
                    left = min(left, j);
                    right = max(right, j);
                    up = min(up, i);
                    down = max(down, i);
                }
            }
        }
        return (right - left + 1) * (down - up + 1);

        
    }
};
