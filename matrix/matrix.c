#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int MAX;

// int matA[MAX][MAX]; 
// int matB[MAX][MAX]; 

int **matA; 
int **matB; 

// int matSumResult[MAX][MAX];
// int matDiffResult[MAX][MAX]; 
// int matProductResult[MAX][MAX]; 

// void fillMatrix(int matrix[MAX][MAX]) {
//     for(int i = 0; i<MAX; i++) {
//         for(int j = 0; j<MAX; j++) {
//             matrix[i][j] = rand()%10+1;
//         }
//     }
// }

void fillMatrix(int **matrix) {
    for(int i = 0; i<MAX; i++) {
        for(int j = 0; j<MAX; j++) {
            matrix[i][j] = rand()%10+1;
        }
    }
}

void printMatrix(int **matrix, int MAX) {
    for(int i = 0; i<MAX; i++) {
        for(int j = 0; j<MAX; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the sum of the
// values at the coordinates of matA and matB.
void* computeSum(void* args) { // pass in the number of the ith thread
    int *i = (int*) args;
    int x = (*i)/MAX;
    int y = (*i)%MAX;
  
//     matSumResult[x][y] = matA[x][y] + matB[x][y];
  
    return NULL;
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the difference of the
// values at the coordinates of matA and matB.
void* computeDiff(void* args) { // pass in the number of the ith thread
  
    int *i = (int*) args;
    int x = (*i)/MAX;
    int y = (*i)%MAX;
  
//     matDiffResult[x][y] = matA[x][y] - matB[x][y];
    return NULL;
}

// Fetches the appropriate coordinates from the argument, and sets
// the cell of matSumResult at the coordinates to the inner product
// of matA and matB.
void* computeProduct(void* args) { // pass in the number of the ith thread
  
    int *i = (int*) args;
    int x = (*i)/MAX;
    int y = (*i)%MAX;
  
//     matProductResult[x][y] = matA[x][y] * matB[x][y];
    return NULL;
}

// Spawn a thread to fill each cell in each result matrix.
// How many threads will you spawn?
int main(int argc, char *argv[]) {
    srand(time(0));  // Do Not Remove. Just ignore and continue below.
    // 0. Get the matrix size from the command line and assign it to MAX
    MAX = atoi(argv[1]);
    printf("%d", MAX);
    
    // 1. Fill the matrices (matA and matB) with random values.
    fillMatrix(matA);
//     fillMatrix(matB, MAX);
    
    // 2. Print the initial matrices.
    printf("Matrix A:\n");
    printMatrix(matA, MAX);
//     printf("Matrix B:\n");
//     printMatrix(matB, MAX);
    
    // 3. Create pthread_t objects for our threads.
    
    // 4. Create a thread for each cell of each matrix operation.
    // 
    // You'll need to pass in the coordinates of the cell you want the thread
    // to compute.
    // 
    // One way to do this is to malloc memory for the thread number i, populate the coordinates
    // into that space, and pass that address to the thread. The thread will use that number to calcuate 
    // its portion of the matrix. The thread will then have to free that space when it's done with what's in that memory.
    
    // 5. Wait for all threads to finish.
    
    // 6. Print the results.
//     printf("Results:\n");
//     printf("Sum:\n");
//     printMatrix(matSumResult);
//     printf("Difference:\n");
//     printMatrix(matDiffResult);
//     printf("Product:\n");
//     printMatrix(matProductResult);
    return 0;
  
}