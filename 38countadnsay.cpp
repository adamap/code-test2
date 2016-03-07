//
//
//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ... 
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//
//Given an integer n, generate the nth sequence. 
//
//Note: The sequence of integers will be represented as a string. 
//
//


class Solution {
public:
    string countAndSay(int n) 
    {
        string str= "1";
        
        for ( int i = 1; i < n; i++)
        {
            int j = 0;
            string temp;
            while(j < str.size())
            {
                if ( j+1 < str.size() && str[j+1] == str[j])
                {
                    if ( j+2 < str.size() && str[j+2] == str[j])
                    {
                        temp.push_back('3');
                        temp.push_back(str[j]);
                        j=j+3;
                    }
                    else
                    {
                        temp.push_back('2');
                        temp.push_back(str[j]);
                        j=j+2;
                    }
                }
                else
                {
                    temp.push_back('1');
                    temp.push_back(str[j]);
                    j++;
                }
            }
            str = temp;
        }
        return str;            
    }
};
