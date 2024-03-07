/**
* @file NHammadProject1
* @description It is a program that executes and tests matrix operations.
* @assignment BP3 Project 1
* @date 4.12.2022
* @author Nouredeen Ahmed Mahmoud Ali Hammad - nouredeen.ahmed@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrixLib.h"

int main(int argc, char* argv[]){

    if(argc<2){
        printf("\nError: please enter a seed number as an argument\n");
        return 0;
    }

    int seed = atoi(argv[1]);
    srand(seed);

    printf("\n########################################################\n");
    printf("\n[1] Return vector:\n");

    float* vec = returnVector(3);
    printVector(vec, 3);

    printf("\n\n[2] Return matrix:\n");

    float** mat = returnMatrix(3,3);
    printMatrix(mat, 3, 3);

    free(vec);
    freeMatrix(mat,3);



    printf("\n########################################################\n");

    float* vec1 = genRandomVector(5);
    printf("\nVector 1:\n");
    printVector(vec1,5);
    float* vec2 = genRandomVector(5);
    printf("\n\nVector 2:\n");
    printVector(vec2,5);

    float vec1mean = mean(vec1,5);
    float vec2mean = mean(vec2,5);
    printf("\n\n[3] Mean of vector 1 = %.3f\n\n    Mean of vector 2 = %.3f\n", vec1mean, vec2mean);

    float vec12cov = covariance(vec1,vec2,5);
    printf("\n[4] Covariance of Vector 1 and 2 = %.3f\n", vec12cov);

    float vec12cor = correlation(vec1,vec2,5);
    printf("\n[5] Correlation of Vector 1 and 2 = %.3f\n", vec12cor);

    free(vec1);
    free(vec2);



    printf("\n########################################################\n");

    float **mat1 = genRandomMatrix(3,4);
    float **mat2 = genRandomMatrix(4,3);
    float **mat1x2 = matrixMultiplication(mat1,mat2,3,4,4,3);
    float **mat2x1 = matrixMultiplication(mat2,mat1,4,3,3,4);

    printf("\nMatrix 1 (3,4):\n");
    printMatrix(mat1,3,4);
    printf("\n\nMatrix 2 (4,3):\n");
    printMatrix(mat2,4,3);
    printf("\n\n[6] Matrix 1 multiplied by Matrix 2:\n");
    printMatrix(mat1x2,3,3);
    printf("\n\nMatrix 2 multiplied by Matrix 1:\n");
    printMatrix(mat2x1,4,4);

    printf("\n");

    float **mat1trans = matrixTranspose(mat1,3,4);
    printf("\n[7] Transpose of Matrix 1:\n");
    printMatrix(mat1trans,4,3);

    //Freeing the memory of matrices that are no longer needed
    freeMatrix(mat1,3);
    freeMatrix(mat2,4);
    freeMatrix(mat1x2,3);
    freeMatrix(mat1trans,4);



    printf("\n########################################################\n");

    float **mat3 = genRandomMatrix(3,3);
    printf("\nMatrix 3 (3,3):\n");
    printMatrix(mat3,3,3);

    printf("\n\n[8] Matrix 3's Row Means (vector):\n");
    float *mat3rm = rowMeans(mat3,3,3);
    printVector(mat3rm,3);

    printf("\n\n[9] Matrix 3's Column Means (vector):\n");
    float *mat3cm = columnMeans(mat3,3,3);
    printVector(mat3cm,3);

    printf("\n\n[10] Matrix 3's Covariance Matrix:\n");
    float **mat3covm = covarianceMatrix(mat3,3,3);
    printMatrix(mat3covm,3,3);

    float mat3det = determinant(mat3,3);
    printf("\n\n[11] Matrix 3's Determinant = %.3f\n\n", mat3det);

    //Freeing the memory of matrices that are no longer needed
    free(mat3cm);
    free(mat3rm);
    freeMatrix(mat3,3);
    freeMatrix(mat3covm,3);

    //Printing a previously freed matrix
    printf("\nMatrix 1 after it has been freed:\n");
    printMatrix(mat1,3,4);
    printf("\n");

    return 0;
}