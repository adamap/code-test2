//
//
//
//
//
//Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
// You may assume that the version strings are non-empty and contain only digits and the . character.
//  The . character does not represent a decimal point and is used to separate number sequences.
//   For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
//   Here is an example of version numbers ordering:
//   0.1 < 1.1 < 1.2 < 13.37
//
//
//
//
//
//

class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        vector<string>s1;
        int i = 0, j = 0;

        while(i < version1.size())
        {
            if ( version1[i] == '.')
            {
                s1.push_back(version1.substr(j, i-j));
                i++;
                j=i;
            }
            else
            {
                i++;
            }
        }
        s1.push_back(version1.substr(j, i-j));
        
        vector<string>s2;
        i = 0; j = 0;

        while(i < version2.size())
        {
            if ( version2[i] == '.')
            {
                s2.push_back(version2.substr(j, i-j));
                i++;
                j=i;
            }
            else
            {
                i++;
            }
        }
        s2.push_back(version2.substr(j, i-j));
        
        vector<int>int1;
        for (i = 0; i < s1.size(); i++)
        {
            int temp;
            istringstream is(s1[i]);
            is>>temp;
            int1.push_back(temp);
        }
        
        vector<int>int2;
        for (i = 0; i < s2.size(); i++)
        {
            int temp;
            istringstream is(s2[i]);
            is>>temp;
            int2.push_back(temp);
        }
        
        i = 0; j = 0;
        
        while(i < int1.size() && j < int2.size())
        {
            if ( int1[i] > int2[i])
            {
                return 1;
            }
            else if ( int1[i] < int2[i])
            {
                return -1;
            }
            i++;
            j++;
        }
        
        if ( int1.size() == int2.size())
        {
            return 0;
        }
        else
        {
            if (  int1.size() > int2.size())
            {
                int sum = 0;
                for ( int k = i; k < int1.size(); k++)
                {
                    sum += int1[k];
                }
                if ( sum == 0)
                {
                    return 0;
                }
                return 1;
            }
            else
            {
                int sum = 0;
                for ( int k = i; k < int2.size(); k++)
                {
                    sum += int2[k];
                }
                if ( sum == 0)
                {
                    return 0;
                }

                return -1;
            }
        }
        
    }
};
