#include <iostream>
#include"BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree tree1;
    string preorder="###ca##ji####spom";
    int index = preorder.length()-1;
    tree1.BuildTree_Postorder(tree1.tree_root,preorder,index);
    cout << "�����������������:";
    tree1.Print(tree1.tree_root);
    cout << endl;
    tree1.Search(tree1.tree_root,"c");
    tree1.PrintPath();
    string del_str;
    cout << "�������ɾ���ڵ�:";
    cin >> del_str;//��ɾ���ڵ�
    cout << "ɾ���ڵ����������������:";
    TreeNode* Root = tree1.tree_root;//Root��������ĸ��ڵ�,�����Ҹ��׵ĺ���
    tree1.find_and_del(tree1.tree_root,del_str,Root);//��һ�������������ô���
    tree1.Print(tree1.tree_root);
    return 0;
}
