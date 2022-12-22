#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

class sorter{
protected:
    int *arr;
    int n;

public:
   virtual void sort(int* arraay,int sizee)=0;
   virtual~sorter(){}

};

class selectionsorter: public sorter{
public:
    selectionsorter(){}
   void sort(int * arraay,int sizee){
        int minIndx;
        n=sizee;
        arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=arraay[i];
        }
        for (int i = 0; i < n - 1; i++){
		   minIndx = i;
		   for (int j = i + 1; j < n; j++)
			  if (arr[j] < arr[minIndx])
				minIndx = j;
	            swap(arr[minIndx], arr[i]);


        }}

    void dispaly()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        }
    ~selectionsorter(){
        delete[]arr;
    }
};




class quicksorter: public sorter{
public:
    quickSorter(){}
    int partition(int *arr,int left,int right){
        int x=arr[left];
        int i=left;
        for(int j=left+1;j<=right;j++){
            if(arr[j]<x){
                i++;
                swap(arr[i],arr[j]);
            }}
        swap(arr[i],arr[left]);
        return i;
        }





    void quickSort(int *arr, int left, int right) {
        if(left<right){
            int middle=partition(arr,left,right);
            quickSort(arr,left,middle-1);
            quickSort(arr,middle+1,right);}
            }



    void sort(int *arraay,int sizee){
        n=sizee;
        arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=arraay[i];
        }
        quickSort(arr,0,n-1);}



     void dispaly()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        }

    ~quicksorter(){
            delete[]arr;
        }
};



class testbed{

public:
    int* GenerateRandomList(int min,int max, int n){
        int* arr = new int[n];
        for(int x=0;x<n;x++){
           arr[x]= min + rand() % (( max + 1 ) - min);}
           return arr;
           }

    int * GenerateReverseOrderedList(int min,int max, int n){
        int* arr = GenerateRandomList(min,max,n);
         for (int i = 0; i < n - 1; i++){
		   int minIndx = i;
		   for (int j = i + 1; j < n; j++)
			  if (arr[j] < arr[minIndx])
				minIndx = j;
	            swap(arr[minIndx], arr[i]);}

        int *b=new int[n];
        int j=0;
        for (int i = n-1; i >=0; i--){
           b[j]=arr[i];
           j++;
        }
         for(int i=0;i<n;i++){
                arr[i]=b[i];
         }

         return arr;
        }




    double RunOnce(sorter *sorting,int *data,int n){
       auto start = high_resolution_clock::now();
       sorting->sort(data,n);
       auto stop = high_resolution_clock::now();
       auto duration = duration_cast<microseconds>(stop - start);
         return duration.count();

    }


    double RunAndAverage(sorter *sorting, int type, int min, int max, int size, int sets_num) {
        double sum=0;
        int *arr=new int[size];
        if (type==0){
                arr=GenerateRandomList(min,max,size);
                }

            else if (type==1){
                arr=GenerateReverseOrderedList(min,max,size);
                }
        for(int i=0;i<sets_num;i++){
            sum=sum+RunOnce(sorting,arr,size);
            }
        return sum/sets_num;
    }

    double RunExperient (sorter *sorting, int type, int min,int max, int min_val, int max_val,int sets_num, int step){
        cout << setw(7) << "Set Size" << setw(15) << "Average Time" << endl;
        for (int n = min_val; n <= max_val; n += step) {
               cout << setw(7)<< n << setw(15) << RunAndAverage(sorting, type, min, max, n, sets_num) << endl;
               }
               }


};







int main()
{
    selectionsorter s1;
    quicksorter s2;

    cout << "Selection Sort: ";
    int arr1[8] = {9, 0, 4, 10, 8, 2, 5, 1};
    s1.sort(arr1, 8);
    s1.dispaly();

    cout << "Quick Sort: ";
    int arr2[8] = {5, -4, 3, 1, 9, -1, 2, 0};
    s2.sort(arr2, 8);
    s2.dispaly();

    cout << endl;

    testbed t1;

    cout << "Selection Sorter of Random list:" << endl;
    t1.RunExperient(&s1, 0, 1, 1000000, 1000, 12000, 100, 2000);

    cout << endl;

    cout << "Selection Sorter of reversed ordered list:" << endl;
    t1.RunExperient(&s1, 1, 1, 1000000, 1000, 12000, 100, 2000);

    cout << endl;

    cout << "Quick Sorter of Random list:" << endl;
    t1.RunExperient(&s2, 0,1, 1000000, 1000, 12000, 100, 2000);

    cout << endl;


    cout << "Quick Sorter of reversed ordered list:" << endl;
    t1.RunExperient(&s2, 1, 1, 1000000, 1000, 12000, 100, 2000);
    return 0;

}


