




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
