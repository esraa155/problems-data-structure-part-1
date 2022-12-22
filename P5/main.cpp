#include<iostream>
#include<vector>
using namespace std;
class StudentName {
private:
    string name;

public:
    StudentName(string n) {

        int no_space = 0;
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == ' ') {
                name = "";
                no_space++;
            }
            name += n[i];
        }
        if (no_space == 0)
            name += ' ' + name + ' ' + name;
        else if (no_space == 1)
            name = n + name;
        else
            name = n;

        name += ' ';
    }

    void print() {
        int no = 1;
        cout << no << ')';
        no++;
        for (int i = 0; i < name.size() - 1; ++i) {
            if (name[i] == ' ') {
                cout << endl << no << ')';
                no++;
                continue;
            }
            cout << name[i];
        }

    }

    bool replace(int i, int j) {

        vector<string> v;
        string n;
        for (int k = 0; k < name.size(); ++k) {
            if (name[k] == ' ') {
                v.push_back(n);
                n = "";
                continue;
            }
            n += name[k];
        }

        int test = max(i, j);
        if (test <= v.size()) {
            string temp2;
            temp2 = v[i - 1];
            v[i - 1] = v[j - 1];
            v[j - 1] = temp2;

            name = "";
            for (int k = 0; k < v.size(); ++k) {
                name += v[k] + ' ';
            }
            cout << endl << "Replacement Done" << endl;
            return true;
        } else {
            cout << "Sorry one of the two indices is out of range,enter another numbers" << endl;
            return false;
        }
    }

};
int main()
{
    StudentName test1("nagham hassan abu elfath");
    if(test1.replace(2,4))
    {
        test1.print();
        cout <<endl;
    }
    StudentName test2("esraa mohamed abd elsatar");
    if(test2.replace(1,3))
    {
        test2.print();
        cout <<endl;
    }
    StudentName test3("omnia alaa");
    if(test3.replace(3,1))
    {
        test3.print();
        cout <<endl;
    }
    StudentName test4("Khaled");
    if(test4.replace(1,3))
    {
        test4.print();
        cout <<endl;
    }
    StudentName test5("ahmed Mohamed sayed");
    if(test5.replace(2,3))
    {
        test5.print();
        cout <<endl;
    }

    return 0;
}
