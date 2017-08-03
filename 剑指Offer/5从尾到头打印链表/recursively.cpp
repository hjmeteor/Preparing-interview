/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> result;
    
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head != NULL){
           printListFromTailToHead(head->next);
           result.push_back(head->val);
        }
        return result;
    }
};