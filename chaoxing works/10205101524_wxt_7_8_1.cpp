#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

double count_percentage(vector<double> &result,ifstream &inp);

int main()
{
    vector<double> result_arr;
    ifstream infile;
    ofstream outfile;
    char let[26];
    for(int i = 0;i<26;i++)
        let[i] = i+97;
    
    infile.open("d:\\input.txt");
    outfile.open("d:\\statistics_data.txt");

    int char_num = count_percentage(result_arr,infile);

    for(int i = 0;i<=25;i++)
    {
        outfile<<let[i]<<' '<<fixed<<setprecision(2)<<(result_arr[i]/char_num)*100<<'%'<<endl;
    }
}

double count_percentage(vector<double> &result,ifstream &inp)
{
    double num_char=0;
    result.resize(26);
    if(inp.is_open())
    {
        char letter;
        while(inp.get(letter))
        {
            num_char++;
            if(letter>=65 && letter <= 90)
            {
                result[letter-65]++;
            }
            else if(letter>=97 && letter<=122)
            {
                result[letter-97]++;
            }
        }
        return num_char;
    }
    else
    {
        cout<<"invalid input"<<endl;
        exit(0);
    }
    
}