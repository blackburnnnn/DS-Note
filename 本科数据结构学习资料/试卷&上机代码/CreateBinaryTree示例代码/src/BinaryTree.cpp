#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    //ctor
    tree_root=NULL;
}

BinaryTree::~BinaryTree()
{
    //dtor
}

void BinaryTree::Print_Preorder(TreeNode *aroot){
    if(aroot!=NULL){
        cout<<aroot->value<<" ";
        Print_Preorder(aroot->left);
        Print_Preorder(aroot->right);
    }
}

int BinaryTree::GetTreeHeight(TreeNode* aroot){
    if(aroot==NULL)
        return 0;
    else {
        int l=GetTreeHeight(aroot->left)+1;
        int r=GetTreeHeight(aroot->right)+1;
        int lr=l>r?l:r;
        return lr;
    }
}



void BinaryTree::BuildTree_Preorder(TreeNode*  &aroot, string &preorder, int &index){
    if(index<(int)preorder.length()){
        if(preorder[index]=='#')
            aroot=NULL;
        else{
            aroot=new TreeNode;
            aroot->value=preorder[index];
            BuildTree_Preorder(aroot->left,preorder,++index);
            BuildTree_Preorder(aroot->right,preorder,++index);
        }
    }
    return;
}

void BinaryTree::BuildTree_BFS(string &bfsorder){
    queue<TreeNode *> aqueue;
    int index=0;
    tree_root=new TreeNode(bfsorder[index]);
    aqueue.push(tree_root);
    while(!aqueue.empty()){
       TreeNode *tmp=aqueue.front();
       char nextc=bfsorder[++index];
       nextc=='#'? tmp->left=NULL: tmp->left=new TreeNode(nextc);
       if(nextc!='#') aqueue.push(tmp->left);
       nextc=bfsorder[++index];
       nextc=='#'? tmp->right=NULL: tmp->right=new TreeNode(nextc);
       if(nextc!='#') aqueue.push(tmp->right);
       aqueue.pop();
    }
    return;
}
void BinaryTree::BuildTree_PreMidOrder(TreeNode* &aroot, string &preorder, string &midorder, int &index, int pstart, int pend){
    int sep=pend;
    for(int z=pend;z>=pstart;z--){
        if(midorder[z]==preorder[index]){
           sep=z; break;
        }
    }
    aroot=new TreeNode(preorder[index]);
    if(sep-1>=pstart)
        BuildTree_PreMidOrder(aroot->left, preorder,midorder,++index, pstart,sep-1);
    if(sep+1<=pend)
        BuildTree_PreMidOrder(aroot->right,preorder,midorder,++index, sep+1,pend);
    return ;
}
