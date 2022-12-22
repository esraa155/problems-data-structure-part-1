#include <iostream>
#include "matrix.h"
using namespace std;



template <class T>
class MatrixCalculator{
public:
void Displaycalculator(){
    int n,r1,c1,r2,c2;
    cout<<"please enter the number of rows and columns of the first matrix respectively: "<<endl;
    cin>>r1;
    cin>>c1;
    Matrix <T> m1(r1,c1);
    cout<<"please enter the elements of the first matrix: "<<endl;
    cin>>m1;
    cout<<"please enter the number of rows and columns of the second matrix respectively: "<<endl;
    cin>>r2;
    cin>>c2;
    Matrix <T> m2(r2,c2);
    cout<<"please enter the elements of the second matrix: "<<endl;
    cin>>m2;
    cout<<"The first matrix: "<<endl;
    cout<<m1<<endl;
    cout<<"The second matrix: "<<endl;
    cout<<m2<<endl;
    bool check=true;
    while(check){
    cout<<"Welcome to FCAI's Matrix Calculator "<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"1- Perform Matrix Addition "<<endl;
    cout<<"2- Perform Matrix Subtraction "<<endl;
    cout<<"3- Perform Matrix Multiplication "<<endl;
    cout<<"4- Matrix Transpose "<<endl;
    cout<<"5-exit "<<endl;

    cout<<"Please choose the number of the operation you want to do: ";
    cin>>n;
        if(n==1){
            cout<<endl;
            cout<<"The matrix Addition is"<<endl;
            cout<<m1+m1<<endl;
            cout<<endl;



        }
        else if(n==2){
            cout<<endl;
            cout<<"The matrix subtraction is"<<endl;
            cout<<m1-m1<<endl;
            cout<<endl;

        }
        else if(n==3){
            cout<<endl;
            cout<<"The matrix Multiplication is"<<endl;
            cout<<m1*m1<<endl;
            cout<<endl;


        }
        else if(n==4){
            cout<<endl;
            cout<<"The transpose of the first matrix is"<<endl;
           m1.Transpose();
           cout<<endl;
            cout<<"The transpose of the second matrix is"<<endl;
            m2.Transpose();
            cout<<endl;

        }
        else if(n==5){
            check=false;


        }


    }

}
};





int main()
{
    MatrixCalculator<int> m;
    m.Displaycalculator();
    return 0;
}
