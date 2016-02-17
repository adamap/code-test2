

//BST serialize(preorder) and de-serialize(preorder)
//BST inorder serialize  



struct bsttree
{
  int val;
  struct bsttree *left, *right;
  bsttree(int i)
 {
   val = i;
   left = NULL;
   right = NULL;
  }
};


string bsttreeInSeralize(bsttree *root)
{
  string s;
  if (NULL == root)
  {
    return s;
  }

  stack<bsttree*>st;

  bsttree *node = root;

  while (node || !st.empty())
  {
     while (node)
    {
      st.push(node);
      node = node->left;
    }

    node = st.top();
    if (node)
    {
      ostringstream os;
      os << node->val;
      s.append(os.str());
      s.push_back(',');
    }
    st.pop();
    node = node->right;
  }
  s.pop_back();
  return s;

}


string bsttreePreSeralize(bsttree *root)
{
  string s;
  if (NULL == root)
  {
    return s;
  }

  stack<bsttree*>st;
  st.push(root);

  while (!st.empty())
  {
    bsttree* node = st.top();
    st.pop();
    ostringstream os;
    os << node->val;
    s.append(os.str());
    s.push_back(',');
    if (node->right)
    {
      st.push(node->right);
    }

   if (node->left)
   {
     st.push(node->left);
   }
  }
  s.pop_back();
  return s;
}

bsttree * bsttreeDeSeralize(string inorders)
{
  if (0 == inorders.size())
  {
    return NULL;
  }

  vector<int>nums;

  int i = 0, j = 0;;
  while (j < inorders.size())
  {
    while (i < inorders.size() && inorders[i] != ',')
    {
      i++;
    } 

    string sub = inorders.substr(j, i - j);
    istringstream is(sub);
    int temp;
    is >> temp;
    nums.push_back(temp);
    j = ++i;
  }

  stack<bsttree *>st;
  bsttree *root = new bsttree(nums[0]);
  st.push(root);

  for (int i = 1; i < nums.size(); i++)
  {
    bsttree *temp = NULL;
    while (!st.empty() && nums[i] > st.top()->val)
   {
     temp = st.top();
     st.pop();
   }  
   bsttree *newnode = new bsttree(nums[i]);
   if (NULL == temp)
   {
     st.top()->left = newnode;
   }
   else
   {
     temp->right = newnode;
   }
   st.push(newnode);
  }

  return root;
}

void test_bts_seralize()
{
  bsttree *root = new bsttree(5);
  root->left = new bsttree(3);
  root->left->left  = new bsttree(1);
  root->left->right = new bsttree(4);

  root->right = new bsttree(8);
  root->right->left = new bsttree(6);
  root->right->right = new bsttree(9);

  string ret = bsttreePreSeralize(root);

  bsttree *node = bsttreeDeSeralize(ret);
}
