#include <iostream>
#include"BinaryTree.h"


using namespace std;

int main()
{
    BinaryTree tree1;
    string preorder="541###2#3##";
    int index=0;
    tree1.BuildTree_Preorder(tree1.tree_root,preorder,index);
    tree1.Print_Preorder(tree1.tree_root);
    cout<<endl;
    cout<<tree1.GetTreeHeight(tree1.tree_root)<<endl;

     BinaryTree tree2;
     string bfsorder="5421##3####";
     tree2.BuildTree_BFS(bfsorder);
     tree2.Print_Preorder(tree2.tree_root);
     cout<<endl;

     BinaryTree tree3;
     string preorder2="54123";
     string midorder="14523";
     index=0;
     tree3.BuildTree_PreMidOrder(tree3.tree_root, preorder2,midorder,index,0,(int)(preorder2.length()-1));
     tree3.Print_Preorder(tree3.tree_root);
     cout<<endl;

    return 0;
}
