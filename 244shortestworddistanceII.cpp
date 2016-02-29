//This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
//
//Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
//
//For example,
//
//Assume that  words = ["practice", "makes", "perfect", "coding", "makes"] .
//
//Given  word1 = "coding" ,  word2 = "practice" , return 3. Given  word1 = "makes" ,  word2 = "coding" , return 1.
//
//
//Note
//
//You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
//




int shortdistance2(vector<string> words, string word1, string word2)
{
  unordered_map<string, vector<int>>hash_map;

  for (int i = 0; i < words.size(); i++)
  {
    hash_map[words[i]].push_back(i);
  }

  vector<int> v1 = hash_map[word1];
  vector<int> v2 = hash_map[word2];

  int distance = INT_MAX;
  int i = 0, j = 0;

  while (i < v1.size() && j < v2.size())
  {
    distance = min(abs(v1[i]-v2[j]), distance);
    if (v1[i] < v2[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }

  return distance;
}
