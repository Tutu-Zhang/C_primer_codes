#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;
void count_avg(ifstream &inp, double &boy_avg, double &girl_avg, double &stu_avg);
void input_func(ifstream, vector<double>);

int main()
{
    double avg,gavg,bavg;
    ifstream infile;
    ofstream outfile;
    
    infile.open("c:\\student.dat");
    outfile.open("c:\\student_inf.txt");
    if (outfile.is_open()) cout << "file3  is open" << endl;

    count_avg(infile,bavg,gavg,avg);
    outfile<<"Average age of boys:"<<fixed<<setprecision(1)<<bavg<<endl<<"Average age of girls:"<<fixed<<setprecision(1)<<gavg<<endl<<"Average age of students:"<<fixed<<setprecision(1)<<avg<<endl;
    outfile.close();
    infile.close();
}

void count_avg(ifstream &inp, double &boy_avg, double &girl_avg, double &stu_avg)
{
    double avg=0,b_avg=0,g_avg=0;
    if(!inp.is_open())
    {
        cout<<"no input file"<<endl;
        exit(0);
    }
    else
    {
        int b_num=0,g_num=0,stu_num=0;
        char kind;
        double age;
        while(inp>>kind>>age)   
        {
            if(kind=='B' || kind == 'b')
            {
                avg += age;
                b_avg += age;
                stu_num++;
                b_num++;
            }
            else if(kind == 'G' || kind == 'g')
            {
                avg += age;
                g_avg += age;
                stu_num++;
                g_num++;
            }
            else
            {
                cout<<"illegal inputs"<<endl;
            }
        }
        if(stu_num)
            avg /= stu_num;
        if(g_num)
            g_avg /= g_num;
        if(b_num)
            b_avg /= b_num;

        stu_avg = avg;
        girl_avg = g_avg;
        boy_avg = b_avg;
    }
    
}