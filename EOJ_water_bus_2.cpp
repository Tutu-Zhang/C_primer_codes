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
using namespace std;


int main()
{
    int n,count=0;
    cin>>n;
    vector<int> queue1,queue2,queue_pos,answer;
    vector<vector<int>> all_queue;
    multiset<pair<int,int>> priority_queue;

    all_queue.resize(n);
    queue_pos.resize(n);

    for(auto i:queue_pos)
        i = 0;
    for(int i = 0;i<n;i++)
    {
        int inp;
        cin>>inp;
        queue1.push_back(inp);
    }
    for(int i = 0;i<n;i++)
    {
        int inp;
        cin>>inp;
        queue2.push_back(inp);
    }

    sort(queue1.begin(),queue1.end());
    sort(queue2.begin(),queue2.end());

    for(int i = 0;i<n;i++)
    {
        //all_queue[i].resize(1);
        all_queue[i].push_back(queue1[i]+queue2[queue_pos[i]]);
        pair<int,int> pri_queue_data;
        pri_queue_data.first = queue1[i]+queue2[queue_pos[i]];
        pri_queue_data.second = i;
        queue_pos[i]++;
        priority_queue.insert(pri_queue_data);
    }

    while(count<n)
    {
        answer.push_back((*priority_queue.begin()).first);
        all_queue[(*priority_queue.begin()).second].pop_back();
        all_queue[(*priority_queue.begin()).second].push_back(queue1[(*priority_queue.begin()).second]+queue2[queue_pos[(*priority_queue.begin()).second]]);
        queue_pos[(*priority_queue.begin()).second]++;

        pair<int,int> pri_queue_data;
        pri_queue_data.first = *all_queue[(*priority_queue.begin()).second].begin();
        pri_queue_data.second = (*priority_queue.begin()).second;

        priority_queue.erase(priority_queue.begin());
        priority_queue.insert(pri_queue_data);

        count++;
       
    }

    for(auto i:answer)
    cout<<i<<' ';

}