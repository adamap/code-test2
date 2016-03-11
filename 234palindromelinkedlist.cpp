//
//
//
//
//Given a singly linked list, determine if it is a palindrome.
//
//Follow up:
// Could you do it in O(n) time and O(1) space?
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int isPalindrome_arr(ListNode* head)
{
    if ( NULL == head)
    {
        return 1;
    }
    vector<int>arr;
    ListNode*tail = head;
    arr.push_back(tail->val);
    while ( tail->next)
    {
        tail = tail->next;
        arr.push_back(tail->val);
    }
        
    int i = 0, j = arr.size()-1;
    while( arr[i] == arr[j] && i < j)
    {
        i++;
        j--;
    }
        
    if (  i >= j)
    {
        return 1;
    }
    return 0;
}

ListNode* findmiddle(ListNode*head)
{
    if ( head == NULL)
    {
        return NULL;
    }
    
    ListNode* slow = head, *fast = head->next;
    
    while( fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

ListNode* reverse(ListNode*head)
{
    if ( head == NULL)
    {
        return NULL;
    }
    
    ListNode*prev = NULL;
    ListNode*cur = head;
    ListNode*next = head->next;
    
    while(cur)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (next)
        {
            next = next->next;
        }
    }
    return prev;
}

int isPalindrome_reverse(ListNode* head)
{
    if ( NULL == head)
    {
        return 1;
    }
    
    ListNode* mid = findmiddle(head);
    ListNode*head2 = reverse(mid->next);
    mid->next = NULL;
    
    while(head && head2 && head->val == head2->val)
    {
        head = head->next;
        head2 = head2->next;
    }

    if ( head2 == NULL)
    {
        return 1;
    }

    return 0;
}
 
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        //return isPalindrome_arr(head);
        return isPalindrome_reverse( head);
    }
};
