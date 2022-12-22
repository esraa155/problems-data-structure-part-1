#include <iostream>
#include <vector>
#include <string>
using namespace std;
void insertion_sort(vector<string> &song,int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        string temp = song[i];
        int j = i - 1;
        while (j >= count && (temp <= song[j] || temp == "untitled")) {
            song[j + 1] = song[j];
            j = j - 1;
        }
        song[j + 1] = temp;
        if (temp == "untitled")
            count++;
    }

}

int main() {
    int size;
    cout << "Enter the number of size" << endl;
    cin >> size;
    vector<string> song;
    for (int i = 0; i < size; i++) {
        cout << "Enter the name of song" << endl;
        string name;
        cin >> name;
        song.push_back(name);
    }
    insertion_sort(song, size);
    for (int i = 0; i < size; i++) {
        cout << song[i] << endl;
    }
    return 0;
}
