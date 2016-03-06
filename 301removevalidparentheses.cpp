//
//
//
//
//
//Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
//
//Note: The input string may contain letters other than the parentheses ( and ). 
//
//Examples:
//
//"()())()" -> ["()()()", "(())()"]
//"(a)())()" -> ["(a)()()", "(a())()"]
//")(" -> [""]
//
//
//


int isvalidparentheses(string s)
{
    
    int count  = 0;
    for ( int i = 0; i < s.size(); i++)
    {
        if ( s[i] == '(')
        {
            count++;
        }
        else if ( s[i] == ')')
        {
            count --;
            if ( count < 0)
            {
                return 0;
            }
        }
    }
    if ( count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) 
    {
        vector<string>result;
        
        queue<string>q;
        unordered_set<string>hash_set;
        
        q.push(s);
        hash_set.insert(s);
        
        int foundmin = 0;
        while(!q.empty())
        {
            string str = q.front();
            q.pop();
            
            if (1 == isvalidparentheses(str) )
            {
                foundmin = 1;
                result.push_back(str);
                continue;
            }
            
            if (foundmin == 1)
            {
                continue;
            }
            
            for ( int i = 0; i < str.size(); i++)
            {
                if ( str[i] != '(' && str[i] != ')' )
                {
                    continue;
                }
                
                string temp = str;
                temp.erase(temp.begin()+i);
                
                if (hash_set.find(temp) == hash_set.end())
                {
                    hash_set.insert(temp);
                    q.push(temp);
                }
            }
        }
        
        return result;
    }
};




























