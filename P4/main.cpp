#include <iostream>
#include <string>
using namespace std;

void RecPermute(string soFar, string rest,string *& arr,int& n)
{
int c=0;
if (rest == "") {
        if (n==0){
           arr[n++]=soFar;
           cout<<soFar<<endl;
            }
        else {
            int i=0;
            while(i<=n){
                if(arr[i]==soFar){
                    c++;
                }
                i++;
            }
            if(c==0){
                arr[n++]=soFar;
                cout<<soFar<<endl;
            }
        }
}
else
    for (int i = 0; i < rest.length(); i++) {
        string next = soFar + rest[i];
        string remaining = rest.substr(0, i)+ rest.substr(i+1);
        RecPermute(next, remaining,arr ,n);
}
}



void ListPermutations(string s) {
int n=0;
string * arr;
arr=new string[100];
RecPermute("", s,arr,n);
}

int main()
{
    int no,i=0;
    cout<<"please enter any string: ";
    while(i>=0){
    if(i>=1){
            cout<<"if you want to continue please enter 1,But if you don't enter zero: ";
            cin>>no;
            if (no==0){
                break;
            }
            cout<<"please enter any string: ";
    }
    string namee;
    cin>>namee;
    cout<<"The Result: "<<endl;
    ListPermutations(namee);
    i++;
    }
    return 0;
}
