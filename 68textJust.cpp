//
//
//Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified. 
//
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters. 
//
//Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right. 
//
//For the last line of text, it should be left justified and no extra space is inserted between words. 
//
//For example,
//words: ["This", "is", "an", "example", "of", "text", "justification."]
//L: 16. 
//
//Return the formatted lines as:
//
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
// ]
//
//
//
//  Note: Each word is guaranteed not to exceed L in length. 
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string>result;
        if (words.size() == 0 || maxWidth <= 0)
        {
            result.push_back("");
            return result;
        }
        
        int n = words.size();
        vector<int>spaces;
        int start = 0, end = 0;
 
        while (end < n)
        {
            spaces.clear();
            int row_len = words[start].size();
            end = start + 1;
  
            while (end < n)
            {
                int lenword = words[end].size();
                if (row_len + 1 + lenword > maxWidth)
                {
                    break;
                }
                row_len += 1 + lenword;
                spaces.push_back(1);
                end++;
            }
  
            int rest = maxWidth - row_len;
            if (spaces.size() == 0 || end == n)
            {
                spaces.push_back(rest);
            }
            else 
            {
                int j = 0;
                while (rest > 0)
                {
                    spaces[j++] += 1;
                    if (j == spaces.size())
                    {
                        j = 0;
                    }
                    rest--;
                }
                spaces.push_back(0);
            }
  
            string line;
            for (int i = start; i < end; i++)
            {
                line.append(words[i]);
                for (int j = 0; j < spaces[i - start]; j++)
                {
                    line.push_back(' ');
                }
            }
            result.push_back(line);
            start = end;
        }
        return result;
        
    }
};
