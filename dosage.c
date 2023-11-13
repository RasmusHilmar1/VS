#include <stdlib.h>
#include "cJSON.h"
#include <stdio.h>
#include "dosage.h"

double liquidDosage(){
    double liquidDose, *dosage = NULL, concentration, patientWeight, maxDosage;
    int unitChoice, unitChoice2, unitChoice3;
    dosage = (double*)malloc(sizeof(double));

    printf("Press 1 for dosage by weight calculator, press 2 for liquid dosage calculator.\n>");
    scanf("%d", &unitChoice2);

    if (unitChoice2 == 2){
        printf("Select the unit of measurement for the liquid dosage.\n");
        printf("1 for ml/L 2 for mg/L, 3 for mcg/L.\n>");
        scanf("%d", &unitChoice);
        printf("Enter the medicine concentration.\n>");
        scanf("%lf", &concentration);
        printf("Enter the dosage.\n>");
        scanf("%lf", dosage);

        if (unitChoice == 1){
            liquidDose = *dosage / concentration;
            printf("The liquid dosage is: %.2lf ml.\n", liquidDose);
        } else if (unitChoice == 2){
            liquidDose = (*dosage / concentration) * 1000;
            printf("The liquid dosage is: %.2lf ml.\n", liquidDose);
        } else if (unitChoice == 3){
            liquidDose = (*dosage / concentration) * 1000000;
            printf("The liquid dosage is: %.2lf ml.\n", liquidDose);
        }

    } else if (unitChoice2 == 1){
        printf("Enter the patient's weight in kilograms\n>");
        scanf("%lf", &patientWeight);
        printf("Input medicine dosage per kg\n>");
        scanf("%lf", dosage);
        printf("Choose the unit (1 for g, 2 for mg, 3 for mcg)\n>");
        scanf("%d", &unitChoice3);
        printf("Enter the maximum allowable dosage\n>");
        scanf("%lf", &maxDosage);

        if (*dosage < maxDosage) {
            if (unitChoice3 == 1) { // g
                *dosage *= patientWeight;
                printf("The calculated dosage is: %.2lf g.\n", *dosage);
            } else if (unitChoice3 == 2) { // mg
                *dosage *= patientWeight * 1000;
                printf("The calculated dosage is: %.2lf mg.\n", *dosage);
            } else if (unitChoice3 == 3) { // mcg
                *dosage *= patientWeight * 1000000;
                printf("The calculated dosage is: %.2lf mcg.\n", *dosage);
            }
        } else if (*dosage > maxDosage) {
            printf("The dosage is too high, please try again.\n");
        }
    }
    free(dosage);
    return 0;
}


