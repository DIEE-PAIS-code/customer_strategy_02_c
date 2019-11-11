
#include "customerModule.h"
#include <stdio.h>
#include <string.h> // strcmp()
#include <stdlib.h> // exit()


T_customer *newCustomer(T_customer *p_c){

    printf("Insert customer's name: ");
    fgets(p_c->name, DIM, stdin);

    printf("Choose customer type:\n");
    printf("a: GOLD\n");
    printf("b: SILVER\n");
    printf("c: BRONZE\n");

    switch (getchar()) {
        case 'a':
            p_c->typeOfCustomer = "gold";
            break;
        case 'b':
            p_c->typeOfCustomer = "silver";
            break;
        case 'c':
            p_c->typeOfCustomer = "bronze";
            break;
        default:
            perror("Unknown customer type");
            exit(1);
    }
    return p_c;
}

float computePrice(T_customer *p_c, float amount,float shipping) {
    /* compute the total price
     * depending on customer category. */
    float price;
    if (strcmp(p_c->typeOfCustomer,"bronze" )==0){
        price= bronzePriceStrategy(amount, shipping);
    }
    else if (strcmp(p_c->typeOfCustomer,"silver" )==0){
        price= silverPriceStrategy(amount, shipping);
    }
    else if (strcmp(p_c->typeOfCustomer,"gold" )==0){
        price= goldPriceStrategy(amount, shipping);
    }
    else{
        perror("Unknown customer type");
        exit(1);
    }
    return price;
}


float bronzePriceStrategy(float amount, float shipping){
    return amount+shipping;
}
float silverPriceStrategy(float amount, float shipping){
    return 0.9*amount+shipping;
}
float goldPriceStrategy(float amount, float shipping){
    return 0.8*amount; // free shipping;
}

void greetings(T_customer  * p_c) {
    /* Happy Birthday (and gift card for some categories) */
    if (strcmp(p_c->typeOfCustomer,"bronze" )==0){
        printf("Happy Birthday!");
    }
    else if (strcmp(p_c->typeOfCustomer,"silver" )==0){
        printf("Happy Birthday + gift card 10 euros!");
    }
    else if (strcmp(p_c->typeOfCustomer,"gold" )==0){
        printf("Happy Birthday + gift card 20 euros!");
    }
    else{
        perror("Unknown customer type");
        exit(1);
    }
}

/*------------------------
Permane ancora la logica condizionale in TRE punti:
- creazione customer
- calcolo costo
- auguri
 */
