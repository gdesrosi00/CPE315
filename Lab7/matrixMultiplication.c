#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

void matMult();
void populateMatrix();
void printMatrix();

int main()
{
   //Initialize matrices of the given size
   static int A[SIZE][SIZE];
   static int B[SIZE][SIZE];
   static int C[SIZE][SIZE];
   int height = SIZE;
   int width = SIZE;

   //Populate matrices with the given value.
   //A and B are populated with 1 for simplicity
   //C is populated with 0 to allow for algorithm to work
   populateMatrix(A, height, width, 1);
   populateMatrix(B, height, width, 1);
   populateMatrix(C, height, width, 0);

   matMult(C, A, B, height, width);

   //This line prints out the product matrix from the matMult function.
   //It was used to make sure the matMult function was correct, but is not needed for the project.
   //printMatrix(C, height, width);

   return 0;
}


//Assume: All values are integers
//        Matrices are of the same size
//        All values are correctly allocated and initialized

void matMult(int C[SIZE][SIZE], int A[SIZE][SIZE], int B[SIZE][SIZE], int height, int width)
{
   int i, j, k;
   for (i = 0; i < height; i++)
   {
      for (j = 0; j < width; j++)
      {
         for (k = 0; k < height /*- (height % 8) */; k++)
         {
            //No unrolling
            C[i][j] = C[i][j] + (A[i][k] * B[k][j]);

            //Level 2 loop unrolling (include original statement too):
            //k++;
            //C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            //
            //Level 4 loop unrolling (include Level 2):
            //k++;
            //C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            //k++;
            //C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            //
            //Level 8 loop unrolling (include Level 4):
            //k++;
            //C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            //k++;
            //C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            //k++;
            //C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            //k++;
            //C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
         }
         //Extra iterations lost for Level 8:
         //C[i][j] = C[i][j] + (A[i][96] * B[96][j]);
         //C[i][j] = C[i][j] + (A[i][97] * B[97][j]);
         //C[i][j] = C[i][j] + (A[i][98] * B[98][j]);
         //C[i][j] = C[i][j] + (A[i][99] * B[99][j]);
      }
   }
}

void populateMatrix(int M[SIZE][SIZE], int height, int width, int val)
{
   int i, j;
   for (i = 0; i < height; i++)
   {
      for (j = 0; j < width; j++)
         M[i][j] = val;
   }
}

void printMatrix(int M[SIZE][SIZE], int height, int width)
{
   int i, j;
   for (i = 0; i < height; i++)
   {
      for (j = 0; j < width; j++)
         printf("%d ", M[i][j]);
   }
   printf("\n");
}
