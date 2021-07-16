#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include"my_template.h"
using namespace std;

int num_way = 0;

void dfs(vector<vector<int>> matrix, int size, int now_layer);
void print_matrix(vector<vector<int>> matrix);
bool check_point(vector<vector<int>> matrix,int x,int y);

int main()
{
    vector<vector<int>> matrix;
    int n;
    cout<<"This is the Queens game.\nWhat is the size of the board?";
    cin>>n;
    
    for(int i = 0;i<n;i++)
    {
        vector<int> line;
        for(int j = 0;j<n;j++)
        {
            line.push_back(0);
        }
        matrix.push_back(line);
    }

    dfs(matrix,n,0);

    cout<<"The number of the answer is "<<num_way;

}

void print_matrix(vector<vector<int>> matrix)
{
    for(int i = 0;i<matrix.size();i++)
    {
        for(int j = 0;j<matrix[i].size();j++)
        {
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

bool check_point(vector<vector<int>> matrix,int layer,int line,int size)
{
    bool if_viable = 1;
    if(if_viable)
    {
        for(int i = 0;i<layer;i++)
        {
            if(matrix[i][line])
                if_viable = 0;
        }
    }

    if(if_viable)
    {
        for(int i = 0;i<layer;i++)
        {
            int j = line - layer + i;
            if(j >=0)
            {   if(matrix[i][j])
                    if_viable = 0;
            }        
        }
    }

    if(if_viable)
    {
        for(int i = 0;i<layer;i++)
        {
            int j = layer + line - i;
            if(j < size)
            {
                if(matrix[i][j])
                    if_viable = 0;
            }        
        }
    }

    return if_viable;
}

void dfs(vector<vector<int>> matrix, int size, int now_layer)
{
    if(now_layer == size)
    {
        num_way++;
        print_matrix(matrix);
    }
    else
    {
        for(int i = 0;i<size;i++)
        {
            if(check_point(matrix,now_layer,i,size))
            {
                matrix[now_layer][i] = 1;
                dfs(matrix,size,now_layer+1);
                matrix[now_layer][i] = 0;
            }
        }
    }
    
}