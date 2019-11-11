

#ifndef CUSTOMERMODULE_H
#define CUSTOMERMODULE_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 50


typedef struct Customer {
    char name[DIM]; //
    char* typeOfCustomer; // gold, silver, bronze, etc
    // to implement:
    //      List orders; address; telephone number; etc
    //      ...
}T_customer;

T_customer *newCustomer(T_customer *p_c);
float computePrice(T_customer *p_c, float amount, float shipping);

float bronzePriceStrategy(float amount, float shipping);
float silverPriceStrategy(float amount, float shipping);
float goldPriceStrategy(float amount, float shipping);

void greetings(T_customer *p_c);


#endif //CUSTOMERMODULE_H
