//
//
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
//
//You may assume that the given expression is always valid.
//
//Some examples:
//
//"3+2*2" = 7
//" 3/2 " = 1
//" 3+5 / 2 " = 5
//
//
//

int priority(char op)
{
    switch(op)
    {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        default: return 0;
    }
}

vector<string> postfix(string s)
{
vector<string>str_set; //postfix string
stack<char>stk; // store operator

int result = 0;
int numberavailable = 0;
for (int i = 0; i < s.size(); i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + s[i] - '0';
numberavailable = 1;
}
else
{
if (numberavailable == 1)
{
ostringstream os;
os << result;
str_set.push_back(os.str());
}
result = 0;
numberavailable = 0;

if (s[i] == ' ')
{
continue;
}
else if (s[i] == '(')
{
stk.push('(');
}
else if (s[i] == ')')
{
while (!stk.empty() && stk.top() != '(')
{
string temp; temp.push_back(stk.top());
str_set.push_back(temp);
stk.pop();
}
stk.pop();
}
else //operator 
{
while (!stk.empty() && priority(s[i]) <= priority(stk.top()))
{
string temp; temp.push_back(stk.top());
str_set.push_back(temp);
stk.pop();
}
stk.push(s[i]);
}
}
}

if (numberavailable == 1)
{
ostringstream os;
os << result;
str_set.push_back(os.str());
}
while (!stk.empty())
{
string temp; temp.push_back(stk.top());
str_set.push_back(temp);
stk.pop();
}

return str_set;
}

int isoperator(string str)
{
    if ( str == "+" || str == "-" || str == "*" || str == "/")
    {
        return 1;
    }
    return 0;
}

int calcproc(int s1, int s2, string oper)
{
    int temp;
    
    if ( oper == "+")
    {
        temp = s1+s2;
    }
    if ( oper == "-")
    {
        temp = s1-s2;
    }
    if ( oper == "*")
    {
        temp = s1*s2;
    }
    if ( oper == "/")
    {
        temp = s1/s2;
    }
    return temp;
}

int evalRPN(vector<string>& tokens) 
{
    stack<int>stk;
        
    for ( int i = 0; i < tokens.size(); i++)
    {
        if (1 == isoperator(tokens[i]))
        {
            int s2 = stk.top();
            stk.pop();
            int s1 = stk.top();
            stk.pop();
            int result = calcproc(s1, s2, tokens[i]);
            stk.push(result);
        }
        else
        {
            stk.push(atoi(tokens[i].c_str()));
        }
    }
    return stk.top();        
}

class Solution {
public:
    int calculate(string s) 
    {
        vector <string> sets = postfix(s);
        
        return evalRPN(sets);
    }
};
