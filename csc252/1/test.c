#include<stdio.h>

int main()
{
	int i;
	int j;
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			/*
			int uncommon = i;
			uncommon |= uncommon >> 1;
			uncommon |= uncommon >> 2;
			uncommon |= uncommon >> 4;
			uncommon |= uncommon >> 8;
			uncommon |= uncommon >> 16;
			i2b(i);
			i2b(j);
			printf("----------------------------------\n");
			i2b(uncommon);
			printf("\n");
			*/
			/*
			//printf("%d | %d = %d\n",i,j,(i|j));
			if(i <= j)
				printf("flag");
			printf("~%d & ~%d = %d\n",i,j,(~i^~j)&(i^j));
			//printf("%d ^ %d = %d\n",i,j,(i^j));
			//printf("\n");
			*/
		}
		printf("\n");
	}
	/*
	for(i = 0; i < 0xFFFFFFF; i++)
	{
		i = 0x7fffFFFF;
		int uncommon = i;
		printf("%d\n",uncommon);
		i2b(uncommon);
		uncommon ^= uncommon >> 1;
		i2b(uncommon);
		uncommon ^= uncommon >> 2;
		i2b(uncommon);
		uncommon ^= uncommon >> 4;
		i2b(uncommon);
		uncommon ^= uncommon >> 8;
		i2b(uncommon);
		uncommon ^= uncommon >> 16;
		i2b(uncommon);
		printf("%d",uncommon);
		printf("\n\n");
	}
	*/
	//sign
	int x = 0x80000000;
	//int x = 0;
	int sign = 0;
	if(x < 0)
		sign = 1;
	sign = sign << 31;
	printf("sign= %d\n",sign);

	//exponent
	int sent = 1 << 31;
	//find log(x)
	int log = 29;
	while((x & sent) != sent)
	{
		sent = sent >> 1;
		log--;
		if(log == 0)
			break;
	}
	printf("log= %d\n",log);
	//bias
	int exp = log-(1 << 7);
	printf("exp early = %d\n",exp);
	exp = exp << 31;
	if(log == 0)
		exp = 0;
	printf("exp- %d\n",exp);
	
	//mantisse
	int msb;
	if(log != 0)	
		msb = 1 << log;
	else
		msb = 0;
	int mant = msb ^ x;
	printf("mant= %d\n",mant);

	int f = sign | exp;
	f = f | mant;
	printf("f- %d\n",f);
	return 1;
}

int i2b(int x)
{
	int hold[32];
	int i;
	for(i = 0; i < 32; i++)
	{
		hold[i] = x % 2;
		x /= 2;
	}
	for(i = 31; i >= 0; i--)
	{
		printf("%d",hold[i]);
	}
	printf("\n");
	return 1;
}
