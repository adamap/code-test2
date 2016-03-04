//
//
//
//
//
//
//
//
//
//
//Additive number is a string whose digits can form additive sequence.
//
//A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//
//For example:
//"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
//1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199. 1 + 99 = 100, 99 + 100 = 199
//
//
//Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid. 
//
//Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
//
//Follow up:
// How would you handle overflow for very large input integers? 
//
//
//




bool isAdditiveNumber_iterative(string num) 
{
    int n = num.size();
    if ( n < 3)
    {
        return 0;
    }
        
    for ( int i = 1; i < n; i++)
    {
        for ( int j = i+1; j < n; j++)
        {
            string s1 = num.substr(0, i);
            string s2 = num.substr(i, j-i);
                
            long long d1 = atoll(s1.c_str());
            long long d2 = atoll(s2.c_str());
                
            if ((s1.size() >1 && s1[0] == '0') || (s2.size() >1 && s2[0] == '0'))
            {
                continue;
            }
                
            long long next = d1+d2;
            ostringstream os;
            os<<next;
                
            string nextstr = os.str();
                
            string now = s1+s2+nextstr;
                
            while( now.size() < num.size())
            {
                d1 = d2;
                d2 = next;
                next = d1+d2;
                ostringstream os;
                os<<next;
                string nextstr = os.str();
                now += nextstr;
            }
                
            if ( now == num)
            {
                return 1;
            }
        }
    }
    return 0;
}

int isAdditiveNumber_rec_helper(string a, string b, string c)
{
    if ((a.size() >1 && a[0] == '0') || (b.size() >1 && b[0] == '0'))
    {
        return 0;
    }
    
    long long da = atoll(a.c_str());
    long long db = atoll(b.c_str());
    
    long long ret = da+db;
    
    string ret_str;
    ostringstream os;
    os<<ret;
    ret_str = os.str();
    
    if ( ret_str == c)
    {
        return 1;
    }
    
    if ( ret_str.size() > c.size() || ret_str != c.substr(0, ret_str.size()))
    {
        return 0;
    }
    
    return isAdditiveNumber_rec_helper(b, ret_str, c.substr(ret_str.size()));
    
}

bool isAdditiveNumber_rec(string num) 
{
    int n = num.size();
    if ( n < 3)
    {
        return 0;
    }
        
    for ( int i = 1; i < n; i++)
    {
        for ( int j = i+1; j < n; j++)
        {
            string a = num.substr(0, i);
            string b = num.substr(i, j-i);
            string c = num.substr(j);
            if (1 == isAdditiveNumber_rec_helper(a, b, c))
            {
                return 1;
            }
        }
    }
    
    return 0;
}

class Solution {
public:
    bool isAdditiveNumber(string num) 
    {
        //return isAdditiveNumber_iterative(num); 
        return isAdditiveNumber_rec(num); 
    }
};
















