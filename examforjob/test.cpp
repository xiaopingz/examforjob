#include<iostream>
#include <string>
#if 0
int isPrimeNum(int n)
{
	int flag=1, a;
	a = sqrt((double)n);
	if ( n<2 )
		flag	=	0;
	else for ( int i=2;i<=a;++i )
	{
		if ( n%i==0 )
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

int primeNumber(int n)
{
	int		count = 0;	//第几个素数，求第n个素数是多少
	int		prime = 0;
	int		a = 2;

	while( count<n )
	{
		if( isPrimeNum(a) )
		{
			count++;
			prime = a;
		}
		a++;
	}
	return prime;
}

//把一个整数分解成两个或更多的除1外的整数相乘的过程。这些整数称为这个数的因数。
//如果所有因数都是质数，则称为分解质因数或质因数分解。如100的质因数分解为2*2*5*5；
//请编程实现501239的质因数分解
bool function(int n)
{
	int i =1,j=0;
	int a[50] = {0};
	int prime = primeNumber(i);
	int t = sqrt((double)n);
	while( prime<t || prime == t && n!=1 )
	{
		if( n%prime==0 )
		{
			a[j++] = prime;
			n /= prime;
		}
		else
		{
			++i;
			prime = primeNumber(i);
		}
	}
	if( n==1 )
	{
		while(j--)
		{
			std::cout<<a[j]<<" ";
		}
		return true;
	}
	else
		return false;
}

int sum()
{
	int i=1, sum=0;
	int a = i*i+1;
	for( ;a<2061098;++i )
	{
		if( !(a&1) )
			sum += a;
		a = i*i +1;
	}
	return sum;
}

int f(int n)
{
	if( n==1 || n==2 )
		return 1;
	else
		return f(n-1)+2*f(n-2);
}
#define fire(x, y) (x)--; (y)++; (x) * (y);


std::string encode(const std::string& str)
{
	std::string s = str;
	for(int i = 0; i < 5; i++)
	{
		char c = str[i];
		char t = c*2 + 10;
		if(t >110)
			t = t/3;
		s[i] = t;
	}
	for(int i = 0; i< 2; i++)
	{
		char t = s[i];
		s[i] = s[5-i];
		s[5-i] = t;
	}
	return s;
}
int main(){
	//function(62894);
	//std::cout<<sum()<<std::endl;
/*	std::cout<<f(20)-f(14)<<std::endl;

	int n1=87345612;
	int n2=0;
	while( n1>0 )
	{
		n2 = n2*10+(n1%10);
		n1 = n1/10;
	}
	std::cout<<n2;
	
	int a = 3, b = 4;
	for(int i = 0; i< 5; i++)
	{
		fire(a, b);
	}
	std::cout<<a << b<<std::endl;
	*/
	std::cout<<encode("12345");
}


#include <stdio.h>
int inc(int a)
{
	return ++a;
}
int multi(int *a, int *b, int *c)
{
	return (*c = *a **b);
}

typedef int (FUNC1) (int in);
typedef int (FUNC2) (int *, int *, int *);

void show(FUNC2 fun, int arg1, int *arg2)
{
	FUNC1 * p = &inc;
	int temp = p(arg1);
	fun(&temp, &arg1, arg2);
	printf("0x%x\n", *arg2);
}

int main()
{
	int a;
	show(multi, 9, & a);
	return 0;
}


#include <stdio.h>
int fun1(int a)
{
	return a *= a;
}

int f2(int x, int y)
{
	int a = 0, b = 0;
	a = fun1(x);
	b = fun1(y);
	return (a + b);
}
int main()
{
	int w;
	w = f2(1, 2);
	printf("%d", w);
}

#endif

#include <stdio.h>
void main()
{
	int c;
	char aa[] = "12345";
	char *p = aa;
	while(*p)
	{
		c = *p;
		switch(c-'2')
		{
		case 0:
		case 1:
			putchar(c + 4);
		case 2:
			putchar(c + 4);
			break;
		case 3:
			putchar(c + 3);
			break;
		default:
			putchar(c + 2);
			break;
		}
		p ++;
	}
	printf("\n");
}