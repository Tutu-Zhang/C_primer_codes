#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"
using namespace std;

int main()
{
    Binary_Tree<int> a;
    a.create_full_tree(a.rootnode,0,9);

    printf("preorder: ");
    a.preorder(a.rootnode);
    printf("\ninorder: ");
    a.inorder(a.rootnode);
    printf("\npostorder: ");
    a.postorder(a.rootnode);
    printf("\nlevelorder: ");
    a.levelorder(a.rootnode);
}