#include<iostream>
using namespace std;
#include<string.h>
class ostr{
	char *p;
	int len;
	public:
	ostr(){
		p=0;
		len=0;
	}
	ostr(const char *s){
		len=strlen(s);
		p=new char[len+1];
		strcpy(p,s);
	}
	ostr(const ostr&t){
		len=t.len;
		p=new char[len+1];
		strcpy(p,t.p);
	}
	void display(){
		cout<<p<<endl;
	}
	~ostr(){
		delete p;
	}
	friend ostr sum(const ostr&,const ostr &);
	friend int l(const ostr&,const ostr &);
};
ostr sum(const ostr&s1,const ostr &s2){
		ostr temp;
		temp.len=s1.len+s2.len;
		temp.p=new char[temp.len+1];
		strcpy(temp.p,s1.p);
		strcat(temp.p,s2.p);
		return temp;
	}
int l(const ostr&s1,const ostr &s2){
	if(s1.len>=s2.len)
	return 1;
	else 
	return 0;
}	
int main(){
	ostr obj1("hello");
	ostr obj2("ji");
	ostr obj3=sum(obj1,obj2);
	obj3.display();
}
