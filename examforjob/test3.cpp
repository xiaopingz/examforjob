#include<iostream>

int transform(int n, int i, int j )
{
	//n为方阵的阶数，就方阵为n*n的
	int k;
	k	=	i * n + j;
	return k;
}

bool isEliminable(char *a)
{
	int i,j,t;
	for( i=0;i<5;++i )
	{
		for( j=0;j<5;++j )
		{
			t	=	transform(5,i,j);
			if( i<3 && j<3 )
				if(a[t]==a[transform(5,i+2,j)] && a[t]==a[transform(5,i+1,j)] || a[t]==a[transform(5,i,j+2)] && a[t]==a[transform(5,i,j+1)])
					return true;
			if( i>=3 && j<3 )
				if(a[t]==a[transform(5,i,j+2)] && a[t]==a[transform(5,i,j+1)] || a[t]==a[transform(5,i-2,j)] && a[t]==a[transform(5,i-1,j)])
					return true;
			if( i>=3 && j>=3 )
				if(a[t]==a[transform(5,i-2,j)] && a[t]==a[transform(5,i-1,j)] || a[t]==a[transform(5,i,j-2)] && a[t]==a[transform(5,i,j-1)])
					return true;
			if( i<3 && j>=3 )	
				if(a[t]==a[transform(5,i+2,j)] && a[t]==a[transform(5,i+1,j)] || a[t]==a[transform(5,i,j-2)] && a[t]==a[transform(5,i,j-1)])
					return true;
		}
	}
	return false;
}

void rightSwap(char *a, int i,int j)
{
	char t	=	a[transform(5,i,j)];
	a[transform(5,i,j)]	=	a[transform(5,i,j+1)];
	a[transform(5,i,j+1)]	=	t;
}

void downSwap(char *a, int i,int j)
{
	char t	=	a[transform(5,i,j)];
	a[transform(5,i,j)]	=	a[transform(5,i+1,j)];
	a[transform(5,i+1,j)]	=	t;
}

bool isThePos(char *a,char *b, int i, int j)
{
	if( i<4 && j<4 )
	{
		rightSwap(b,i,j);
		if(isEliminable(b))
			return true;
		memcpy(b,a,25);
		downSwap(b,i,j);
		if(isEliminable(b))
			return true;
	}
	else
	{
		if(i==4)
		{
			rightSwap(b,i,j);
			if(isEliminable(b))
				return true;
		}
		else
		{
			downSwap(b,i,j);
			if(isEliminable(b))
				return true;
		}
	}
	return false;
}

int main(){
	char a[26] = {0};
	char b[26] = {0};
	for( int i=0;i<25;++i )
		std::cin>>a[i];
	int i,j;
	for( i=0;i<5;++i )
	{
		for( j=0;j<5;++j )
		{
			memcpy(b,a,25);
			if( isThePos(a,b,i,j) )
			{
				std::cout<<"YES "<<transform(5,i,j)+1<<std::endl;
				return 0;
			}
		}
	}
	std::cout<<"NO"<<std::endl;
	return 0;
}