#include "stdio.h"
#include "login.h"
#include "patient information.h"

int main() {
    // Take CPR input and print info from user.pass
    char cpr[12];
    printf("Input CPR\n>");
    scanf("%s", cpr);
    print_patient(cpr);
}