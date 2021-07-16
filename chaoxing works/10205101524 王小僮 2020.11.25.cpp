#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>

int main()
{
	printf("有一种加密算法，若明文是字母则将其减少一个整数key值，若不是则保持不变\
	\nkey需要我们通过运算100到200之间所有的素数之和，然后取该和的个位数就是key\n有如下一段密文，请破解并输出其明文\n");
	printf("P^ pbee aZo^ ma^ l^hg] fhgmaer m^lm hg Gho^f[^k 27, 2037.\n");
	 int ans=0;
   for(int i = 100;i<=200;i++)
   {
       int temp;
        for(int j = 1;j<i;j++)
        {
            if(i%j == 0)
                temp = j;
        }

        if(temp == 1)
        {
            ans += i;
        }
   }
   	int key = ans % 10;
   std::cout<<"密钥key是"<<key<<"\n";
   	printf("P^ pbee aZo^ ma^ l^hg] fhgmaer m^lm hg Gho^f[^k 27, 2037.\n");
   

	char encoded[100] = {"P^ pbee aZo^ ma^ l^hg] fhgmaer m^lm hg Gho^f[^k 27, 2037."};
	
	for(int i = 0;i<100;i++)
	{
		if(isdigit(encoded[i])||isspace(encoded[i])||encoded[i] == ','||encoded[i] == '.')
			putchar(encoded[i]);
		else
		{
			putchar(encoded[i] + key);
		}
	}
   
   
}
