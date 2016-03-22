//
//
//Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
//
//You may assume each number in the sequence is unique.
//
//Follow up:
// Could you do it using only constant space complexity?
//
//

int findfirstsamller(vector<int>& preorder, int root, int start, int end)
{
    for ( int i = end-1; i >=start; i--)
    {
        if (preorder[i] < root)
        {
            return i;
        }
    }
    
    return -1;
}

//[start, pos] all smaller than root, [pos+1, end-1]all larger than root
int  checkvalid(vector<int>& preorder, int pos, int start, int end)
{
    if (pos == -1)
    {
        return 1;
    }
    
    for ( int i = start; i <= pos; i++)
    {
        if (preorder[i] > preorder[end] )
        {
            return 0;
        }
    }
    
    for ( int i = pos+1; i <= end-1; i++)
    {
        if (preorder[i] < preorder[end] )
        {
            return 0;
        }
    }
    
    return 1;
}

int verifyPostorder_helper(vector<int>& preorder, int start, int end)
{
    if ( start <= end)
    {
        int ret1= 1, ret2 =1;
        int root = preorder[end];
        
        int pos = findfirstsamller(preorder, root, start, end);
     
        int ret = checkvalid(preorder, pos, start, end);
     
        if ( ret == 1)
        {
            if ( pos == -1)
            {
                ret1 = verifyPostorder_helper(preorder, start, end-1);
            }
            else
            {
                ret1 = verifyPostorder_helper(preorder, start, pos);
                ret2 = verifyPostorder_helper(preorder, pos+1, end-1);
            }
        
            return (ret1&&ret2);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}


int findprefirstlarger(vector<int>& preorder, int root, int start, int end)
{
    for ( int i = start+1; i <= end; i++)
    {
        if (preorder[i] > root)
        {
            return i;
        }
    }
    
    return -1;
}

//[start+1, pos-1] all smaller than root, [pos, end] all larger than root
int  checkprevalid(vector<int>& preorder, int pos, int start, int end)
{
    if (pos == -1)
    {
        return 1;
    }
    
    for ( int i = start+1; i < pos; i++)
    {
        if (preorder[i] > preorder[start] )
        {
            return 0;
        }
    }
    
    for ( int i = pos; i <= end; i++)
    {
        if (preorder[i] < preorder[start] )
        {
            return 0;
        }
    }
    
    return 1;
}

int verifyPreorder_helper(vector<int>& preorder, int start, int end)
{
    if ( start <= end)
    {
        int ret1= 1, ret2 =1;
        int root = preorder[start];
        
        int pos = findprefirstlarger(preorder, root, start, end);
     
        int ret = checkprevalid(preorder, pos, start, end);
     
        if ( ret == 1)
        {
            if ( pos == -1)
            {
                ret1 = verifyPreorder_helper(preorder, start+1, end);
            }
            else
            {
                ret1 = verifyPreorder_helper(preorder, start+1, pos-1);
                ret2 = verifyPreorder_helper(preorder, pos, end);
            }
        
            return (ret1&&ret2);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}


int verifyPreorder_stk(vector<int> preorder)
{
    
    stack<int>stk;
    stk.push(preorder[0]);
    
    int min_val = INT_MIN;
    for ( int i = 1; i < preorder.size(); i++)
    {
        if ( preorder[i] < min_val)
        {
            return 0;
        }
        while(!stk.empty() && preorder[i] > stk.top())
        {
            min_val = stk.top();
            stk.pop();
        }
        
        stk.push(preorder[i]);
    }
    return 1;    
}


int verifyPostOrder_stk(vector<int> postorder)
{
    stack<int>stk;
    stk.push(postorder[0]);
    
    int max_val = INT_MAX;
    for ( int i = 1; i < postorder.size(); i++)
    {
        if ( postorder[i] > max_val)
        {
            return 0;
        }
        while(!stk.empty() && postorder[i] < stk.top())
        {
            max_val = stk.top();
            stk.pop();
        }
        
        stk.push(postorder[i]);
    }
    return 1;    
}

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) 
    {
        if ( preorder.size() == 0)
        {
            return 1;
        }
        //return verifyPostorder_helper(preorder, 0, preorder.size()-1);
        //return verifyPreorder_helper(preorder, 0, preorder.size()-1);
        
        return verifyPreorder_stk(preorder);
    }
};
