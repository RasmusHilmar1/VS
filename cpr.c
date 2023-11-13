#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "patient information.h"

char EnterCPR() {
    char CPRnr[11];  // Make room for 10 digits and the null terminator

    // Input and scan for CPR-number
    printf("Please enter patients CPR-number:\n>");
    scanf("%s", CPRnr);

    // Check if the input matches what a CPR number would be
    int CPRnrInputLength = strlen(CPRnr);
    bool IsDigit = true;

    for (int i = 0; i < CPRnrInputLength; i++) {
        if (!isdigit(CPRnr[i])) {
            IsDigit = false;
            break;
        }
    }

    if (!(IsDigit == true && CPRnrInputLength == 10)) {
        printf("Invalid CPR-number\n");
        return EnterCPR();  // Re-enter CPR number
    }

    print_patient(CPRnr);
}