
class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* mergeTwoLists(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        
        Node* result;
        
        if (a->data < b->data) {
            result = a;
            result->bottom = mergeTwoLists(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeTwoLists(a, b->bottom);
        }
        
        return result;
    }
    
    Node* flatten(Node* root) {
    if (!root || !root->next) return root;

    root->next = flatten(root->next);
    
    root = mergeTwoLists(root, root->next);

    return root;
}
};
