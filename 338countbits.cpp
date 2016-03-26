//
//
//Given a non negative integer number num. For every numbers i in the range 0 ¡ i ¡ num calculate the number of 1's in their binary representation and return them as an array. 
//
//Example:
// For num = 5 you should return [0,1,1,2,1,2]. 
//
// Follow up: 
// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
//



vector<int> countBits1(int num)
{
    vector<int> result;
    for ( int i = 0; i <= num; i++)
    {
        int temp = i;
        int count = 0;
        while(temp > 0)
        {
            if ( temp&0x01 == 1)
            {
                count ++;
            }
            temp = temp>>1;
        }
        result.push_back(count);
    }
    
    return result;
}

vector<int> countBits2(int num)
{
    vector<int>result;
    result.push_back(0);
    
    for ( int i = 1; i <= num; i++)
    {
       if(i%2 == 0)
       {
           result.push_back(result[i/2]);
       }
       else
       {
           result.push_back(result[i/2]+1);
       }
    }
    return result;    
}

class Solution {
public:
    vector<int> countBits(int num) 
    {
        //return countBits1(num);
        return countBits2(num);
        
    }
};
