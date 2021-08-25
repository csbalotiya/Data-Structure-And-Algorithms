//https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  // space O[N] time O[N]
    bool isPalindrome(ListNode* head) {
        ListNode* slow= head;
            stack <int> s;
            while(slow != NULL){
                    s.push(slow->val);
                    slow = slow->next;
            }
            while(head != NULL ){
                 int i=s.top();
                 s.pop();
                if(head -> val != i){
                    return false;
                }
               head=head->next;
            }
        return true;
    }
    /*
      // space O[1] time O[N]
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* start = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow;
        ListNode *prev = NULL,*agla = NULL;
        while(temp != NULL){
            agla = temp->next;
            temp->next = prev;
            prev = temp;
            temp = agla;
        }
        temp = prev;
        while(temp != NULL && start != NULL){
            if(temp->val != start->val){
                return false;
            }
            temp = temp->next;
            start = start->next;
        }
        return true;
    }
*/
};
