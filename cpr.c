#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "Enter CPR .h"

// A function (int Enter_CPR()) to type in a CPR number and check if it is in the database
// Make variabels?

//  It needs to check if the CPR number is in the database
// Needs an if/else

// If the CPR number is in the database, then the code for patient information is to run
// Else print "invalid patient" and back to "Enter CPR number"

int EnterCPR() {
    FILE *fileptr;

    //input and scan for CPR-number
    printf("Please enter patients CPR-number:\n>");
    scanf("" CPRnr);

    //open json file
    fileptr = fopen(//json document location,---);

}
