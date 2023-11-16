#ifndef VS_TIMESTAMP_H
#define VS_TIMESTAMP_H

#include "cJSON.h"

void timestamp(cJSON *patient);
cJSON* searchPatientByCPR(const char *jsonString, int cpr);
void printPatientInfo(cJSON *patient);

#endif
