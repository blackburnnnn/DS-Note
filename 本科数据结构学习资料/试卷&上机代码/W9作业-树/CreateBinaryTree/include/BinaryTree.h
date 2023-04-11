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
        void BuildTree_Postorder(TreeNode* &aroot, string &preorder, int &index);//������ʱ������aroot�β�ǰ����&
        void Print(TreeNode* aroot);//.h�ļ��е�arootֻ��һ������
        int GetTreeHeight(TreeNode* aroot);
        TreeNode *tree_root;//���ڵ�ṹ�����͵�ָ��(���Ա�ĳ�Ա����)
        void Search(TreeNode* aroot,string str);
        void PrintPath();
        stack<string> stack1;//��·��
        stack<string> stack2;
        TreeNode* FatherNode(TreeNode* Root, string del_str);//�ҵ�del_str��Ӧ�ڵ�ĸ��׽ڵ�
        void find_and_del(TreeNode* &aroot, string del_str, TreeNode* &Root);//�ҵ���ɾ��λ�ýڵ�
        void del(TreeNode* &aroot, string del_str, TreeNode* &Root);
        TreeNode* FindMax(TreeNode*);

};

