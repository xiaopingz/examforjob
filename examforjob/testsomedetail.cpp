#if 0
#include<iostream>

struct foo{
	enum{	//union
		a,b
		/*int n;
		char buf[8];*/
	};
	char c;
};

void calc_buf_len(char buf[16]){
	printf("%d\n",sizeof(buf));
}

namespace ff{
class Base{
public:
	Base(){
		prepare();
		std::cout<<"Base"<<std::endl;
	}
	virtual ~Base(){
		clean_up();
		std::cout<<"~Base"<<std::endl;
	}
	virtual void prepare(){
		std::cout<<"Base prepare"<<std::endl;
	}
	virtual void clean_up(){
		std::cout<<"Base clean up"<<std::endl;
	}
};
}

class Derive:public ff::Base{
public:
	Derive(){
		std::cout<<"derive"<<std::endl;
	}
	~Derive(){
		std::cout<<"~derive"<<std::endl;
	}
	void	prepare(){	//virtual
		std::cout<<"Derive prepare"<<std::endl;
	}
	void clean_up(){
		std::cout<<"Derive clean_up"<<std::endl;
	}
};

void main(){
	/*int a = 4,b = 5;
	printf("%%%d",(a/b)*100);*/

	/*int a, sum=0,i=1;
	int b[]	=	{2,3,5,6,4,2,0};
	while(a=b[i++]!=4){
		sum += a;
	}
	printf("%d",sum);*/

	printf("%d\n",sizeof(foo));

	char * buf = (char *)malloc(16);
	strcpy(buf,"hello");
	printf("%d\n",sizeof(buf));
	calc_buf_len(buf);
	free( buf );

	int a[] = {1,2,3,4,5,6};
	int *b	=	new int[6];
	std::cout<<sizeof(a)<<" "<<sizeof(b)<<std::endl;

	ff::Base * p = new Derive();
	((ff::Base *)p)->prepare();
	delete p;
}

#endif