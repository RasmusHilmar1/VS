#include <stdio.h>
#include "timestamp.h"
#include "cJSON.h"

void timestamp(cJSON *patient) {
    char timestamp[50];
    printf("Enter the timestamp:\n>");
    scanf("%s", timestamp);
    // Add the timestamp to the patient's information
    cJSON_AddItemToObject(patient, "Timestamp", cJSON_CreateString(timestamp));
}

/* void printPatientInfo(cJSON *patient) {
    if (patient != NULL) {
        printf("Name: %s\n", cJSON_GetObjectItemCaseSensitive(patient, "Name")->valuestring);
        printf("Age: %d\n", cJSON_GetObjectItemCaseSensitive(patient, "Age")->valueint);
        // Add more fields as needed
    } else {
        printf("Patient not found.\n");
    }
}

    cJSON* searchPatientByCPR(const char *jsonString, int cpr) {
    // Parse the JSON string
    cJSON *json = cJSON_Parse(jsonString);
    if (json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            printf("Error: %s\n", error_ptr);
        }
        return NULL;
    }

    // Search for the patient by CPR number
    cJSON *usersArray = cJSON_GetObjectItemCaseSensitive(json, "Users");
    if (cJSON_IsArray(usersArray)) {
        cJSON *patient = NULL;
        cJSON_ArrayForEach(patient, usersArray) {
            cJSON *cprNode = cJSON_GetObjectItemCaseSensitive(patient, "CPR");
            if (cJSON_IsNumber(cprNode) && cprNode->valueint == cpr) {
                return patient; // Found the patient
            }
        }
    }

    // Patient not found
    return NULL;
} */