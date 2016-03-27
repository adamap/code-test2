//
//
//Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that: 
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
//Return
//
//  [
//      ["hit","hot","dot","dog","cog"],
//      ["hit","hot","lot","log","cog"]
//  ]
//
//
//
//            Note:
//
//            All words have the same length.
//            All words contain only lowercase alphabetic characters.
//

void genPath(unordered_map<string, vector<string> > &father, vector<string> &path, 
    string end, string curWord, vector<vector<string>> &result) 
{
  path.push_back(curWord);
  
  if(curWord == end) 
  {
    result.push_back(path);
  }
  else 
  {
    for(int i=0; i<father[curWord].size(); i++) 
    {
      string tmp = father[curWord][i];
      genPath(father, path, end, tmp, result);
    }
  }
  path.pop_back();
}

void findladder(string start, string end, unordered_set<string> dict, vector<vector<string>> &result)
{

  unordered_set<string>isvisited;
  unordered_map<string, vector<string>>path;
  unordered_set<string>cur, next;

  cur.insert(start);
  int found = 0;

  while(!cur.empty())
  {
    for ( unordered_set<string>::iterator it = cur.begin(); it != cur.end(); it++)
    {
      isvisited.insert(*it);
    }

    for ( unordered_set<string>::iterator it = cur.begin(); it != cur.end(); it++)
    {
      string curstring = *it;

      for ( int i = 0; i < curstring.size(); i++)
      {
        string temp = curstring;

        for (char c = 'a'; c <= 'z'; c++)
        {
          temp[i] = c;

         if ( temp == curstring)
         {
           continue;
         }

        if ( temp == end)
        {
          found = 1;
          path[curstring].push_back(temp);
          break;
        }

        if ( dict.find( temp) != dict.end() && isvisited.find(temp) == isvisited.end())
        {
          path[curstring].push_back(temp);
          next.insert(temp);
        }
      }
     }
   }

   if ( 1 == found)
   {  
     break;
   } 

   cur.swap(next);
   next.clear();
  }

  vector<string> subsetpath;

  genPath(path, subsetpath, end, start, result);
}

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) 
    {
        vector<vector<string>>result;
        findladder( beginWord,  endWord,  wordList, result);
        return result;
    }
};
