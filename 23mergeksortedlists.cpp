//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.


struct comparator
{
  bool operator()(ListNode*p1, ListNode* p2)
  {
      return (p1->val > p2->val);
  }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*, vector<ListNode*>, comparator>heap;
        
        
        for ( int i = 0; i < lists.size(); i++)
        {
            if(lists[i])
            {
                heap.push(lists[i]);
            }
        }
        
        ListNode* dummynode = new ListNode(0);
        ListNode* head = dummynode;
        
        while(!heap.empty())
        {
            ListNode* node = heap.top();
            heap.pop();
            if ( node->next)
            {
                heap.push(node->next);
            }
            dummynode->next = node;
            dummynode = dummynode->next;
        }
        
        ListNode*ret = head->next;
        delete head;
        return ret;
    }
};
