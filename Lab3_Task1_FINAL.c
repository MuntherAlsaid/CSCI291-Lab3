#include<stdio.h>   
#include <stdbool.h> // Library for boolean
#define SIZE 5       // Define constant for array size
#define nRows 8      // Define constant for the number of rows in a matrix
#define nCols 3      // Define constant for the number of columns in a matrix

int pos = 2;         // Position variable used in array manipulation functions
int value = 80;      // Value variable used for inserting into an array
int arr2d[nRows][nCols]; // Declare a 2D array with 8 rows and 3 columns

// FUNCTION PROTOTYPES
void print_array(int array[], int length); // Function to print elements of a 1D array
void print_matrix(int mat[][nCols], int rows); // Function to print elements of a 2D matrix
bool isValid(const int array[], int length, int pos); // Check if position is within array bounds
void remove_element(int arr[],int length, int pos); // Remove element from array at a specific position
void reshape(const int arr[], int length, int rows, int cols, int arr2d[nRows][nCols]); // Reshape 1D array into 2D
bool found_duplicate(int arr[],int length); // Check if array has duplicate elements
void insert_element(int arr[],int length, int pos, int value); // Insert value at specific position in array
void trans_matrix(int rows, int cols, const int arr2d[nRows][nCols], int mat_transp[nCols][nRows]); // Transpose 2D matrix

int main()
{
    int arr[SIZE] = {10, 20, 30, 40, 50}; // Initialize array with values
    int arr2d[nRows][nCols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 2, 3}, {7, 8, 9} }; // Initialize 2D array with values

    printf("Array UnTouched: \n");
    print_array(arr, SIZE); // Print original 1D array
    printf("\n");

    printf("Matrix UnTouched: \n");
    print_matrix(arr2d, nRows); // Print original 2D matrix
    printf("\n");

    // Call to different functions
    isValid(arr, SIZE, pos); // Check if position is within valid bounds for the array

    printf("Array after removing element: \n");
    remove_element(arr ,SIZE, pos); // Remove element at specified position in array
    print_array(arr, SIZE); // Print modified array
    printf("\n");

    printf("Array after inserting an elemnts: \n");
    insert_element(arr, SIZE, pos, value); // Insert new value at specified position
    print_array(arr, SIZE); // Print modified array
    printf("\n");

    reshape(arr, SIZE, nRows, nCols, arr2d); // Reshape 1D array into a 2D matrix

    found_duplicate(arr, SIZE); // Check for duplicates in array
    if (found_duplicate) {
        printf("Duplicates found\n"); // Print if duplicates found
    } else {
        printf("Duplicates not found"); // Print if no duplicates found
    }
    printf("\n");

    int arr2d_transp[8][3];
    printf("Transposed matrix");
    trans_matrix(nRows, nCols, arr2d, arr2d_transp); // Transpose the matrix
    print_matrix(arr2d, nRows); // Print transposed matrix
}

void print_array(int array[], int length) {
    for (int i = 0; i < length; i++) // Loop through array elements
        printf("array[%d]= %d\n", i, array[i]); // Print each element with its index
}

void print_matrix(int mat[][nCols], int rows) {
    for (int i = 0; i < rows; i++) { // Loop through rows
        for (int j = 0; j < nCols; j++) // Loop through columns
            printf("mat[%d][%d]= %d\n", i, j, mat[i][j]); // Print each matrix element
        puts(""); // Add a new line after each row
    }
}

// FUNCTION DEFINITIONS
bool isValid(const int arr[], int length, int pos) {
    return pos >= 0 && pos < length; // Check if position is within the bounds
}

void remove_element(int arr[], int length, int pos) {
    for (int i = pos; i > 0; i--) { // Shift elements one position left starting from pos
        arr[i] = arr[i - 1];
    }
}

void reshape(const int arr[], int length, int rows, int cols, int arr2d[nRows][nCols]) {
    if (length != (rows * cols)) { // Check if rows * cols is equal to length
        printf("\nError: The length of the array is not equal to nRows * nCols \n");
        return;
    } else {
        int x;
        do {
            for (int i = 0; i < nCols; i++) { // Loop through columns
                for (int j = 0; j < nRows; j++) { // Loop through rows
                    arr2d[j][i] = arr[i];
                    x++;
                }
            }
        } while (x > length);
        printf("Printing reshaped matrix: \n");
        print_matrix(arr2d, nRows); // Print reshaped 2D matrix
    }
}

bool found_duplicate(int arr[], int length) {
    for (int z = 0; z < (length - 1); z++) { // Loop through array elements
        for (int j = z + 1; j < length; j++) { // Compare with subsequent elements
            if (arr[z] == arr[j]) { // Check if duplicate is found
                return true; // Return true if duplicate exists
            } else {
                return false; // Return false if no duplicate
            }
        }
    }
}

void insert_element(int arr[], int length, int pos, int value) {
    int y;
    y = arr[pos - 1]; // Store value at specified position
    for (int i = 0; i < (length - 1); i++) { // Loop through array elements
        if (i == pos - 1) {
            arr[i] = arr[pos]; // Shift elements to the right to make room
        } else if (i == pos - 2) {
            arr[i] = y; // Restore stored value in appropriate position
        }
        arr[i] = arr[i];
    }
    arr[pos] = value; // Insert new value at specified position
}

void trans_matrix(int rows, int cols, const int arr2d[nRows][nCols], int mat_transp[nCols][nRows]) {
    for (int i = 0; i < nRows; i++) { // Loop through rows
        for (int j = 0; j < nCols; j++) { // Loop through columns
            mat_transp[j][i] = arr2d[i][j];
        }
    }
}
