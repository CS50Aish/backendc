#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int main() {
    cJSON *root, *name, *age, *city;
    char *json_string;

    // Create a JSON object
    root = cJSON_CreateObject();

    // Create name, age, and city objects
    name = cJSON_CreateString("John");

    // Corrected order: Create age and then add it to root
    age = cJSON_CreateNumber(30);
    cJSON_AddItemToObject(root, "age", age);

    city = cJSON_CreateString("New York");
    cJSON_AddItemToObject(root, "city", city);

    // Convert JSON object to a String
    json_string = cJSON_Print(root);

    // Print JSON string to the console
    printf("%s\n", json_string);

    // Free memory
    free(json_string);
    cJSON_Delete(root);

    return 0;
}
