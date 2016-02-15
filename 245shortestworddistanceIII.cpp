





int shortdistance3(vector<string> words, string word1, string word2)
{

  int idx1 = -1, idx2 = -1, distance = INT_MAX;

  int inc = (word1 == word2) ? 1 : 0, turn = 0;

  for (int i = 0; i < words.size(); i++)
  {
    if (words[i] == word1 && turn %2 == 0)
    {
      idx1 = i;
      if (idx2 != -1)
      {
        distance = min(distance, idx1 - idx2);
      }
      turn += inc;
    }
    else if (words[i] == word2)
    {
      idx2 = i;
      if (idx1 != -1)
      {
        distance = min(distance, idx2 - idx1);
      }
      turn += inc;
    }
  }

  return distance;
}

