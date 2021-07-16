#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<time.h>
#include<vector>
#include<iomanip>
#include<stack>
#include<set>
#include<sstream>
using namespace std;

int main()
{
    int n;
    cout<<"Input the cardinality n of the matrix"<<endl;
    cin>>n;

    vector<vector<short int>> matrix,end_matrix,first_matrix;
    matrix.resize(n);
    for(auto &i:matrix)
        i.resize(n);

    cout<<"Input the matrix"<<endl;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            bool inp;
            cin>>inp;
            matrix[i][j] = inp; 
        }
    }
    first_matrix = matrix;
    end_matrix = matrix;
    for(int r = 1;r<n;r++)
    {
        vector<vector<short int>> now_matrix;
        now_matrix = first_matrix;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                bool this_point = 0;
                int line_po=0,row_po=0;
                while(!this_point && line_po < n)
                {
                    this_point = matrix[i][line_po] & first_matrix[row_po][j];
                    line_po++;
                    row_po++;
                }
                now_matrix[i][j] = this_point;
            }
        }

        matrix = now_matrix;
         for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                end_matrix[i][j] |= matrix[i][j];
            }
        }  
    }

    cout<<endl;
    for(auto i:end_matrix)
    {
        for(auto j:i)
        {
            cout<<j<<' ';
        }
        cout<<endl;
    }
}
