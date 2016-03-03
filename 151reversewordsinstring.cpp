//
//
//
//Given an input string, reverse the string word by word. 
//
//For example,
// Given s = "the sky is blue",
//  return "blue is sky the". 
//
// note: need to skip leading and trailing spaces 
//
class Solution {
public:
    void reverseWords(string &s) 
    {
       string ret;
       
       for ( int i = s.size()-1; i >= 0; )
       {
           while ( i >= 0 && s[i] == ' ')
           {
               i--;
           }
           
           if ( i < 0)
           {
               break;
           }
           
           if (!ret.empty())
           {
               ret.push_back(' ');
           }
           string t;
           while ( i >= 0 && s[i] != ' ')
           {
               t.push_back(s[i--]);
           }
           
           reverse(t.begin(), t.end());
           ret.append(t);
       }
       s = ret;
    }
};
