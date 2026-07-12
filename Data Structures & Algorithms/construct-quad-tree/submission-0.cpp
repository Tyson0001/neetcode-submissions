/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,0,0,grid.size());
    }
    Node* solve(vector<vector<int>> &grid , int x ,int y, int len){
        if(check(grid,x,y,len)){
            return new Node(grid[x][y]==1 , true);
        }
        Node* node =new Node(false , false); 
        int new_len=len/2;
        node->topLeft=solve(grid, x,y,new_len);
        node->topRight=solve(grid,x, y+new_len, new_len);
        node->bottomLeft=solve(grid , x+new_len, y, new_len);
        node->bottomRight=solve(grid , x+new_len, y+new_len, new_len);
        return node;
    } 
    bool  check(vector<vector<int>> & grid ,int x , int y , int len){
        for(int i=x;i<x+len;i++){
            for(int j=y;j<y+len;j++){
                if(grid[x][y]!=grid[i][j]) return false;
            }
        }
        return true;
    }
};