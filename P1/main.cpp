#include <iostream>
#include<string>
using namespace std;
class BigDecimalInt
{
private:
    string num1="";
public:
    friend void equality(string &num1,string &num2);
    friend void sign(string &num1,string &num2);
    friend ostream& operator<<(ostream&out,BigDecimalInt n);
    BigDecimalInt(string num1);
    BigDecimalInt(int num1);
    int getSize();
    BigDecimalInt operator +(BigDecimalInt n);

    BigDecimalInt operator -(BigDecimalInt n);
    char getVe();
};
void equality(string &num1,string &num2)
{
    string zero="",newnum="", choice="";
    int diff=0;

    if(num1.size()!=(num2).size())
    {
        if(num1.size()>num2.size())
        {
            diff+=((num1.size())-(num2.size()));
            for(int j=0; j<diff; j++)
            {
                zero+="0";
            }
            newnum+=(zero+num2);
            num2=newnum;
        }
        if(num2.size()>num1.size())
        {
            diff+=((num2.size())-(num1.size()));
            for(int j=0; j<diff; j++)
            {
                zero+="0";
            }
            newnum+=(zero+num1);
            num1=newnum;
        }
    }
}
void sign(string &num1,string &num2)
{
    if(num1[0]=='-'&&num2[0]=='-')
    {
        num1.erase(0,1);
        num2.erase(0,1);
    }
    if(num1[0]=='-'&&num2[0]!='-')
    {
        num1= num1.erase(0,1);
    }
    if(num1[0]!='-'&&num2[0]=='-')
    {
        num2=num2.erase(0,1);
    }
}

BigDecimalInt::BigDecimalInt(int num2) {
    bool negative=false;
    if(num2<0)
        negative=true;
    num2=abs(num2);
    while (num2) {
        num1 = to_string(num2 % 10) + num1;
        num2 /= 10;
    }
    if(negative)
        num1='-'+num1;
}
BigDecimalInt::BigDecimalInt(string num2) {
    num1 = num2;
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt n) {
    sign(num1, n.num1);
    equality(num1, n.num1);
    int x = 0;
    string y = "";
    string addit = "";
    string Addition;
    for (int i = ((num1.size()) - 1); i >= 0; i--) {
        int int_num1 = 0, int_num2 = 0, add = 0;
        int_num1 += ((int(num1[i]) - 48) + x);
        int_num2 += (int(n.num1[i]) - 48);
        add += int_num1 + int_num2;
        x = 0;
        if (add >= 10) {
            if (i == 0) {
                y += "1";
            }
            add -= 10;
            x += 1;
        }
        addit += char(add + 48) + y;
    }
    for (int i = (addit.size() - 1); i >= 0; i--) {
        Addition += addit[i];
    }
    BigDecimalInt A_num(Addition);
    return A_num;
}
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt n)
{
    sign(num1,n.num1);
    equality(num1,n.num1);
    int carry=0;
    string negative="";
    string y="";
    string subtract="";
    string Subtraction="";
    for(int i=0; i<num1.size(); i++)
    {
        if(int(num1[i])>int(n.num1[i]))
        {
            break;
        }
        if(int(num1[i])<int(n.num1[i]))
        {
            swap(num1,n.num1);
            negative="-";
            break;
        }
    }
    int int_num1=0,int_num2=0,sub=0;

    for (int i=((num1.size())-1); i>=0; i--)
    {
        int_num1=0;
        int_num2=0;
        sub=0;
        int_num1+=((int(num1[i])-48)-carry);

        int_num2+=(int(n.num1[i])-48);
        carry=0;
        if(int_num1<int_num2)
        {
            int_num1+=10;
            carry=1;
        }
        sub+=int_num1-int_num2;
        subtract+=char(sub+48);
    }
    subtract+=negative;
    for(int i=(subtract.size()-1); i>=0; i--)
    {
        Subtraction+=subtract[i];
    }
    BigDecimalInt S_num(Subtraction);
    return S_num;
}

int BigDecimalInt::getSize() {
    return num1.size();
}
char BigDecimalInt::getVe() {
    return num1[0];
}
ostream& operator<<(ostream&out,BigDecimalInt n)
{
    out<<n.num1;
    return out;
}
int main()
{
    string num1,num2;
    int choice;
    char sign='-';

    cout<<"Welcome to FCAI Calculator"<<endl;
    cout<<"1)Perform Addition\n"<<"2)Exit "<<endl;
    cin>>choice;
    if(choice==1){
        cout<<"Please enter your first Big NUMBER:    "<<endl;
        cin>>num1;
        cout<<"Num1= "<<num1<<endl;
        cout<<"please enter the second Big NUMBER:   "<<endl;
        cin>>num2;
        cout<<"Num2= "<<num2<<endl;
        BigDecimalInt ob(num1);
        BigDecimalInt obj(num2);

        if(ob.getVe()=='-'&&obj.getVe()=='-')
        {
            cout<<"Num1+Num2= "<<sign<<ob+obj<<endl;

        }

        else if(ob.getVe()=='-'&&obj.getVe()!='-')
        {
            cout<<"num1+Num2= "<<obj-ob<<endl;
        }
        else if(ob.getVe()!='-'&&obj.getVe()=='-')
        {
            cout<<"Num1+Num2= "<<ob-obj<<endl;
        }
        else
        {
            cout<<"Num1+Num2= "<<ob+obj<<endl;
        }
    }

    if (choice==2)
    {
        cout<<"Exit the program"<<endl;
        return 0;
    }

    return 0;
}
