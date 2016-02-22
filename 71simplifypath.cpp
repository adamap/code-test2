//Given an absolute path for a file (Unix-style), simplify it.
//
//For example,
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"



class Solution {
public:
    string simplifyPath(string path) 
    {
        if (path.size() == 0)
        {
            return path;
        }
        vector<string>result;
        
        string set;
        path.push_back('/');
        for ( int i = 0; i < path.size(); i++)
        {
            
            if (path[i] == '/')
            {
                if( set.empty())
                {
                    continue;
                }
                else if (set ==".")
                {
                    set.clear();
                }
                else if (set == "..")
                {
                    if (!result.empty())
                    {
                        result.pop_back();
                    }
                    set.clear();
                }
                else
                {
                    result.push_back(set);
                    set.clear();
                }
            }
            else
            {
                set.push_back(path[i]);    
            }
        }
        string retstr;
        retstr.push_back('/');
        for ( int i = 0; i < result.size(); i++)
        {
            retstr.append(result[i]);
            if ( i != result.size()-1 )
            {
                retstr.push_back('/');
            }
        }
        return retstr;
        
    }
};
