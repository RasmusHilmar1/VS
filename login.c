#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "cJSON.h"

int login() {
    FILE *fileptr;
    char *buffer;
    long filelen;
    char username[25], password[25];
    int logintrack = 0;

    while (logintrack != 1) {
        // Scan in username and password
        printf("Input login username\n>");
        scanf("%s", username);
        printf("Input login password\n>");
        scanf("%s", password);

        // Open file, print error if fail
        fileptr = fopen("pass.json", "r");
        if (fileptr == NULL) {
            perror("Error opening file");
            return -1;
        }

        fseek(fileptr, 0, SEEK_END);
        filelen = ftell(fileptr);
        rewind(fileptr);

        // allocate memory for file
        buffer = (char *) malloc((filelen + 1) * sizeof(char));
        if (buffer == NULL) {
            perror("Error allocating memory for file content");
            fclose(fileptr);
            return -1;
        }
        fread(buffer, filelen, 1, fileptr);
        fclose(fileptr);

        buffer[filelen] = '\0';

        // parse the file
        cJSON *json = cJSON_Parse(buffer);
        if (json == NULL) {
            const char *error_ptr = cJSON_GetErrorPtr();
            if (error_ptr != NULL) {
                fprintf(stderr, "Error before: %s\n", error_ptr);
            }
            free(buffer);
            return -1;
        }

        // find data from the file
        int found = 0;
        cJSON *users = cJSON_GetObjectItemCaseSensitive(json, "Users");
        cJSON *user;

        // check if the user and password are correct, if so, print the result
        cJSON_ArrayForEach(user, users) {
            cJSON *json_username = cJSON_GetObjectItemCaseSensitive(user, "Username");
            cJSON *json_password = cJSON_GetObjectItemCaseSensitive(user, "Password");
            if (cJSON_IsString(json_username) && (json_username->valuestring != NULL)) {
                if (strcmp(username, json_username->valuestring) == 0) {
                    found = 1;
                    if (cJSON_IsString(json_password) && (json_password->valuestring != NULL)) {
                        if (strcmp(password, json_password->valuestring) == 0) {
                            printf("Login successful.\n\n");
                            logintrack = 1;
                        } else {
                            printf("Password incorrect.\n");
                        }
                    }
                    break;
                }
            }
        }

        // checks if the username exists in the list
        if (!found) {
            printf("Incorrect login.\n");
        }

        cJSON_Delete(json);
        free(buffer);
    }

    return 0;
}