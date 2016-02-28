//Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that: 
//1.Only one letter can be changed at a time
//2.Each intermediate word must exist in the word list
//
//For example, 
//
//Given:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//
//
//As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5. 
//
//
earch(string beginWord, string endWord, int index, unordered_set<string>wordList, int &minchange)
{
    if ( beginWord == endWord)
    {
        minchange = min(minchange, index);
        return;
    }
   
    
    for ( int i = 0; i < beginWord.size(); i++)
    {
        string tempword = beginWord ;
        for ( char cset = 'a'; cset <= 'z'; cset++)
        {
            tempword[i] = cset;
            
            if(tempword == beginWord)
            {
                continue;
            }
            
            if ( wordList.find(tempword) != wordList.end())
            {
                wordList.erase(tempword);
                ladderLength_search(tempword, endWord, index+1, wordList, minchange);
            }
        }
    }
    return;
}

int ladderLength_dfs(string beginWord, string endWord, unordered_set<string>& wordList)
{
    int minchange = INT_MAX;
    wordList.insert(endWord);
    ladderLength_search(beginWord, endWord, 1, wordList, minchange);
    if (minchange == INT_MAX)
    {
        return 0;
    }
    return minchange;    
}
// DFS find all possible solutions, BFS find min path

int ladderLength_bfs(string beginWord, string endWord, unordered_set<string>& wordList)
{
    queue<string>q;
    
    q.push(beginWord);
    
    int cur = 1, next = 0;
    int step= 1;
    while(!q.empty())
    {
        while( cur > 0)
        {
            string wordnode = q.front();
            q.pop();
            cur--;
        
            for ( int i = 0; i < beginWord.size(); i++)
            {
                string tempstr = wordnode;
                for ( char cset = 'a'; cset <= 'z'; cset++)
                {
                    tempstr[i] = cset;
                
                    if ( tempstr == wordnode)
                    {
                        continue;
                    }
                    
                    if ( tempstr == endWord)
                    {
                        return step+1;
                    }
                
                    if ( wordList.find(tempstr) != wordList.end())
                    {
                        wordList.erase(tempstr);
                        q.push(tempstr);
                        next++;
                    }
                }
            }
        }
        step++;
        cur = next;
        next = 0;
    }
    
    return 0;
}


class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) 
    {
        //return ladderLength_dfs(beginWord, endWord, wordList); 
        return ladderLength_bfs(beginWord, endWord, wordList); 
    }
};
