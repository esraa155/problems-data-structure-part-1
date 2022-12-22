#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class Matrix{
private:
    T**M;
    int r;
    int c;
public:

    Matrix(int rows=0,int coloumns=0){
        r=rows;
        c=coloumns;
        M=new T*[r];
        for(int i=0;i<c;i++){
                M[i]=new int[c];
        }
        }

    void setrows(int rows){
        r=rows;
    }
     void setcolumns(int col){
        c=col;
    }

    T getrows(){
        return r;
    }
     T columns(){
        return c;
    }


   friend ostream & operator<<(ostream& os,const Matrix<T> & matrixx){
       os<<endl;
       for(int i=0;i<matrixx.r;i++){
                for(int j=0;j<matrixx.c;j++){
                    os<<" "<<matrixx.M[i][j]<<" ";}
                    os<<endl;
                    }

                    return os;
                    }
   friend istream & operator>>(istream& is,const Matrix<T> & matrixx){
       for(int i=0;i<matrixx.r;i++){
                for(int j=0;j<matrixx.c;j++){
                    is>>matrixx.M[i][j];}
                    }
                    }


    Matrix<T> operator +(const  Matrix<T> &matrixx){
        Matrix <T> temp(r,c);
        for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                        temp.M[i][j]=0;
                    }
                    }
                for(int i=0;i<r;i++){
                        for(int j=0;j<c;j++){
                            temp.M[i][j]=M[i][j]+matrixx.M[i][j];
                    }
                    }
                return temp;}


       Matrix<T> operator -(const  Matrix<T> &matrixx){
        Matrix <T> temp(r,c);
        for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                        temp.M[i][j]=0;
                    }
                    }
                for(int i=0;i<r;i++){
                        for(int j=0;j<c;j++){
                            temp.M[i][j]=M[i][j]-matrixx.M[i][j];
                    }
                    }
                return temp;}



Matrix<T> operator *(const  Matrix<T> &matrixx){
        Matrix <T> temp(r,c);
        for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                        temp.M[i][j]=0;
                    }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                    T sum=0;
                for(int k=0; k<r; k++){
                     sum+=(M[i][k]*matrixx.M[k][j]);
                     }
            temp.M[i][j]=sum;
                     }}
            }
            return temp;
            }



        void Transpose(){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout<<" "<<M[j][i]<<" ";}
                    cout<<endl;
                    }
                    }

    ~Matrix() {
   for (int i = 0; i < r; i++){
        delete [] M[i];
   }
   delete [] M;
   }



};


#endif // MATRIX_H_INCLUDED
