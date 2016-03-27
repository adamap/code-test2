//
//
//Numbers can be regarded as product of its factors. For example, 
//8 = 2 x 2 x 2;
//  = 2 x 4.
//
//
//  Write a function that takes an integer n and return all possible combinations of its factors. 
//
//  Note: 
//
//  1.Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2]. 
//  2.You may assume that n is always positive. 
//  3.Factors should be greater than 1 and less than n.
//
//
//  Examples: 
//   input: 1
//    output: 
//
//    []
//
//    input: 37
//     output: 
//     []
//
//     input: 12
//      output:
//      [
//       [2, 6],
//       [2, 2, 3],
//       [3, 4]
//      ]
//
//     input: 32
//      output:
//      [
//       [2, 16],
//       [2, 2, 8],
//       [2, 2, 2, 4],
//       [2, 2, 2, 2, 2],
//       [2, 4, 4],
//       [4, 8]
//      ]
//
//
//


void getFactors_helper(int ori, int n, int start, vector<int>set, vector<vector<int>> &result)
{
    if ( n <= 1)
    {
        result.push_back(set);
        return;
    }
    
    for ( int i = start; i <= n && i < ori; i++)
    {
        if ( n%i == 0)
        {
            set.push_back(i);
            getFactors_helper(ori, n/i, i, set, result);
            set.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> getFactors(int n) 
    {
        vector<vector<int>> result;
        if ( n <= 3)
        {
            return result;
        }
        
        vector<int>set;
        getFactors_helper(n, n, 2, set, result);
        return result;
    }
};

