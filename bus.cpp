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
#include<queue>
using namespace std;
int reverse(int *a,int *b)
{
	int *temp = a;
	a = b;
	b = temp;
}

float fpwr2(int x)
{
	/*Result exponent and fraction*/
	unsigned exp, frac;
	unsigned u;

	if(x <  -149  )
	{
		//too small return 0.0
		exp = 0;
		frac = 0;
	}
	else if(x < -126)
	{
		//Denormalised
		exp = 0;
		frac = 1<< (x + 149);
	}
	else if(x< 128)
	{
		//	Normalised
		exp = x+127;
		frac = 0;
	}
	else
	{
		//Too big
		exp = 0xFF;
		frac = 0;
	}

	u = exp<<23|frac;
}

int main()
{
	printf("%f",59.0/128.0);
}