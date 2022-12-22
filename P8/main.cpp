#include <iostream>
#include <chrono>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std::chrono;
using namespace std;
int BinarySearch(int arr[], int left, int right, int temp){
    if (right <= left)
        return (temp> arr[left])?  (left + 1): left ;
    int mid = (left + right)/2;
    if(temp == arr[mid])
        return mid+1;
    if(temp > arr[mid])
        return BinarySearch(arr,  mid+1, right , temp);
    return BinarySearch(arr, left, mid-1 , temp);
};
void BianryInsertionSort(int arr[], int n){
    int i, key, j,place;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        place = BinarySearch(arr, 0, j, key);
        while (j >= place) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
};
/*
time complexity of  Binary insertion sort
 Best case O(nlog(n))
 ave and worst case O(n^2)
 */
void InsertionSort(int arr[], int n){
    int  key;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;

        while ( j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
};
/*
time complexity of insertion sort
 Best case O(n)
 ave and worst case O(n^2)
 */
int main() {
    int choice;
    cout<<"Welcome "<<endl;
    cout<<"1)InsertionSort\n"<<"2)BianryInsertionSort\n"<<"3)Exist"<<endl;
    cin>>choice;
    while (true){
    int *ptr;
    int n;
        if (choice==1) {
            cout << "Enter the number" << endl;
            cin >> n;
            auto f = []() -> int { return rand() % 10000; };
            ptr = new int[n];
            generate(ptr, ptr + n, f);

            auto start = high_resolution_clock::now();
            InsertionSort(ptr, n);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << duration.count() << "mircosecond" << endl;
            break;
        }
      else if (choice==2){
            cout<<"Enter the number"<<endl;
            cin>>n;
            auto f=[]()-> int {return rand()%10000;};
            ptr= new int[n];
            generate(ptr,ptr+n,f);
            auto start=high_resolution_clock::now();
            BianryInsertionSort(ptr,n);
            auto stop =high_resolution_clock::now();
            auto duration= duration_cast<microseconds>(stop-start);
            cout<<duration.count()<<"mircosecond"<<endl;
            break;
      }
    else if (choice==3){
        cout<<"End the program"<<endl;
            break;
    }}


    return 0;
    }
