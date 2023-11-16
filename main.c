#include "stdio.h"
#include "login.h"
#include "patient information.h"
#include "dosage.h"
#include "cpr.h"

int main() {
<<<<<<< HEAD
    // Take CPR input and print info from user.pass
    EnterCPR();

    liquidDosage();
=======
    if (login() == 1) {
        EnterCPR();
        dosageCalculator();
    }
    return 0;
>>>>>>> parent of 7775d43 (timestamp)
}