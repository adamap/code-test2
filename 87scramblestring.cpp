//
//
//
//Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively. 
//
//Below is one possible representation of s1 = "great": 
//    great
//   /    \
//  gr    eat
// / \    /  \
// g   r  e   at
//           / \
//          a   t
//
//
//  To scramble the string, we may choose any non-leaf node and swap its two children. 
//
//   For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat". 
//                                   rgeat
//                                  /    \
//                                 rg    eat
//                                / \    /  \
//                               r   g  e   at
//                                         / \
//                                        a   t
//
//
//  We say that "rgeat" is a scrambled string of "great". 
//Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae". 
//                                  rgtae
//                                 /    \
//                                rg    tae
//                               / \    /  \
//                              r   g  ta  e
//                                    / \
//                                   t   a
//
//
//  We say that "rgtae" is a scrambled string of "great". 
//
//  Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 
//
//

int isScramble_check(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1==s2);
}

int isScramble_helper(string s1, string s2)
{
    if ( s1.size() != s2.size())
    {
        return 0;
    }
    
    if (s1.size() == 0 || s2.size() == 0)
    {
        return (s1.size() == s2.size());
    }
    if (0 == isScramble_check(s1, s2))
    {
        return 0;
    }

    if ( 1 == s1.size())
    {
        return 1;
    }
    
    for ( int j = 1; j < s1.size(); j++)
    {
        string s11 = s1.substr(0, j);
        string s12 = s1.substr(j, s1.size()-j);
        string s21 = s2.substr(0, j);
        string s22 = s2.substr(j, s2.size()-j);
        
        string s23 = s2.substr(0, s2.size()-j);
        string s24 = s2.substr(s2.size()-j, j);

        if  ( (isScramble_helper(s11, s21) && isScramble_helper(s12, s22))
              || (isScramble_helper(s11, s24) && isScramble_helper(s12, s23)) )
        {
            return 1;          
        }
    }
    
    return 0;
}


class Solution {
public:
    bool isScramble(string s1, string s2) 
    {
        return isScramble_helper(s1, s2);
    }
};
