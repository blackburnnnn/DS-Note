#include<iostream>
#include <stack>
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
        void BuildTree_Postorder(TreeNode* &aroot, string &preorder, int &index);//创建树时必须在aroot形参前加上&
        void Print(TreeNode* aroot);//.h文件中的aroot只是一个名称
        int GetTreeHeight(TreeNode* aroot);
        TreeNode *tree_root;//树节点结构体类型的指针(类成员的成员变量)
        void Search(TreeNode* aroot,string str);
        void PrintPath();
        stack<string> stack1;//存路径
        stack<string> stack2;
        TreeNode* FatherNode(TreeNode* Root, string del_str);//找到del_str对应节点的父亲节点
        void find_and_del(TreeNode* &aroot, string del_str, TreeNode* &Root);//找到待删除位置节点
        void del(TreeNode* &aroot, string del_str, TreeNode* &Root);
        TreeNode* FindMax(TreeNode*);

};

