#include <iostream>
#include <vector>

using namespace std;

class PhoneDirectory{
private:
    vector<string>firstName;
    vector<string>lastName;
    vector<string>phoneNum;
public:
    string AddFirstName( string x){
        cout << "enter the first name" << endl;
        cin >> x;
        firstName.push_back(x);
    }
    void AddLastName( string y){
        cout << "enter the Last name" << endl;
        cin >> y;
        lastName.push_back(y);
    }
    void AddPhoneNumber(string z){
        cout << "enter phone number" << endl;
        cin >> z;
        phoneNum.push_back(z);
    }
    void AddEntry(string x,string y,string z){
        int j;
        cout << "enter the number of entries you want to add" << endl;
        cin >> j;
        for (int i = 0; i < j; ++i) {
            AddFirstName(x);
            AddLastName(y);
            AddPhoneNumber(z);
        }
    }
    string SearchByPhoneNum(string x){
        cin >> x;
        for (int i = 0; i < phoneNum.size(); ++i) {
            if (x==phoneNum[i]){
                return "first name is "+firstName[i]+" last name is "+lastName[i];
            }
        }
        return "not found";
    }
    string SearchByFirstName(string y){
        cin >> y;
        for (int i = 0; i < firstName.size(); ++i) {
            if (y==firstName[i]){
                return "last name is "+lastName[i]+" phone number is "+phoneNum[i];
            }
        }
        return "not found";
    }
    void delete_entry(string fi) {
        for (int i = 0; i < firstName.size(); ++i) {
            if (fi == firstName[i]) {
                firstName.erase(firstName.begin() + i);
                lastName.erase(lastName.begin() + i);
                phoneNum.erase(phoneNum.begin() + i);
            }
        }
    }
    void insertionSort() {
        for (int i = 1; i < firstName.size(); ++i) {
            string temp = firstName[i];
            int j = 0;
            for (j = i; j > 0 && temp < firstName[j - 1]; --j)
                firstName[j] = firstName[j - 1];
            firstName[j] = temp;
        }
    }
    void selectionSort() {
        for (int i = 0; i < firstName.size(); ++i) {
            int least = i;
            for (int j = i + 1; j < firstName.size(); ++j) {
                if (firstName[j] < firstName[least]) {
                    least = j;
                }
            }
            swap(firstName[i], firstName[least]);
        }
    }
    void bubbleSort() {
        for (int i = 0; i < firstName.size(); ++i) {
            for (int j = 0; j < firstName.size(); ++j) {
                if (firstName[j] < firstName[j - 1]) {
                    swap(firstName[j], firstName[j - 1]);
                }
            }

        }
    }
};

int main() {
    string array;
    int chose;
    string phoneNum, FirstName, key;
    PhoneDirectory p;
    do {
        cout << "1. Add an entry to the directory" << endl;
        cout << "2. Look up a phone number" << endl;
        cout << "3. Look up by first name" << endl;
        cout << "4. Delete an entry from the directory" << endl;
        cout << "5. List All entries in phone directory" << endl;
        cout << "6. Exit form this program" << endl;
        cout << "choose from the menu" << endl;
        cin >> chose;
        switch (chose) {
            case 1: {
                string x, y, z;
                p.AddEntry(x, y, z);
                break;
            }
            case 2: {
                cout << "enter phone number" << endl;
                string result1 = p.SearchByPhoneNum(phoneNum);
                cout << result1 << endl;
                break;
            }
            case 3: {
                cout << "enter first name" << endl;
                string result2 = p.SearchByFirstName(FirstName);
                cout << result2 << endl;
                break;
            }
            case 4: {
                cout << " enter the first name of the entry you want to delete" << endl;
                cin >> key;
                p.delete_entry(key);
                break;
            }
            case 5: {
                cout << "choose a number from 1 to 3 to sort and enter 4 to exit" << endl;
                int srt;
                cin >> srt;
                switch (srt) {
                    case 1: {
                        p.bubbleSort();
                        break;
                    }
                    case 2: {
                        p.insertionSort();
                        break;
                    }
                    case 3: {
                        p.selectionSort();
                        break;
                    }
                }
                while (srt !=4);
            }
        }
    } while (chose != 6);
}
