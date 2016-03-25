//
//
//Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form. 
//
//For example: 
//
//Given s = "aabb", return ["abba", "baab"]. 
//
//Given s = "abc", return []. 
//



int canPermutePalindrome(string s, unordered_map<char, int>&hash_map, string &s_subset1, string &s_subset2, char &c) 
{
    for ( int i = 0; i < s.length(); i++)
    {
        hash_map[s[i]]++;
    }
        
    int count = 0;
    unordered_map<char, int>::iterator it;
    for (it = hash_map.begin(); it != hash_map.end(); it++)
    {
        
        if ( (it->second%2) != 0)
        {
            for ( int i = 0; i < it->second/2; i++)
            {
                s_subset2.push_back(it->first);
            }
            c = it->first;
            count ++;
        }
        else
        {   for ( int i = 0; i < it->second/2; i++)
            {
                s_subset1.push_back(it->first);
            }
        }
        if ( count >=2)
        {
            return 0;
        }
    }
    
    return count+1;
}

void calcPermu_helper(string s, vector<int>&isVisited, string set, vector<string>&result)
{
    if ( set.length() == s.length())
    {
        result.push_back(set);
        return;
    }
    
    for ( int i = 0; i < s.length(); i++)
    {
        if ( isVisited[i] == 1)
        {
            continue;
        }
        if ( i > 0 && s[i] == s[i-1] && isVisited[i-1] == 0)
        {
            continue;
        }
        
        set.push_back(s[i]);
        isVisited[i] = 1;
        calcPermu_helper(s, isVisited, set, result);
        set.pop_back();
        isVisited[i] = 0;
    }
}

vector<string> calcPermu(string s)
{
    sort(s.begin(), s.end());
    vector<string> result;
    string set;
    
    vector<int>isVisited(s.length(), 0);
    calcPermu_helper(s, isVisited, set, result);
    return result;
}
    
int isPermu(string s)
{
    int i = 0, j = (int)s.length()-1;
    while( i < j)
    {
        if ( s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return 0;
        }
    }
    
    return 1;
}
    
class Solution {
public:
    vector<string> generatePalindromes(string s) 
    {
        vector<string> result;
        string s_subset1, s_subset2;
        char c;
        unordered_map<char, int>hash_map;
        int isexist = canPermutePalindrome(s, hash_map, s_subset1, s_subset2, c);
        
        if ( isexist == 0)
        {
            return result;
        }
        int len;
        
        if ( s_subset1.size() > 0)
        {
            string subset = s_subset1+s_subset2;
            vector<string> permu = calcPermu(subset);
            if ( isexist == 1)
            {
                for ( int i = 0; i < permu.size(); i++)
                {
                    string clone(permu[i]);
                    reverse(clone.begin(), clone.end());
                    result.push_back(permu[i]+clone);
                }
            }
            else
            {
                for ( int i = 0; i < permu.size(); i++)
                {
                    string clone(permu[i]);
                    reverse(clone.begin(), clone.end());
                    permu[i].push_back(c);
                    result.push_back(permu[i]+clone);
                }
            }
        }
        else
        {
            result.push_back(s);
        }
        //vector<string> permu = calcPermu(s);
        
        //for ( int i = 0; i < permu.size(); i++)
        //{
        //    if ( 1 == isPermu(permu[i]))
        //    {
        //        result.push_back(permu[i]);
        //    }
        //}
        return result;
        
    }
};
