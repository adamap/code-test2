//
//
//
//
//
//
//The structure of Expression Tree is a binary tree to evaluate certain expressions.
// All leaves of the Expression Tree have an number string value. All non-leaves of the Expression Tree have an operator string value.
//
// Now, given an expression array, build the expression tree of this expression, return the root of this expression tree.
//
//For the expression (2*6-(23+7)/(1+2)) (which can be represented by ["2" "*" "6" "-" "(" "23" "+" "7" ")" "/" "(" "1" "+" "2" ")"]). 
// The expression tree will be like
//                  [ - ]
//              /          \
//         [ * ]              [ / ]
//        /     \           /         \
//      [ 2 ]  [ 6 ]      [ + ]        [ + ]
//                       /    \       /      \
//                    [ 23 ][ 7 ] [ 1 ]   [ 2 ] .
//
//
//

/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

struct expTreenode
{
    int priority;
    struct ExpressionTreeNode *node;
    expTreenode(int i, string s):priority(i)
    {
        node = new ExpressionTreeNode(s);
    }
};

void calculate(vector<struct expTreenode *>&priority, vector<string> expression)
{
    int base = 0;
    
    for (int i = 0; i < expression.size(); i++)
    {
        if ( expression[i] == "(")
        {
            base += 10;
        }
        else if ( expression[i] == ")")
        {
            base -= 10;
        }
        else if (expression[i] == "+" || expression[i] == "-")
        {
            struct expTreenode *node = new expTreenode(base+1, expression[i]);
            priority.push_back(node);
        }
        else if (expression[i] == "*" || expression[i] == "/")
        {
            struct expTreenode *node = new expTreenode(base+2, expression[i]);
            priority.push_back(node);
        }
        else
        {
            struct expTreenode *node = new expTreenode(INT_MAX, expression[i]);
            priority.push_back(node);
        }
    }
}

ExpressionTreeNode* mintreeBuild(vector<struct expTreenode *>&priority)
{
    stack<struct expTreenode *>s;

    for (int i = 0; i < priority.size(); i++)
    {
        expTreenode* curnode = priority[i];
        
        while(!s.empty() && s.top()->priority >= curnode->priority)
        {
            curnode->node->left = s.top()->node;
            s.pop();
        }
        
        if(!s.empty())
        {
            s.top()->node->right = curnode->node;
        }
        s.push(curnode);
    }
        
    expTreenode *root; 
    while( !s.empty())
    {
        root = s.top();
        s.pop();
    }
    if (NULL == root)
    {
        return NULL;        
    }
    return root->node;
}

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression)
    {
        // write your code here
        vector<struct expTreenode *> priority;
        calculate(priority, expression);
        ExpressionTreeNode* node = mintreeBuild(priority);
        return node;
    }
};
