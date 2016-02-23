//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
// Return 
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//
//
//
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result;
        
        if (0 == numRows)
        {
            return result;
        }
        
        vector<int>set;
        set.push_back(1);
        result.push_back(set);
        
        for ( int i = 1; i < numRows; i++)
        {
            vector<int>set(i+1, 0);
            
            for ( int j = 0; j < set.size(); j++)
            {
                set[j] = ((j == 0)?0:result[i-1][j-1]) + ((j== set.size()-1)?0:result[i-1][j]);
            }
            
            result.push_back(set);
        }
        
        return result;
        
    }
};                
