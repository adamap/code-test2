//
//
//Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation. 
//
//For example: 
//
//Given "aacecaaa", return "aaacecaaa".
//
//Given "abcd", return "dcbabcd".
//
bool isPalindrom(string &s, int start, int end) 
{
    while (start < end) 
    {
        if (s[start] != s[end]) 
        {
            return false;
        }
        ++start; --end;
    }
    return true;
}

string shortestPalindrome_t(string s)
{
    int pos = (int)s.length() - 1;
    if (pos <= 0) 
    {
        return s;
    }

    for (; pos > 0; --pos) 
    {
        if (s[pos] == s[0] && isPalindrom(s, 0, pos)) 
        {
            break;
        }
    }
        
    string res;
    for (int i = s.length() - 1; i > pos; --i) 
    {
        res.push_back(s[i]);
    }
    res += s;
    return res;
}

 string shortestPalindrome_kmp(string s) 
 {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> p(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) 
        {
            int j = p[i - 1];
            while (j > 0 && t[i] != t[j]) 
            {
                j = p[j - 1];
            }
            p[i] = (j += t[i] == t[j]);
        }
        return r.substr(0, s.size() - p[t.size() - 1]) + s;
    }


class Solution {
public:
    string shortestPalindrome(string s) 
    {
        //return shortestPalindrome_t(s);
        return shortestPalindrome_kmp(s);
    }
};
