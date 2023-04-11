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

void BinaryTree::Print(TreeNode *aroot){
    if(aroot!=NULL){
        Print(aroot->left);
        Print(aroot->right);
        cout<<aroot->value<<" ";
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

void BinaryTree::BuildTree_Postorder(TreeNode* &aroot, string &preorder, int &index){
    if(index>=0){
        if(preorder[index] == '#'){
            aroot = NULL;
        }
        else{
            aroot = new TreeNode;
            aroot->value = preorder[index];
            BuildTree_Postorder(aroot->right,preorder,--index);
            BuildTree_Postorder(aroot->left,preorder,--index);
        }
    }
    return;
}

void BinaryTree::Search(TreeNode* aroot, string str)
{
    if(aroot != NULL){
        if(aroot->value == str){
            stack1.push(aroot->value);
            return;
        }
        else{
            if(str < aroot->value){
                stack1.push(aroot->value);
                Search(aroot->left,str);
            }
            else{
                stack1.push(aroot->value);
                Search(aroot->right,str);
            }
        }
    }
}

void BinaryTree::PrintPath()
{
    cout << "根节点到c的路径为:";
    string item;
    while(!stack1.empty()){
        item = stack1.top();
        stack1.pop();
        stack2.push(item);
    }
    while(!stack2.empty()){
        item = stack2.top();
        stack2.pop();
        cout << item;
        if(item != "c") cout << " -> ";
    }
    cout << endl;
}

TreeNode* BinaryTree::FatherNode(TreeNode* Root, string del_str)//Root是最初的根节点
{
    if(Root->value < del_str){
        if(Root->right->value == del_str){//str是Root的右孩子
            return Root;
        }
        else return FatherNode(Root->right,del_str);///debug 返回值是TreeNode*类型
    }
    else if(Root->value > del_str){///debug
        if(Root->left->value == del_str){//str是Root的左孩子
            return Root;
        }
        else return FatherNode(Root->left,del_str);
    }
}

void BinaryTree::find_and_del(TreeNode* &aroot, string del_str, TreeNode* &Root)
{
    if(aroot != NULL){
    if(aroot->value == del_str){
        del(aroot,del_str,Root);
    }
    else{
        if(del_str < aroot->value){
            find_and_del(aroot->left,del_str,Root);
        }
        else{
            find_and_del(aroot->right,del_str,Root);
        }
     }
   }
}

TreeNode* BinaryTree::FindMax(TreeNode* aroot)//寻找从当前节点开始小于它的最大节点
{
    if(aroot->right==NULL) return aroot;
    else return FindMax(aroot->right);
}

void BinaryTree::del(TreeNode* &aroot, string del_str, TreeNode* &Root)///传入的aroot是待删除位置
{                                                                     ///Root是最初的根节点
    if(aroot->left==NULL && aroot->right==NULL){//左右均为NULL
        aroot = NULL;
    }
    else if(aroot->left==NULL||aroot->right==NULL){
        TreeNode* Father = FatherNode(Root,del_str);//找到待删除节点的父亲节点
        if(aroot->left==NULL){//左子树为空，右子树不为空
            if(Father->left->value == del_str){//待删除位置是父亲节点的左孩子
                Father->left = aroot->right;//把父亲的左指针指向左孩子的右孩子
            }
            else Father->right = aroot->right;
        }
        else if(aroot->right==NULL){//右子树为空，左子树不为空
            if(Father->left->value == del_str){
                Father->left = aroot->left;
            }
            else Father->right = aroot->left;
        }
    }
    else{//左右均有子节点
        TreeNode* LeftMax = FindMax(aroot->left);//找到待删除节点左边最大节点
        TreeNode* Father = FatherNode(Root,LeftMax->value);//找到左边最大节点的父亲
        aroot->value = LeftMax->value;
        Father->right = LeftMax->left;
    }
}











