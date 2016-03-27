//
//
//Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word. 
//
//Return all such possible sentences. 
//
//For example, given
//s = "catsanddog",
//dict = ["cat", "cats", "and", "sand", "dog"]. 
//
//A solution is ["cats and dog", "cat sand dog"]. 
//
//


void findWordBreak(string &s, unordered_set<string> &dict, int start, vector<string> &sol, vector<string> &sentences, vector<int>&possible) 
{
    if(start==s.size() && !sol.empty()) 
    {   
        // find word break
        string temp = sol[0];
        for(int i=1; i<sol.size(); i++) 
        {
            temp.append(" "+sol[i]);
        }
        sentences.push_back(temp);
    }
        
    string word;
    for(int i=start; i<s.size(); i++) 
    {
        word.push_back(s[i]);
        if(dict.count(word)!=0 && possible[i+1] == 1) 
        {
            sol.push_back(word);
            int size_record = sentences.size();
            findWordBreak(s, dict, i+1, sol, sentences, possible);
            if (sentences.size() == size_record )
            {
                possible[i+1] = 0;
            }
            sol.pop_back();
        }
    }
}


class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
    {
        vector<string> sentences;
        vector<string> sol;
        vector<int> possible(s.length()+1, true); 
        findWordBreak(s, wordDict, 0, sol, sentences, possible);
        return sentences;
    }
};
