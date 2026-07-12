/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        auto ptr1=p;
        auto ptr2=q;
        while(ptr1!=ptr2){
            ptr1=ptr1?ptr1->parent:q;
            ptr2=ptr2?ptr2->parent:p;
        }
        return ptr1;

    }
};