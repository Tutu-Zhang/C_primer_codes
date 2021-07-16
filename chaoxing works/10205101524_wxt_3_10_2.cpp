#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include"my_template.h"

int main()
{
    printf("Bracket matching program\ninput a string line\n");
    mystack<char> statement;
    bool iflegal = 1;
    char ch;
    ch = getchar();
    while(ch!='\n')
    {
        if(ch == '('||ch == '['||ch == '{')
        {
            statement.push_back(ch);
        }
        else if(ch == ')')
        {
            if(!statement.size())
            {
                std::cout<<"illegal";
                return 0;
            }
           if(statement.top()!='(')
            iflegal = 0;
            statement.pop_back();
        }
        else if(ch == ']')
        {
            if(!statement.size())
            {
                std::cout<<"illegal";
                return 0;
            }
           if(statement.top()!='[')
            iflegal = 0;
            statement.pop_back();
        }
        else if(ch == '}')
        {
            if(!statement.size())
            {
                std::cout<<"illegal";
                return 0;
            }
           if(statement.top()!='{')
            iflegal = 0;
            statement.pop_back();
        }
        
        {
            ch = getchar();
        }
        
    
    }

    if(statement.size())
        iflegal = 0;

    if(iflegal)
        std::cout<<"legal";
    else
    {
        std::cout<<"illegal";
    }
    
}