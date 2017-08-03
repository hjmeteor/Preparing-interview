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
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> nodes;
        ListNode* tmp = head;
        int count = 0;
        while(tmp != NULL){
            nodes.push_back(tmp->val);
            count++;
            tmp = tmp->next;
        }
        // 为了效率我们静态vector开辟空间
        vector<int> result(count);
        for(int i = 0; i < count && st.empty( ) != true; i++){
            // 如果静态开辟vector不能使用push_back
            // 否则会在原来数据的基础上增加
            result.push_back(nodes.back());
            nodes.pop_back();
        }
        return result;
    }
};