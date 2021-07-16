#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"

int main()
{
    printf("This is a reverse Polish Calculator.\nPlease enter a valid command:\n");
    printf("[?]push to stack  [=]print top  [+][-][*][/] are arithmetic operator [q]quit");
    printf("Select command and press <Enter>\n");

    mystack<double> stack_for_polish;
    char ch;
    std::cin>>ch;
    while(ch != 'q'&&ch != 'Q')
    {
        if(ch == '?')
        {
            double num;
            std::cin>>num;
            stack_for_polish.push_back(num);
        }
        else if(ch == '+')
        {
            double variation_1,variation_2,sum;
            variation_1= stack_for_polish.top();
            stack_for_polish.pop_back();
            variation_2 = stack_for_polish.top();
            stack_for_polish.pop_back();
            sum = variation_1 + variation_2;
            stack_for_polish.push_back(sum);
        }
        else if(ch == '-')
        {
            double variation_1, variation_2, sum;
            variation_1 = stack_for_polish.top();
            stack_for_polish.pop_back();
            variation_2 = stack_for_polish.top();
            stack_for_polish.pop_back();
            sum = variation_2 - variation_1;
            stack_for_polish.push_back(sum);
        }
        else if(ch == '*')
        {
            double variation_1, variation_2, sum;
            variation_1 = stack_for_polish.top();
            stack_for_polish.pop_back();
            variation_2 = stack_for_polish.top();
            stack_for_polish.pop_back();
            sum = variation_1 * variation_2;
            stack_for_polish.push_back(sum);
        }
        else if(ch == '/')
        {
            double variation_1, variation_2, sum;
            variation_1 = stack_for_polish.top();
            stack_for_polish.pop_back();
            variation_2 = stack_for_polish.top();
            stack_for_polish.pop_back();
            sum = variation_2 / variation_1;
            stack_for_polish.push_back(sum);
        }
        else if (ch == '=')
        {
            std::cout << stack_for_polish.top() << std::endl;
        }


        std::cin >> ch;
    }
}



