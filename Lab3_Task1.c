#include<stdio.h> 
#include <stdbool.h> 
#define SIZE 5
#define nRows 8
#define nCols 3
int pos = 2;
int value = 80;
int arr2d[nRows][nCols];

// PROTOTYPES
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
bool isValid(const int array[], int length, int pos);
void remove_element(int arr[],int length, int pos);
void reshape(const int arr[], int length, int rows, int cols, int arr2d[nRows][nCols]);
bool found_duplicate(int arr[],int length);
void insert_element(int arr[],int length, int pos, int value);
void trans_matrix(int rows, int cols, const int arr2d[nRows][nCols], int mat_transp[nCols][nRows]);

int main()
{
int arr[SIZE] = {10, 20, 30, 40, 50};
    int arr2d[nRows][nCols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 2, 3}, {7, 8, 9} };

printf("Array UnTouched: \n");
print_array(arr, SIZE);
printf("\n");

printf("Matrix UnTouched: \n");
print_matrix(arr2d,nRows);
printf("\n");
//Call to different functions
isValid(arr,SIZE, pos);

printf("Array after removing element: \n");
remove_element(arr ,SIZE, pos);
print_array(arr, SIZE);

printf("\n");

printf("Array after inserting an elemnts: \n");
insert_element(arr,SIZE,pos,value);
print_array(arr, SIZE);

printf("\n");

reshape(arr, SIZE, nRows, nCols, arr2d[nRows][nCols]);
print_matrix(arr2d,nRows);

found_duplicate(arr,SIZE);

printf("\n");

int arr2d_transp[8][3];
printf("Transposed matrix");
trans_matrix(nRows, nCols, arr2d, arr2d_transp);
print_matrix(arr2d,nRows);
}

void print_array(int array[], int length){
   for(int i=0; i < length; i++ )
      printf("array[%d]= %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows){
   for(int i=0; i < rows; i++){
    for(int j=0; j < nCols; j++)
         printf("mat[%d][%d]= %d\n", i,j, mat[i][j]);
    puts("");     
   }     
}

//FUNCTION DEFINITIONS
bool isValid(const int arr[], int length, int pos) {
    return pos >= 0 && pos < length;
}

void remove_element(int arr[],int length, int pos){
    for (int i = pos; i > 0; i--){
        arr[i] = arr[i - 1];
    }
}

void reshape(const int arr[], int length, int rows, int cols, int arr2d[nRows][nCols]){
    if(length != (rows*cols)){
        printf("Error: The length of the array is not equal to nRows * nCols \n");
    }
    int x;
    do{
        for(int i = 0; i< nCols; i++){
            for(int j =0; j<nRows; j++){
            
                arr2d[j][i] = arr[i];
                x++;
            }
        }
    }while(x > length);
}

bool found_duplicate(int arr[],int length) {
    for (int z = 0; z < (length-1); z++) {
        for (int j = z + 1; j < length; j++) {
            if(arr[z] == arr[j]){
                return true;
            }else {
                return false;
            }
        }
    }
}

void insert_element(int arr[],int length, int pos, int value) {
    int y;
    y = arr[pos-1];
    for (int i = 0; i < (length-1); i++) {
        if(i == pos-1 ){
            arr[i] = arr[pos];
        } else if(i == pos - 2) {
            arr[i] = y;
        }
        arr[i] = arr[i];
    }
    arr[pos] = value;
}

void trans_matrix(int rows, int cols, const int arr2d[nRows][nCols], int mat_transp[nCols][nRows]){
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            mat_transp[j][i] = arr2d[i][j];
        }
    }
}
