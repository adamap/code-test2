//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
// Return [1,3,3,1]. 
//


vector<int> getRow1(int rowIndex) 
{
    vector<int> result(rowIndex+1, 0);
    vector<int> temp(rowIndex+1, 0);
        
    result[0] = 1;
    temp[0] = 1;
    for ( int i = 1; i <= rowIndex; i++)
    {
        for ( int j = 0; j <= i; j++)
        {
            result[j] = ((j == 0)?0:temp[j-1]) + ((j== i)?0:temp[j]);
        }
        temp = result;
    }
        
    return result;
}

vector<int> getRow2(int rowIndex) 
{
    vector<int> result(rowIndex+1, 1);
    
    for ( int i = 1;  i <= rowIndex; i++)
    {
        int prev = 1;
        for ( int j = 1; j < i; j++)
        {
            int temp = result[j];
            result[j] = prev + result[j];
            prev = temp;
        }
    }
    
    return result;
        
}

class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        return getRow2(rowIndex); 
    }
};
