#include<vector>
#include<string>
#include<iostream>
using namespace std;

int		strToInt(char * a, int len)
{
	int sum = 0;
	double	t = 0.1;
	for ( int i=len-1;i>=0;--i )
	{
		t	*=	10;
		sum	+=	(a[i]-'0')*t;
	}
	return	sum;
}

int		digitNumbers(int d)
{
	char	a[8];
	int		n;
	n	=	sprintf(a,"%d",d);
	return	n;
}

char *	intToStr(int n)
{
	char *	a;
	int		len	=	digitNumbers(n);
	a	=	(char *)malloc((len+1) * sizeof(char));
	memset(a,'\0',len+1);
	for ( int i=0;i<len;i++ )
	{
		a[i]	=	n/pow((double)10,len-i-1)+'0';
		n		=	n%(int)pow((double)10,len-i-1);
	}
	return a;
}

int * convert(string intervalString)
{
	int *a = new int[2];
	int startPos = 0;
	int iPos	=	intervalString.find(',');
	char str[5] = {'0'};
	size_t length = intervalString.copy(str,iPos-1,1);
	a[0] = strToInt(str,length);
	length	=	intervalString.copy(str,intervalString.length()-2-iPos,iPos+1);
	a[1]	=	strToInt(str,length);
	return a;
}

bool isBiggerThan(string intervalStr1,string intervalStr2)
{
	int *a1, *a2;
	a1	=	convert(intervalStr1);
	a2	=	convert(intervalStr2);
	if( a1[0]>a2[1] )
		return true;
	else
		return false;
}

bool isSmallerThan(string intervalStr1,string intervalStr2)
{
	int *a1,*a2;
	a1	=	convert(intervalStr1);
	a2	=	convert(intervalStr2);
	if( a1[1]<a2[0] )
		return true;
	else
		return false;
}

string merge(string str1,string str2)
{
	int *a1,*a2;
	a1	=	convert(str1);
	a2	=	convert(str2);
	int min = 100000 ,max = 0;
	for( int i=0;i<2;++i )
	{
		if(a1[i]<min)
			min	=	a1[i];
		if(a2[i]<min)
			min	=	a2[i];
		if(a1[i]>max)
			max =	a1[i];
		if(a2[i]>max)
			max	=	a2[i];
	}
	string str;
	str.append(1u,'"');
	char *b	=	intToStr(min);
	str.append(b);
	str.append(1u,',');
	b	=	intToStr(max);
	str.append(b);
	str.append(1u,'"');
	return str;
}

vector < string > mergeSortIntervals(vector < string > intervalSequence1, vector < string > intervalSequence2) {
	vector<string> seq(intervalSequence1);
	vector<string>::iterator it1 = seq.begin();
	vector<string>::iterator it2 = intervalSequence2.begin();
	for( ;it2!=intervalSequence2.end();++it2 )
	{
		while( it1!=seq.end() )
		{
			if( isBiggerThan(*it2,*it1) )
			{
				++it1;
			}
			if( isSmallerThan(*it2,*it1) )
			{
				seq.insert(it1,*it2);
				break;
			}
			if( !isBiggerThan(*it2,*it1) && !isSmallerThan(*it2,*it1) )
			{
				string str = merge(*it1,*it2);
				seq.insert(it1,str);
				seq.erase(it1);
				break;
			}
		}
	}
	return seq;
}

int main()
{
	vector<string> v1,v2,v3;
	string str = "'1,2'";
	v1.push_back(str);
	str = "'3,5'";
	v1.push_back(str);
	str = "'4,6'";
	v2.push_back(str);
	v3 = mergeSortIntervals(v1,v2);
	for( vector<string>::iterator it = v3.begin();it!=v3.end();++it )
	{
		cout<<*it<<" ";
	}
}