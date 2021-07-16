#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<cmath>
#include<time.h>
#include<climits>

using namespace std;

class Random
{
    private:
    int seed,multiplier,addon;
    int reseed()
    {
        seed = seed*multiplier+addon;
        return seed;
    }
    public:
    Random(bool pse)
    {
        if(pse) seed = 1;
        else seed = time(NULL)%~(1<<31)-1;
        multiplier = 2743;
        addon = 5923;
    }
    double random_realnum()
    {
        double max = ~(1<<31);
        double temp = reseed();
        if(temp<0) temp = temp + max;
        return temp/max;
    }
    double possion(double mean)
    {
        double limit = exp(-mean);
        double product = random_realnum( );
        int count = 0;
        while (product > limit) {
        count++;
        product *= random_realnum( );
        }
        return count;
    }
};

int main()
{
    Random sequence(1);
    int n;
    double avg;
    std::cout<<"请输入概率均值:"<<std::endl;
    std::cin>>avg;
    std::cout<<"请输入产生随机整数的个数"<<std::endl;
    std::cin>>n;
    std::cout<<"产生随机整数序列:"<<std::endl;

    int linenum = 100;
    int count = 0;

    double all_count=0;
    for(int i = 0;i<n;i++)
    {
        int output = sequence.possion(avg);
        std::cout<<output<<' ';
        all_count += output;
        count++;
        if(count == linenum)
        {
            std::cout<<std::endl;
            count = 0;
        }    
    }
    cout<<"随机整数序列的平均值是:"<<all_count/n;
}