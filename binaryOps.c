#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int *binNegate(int *bin, int size, int *outsize);
int *binAnd(int *bin1, int size1, int *bin2, int size2, int *outSize);
int *binOr(int *bin1, int size1, int *bin2, int size2, int *outSize);
int *binXOr(int *bin1, int size1, int *bin2, int size2, int *outSize);
int *binAdd(int *bin1, int size1, int *bin2, int size2, int *outSize);
int *reverse(int *bin, int size);
int *appendZeros(int *bin, int size, int newSize);
int *trimLeadingZeros(int *bin, int size, int *outSize);
void printArray(char *title, int *bin, int size);
void printArrayDebug(int *bin, int size);
// double pow(double x, double y);
int main() {
//     int size = 9;
//     int bin[] = {1,0,0,1,1,1,0,1,1};

//     int outSizeVal = size;
    // int *outSize = &outSizeVal;
    
//     printArray("binNegate", binNegate(bin, size, outSize), *outSize);

//     int size1 = 9;
//     int size2 = 4;
//     int outSizeVal2 = size2;
//     *outSize = outSizeVal2;
//     int bin1[] = {1,0,0,1,1,1,0,0,1};
//     int bin2[] = {1,1,0,0};
    
//     printArray("binAnd", binAnd(bin1, size1, bin2, size2, outSize), *outSize);

//     int sizeOr1 = 9;
//     int sizeOr2 = 4;
//     int bin1Or[] = {1,0,0,1,1,1,0,0,1};
//     int bin2Or[] = {1,1,0,0};

//     printArray("binOr", binOr(bin1Or, sizeOr1, bin2Or, sizeOr2, outSize), 9);
//    int sizeXOr1 = 9;
//     int sizeXOr2 = 4;
//     int bin1XOr[] = {1,0,0,1,1,1,0,0,1};
//     int bin2XOr[] = {1,1,0,0};
   
//     printArray("binXOr", binXOr(bin1XOr, sizeXOr1, bin2XOr, sizeXOr2, outSize), 9);


   int sizeAdd1 = 5;
    int sizeAdd2 = 4;
    int bin1Add[] = {1,1,0,0,1};
    int bin2Add[] =   {1,1,0,0};
    int sizeAdd = 6;
    int *addOutSize = &sizeAdd;
    int *array = binAdd(bin1Add, sizeAdd1, bin2Add, sizeAdd2, addOutSize);
    printArray("binAdd", array, *addOutSize);
    free(array);
    return 0;
}
// Add.
/*
if A[i] = 1 and B[i] = 1 then result[i] = 0 and update B to include another 1 at i - 1.
if 

*/

int *binAdd(int *bin1, int size1, int *bin2, int size2, int *outSize) {
    int largerSize = size1 > size2 ? size1 : size2;
    bin1 = reverse(bin1, size1);
    bin2 = reverse(bin2, size2);
    bin1 = appendZeros(bin1, size1 + 1, *outSize);
    bin2 = appendZeros(bin2, size2 + 1, *outSize);

    int resultSize = size1 >= size2 ? size1 : size2;
    int *result = malloc(sizeof(int) * resultSize);

    int decimalVal1 = 0;
    int decimalVal2 = 0;
    int j = 0;
    printf("%d", *outSize);
    for (double i = 0; i < *outSize; i++) {
        
        decimalVal1 += (bin1[j] * pow(2.0, i));
        decimalVal2 += (bin2[j] * pow(2.0, i));
        j++;

    }
    printf("D1 %d", decimalVal1);
    printf("D1 %d", decimalVal2);
    int resultDecimal = decimalVal1 + decimalVal2;
    int *newArray = malloc(sizeof(int) * *outSize);
    for (int i = 0; i < *outSize; i++) {

        newArray[i] = (resultDecimal % 2);
        resultDecimal /= 2;    printf(" %d", resultDecimal);

    }
    free(bin1);
    free(bin2);
    free(result);
    return reverse(newArray, *outSize);
}
int *reverse(int *bin, int size) {
    int *reversedArray = malloc(sizeof(int) * size);
    int j = 0;
    for (int i = size - 1; i >= 0; i--) {
        reversedArray[j] = bin[i];
        j++;
    }
    return reversedArray;
}

int *appendZeros(int *bin, int size, int newSize) {
    int *binNew = malloc(sizeof(int) * newSize);
    for (int i = 0; i < size; i++) {
        binNew[i] = bin[i];
    }
    for (int i = 0; i < newSize - size; i++) {
        binNew[size - 1 + i] = 0;
    }
    return binNew;
}

int *binNegate(int *bin, int size, int *outsize) {
    bin = trimLeadingZeros(bin, size, outsize);
    for (int i = 0; i < size; i++) {
        if (bin[i] == 0) {
            bin[i] = 1;
        } else {
            bin[i] = 0;
        }
    }
    return trimLeadingZeros(bin, size, outsize);
}

int *binAnd(int *bin1, int size1, int *bin2, int size2, int *outSize) {
    static int i = 0;
    static int *newBin;
    // printf("%d", bin1[i]);
    //     printf("%d", bin2[i]);

    if (i == 0) {
        bin1 = reverse(bin1, size1);
        bin2 = reverse(bin2, size2);
        newBin = malloc(sizeof(int) * *outSize);
    }
    i++;
    *outSize = size1 < size2 ? size1 : size2;
    if (i > *outSize) {
        printArray("ANDED NEW BIN: ", trimLeadingZeros(reverse(newBin, *outSize), *outSize, outSize), *outSize);
        // printArray("bin2 in AND: ", bin2, size2);
        return trimLeadingZeros(reverse(newBin, *outSize), *outSize, outSize);
    } else if (bin1[i] == 1 && bin1[i] == bin2[i]) {
 
        newBin[i] = 1;
    } else {
        newBin[i] = 0;
    }
    binAnd(bin1, size1, bin2, size2, outSize);
}

int *binOr(int *bin1, int size1, int *bin2, int size2, int *outSize) {
    bin1 = reverse(bin1, size1);
    bin2 = reverse(bin2, size2);
    *outSize = size1 > size2 ? size1 : size2; // Ensure outsize is largest size.
    int *newArray = malloc(sizeof(int) * *outSize);
    int j = -1;
    for (int i = 0; i <= *outSize; i++) {
        j++;
            if (((bin1[i] == 1) && j < size1) || ((bin2[i] == 1) && j < size2)) {
            // printf("bin1 at %d =%d, compared to bin2 at %d =%d j at %d size1 at %d size2 at %d\n",i,bin1[i],i,bin2[i],j,size1,size2);
                newArray[i] = 1;
            } else if (j < size2 && j < size1){
            // printf("bin1 at %d =%d, compared to bin2 at %d =%d j at %d size1 at %d size2 at %d\n",i,bin1[i],i,bin2[i],j,size1,size2);
                newArray[i] = 0;
            }
    }
    
    return trimLeadingZeros(reverse(newArray, *outSize), *outSize, outSize);
}
int *binXOr(int *bin1, int size1, int *bin2, int size2, int *outSize) {

    // printArrayDebug(bin1, size1);
    // printArrayDebug(bin2, size2);
    bin1 = reverse(bin1, size1);
    bin2 = reverse(bin2, size2);
    printArray("TESTING", bin1, size1);

     printArray("TESTING", bin2, size2);
    *outSize = size1 > size2 ? size1 : size2; // Ensure outsize is largest size.
    int lesserSize = size1 < size2 ? size1 : size2; 

    int *newArray = malloc(sizeof(int) * *outSize);
    int j = -1;
        printf("%d", *outSize - lesserSize - 1);

    for (int i = 0; i <= abs(*outSize - lesserSize - 1); i++) {
        j++;
            if (((bin1[i] == 1) && j < size1) && ((bin2[i] != 1) && j < size2) 
            || ((bin1[i] != 1) && j < size1) && ((bin2[i] == 1) && j < size2)) {
            // printf("bin1 at %d =%d, compared to bin2 at %d =%d j at %d size1 at %d size2 at %d\n",i,bin1[i],i,bin2[i],j,size1,size2);
                newArray[i] = 1;
            } else if (j < size2 && j < size1){
            // printf("bin1 at %d =%d, compared to bin2 at %d =%d j at %d size1 at %d size2 at %d\n",i,bin1[i],i,bin2[i],j,size1,size2);
                newArray[i] = 0;
            }
    }
    for (int i = abs(*outSize - lesserSize - 1); i <= *outSize; i++) {
        if (size1 < size2) {
            newArray[i] = bin2[i];

        } else {
            newArray[i] = bin1[i];
        }
    }
    // printArray("FINAL XOR ", trimLeadingZeros(reverse(newArray, *outSize), *outSize, outSize), 5);
    printArray("FINAL XOR ", newArray, 5);
    return trimLeadingZeros(reverse(newArray, *outSize), *outSize, outSize);
}
int *trimLeadingZeros(int *bin, int size, int *outSize) {
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
    return bin;
}

void printArrayDebug(int bin[], int size) {
    printArray("DEBUGGING: unspecified func", bin, size);
}

void printArray(char *title, int bin[], int size) {
    printf("Function in use is: %s and produces the array: ", title);
    printf("[");
    for (unsigned int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d]", bin[i]);
        } else {
            printf("%d,", bin[i]);

        }
    }
    printf("\n");
}