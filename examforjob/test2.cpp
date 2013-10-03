#if 0
//huawei  2
#include<string>
#include<iostream>
#include<algorithm>
#define MAXLEN 50

void getManName(char *a, int &len){
	char c;
	int  i;
	for( i=0;i<len && (c=getchar())!='#' && c!='\n';++i )
	{
		a[i]	=	c;
	}
	len	=	i;
}

void main(){
	char a[26] = {0};
	int	len = 50;
	int	i,j,iCount=0,maxCount=0,pos;
	char strFemaleNames[10][MAXLEN]	=	{"wang fei","zhang man yu","zhang zhi yi","li li","li xiao man","li yu cun","yang ni","xiao tong","li lei","zhang san"};
	char	* strMan;
	strMan = (char *)malloc(len*sizeof(char));
	memset(strMan,0,len);
	getManName(strMan,len);

	for( i=0;i<len;++i )
	{
		pos	=	strMan[i]-'a';
		a[pos]	=	strMan[i];
	}
	pos	=	0;
	for( i=0;i<10;++i )
	{
		iCount	=	0;
		char * pStrTmp	=	strFemaleNames[i];
		int		tmpLen	=	strlen(strFemaleNames[i]);	
		for( j=0;j<26;++j )
		{
			if( a[j]!=0 )
				if( std::find(pStrTmp,pStrTmp+tmpLen,a[j] )!=pStrTmp+tmpLen )
				{
					++iCount;
				}
		}
		if( iCount>maxCount )
		{
			maxCount = iCount;
			pos = i;
		}
	}
	std::cout<<strFemaleNames[pos]<<std::endl;
}

#endif