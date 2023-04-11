#include <iostream>
#include"BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree tree1;
    string preorder="###ca##ji####spom";
    int index = preorder.length()-1;
    tree1.BuildTree_Postorder(tree1.tree_root,preorder,index);
    cout << "后序遍历所构建的树:";
    tree1.Print(tree1.tree_root);
    cout << endl;
    tree1.Search(tree1.tree_root,"c");
    tree1.PrintPath();
    string del_str;
    cout << "请输入待删除节点:";
    cin >> del_str;//待删除节点
    cout << "删除节点后继续后序遍历该树:";
    TreeNode* Root = tree1.tree_root;//Root保存最初的根节点,用于找父亲的函数
    tree1.find_and_del(tree1.tree_root,del_str,Root);//第一个参数必须引用传递
    tree1.Print(tree1.tree_root);
    return 0;
}
