#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <math.h>
#include <thread>
#include <cmath>

using namespace std;


int averageMatrix( int** arr , const int col , const int row ) {
//    int** a2d2 = new int* [row];
//    for ( int i = 0; i < row; i++ ) {
//        a2d2[i] = new int[col];
//    }
    int rowLimit = sizeof(arr)-1;
    int colLimit = sizeof(arr[0])-1;
    int sum = 0;

    if( row < 0 || col < 0){
        cout << "invalid" << endl;
        return 0;
    }
    if ( row > rowLimit ||  col > colLimit){
        cout << "out of range" << endl;
        return 0;
    }
    // Find neighbor for each elements and then return average.
    for(int m = fmax(0,row-1); m <= fmin(row+1,rowLimit); m++ ){
        for(int n = fmax(0,col-1); n <= fmin(col+1,colLimit); n++){
            if( m!= row || n != col){
                sum += arr[m][n];
//              a2d2[m][n] = round(sum/4);
            }
            return round(sum/4);
//            return a2d2[m][n];
        }
    }
    return 0;
}

void pMatrix(int** arr, const int row, const int col){
    // print the matrix
    for ( int x = 0; x < row; x++ ){
        for ( int y = 0; y  < col; y++ ){
            cout << arr[x][y];
            cout << " ";
        }
        cout << endl;
    }
}

void randomFill(int** arr,const int row,const int col){
    // filling matrix with random numbers between 0-10.
    for ( int y = 0; y < col; y++ ){
        for ( int x = 0; x  < row; x++ ){
            arr[x][y] = rand() % 10;
        }
    }
}


int main(){

    //thread th (Matrix);
    //th.join();
    
    // read row,col and thread from input.txt
    ifstream input;
    input.open("C:\\Users\\metehaansecer\\CLionProjects\\untitled1\\input.txt"); // change with your own path
    int row,col,thread;
    if(input.is_open()){
        while ( input >> col >> row >> thread ){
            cout<< "col: " << col << " row: " <<  row << " thread: "<< thread <<"\n\n";
            input.close();
        }
    }

    // allocate the  matrix
    int** a2d = new int* [row];
    for ( int i = 0; i < row; i++ ) {
        a2d[i] = new int[col];
    }

    randomFill(a2d,row,col);

    pMatrix(a2d,row,col);


    // write it first to matrix_1.txt bc it will change after then.
    ofstream matris_1 ("matris_1.txt");
    if (matris_1.is_open())
    {
        for( int x = 0; x < row; x++ ){
            for( int y=0; y< col; y++ ) {
                matris_1 << a2d[x][y] << " ";
            }
            matris_1 << "\n";
        }
        matris_1.close();
    }


    return 0;
}
