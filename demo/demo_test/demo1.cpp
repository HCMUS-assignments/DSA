#include <bits/stdc++.h>
using namespace std;

class TamGiac{
private:
	int a,b,c;
public:
	TamGiac()
	{
		a = 1;
		b = 1;
		c = 1;
	}
	TamGiac(int a, int b, int c): a(a), b(b), c(c) {};
	
	friend bool kiemTraTG(TamGiac tg);
	
	friend ostream& operator << (ostream &os ,TamGiac &tg)
	{
		os<<"a = "<<tg.a<<" b = "<<tg.b<<" c = "<<tg.c<<endl;
		return os;
	}
};
	bool kiemTraTG(TamGiac tg)
	{
		if(tg.a>0 && tg.b>0 && tg.c>0 && (tg.a+tg.b>tg.c) && (tg.a+tg.c>tg.b) && (tg.b+tg.c>tg.a))
			return true;
		return false;
	}
	
int main()
{
	TamGiac t(3,4,5);
	cout<<kiemTraTG(t);
	cout<<t;
	return 0;
 }