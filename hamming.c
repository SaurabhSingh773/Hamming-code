#include <stdio.h>
#include <math.h>
void generateHammingCode(int data[4], int hammingCode[7]) {
    hammingCode[2] = data[0];  
    hammingCode[4] = data[1];  
    hammingCode[5] = data[2];  
    hammingCode[6] = data[3];  
    hammingCode[0] = hammingCode[2] ^ hammingCode[4] ^ hammingCode[6]; 
    hammingCode[1] = hammingCode[2] ^ hammingCode[5] ^ hammingCode[6];
    hammingCode[3] = hammingCode[4] ^ hammingCode[5] ^ hammingCode[6];  
}

void detectError(int hammingCode[7]) {
    int p1 = hammingCode[0] ^ hammingCode[2] ^ hammingCode[4] ^ hammingCode[6];
    int p2 = hammingCode[1] ^ hammingCode[2] ^ hammingCode[5] ^ hammingCode[6];
    int p3 = hammingCode[3] ^ hammingCode[4] ^ hammingCode[5] ^ hammingCode[6];
    int errorPosition = p3 * 4 + p2 * 2 + p1;  

    if (errorPosition == 0) {
        printf("No error detected in the Hamming code.\n");
    } else {
        printf("Error detected at position: %d\n", errorPosition);
        hammingCode[errorPosition - 1] ^= 1;  
        printf("Corrected Hamming code: ");
        for (int i = 0; i < 7; i++) {
            printf("%d ", hammingCode[i]);
        }
        printf("\n");
    }
}

int main() {
    int data[4];
    int hammingCode[7] = {0};
    printf("Enter 4 data bits (0 or 1): ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &data[i]);
    }
    generateHammingCode(data, hammingCode);
    printf("Generated Hamming Code: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", hammingCode[i]);
    }
    printf("\n");
    detectError(hammingCode);

    return 0;
}
