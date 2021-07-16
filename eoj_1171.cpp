#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<time.h>
#include<vector>
using namespace std;

int main()
{
  vector<string> mail_address,passed_mail_address;
  string input;
    
    while(getline(cin,input))
    {
        mail_address.push_back(input);
    }

    for(auto i = mail_address.begin();i!=mail_address.end();i++)
    {
        int num_of_ait=0,num_of_dot=0,illegal_dot=0,if_space=0,num_of_d_quotation=0,ipplace=0;
        bool if_last_is_dot=0,if_one_after_ait_is_dot=0,if_in_d_quotation=0,if_in_duankou=0,if_in_ip=0,illegal_ip=0;
        for(auto j = i->begin();(*j)!='\0';j++)
        {
            if(*j == '\"' && j == i->begin())
            {
                if_in_d_quotation = 1;
                num_of_d_quotation++;
            }
            
              if(*j == ' ')
                    if_space = 1;

            if(if_in_d_quotation)
            {
                if(*j == '\"' && *(j+1) == '@' && j!=i->begin())
                    num_of_d_quotation++,if_in_d_quotation = 0;
            }

            else
            {       
                if(*j == '@')
                    num_of_ait++;

                if(*j == '('||*j == ')')
                    illegal_dot++;
            
                if(*j == '\\')
                    illegal_dot++;

                if(!num_of_ait&&*j == '.')
                {
                    if(*j == *(i->begin()))
                        illegal_dot++;
                    if(*(j+1) == '@')
                        illegal_dot++;
                    if(*(j-1) == '.')
                        illegal_dot++;
                }
            
                if(num_of_ait)
                {
                    if(*j == '['&&*(j-1) == '@')
                        if_in_ip = 1;

                    if(*j == ']' && j+1 == i->end())
                        if_in_ip = 0;

                    if(if_in_ip)
                    {
                        if(isalpha(*j))
                            illegal_dot++;

                        if(j+1 == i->end())
                            illegal_ip = 1;

                        if(isdigit(*j)&&!if_in_duankou)
                        {
                            ipplace++;
                        }

                        if(*j == '.')
                            num_of_dot++,ipplace = 0;

                        if(ipplace == 3)
                        {
                            if(*(j-2) >'2')
                                illegal_ip = 1;
                            
                            if(*(j-2) == '2'&&*(j-1) >'5')
                                illegal_ip = 1;
                            
                            if(*(j-2) == '2'&&*(j-1) =='5' && *j > '5')
                                illegal_ip = 1;
                        }

                        if(ipplace>3)
                        illegal_ip = 1;

                        if(*j == ':')
                            ipplace = 0,if_in_duankou = 1;
                        if(if_in_duankou)
                        {

                        }
                    }

                    else
                    {
                        if(*j == ':')
                            illegal_dot++;

                        if(*j == '.')
                       num_of_dot++;

                        if(*j == '.'&& *(j-1) == '.')
                        {
                           illegal_dot++;
                        }

                        if(*j == '.'&& *(j-1) == '@')
                        {
                            illegal_dot++;
                        }

                        if(*j == '.'&& j == i->end()-1)
                        {
                            illegal_dot++;
                        }
                    }
                    
                    
                }
            }
        }
        if(!illegal_ip&&num_of_ait == 1&&!if_space&&num_of_dot&&!illegal_dot&&(num_of_d_quotation == 2||num_of_d_quotation == 0))
        passed_mail_address.push_back(*i);
    }

    for(auto i = passed_mail_address.begin();i!= passed_mail_address.end();i++)
        cout<<*i<<endl;

}
