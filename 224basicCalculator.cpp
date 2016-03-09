//
//
//
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
//
//You may assume that the given expression is always valid.
//
//Some examples:
//
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23
//
//
//
//Note: Do not use the eval built-in library function. 
//
//
void postprocessing(string str, stack<string>&stk)
{
    if (stk.empty() || stk.top() == "(")
    {
        stk.push(str);
        return;
    }
    
    int val = atoi(str.c_str());
    if ( stk.top() == "+")
    {
        stk.pop(); // pop "+"
        int val_add = atoi(stk.top().c_str());
        stk.pop(); 
        val_add += val;
        ostringstream os;
        os<<val_add;
        stk.push(os.str());
    }
    else if ( stk.top() == "-")
    {
        stk.pop(); // pop "-"
        int val_add = atoi(stk.top().c_str());
        stk.pop();
        val_add -= val;
        ostringstream os;
        os<<val_add;
        stk.push(os.str());
    }
}

class Solution {
public:
    int calculate(string s) 
    {
        stack<string>stk;
        
        int i = 0;
        
        while ( i < s.size())
        {
            if (s[i] == '+')
            {
                stk.push("+");
                i++;
            }
            else if (s[i] == '-')
            {
                stk.push("-");
                i++;
            }
            else if (s[i] == '(')
            {
                stk.push("(");
                i++;
            }
            else if (s[i] == ')')
            {
                string str = stk.top();
                stk.pop();
                stk.pop(); //pop out "("
                i++;
                postprocessing(str, stk);
            }
            else if ( s[i] == ' ')
            {
                i++;
            }
            else
            {
                int j = i+1;
                while( j < s.size() && (s[j]>='0' && s[j] <='9'))
                {
                    j++;
                }
                string str = s.substr(i, j-i);
                postprocessing(str, stk);
                i=j;
            }
        }
        
        string ret = stk.top();
        int result = atoi(ret.c_str());
        return result;
    }
};
