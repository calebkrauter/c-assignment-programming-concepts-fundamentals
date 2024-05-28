#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void binNegate(int *bin, int size, int *outsize);
void binAnd(int *bin1, int size1, int *bin2, int size2, int *outSize);
void trimLeadingZeros(int *bin, int size, int *outSize);
void printArray(int *bin, int size);
int *initBinArray(int binLiteral[], int *binOut, int size);

int main() {
    int *bin;
    int size = 9;
    bin = malloc( size * sizeof(int));
    // Use foor binNegate Example.
    int binLiteral[] = {1,0,0,1,1,1,0,1,1};
    // Use for trimLeadingZeros Example.
    // int binLiteral[] = {0,0,0,1,1,1,0,0,1};

    bin = initBinArray(binLiteral, bin, size);

    int outSizeVal = size;
    int *outSize = &outSizeVal;
    binNegate(bin, size, outSize);
    printArray(bin, *outSize);
    // trimLeadingZeros(bin, size, outSize);
    int *bin1, *bin2;
    int size1 = 9;
    int size2 = 4;
    int outSizeVal2 = size2;
    *outSize = outSizeVal2;
    bin1 = malloc(size1 * sizeof(int));
    bin2 = malloc(size2 * sizeof(int));
    int bin1Literal[] = {1,0,0,1,1,1,0,0,1};
    int bin2Literal[] = {1,1,0,0};
    bin1 = initBinArray(bin1Literal, bin1, size1);
    
    bin2 = initBinArray(bin2Literal, bin2, size2);


    binAnd(bin1, size1, bin2, size2, outSize);
    
    // printf("%d,", *outSize);
    printArray(bin1, *outSize);
    return 0;
}

int *initBinArray(int binLiteral[], int *bin, int size) {
    for (int i = 0; i < size; i++) {
        bin[i] = binLiteral[i];
    }
    return bin;
}

void binNegate(int *bin, int size, int *outsize) {
    for (int i = 0; i < size; i++) {
        if (bin[i] == 0) {
            bin[i] = 1;
        } else {
            bin[i] = 0;
        }
    }
    trimLeadingZeros(bin, size, outsize);
}

void binAnd(int *bin1, int size1, int *bin2, int size2, int *outSize) {
    static int i = 0;
    i++;
        // printf("%d", bin1[i]);
        // printArray(bin1, size1);
    *outSize = size1 < size2 ? size1 : size2;
    // printf("%d, ", *outSize);
    if (i >= *outSize) {
        trimLeadingZeros(bin1, size1, outSize);
        return;
    } else if (bin1[i] == 1 && bin1[i] == bin2[i]) {
        bin1[i] = 1;
    } else {
        bin1[i] = 0;
    }
    binAnd(bin1, size1, bin2, size2, outSize);
}

void trimLeadingZeros(int *bin, int size, int *outSize) {
    int foundFirst1 = 0;
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (bin[i] == 1) {
            foundFirst1 = 1;
        }
        if (foundFirst1) {
            bin[j] = bin[i];
            j++;
        }
    }
    // This line only appears useful because
    // it modifies the amount of digits printed from the array
    // not the actual size of the array.
    if (*outSize >= j) {
        *outSize = j;
    }
}

void printArray(int bin[], int size) {
    printf("[");
    for (unsigned int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d]", bin[i]);
        } else {
            printf("%d,", bin[i]);

        }
    }
}