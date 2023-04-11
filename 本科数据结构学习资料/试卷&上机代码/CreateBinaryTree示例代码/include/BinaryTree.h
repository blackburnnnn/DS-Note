#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<string>
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
  TreeNode *left;
  TreeNode *right;
  string value;
  TreeNode(){
    left=right=NULL;
    value="";
  }
  TreeNode(char c){
    left=right=NULL;
    value=c;
  }
};

class BinaryTree
{

    public:
        BinaryTree();
        virtual ~BinaryTree();
        void BuildTree_Preorder(TreeNode* &aroot, string &preorder, int &index);
        void BuildTree_BFS(string &bfsorder);
        void BuildTree_PreMidOrder(TreeNode* &aroot, string &preorder, string &midorder, int &index, int pstart, int pend);
        void Print_Preorder(TreeNode *aroot);
        int GetTreeHeight(TreeNode* aroot);
        TreeNode *tree_root;

    protected:

    private:



};

#endif // BINARYTREE_H
