/*Unions exercise learn-c.org
    Unions are a way to preserve multiple variable is smaller memory space of the largest
    variable in the Union, ie, union containing, int, double, and float.  The union would be
    of size double, since it's the largest, and the rest of the variables will by used in that
    memory space (just not filling it completely).
*/

#include <stdio.h>
#include <stdlib.h>

//multiple ways to implement unions in structs

//standard
struct operator {
    int intNum;
    float floatNum;
    int type;
    double doubleNum;
};

//union style one
struct operator_u1 {
    int type;
    union {
        int intNum;
        float floatNum;
        double doubleNum;
    } types;
};

//nameless union
struct operator_u2 {
    int type;
    union {
        int intNum;
        float floatNum;
        double doubleNum;
    };
};

//nameless struct with named union for name readability and indexing (ease of iteration)
union Coins {
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    }; //nameless struct
    int coins[4];  //variable for indexing
};

/*Union for exercise*/
union Exercise {
    int ints[6];
    char chars[21];
};

//to call
void main() {

    //standard
    struct operator op;
    op.type = 0;
    op.intNum = 256;
    //union style 1
    struct operator_u1 op1;
    op1.type = 1;
    op1.types.intNum = 350;
    //union style 2
   struct operator_u2 op2;
    op2.type = 2;
    op2.intNum = 355;
    //union style 3 : the "Coins" union struct
    union Coins change;
    change.quarter = 25;
    change.dime = 10;
    change.nickel = 5;
    change.penny = 1;
        
    printf("quarter: %d, dime: %d, nickel: %d, penny: %d\n", 
        change.coins[0], change.coins[1], change.coins[2], change.coins[3]);


    /*Begin exercise */

    // initializer lists like this are assigned to the first member of the union/struct!
    // There are 6 ints here so...
        union Exercise intCharacters = 
            {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};
      
        /* testing code */
        printf("[");
        // only go to 18 because 1 byte is for the terminating 0 and we don't print the last in the loop
        for(int i = 0; i < 19; ++i)
            printf("%c, ", intCharacters.chars[i]);
        printf("%c]\n", intCharacters.chars[19]);
    
        printf("%s\n", intCharacters.chars);

        //prints I understand Unions!
}
