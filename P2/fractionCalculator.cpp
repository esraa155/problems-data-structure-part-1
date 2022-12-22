#include "fractionCalculator.h"
#include "fraction.h"
using namespace std;
fractionCalculator::fractionCalculator()
{
}
void fractionCalculator::begincalculator(){
    cout<<"Welcome to fraction calculator: "<<endl;
    fraction f1,f2;
    cout<<"Enter your first fraction "<<endl;
    cin>>f1;
    cout<<"Enter your second fraction "<<endl;
    cin>>f2;
    int choise;
    while(true){
        cout<<"1)Addtion"<<endl
            <<"2)Subtraction"<<endl
            <<"3)Multiplication"<<endl
            <<"4)Dividing"<<endl
            <<"5)Exit"<<endl
            <<"Choose what you want: "<<endl;
        cin>>choise;
        if(choise==1){
            fraction f3(f1+f2);
            cout<<"fraction1+fraction2= "<<f3<<endl;
        }
        else if(choise==2){
            fraction f3(f1-f2);
            cout<<"fraction1-fraction2= "<<f3<<endl;
        }
        else if(choise==3){
            fraction f3(f1*f2);
            cout<<"fraction1*fraction2= "<<f3<<endl;
        }
        else if(choise==4){
            fraction f3(f1/f2);
            cout<<"fraction1/fraction2= "<<f3<<endl;
        }
        else if(choise==5){
            cout<<"End the program"<<endl;
            break;
        }
    }
}