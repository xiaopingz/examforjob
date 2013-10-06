#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

//question 1/2
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
	vector<string> seq;
	vector<string>::iterator it1 = intervalSequence1.begin();
	vector<string>::iterator it2 = intervalSequence2.begin();
	while( it1!=intervalSequence1.end() && it2!=intervalSequence2.end() )
	{
		if( isBiggerThan(*it2,*it1) )
			seq.push_back(*it1++);
		else if( isSmallerThan(*it2,*it1) )
			seq.push_back(*it2++);
		else
		{
			string str = merge(*it1,*it2);
			seq.push_back(str);
			++it1;
			++it2;
		}
	}
	while( it1!=intervalSequence1.end() )
		seq.push_back(*it1++);
	while( it2!=intervalSequence2.end() )
		seq.push_back(*it2++);
	return seq;
}

//question 2/2

struct treeNode
{
	int data;
	treeNode * lChild;
	treeNode * rChild;
	treeNode(int a):data(a),lChild(nullptr),rChild(nullptr){};
};

void getPostOrder(treeNode * T,vector<int> &postOrder)
{
	if( T->lChild )
		getPostOrder(T->lChild,postOrder);
	if( T->rChild )
		getPostOrder(T->rChild,postOrder);
	postOrder.push_back(T->data);
}

void makeTree(vector<int> preOrder,vector<int> midOrder,int s1,int s2,int len, treeNode * & root)
{
	if( len==1 )
		return;
	int pos = s2;
	for( ;pos<s2+len;++pos )
	{
		if( midOrder[pos]==preOrder[s1] )
			break;
	}
	int lNum	=	pos - s2;
	int rNum	=	s2 + len - 1 - pos;
	if( lNum>0 )
	{
		root->lChild = new treeNode(preOrder[s1+1]);
		makeTree(preOrder,midOrder,s1+1,s2,lNum,root->lChild);
	}
	if( rNum>0 )
	{
		root->rChild = new treeNode(preOrder[s1+lNum+1]);
		makeTree(preOrder,midOrder,s1+lNum+1,s2+lNum+1,rNum,root->rChild);
	}
}

vector<int> getPostOrderTraversal(vector<int> preOrder,vector<int> midOrder)
{
	 vector<int> postOrder;
	 treeNode * L	=	new treeNode(preOrder[0]);
	 makeTree(preOrder,midOrder,0,0,preOrder.size(),L);
	 getPostOrder(L,postOrder);
	 return postOrder;
}

int main()
{
	//question 1/2
	/*vector<string> v1,v2,v3;
	string str = "\"1,2\"";
	v1.push_back(str);
	str = "\"3,5\"";
	v1.push_back(str);
	str = "\"4,6\"";
	v2.push_back(str);
	v3 = mergeSortIntervals(v1,v2);
	for( vector<string>::iterator it = v3.begin();it!=v3.end();++it )
	{
		cout<<*it<<" ";
	}*/

	//question 2/2
	int a1[] = {1,3,8,2,6,4,5};
	int a2[] = {8,3,2,1,5,4,6};
	vector<int> v1(a1,a1+7),v2(a2,a2+7),v3;
	v3	=	getPostOrderTraversal(v1,v2);
	for( vector<int>::iterator it = v3.begin();it!=v3.end();++it )
	{
		cout<<*it<<" ";
	}
}