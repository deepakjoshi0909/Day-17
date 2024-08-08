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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr){
            bool isTrue = false;
            while(curr->next && curr->val == curr->next->val){
                isTrue = true;
                curr = curr->next;
            }

            if(isTrue){
                prev->next = curr->next;
            }
            else{

                prev = prev->next;
            }

            curr = curr->next;
        }
        return dummy->next;
    }
};
