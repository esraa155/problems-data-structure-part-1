#include "fraction.h"
#include <iostream>
using namespace std;
fraction::fraction()
{
    this->reduce();
}
fraction :: fraction(int n,int m)
{
    num=n;
    dum=m;
    this->reduce();
}
fraction ::fraction(const fraction &obj)
{
    num = obj.num;
    dum=obj.dum;
    this->reduce();
}
int fraction ::gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void fraction :: reduce ()
{
    int x=gcd(num,dum);
    num/=x;
    dum/=x;
}
bool fraction :: operator == (fraction obj)
{
    if (num==obj.num&&dum==obj.dum)
        return 1;
    return 0;
}
bool fraction :: operator != (fraction obj)
{
    if (num==obj.num&&dum==obj.dum)
        return 0;
    return 1;
}
bool fraction :: operator >= (fraction obj)
{
    if(( float )num/dum>=( float )obj.num/obj.dum)
        return 1 ;
    return 0;
}
bool fraction :: operator <= (fraction obj)
{
    if(( float )num/dum<=( float )obj.num/obj.dum)
        return 1 ;
    return 0;
}
istream & operator >> (istream & in , fraction & obj)
{
    cout<<"Enter Nominator : ";
    in>>obj.num;
    cout<<"Enter Dominator : ";
    in>>obj.dum;
    obj.reduce();
    return in;
}
ostream & operator << (ostream & out , fraction  obj)
{
    if (obj.dum==0)
        out<<"you can't divide by zero"<<endl;
    else if (obj.num==0)
        out<<0<<endl;
    else if (obj.dum==obj.num)
        out<<1<<endl;
    else
        out<<obj.num<<'/'<<obj.dum;
    return out;
}
fraction fraction ::operator+(fraction  obj)
{
    fraction f;
    f.dum = dum*obj.dum;
    f.num = num*obj.dum+obj.num*dum;
    f.reduce();
    return f;
}
fraction fraction ::operator-(fraction  obj)
{
    fraction f;
    f.dum = dum*obj.dum;
    f.num = num*obj.dum-obj.num*dum;
    f.reduce();
    return f;
}
fraction fraction ::operator*(fraction  obj)
{
    fraction f;
    f.dum = dum*obj.dum;
    f.num = num*obj.num;
    f.reduce();
    return f;
}
fraction fraction ::operator/(fraction  obj)
{
    fraction f;
    f.dum = dum*obj.num;
    f.num = num*obj.dum;
    f.reduce();
    return f;
}


