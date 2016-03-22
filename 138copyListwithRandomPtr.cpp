//
//
//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null. 
//
//Return a deep copy of the list. 
//
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if ( head == NULL)
        {
            return NULL;
        }
        RandomListNode *temp = head;

    while (temp)
    {
    RandomListNode *node = new RandomListNode(temp->label);
    node->next = temp->next;
    temp->next = node;
    temp = node->next;
    }

    temp = head;
    RandomListNode *ret = head->next;
    RandomListNode *result = head->next;

    while (temp)
    {
    RandomListNode *ptr;
    ptr = temp->random;
    if (ptr == NULL)
    {
    ret->random = ptr;
    }
    else
    {
    ret->random = ptr->next;
    }
    temp = temp->next->next;
    if (ret->next)
    {
    ret = ret->next->next;
    }
    }

    temp = head;
    ret = head->next;
    result = head->next;

    while(temp)
    {
    temp->next = temp->next->next;
    temp = temp->next;

    if (ret->next)
    {
    ret->next = ret->next->next;
    ret = ret->next;
    }
    }

    return result;
    }
};
