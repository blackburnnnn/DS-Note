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
    cout << "���ڵ㵽c��·��Ϊ:";
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

TreeNode* BinaryTree::FatherNode(TreeNode* Root, string del_str)//Root������ĸ��ڵ�
{
    if(Root->value < del_str){
        if(Root->right->value == del_str){//str��Root���Һ���
            return Root;
        }
        else return FatherNode(Root->right,del_str);///debug ����ֵ��TreeNode*����
    }
    else if(Root->value > del_str){///debug
        if(Root->left->value == del_str){//str��Root������
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

TreeNode* BinaryTree::FindMax(TreeNode* aroot)//Ѱ�Ҵӵ�ǰ�ڵ㿪ʼС���������ڵ�
{
    if(aroot->right==NULL) return aroot;
    else return FindMax(aroot->right);
}

void BinaryTree::del(TreeNode* &aroot, string del_str, TreeNode* &Root)///�����aroot�Ǵ�ɾ��λ��
{                                                                     ///Root������ĸ��ڵ�
    if(aroot->left==NULL && aroot->right==NULL){//���Ҿ�ΪNULL
        aroot = NULL;
    }
    else if(aroot->left==NULL||aroot->right==NULL){
        TreeNode* Father = FatherNode(Root,del_str);//�ҵ���ɾ���ڵ�ĸ��׽ڵ�
        if(aroot->left==NULL){//������Ϊ�գ���������Ϊ��
            if(Father->left->value == del_str){//��ɾ��λ���Ǹ��׽ڵ������
                Father->left = aroot->right;//�Ѹ��׵���ָ��ָ�����ӵ��Һ���
            }
            else Father->right = aroot->right;
        }
        else if(aroot->right==NULL){//������Ϊ�գ���������Ϊ��
            if(Father->left->value == del_str){
                Father->left = aroot->left;
            }
            else Father->right = aroot->left;
        }
    }
    else{//���Ҿ����ӽڵ�
        TreeNode* LeftMax = FindMax(aroot->left);//�ҵ���ɾ���ڵ�������ڵ�
        TreeNode* Father = FatherNode(Root,LeftMax->value);//�ҵ�������ڵ�ĸ���
        aroot->value = LeftMax->value;
        Father->right = LeftMax->left;
    }
}











