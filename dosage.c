#include <stdlib.h>
#include "cJSON.h"
#include <stdio.h>
#include "dosage.h"

// https://www.omnicalculator.com/health/dosage#calculating-medication-dosage-by-weight

double liquidDosage(){
    double liquidDose, dosage, concentration, patientWeight, dosagePerKg, maxDosage;
    int unitChoice, unitChoice2, unitChoice3;

    printf("Press 1 for dosage by weight calculator, press 2 for liquid dosage calculator.\n>");
    scanf("%d", &unitChoice2);

    if (unitChoice2 == 2){
        printf("Select the unit of measurement for the liquid dosage.\n");
        printf("1 for ml/L 2 for mg/L, 3 for mcg/L, 4 for mg/mL, 5 for mcg/mL).\n>");
        scanf("%d", &unitChoice);
        printf("Enter the medicine concentration.\n>");
        scanf("%lf", &concentration);
        printf("Enter the dosage.\n>");
        scanf("%lf", &dosage);

        if (unitChoice == 1){
            liquidDose = dosage / concentration;
            printf("The liquid dosage is: %.2lf ml/L.\n", liquidDose);
        } else if (unitChoice == 2){
            liquidDose = (dosage / concentration) * 1000;
            printf("The liquid dosage is: %.2lf mg/L.\n", liquidDose);
        } else if (unitChoice == 3){
            liquidDose = (dosage / concentration) * 1000000;
            printf("The liquid dosage is: %.2lf mcg/L.\n", liquidDose);
        } else if (unitChoice == 4){
            liquidDose = concentration / dosage;
            printf("The liquid dosage is: %.2lf mg/mL.\n", liquidDose);
        } else if (unitChoice == 5) {
            liquidDose = concentration / dosage;
            printf("The liquid dosage is: %.2lf mcg/mL.\n", liquidDose);
        }
    } else if (unitChoice2 == 1){
        printf("Enter the patient's weight in kilograms\n>");
        scanf("%lf", &patientWeight);
        printf("Input medicine dosage per kg\n>");
        scanf("%lf", &dosagePerKg);
        printf("Choose the unit (1 for g, 2 for mg, 3 for mcg)\n>");
        scanf("%d", &unitChoice);
        printf("Enter the maximum allowable dosage\n>");
        scanf("%lf", &maxDosage);

        if (unitChoice3 == 1) { // g
            dosage = patientWeight * dosagePerKg;
            printf("The calculated dosage is: %.2lf g.\n", dosage);
        } else if (unitChoice3 == 2) { // mg
            dosage = (patientWeight * dosagePerKg) * 1000;
            printf("The calculated dosage is: %.2lf mg.\n", dosage);
        } else if (unitChoice3 == 3) { // mcg
            dosage = (patientWeight * dosagePerKg) * 1000000;
            printf("The calculated dosage is: %.2lf mcg.\n", dosage);
        }

        if (dosage > maxDosage) {
            return maxDosage;
        } else {
            return dosage;
        }
    }
    return 0;
}


