#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"
using namespace std;

int main()
{
    //采用的构造删除方法以及添加方法略有不同，因此结果和标准程序可能有出入
    AVL_Tree<int> a;
    for(int i = 15;i>0;i--)
    {
        a.add(i);
    }

    cout<<"preorder:";
    a.preorder(a.rootnode);
    cout<<endl;
    cout<<"inorder:";
    a.inorder(a.rootnode);
    cout<<endl;
    cout<<"postorder:";
    a.postorder(a.rootnode);

    a.remove(8);
    cout<<endl<<endl;

    cout<<"preorder:";
    a.preorder(a.rootnode);
    cout<<endl;
    cout<<"inorder:";
    a.inorder(a.rootnode);
    cout<<endl;
    cout<<"postorder:";
    a.postorder(a.rootnode);
}