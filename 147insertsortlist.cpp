//Sort a linked list using insertion sort.a

//practice insert sort

void insertsort(vector<int>&nums)
{
    for (int i = 0; i < nums.size(); i++)
{
int insertnum = nums[i];
for (int j = i - 1; j >= 0; j--)
{
if (nums[j] > insertnum)
{
nums[j + 1] = nums[j];
nums[j] = insertnum;
}
}
}
}

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
    ListNode* insertionSortList(ListNode* head) 
    {
        
        ListNode* start_node = head;
        ListNode* node = head;
        
        while(node)
        {
                
            ListNode* head_node = start_node;
            ListNode* dummynode = new ListNode(0);
            dummynode->next = head_node;
            
            ListNode* dummynode_ptr = dummynode;
            
            while(head_node && head_node != node && head_node->val < node->val)
            {
                dummynode = dummynode->next;
                head_node = head_node->next;
            }
            
            if ( head_node == node)
            {
                node = node->next;
                continue;
            }
            
            ListNode *temp_currnode = node;
            ListNode *temp_nextnode = node->next;
    
            if ( dummynode->next == start_node)
            {
              start_node = temp_currnode;
            }
    
            dummynode->next = temp_currnode;
            temp_currnode->next = head_node;
            
            while( head_node->next != temp_currnode)
            {
                head_node = head_node->next;
            }
            
            head_node->next = temp_nextnode;
            node = temp_nextnode;
            
            delete dummynode_ptr;
        }
        
        return start_node;
        
    }
};
