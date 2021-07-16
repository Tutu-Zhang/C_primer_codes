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
#include<sstream>
using namespace std;

int str_cmp(string ,string ,string);

int main()
{
    vector<vector<string>> output;
    string new_sequence;
    while(cin>>new_sequence)
    {
        getchar();
        vector<string> sequence;
        string input,str;
        getline(cin,input);
        stringstream ss(input);
        while(ss>>str)
        {
            sequence.push_back(str);
        }

        for(int i = 0;i<sequence.size()-1;i++)
            for(int j = 0;j<sequence.size()-1-i;j++)
            {
                if(!str_cmp(sequence[j],sequence[j+1],new_sequence))
                {
                    string temp = sequence[j];
                    sequence[j] = sequence[j+1];
                    sequence[j+1] = temp; 
                }
            }

        output.push_back(sequence);
    }

    for(int i = 0;i!=output.size();i++)
    {
        for(auto j = output[i].begin();j!=output[i].end();j++)
        {
            cout<<*j<<' ';
        }
        cout<<endl;
    }

}

int str_cmp(string in_str1,string in_str2,string new_sequence)
{
    string str1 = in_str1,str2 = in_str2;
    for(int i = 0;i<min(str1.size(),str2.size());i++)
    {
        int level1,level2;
        for(int j = 0;j<new_sequence.size();j++)
        {
            if(toupper(str1[i]) == new_sequence[j])
                level1 = j;
            if(toupper(str2[i]) == new_sequence[j])
                level2 = j;
        }

        if(level1 == level2)
            continue;
        if(level1<level2)
            return 1;
        if(level1>level2)
            return 0;
    }

    return str1.size()<str2.size();
}