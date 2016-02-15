//
//
//based on direct friend lists, recommend possible known friends
//
//
//a-----b------d
//      -------e
//a-----c-----d 
//
//d is possible friend of a since d is common friend of b and c
//who both are direct friends of a, more than e since e is not c direct friend



//'A', new char[][]{ { 'A','B' },{ 'A','C' },{ 'B','D' },{ 'B','E' },{ 'C','D' },{ 'B','A' },{ 'C','A' } });

string findpossiblefriend(string p, vector<vector<string>>friendlist)
{
  // neighbor relationship graph
  unordered_map<string, unordered_set<string>>graph;

  // to count indirect friend occurance
  unordered_map<string, int>friend_count;

  for (int i = 0; i < friendlist.size(); i++)
  {
//if (graph.find(friendlist[i][0]) == graph.end())
//{
//graph[friendlist[i][0]].insert(friendlist[i][1]);
//}
//if (graph.find(friendlist[i][1]) == graph.end())
//{
//graph[friendlist[i][1]].insert(friendlist[i][0]);
//}
    graph[friendlist[i][0]].insert(friendlist[i][1]);
    graph[friendlist[i][1]].insert(friendlist[i][0]);

    if (friend_count.find(friendlist[i][0]) == friend_count.end())
    {
      friend_count[friendlist[i][0]] = 0;
    }
    if (friend_count.find(friendlist[i][1]) == friend_count.end())
    {
      friend_count[friendlist[i][1]] = 0;
    }
  }

  queue < string> q;
  int curnum = 1;
  int nextnum = 0;
  int level = 0;

  q.push(p);
  unordered_set<string>visited;
  visited.insert(p);

  string ret;
  int max_count = INT_MIN;

  while (!q.empty())
  {

    while (curnum > 0)
    {
      curnum--;
      string node = q.front();
      q.pop();
      if (level == 2)
     {
       if (friend_count[node] > max_count)
       {
         max_count = friend_count[node];
         ret = node;
       }
     }
    else
    {
      if (graph.find(node) != graph.end())
      {
        unordered_set<string>::iterator it;
        for (it = graph[node].begin(); it != graph[node].end(); it++)
        {
          if (visited.find(*it) == visited.end())
          {
            q.push(*it);
            visited.insert(*it);
            nextnum++;
          }
         if (level == 1)
         {
           friend_count[*it]++;
         }
       }
     }
   }
  }
  level++;
  curnum = nextnum;
  nextnum = 0;
 }

  return ret;
}


void test_findpossiblefriends()
{
  string cur = "A";

  vector<vector<string>>friendlist;

  vector<string>str; str.push_back("A"); str.push_back("B"); friendlist.push_back(str);

  vector<string>str1; str1.push_back("A"); str1.push_back("C"); friendlist.push_back(str1);

  vector<string>str2; str2.push_back("B"); str2.push_back("D"); friendlist.push_back(str2);

  vector<string>str3; str3.push_back("B"); str3.push_back("E"); friendlist.push_back(str3);

  vector<string>str4; str4.push_back("C"); str4.push_back("D"); friendlist.push_back(str4);

  vector<string>str5; str5.push_back("B"); str5.push_back("A"); friendlist.push_back(str5);

  vector<string>str6; str6.push_back("C"); str6.push_back("A"); friendlist.push_back(str6);

  string ret = findpossiblefriend(cur, friendlist);
}
