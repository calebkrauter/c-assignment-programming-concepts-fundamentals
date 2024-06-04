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
int test(int *actual, int *expected, int size);
int main() {

    /*Test binNegate on 1,0,0,1,1,1,0,1,1*/
    int size = 9;
    int bin[] = {1,0,0,1,1,1,0,1,1};
    int binExpected[] = {1,1,0,0,0,1,0,0};
    int outSizeVal = size;
    int *outSize = &outSizeVal;
    int *outputNegate1 = binNegate(bin, size, outSize);
    printArray("binNegate", outputNegate1, *outSize);
    printArray("NON FUNC INPUT ARRAY", bin, size);
    printf("0 fail, 1 pass, result: %d : \n", test(outputNegate1, binExpected, *outSize));
    /*Test binNegate on 1*/
    int size2 = 1;
    int bin2[] = {1};
    int binExpected2[] = {0};
    int outSizeVal2 = size2;
    int *outSize2 = &outSizeVal2;
    int *outputNegate2 = binNegate(bin2, size2, outSize2);
    printArray("binNegate", outputNegate2, size2);
    printArray("NON FUNC INPUT ARRAY", bin2, size2);
    printf("0 fail, 1 pass, result: %d : \n", test(outputNegate2, binExpected2, *outSize2));
    /*Test binNegate on 0*/
    int size3 = 1;
    int bin3[] = {0};
    int binExpected3[] = {1};
    int outSizeVal3 = size3;
    int *outSize3 = &outSizeVal3;
    int *ouputNegate3 = binNegate(bin3, size3, outSize3);
    printArray("binNegate", ouputNegate3, size3);
    printArray("NON FUNC INPUT ARRAY", bin3, size3);
    printf("0 fail, 1 pass, result: %d : \n", test(ouputNegate3, binExpected3, *outSize3));
    /*Test binAnd on 1,0,0,1,1,1,0,0,1 and 1,1,0,0*/
    int size14 = 9;
    int size24 = 4;
    int outSizeVal4 = size24;
    int *outSize4 = &outSizeVal4;
    int bin14[] = {1,0,0,1,1,1,0,0,1};
    int bin24[] = {1,1,0,0};
    int resultAnd1[] = {1,0,0,0};
    int *outputAnd1 = binAnd(bin14, size14, bin24, size24, outSize4);
    printArray("binAnd", outputAnd1, *outSize4);
    printArray("NON FUNC INPUT ARRAY 1 ", bin14, size14);
    printArray("NON FUNC INPUT ARRAY 2 ", bin24, size24);
    printf("0 fail, 1 pass, result: %d : \n", test(outputAnd1, resultAnd1, *outSize4));
    /*Test binAnd on 1,0,0,1,1,1,0,0,1 and 0,0,1,1*/
    int size15 = 9;
    int size25 = 4;
    int outSizeVal5 = size24;
    int *outSize5 = &outSizeVal5;
    int bin15[] = {1,0,0,1,1,1,0,0,1};
    int bin25[] = {0,0,1,1};
    int resultAnd2[] = {1,0,0,0};
    int *outputAnd2 = binAnd(bin14, size14, bin24, size24, outSize4);
    printArray("binAnd", outputAnd2, *outSize5);
    printArray("NON FUNC INPUT ARRAY 1 ", bin15, size15);
    printArray("NON FUNC INPUT ARRAY 2 ", bin25, size25);
    printf("0 fail, 1 pass, result: %d : \n", test(outputAnd2, resultAnd1, *outSize4));
    /*Test binAnd on 1,1,0,1,0,1,0,0,1 and 0,0,1,1*/
    int size16 = 9;
    int size26 = 4;
    int outSizeVal6 = size24;
    int *outSize6 = &outSizeVal6;
    int bin16[] = {1,1,0,1,0,1,0,0,1};
    int bin26[] = {0,0,1,1};
    int resultAnd6[] = {1,0,0,0};
    int *outputAnd3 = binAnd(bin16, size16, bin26, size26, outSize6);
    printArray("binAnd", outputAnd3, *outSize6);
    printArray("NON FUNC INPUT ARRAY 1 ", bin16, size16);
    printArray("NON FUNC INPUT ARRAY 2 ", bin26, size26);
    printf("0 fail, 1 pass, result: %d : \n", test(outputAnd3, resultAnd6, *outSize6));
    /*Test binOr on 1,0,0,1,1,1,0,0,1 and 1,1,0,0*/
    int sizeOr1 = 9;
    int sizeOr2 = 4;
    int bin1Or[] = {1,0,0,1,1,1,0,0,1};
    int bin2Or[] = {1,1,0,0};
    int resultOr1[] = {1,0,0,1,1,1,1,0,1};
    int outSizeVal7 = sizeOr2;
    int *outSize7 = &outSizeVal7;
    int *outputOr1 = binOr(bin1Or, sizeOr1, bin2Or, sizeOr2, outSize7);
    printArray("binOr", outputOr1, *outSize7);
    printArray("NON FUNC INPUT ARRAY 1 ", bin15, size15);
    printArray("NON FUNC INPUT ARRAY 2 ", bin25, size25);
    printf("0 fail, 1 pass, result: %d : \n", test(outputOr1, resultOr1, *outSize7));
    /*Test binOr on 1,0,0,1,1,1,0,0,1 and 1,1,0,0*/
    int sizeOr12 = 9;
    int sizeOr22 = 9;
    int bin1Or2[] = {1,0,0,1,1,1,0,0,1};
    int bin2Or2[] = {1,1,1,1,1,1,1,1,1};
    int resultOr12[] = {1,1,1,1,1,1,1,1,1};
    int outSizeVal8 = sizeOr22;
    int *outSize8 = &outSizeVal8;
    int *outputOr12 = binOr(bin1Or2, sizeOr12, bin2Or2, sizeOr22, outSize8);
    printArray("binOr", outputOr12, *outSize8);
    printArray("NON FUNC INPUT ARRAY 1 ", bin1Or2, sizeOr12);
    printArray("NON FUNC INPUT ARRAY 2 ", bin2Or2, sizeOr22);
    printf("0 fail, 1 pass, result: %d : \n", test(outputOr12, resultOr12, *outSize8));
    /*Test binOr on 0,0,0,0,0,0,0 and 0*/
    int sizeOr13 = 7;
    int sizeOr23 = 1;
    int bin1Or3[] = {0,0,0,0,0,0,0};
    int bin2Or3[] = {0};
    int resultOr13[] = {0};
    int outSizeVal9 = sizeOr23;
    int *outSize9 = &outSizeVal8;
    int *outputOr13 = binOr(bin1Or3, sizeOr13, bin2Or3, sizeOr23, outSize9);
    printArray("binOr", outputOr13, *outSize9);
    printArray("NON FUNC INPUT ARRAY 1 ", bin1Or3, sizeOr13);
    printArray("NON FUNC INPUT ARRAY 2 ", bin2Or3, sizeOr23);
    printf("0 fail, 1 pass, result: %d : \n", test(outputOr13, resultOr13, *outSize9));
    /*Test binXOr on 1,0,0,1,1,1,0,0,1 and 1,1,0,0*/
    int sizeXOr1 = 9;
    int sizeXOr2 = 4;
    int bin1XOr[] = {1,0,0,1,1,1,0,0,1};
    int bin2XOr[] = {1,1,0,0};
    int resultXOr1[] = {1,0,0,1,1,0,1,0,1};
    int outSizeValXOr1 = 9;
    int *outSizeXor1 = &outSizeValXOr1;
    int *outputXOr1 = binXOr(bin1XOr, sizeXOr1, bin2XOr, sizeXOr2, outSizeXor1);
    outSizeValXOr1 = 9;
    printArray("binXOr", outputXOr1, *outSizeXor1);
    printArray("NON FUNC INPUT ARRAY 1 ", bin1XOr, sizeXOr1);
    printArray("NON FUNC INPUT ARRAY 2 ", bin2XOr, sizeXOr2);
    printf("0 fail, 1 pass, result: %d : \n", test(outputXOr1, resultXOr1, *outSizeXor1));
    /*Test binXOr on 1,0,0,1,1,1,0,0,1 and 1,1,1,1,1,1,1,1,1*/
    int sizeXOr12 = 9;
    int sizeXOr22 = 9;
    int bin1XOr2[] = {1,0,0,1,1,1,0,0,1};
    int bin2XOr2[] = {1,1,1,1,1,1,1,1,1};
    int resultXOr12[] = {1,1,0,0,0,1,1,0};
    int outSizeValXOr12 = 8;
    int *outSizeXor12 = &outSizeValXOr12;
    int *outputXOr12 = binXOr(bin1XOr2, sizeXOr12, bin2XOr2, sizeXOr22, outSizeXor12);
    printArray("binXOr", outputXOr12, *outSizeXor12);
    printArray("NON FUNC INPUT ARRAY 1 ", bin1XOr2, sizeXOr12);
    printArray("NON FUNC INPUT ARRAY 2 ", bin2XOr2, sizeXOr22);
    outSizeValXOr12 = 8;
    printf("0 fail, 1 pass, result: %d : \n", test(outputXOr12, resultXOr12, *outSizeXor12));
    /*Test binXOr on 1 and 1*/
    int sizeXOr13 = 1;
    int sizeXOr23 = 1;
    int bin1XOr3[] = {1};
    int bin2XOr3[] = {1};
    int resultXOr13[] = {0};
    int outSizeValXOr13 = 1;
    int *outSizeXor13 = &outSizeValXOr13;
    int *outputXOr13 = binXOr(bin1XOr3, sizeXOr13, bin2XOr3, sizeXOr23, outSizeXor13);
    printArray("binXOr", outputXOr13, *outSizeXor13);
    printArray("NON FUNC INPUT ARRAY 1 ", bin1XOr3, sizeXOr13);
    printArray("NON FUNC INPUT ARRAY 2 ", bin2XOr3, sizeXOr23);
    printf("0 fail, 1 pass, result: %d : \n", test(outputXOr13, resultXOr13, *outSizeXor13));
    /*Test binAdd on 1,1,0,0,1 and 1,1,0,0*/
    int sizeAdd1 = 5;
    int sizeAdd2 = 4;
    int bin1Add[] = {1,1,0,0,1};
    int bin2Add[] =   {1,1,0,0};
    int sizeAdd = 6;
    int *addOutSize = &sizeAdd;
    int *outputAdd1 = binAdd(bin1Add, sizeAdd1, bin2Add, sizeAdd2, addOutSize);
    int resultAdd1[] = {1,0,0,1,0,1};
    printArray("binAdd", outputAdd1, *addOutSize);
    printArray("NON FUNC INPUT ARRAY 1 ", bin1Add, sizeAdd1);
    printArray("NON FUNC INPUT ARRAY 2 ", bin2Add, sizeAdd2);
    printf("0 fail, 1 pass, result: %d : \n", test(outputAdd1, resultAdd1, *addOutSize));
    /*Test binAdd on 1,1,1,1,1,1,1,1,1 and 1,1,1,1,1,1,1,1,1*/
    int sizeAdd12 = 9;
    int sizeAdd22 = 9;
    int bin1Add2[] = {1,1,1,1,1,1,1,1,1};
    int bin2Add2[] = {1,1,1,1,1,1,1,1,1};
    int sizeAdd2Val = 10;
    int *addOutSize2 = &sizeAdd2Val;
    int *outputAdd12 = binAdd(bin1Add2, sizeAdd12, bin2Add2, sizeAdd22, addOutSize2);
    int resultAdd12[] = {1,1,1,1,1,1,1,1,1,0};
    printArray("binAdd", outputAdd12, *addOutSize2);
    printArray("NON FUNC INPUT ARRAY 1 ", bin1Add2, sizeAdd12);
    printArray("NON FUNC INPUT ARRAY 2 ", bin2Add2, sizeAdd22);
    printf("0 fail, 1 pass, result: %d : \n", test(outputAdd12, resultAdd12, *addOutSize2));
    /*Test binAdd on 0,0,0 and 0*/
    int sizeAdd13 = 3;
    int sizeAdd23 = 1;
    int bin1Add3[] = {0,0,0};
    int bin2Add3[] = {0};
    int sizeAdd3Val = 1;
    int *addOutSize3 = &sizeAdd3Val;
    int *outputAdd13 = binAdd(bin1Add3, sizeAdd13, bin2Add3, sizeAdd23, addOutSize3);
    int resultAdd13[] = {0};
    printArray("binAdd", outputAdd13, *addOutSize3);
    printArray("NON FUNC INPUT ARRAY 1 ", bin1Add3, sizeAdd13);
    printArray("NON FUNC INPUT ARRAY 2 ", bin2Add3, sizeAdd23);
    printf("0 fail, 1 pass, result: %d : \n", test(outputAdd13, resultAdd13, *addOutSize3));
    /*Test trimLeadingZeros on 0,0,0,0,0,0,0,0,0*/
    int tooManyZeros[] = {0,0,0,0,0,0,0,0,0};
    int *outSizeTrim;
    int val1 = 1;
    outSizeTrim = &val1;
    int *trimOutSizeResult;
    int val2 = 1;
    trimOutSizeResult = &val2;
    int trimResult[] = {0};
    printArray("trimLeadingZeros", tooManyZeros, *outSizeTrim);
    printArray("NON FUNC INPUT ARRAY 2 ", tooManyZeros, 9);
    printf("0 fail, 1 pass, result: %d : \n", test(trimLeadingZeros(tooManyZeros, 9, outSizeTrim), trimResult, *trimOutSizeResult));
    /*Test trimLeadingZeros on 0,1,0,0,0,0,0,0,0*/
    int tooManyZeros2[] = {0,1,0,0,0,0,0,0,0};
    int *outSizeTrim2;
    int val12 = 8;
    outSizeTrim2 = &val12;
    int *trimOutSizeResult2;
    int val22 = 8;
    trimOutSizeResult2 = &val22;
    int trimResult2[] = {1,0,0,0,0,0,0,0};
    printArray("trimLeadingZeros", tooManyZeros2, *outSizeTrim2);
    printArray("NON FUNC INPUT ARRAY 2 ", tooManyZeros2, 9);
    printf("0 fail, 1 pass, result: %d : \n", test(trimLeadingZeros(tooManyZeros2, 9, outSizeTrim), trimResult2, *trimOutSizeResult2));

    free(outputAnd1);
    free(outputAnd2);
    free(outputAnd3);
    free(outputOr1);
    free(outputOr12);
    free(outputOr13);
    free(outputXOr1);
    free(outputXOr12);
    free(outputXOr13);
    free(outputAdd1);
    free(outputAdd12);
    free(outputAdd13);
    return 0;
}

int test(int *actual, int *expected, int size) {
    int pass = 0;
        printArray("actual   ", actual, size);
        printArray("expected ", expected, size);
    for (unsigned int i = 0; i < size; i++) {
        if (actual[i] == expected[i]) {
            pass = 1;
        } else {
            return pass = 0;
        }
    }
    printf("------------------------------------------------------------------------");
    return pass;
}

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
    for (double i = 0; i < *outSize; i++) {
        
        decimalVal1 += (bin1[j] * pow(2.0, i));
        decimalVal2 += (bin2[j] * pow(2.0, i));
        j++;

    }
    int resultDecimal = decimalVal1 + decimalVal2;
    int *newArray = malloc(sizeof(int) * *outSize);
    for (int i = 0; i < *outSize; i++) {

        newArray[i] = (resultDecimal % 2);
        resultDecimal /= 2;

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
    if (i == 0) {
        bin1 = reverse(bin1, size1);
        bin2 = reverse(bin2, size2);
        newBin = malloc(sizeof(int) * *outSize);
    }
    i++;
    *outSize = size1 < size2 ? size1 : size2;
    if (i > *outSize) {
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
                newArray[i] = 1;
            } else if (j < size2 && j < size1){
                newArray[i] = 0;
            }
    }
    
    return trimLeadingZeros(reverse(newArray, *outSize), *outSize, outSize);
}
int *binXOr(int *bin1, int size1, int *bin2, int size2, int *outSize) {
    bin1 = reverse(bin1, size1);
    bin2 = reverse(bin2, size2);
    *outSize = size1 > size2 ? size1 : size2;
    int lesserSize = size1 < size2 ? size1 : size2; 
    int *newArray = malloc(sizeof(int) * *outSize);
    for (int i = 0; i < lesserSize; i++) {
        newArray[i] = (bin1[i] ^ bin2[i]);
    }
    for (int i = lesserSize; i < *outSize; i++) {
        if (size1 > size2) {
            newArray[i] = bin1[i];
        } else {
            newArray[i] = bin2[i];
        }
    }
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
    if (j == 0) {
        bin[0] = 0;
        j = 1;
    }
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