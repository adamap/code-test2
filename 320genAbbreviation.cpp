//
//
//Write a function to generate the generalized abbreviations of a word.
//
//Example:
//
//
//Given word = "word", return the following list (order does not matter):
//
//["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
//
//
//



vector<string> generateAbbreviations_iterative(string word)
{
    vector<string> result;
    int n = word.length();
    
    for ( int i = 0; i < (1<<n); i++)
    {
        string out = "";
        int cnt = 0;
        
        for ( int j = 0; j < word.length(); j++)
        {
            if ( (i>>j) &1)
            {
                cnt++;
            }
            else
            {
                if ( cnt != 0)
                {
                    ostringstream ss;
        ss << cnt;
        out += ss.str();
        cnt = 0;
                }
                out += word[j];
            }
        }
        
        if ( cnt != 0)
        {
            ostringstream ss;
        ss << cnt;
        out += ss.str();
        }
        result.push_back(out);    
    }
    return result;    
}

void generateAbbreviations_helper(string word, int index, vector<string>&result)
{
    for ( int i = index; i < word.size(); i++)
    {
        for ( int len = 1; i+len <= word.size(); len++)
        {
            string set = word.substr(0, i);
            
            ostringstream ss;
ss << len;
set += ss.str();
            
            set += word.substr(i+len);
            
            result.push_back(set);
            generateAbbreviations_helper(set, i+1+ss.str().length(), result);
        }
    }
}


class Solution {
public:
    vector<string> generateAbbreviations(string word) 
    {
        //vector<string> result;
        //generateAbbreviations_helper(word, 0, result);
        //result.push_back(word);
        //return result;
        
        return generateAbbreviations_iterative(word);
    }
};
