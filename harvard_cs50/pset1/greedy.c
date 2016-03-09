#include <stdio.h>
#include <math.h>
#include <cs50.h>

const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKEL = 5;
const int CENTS_PER_PENNY = 1;

const int available_coins[4] = {
    CENTS_PER_QUARTER,
    CENTS_PER_DIME,
    CENTS_PER_NICKEL,
    CENTS_PER_PENNY
};

int get_num_coins_owed(float dollars_owed)
{
    int initial_cents_owed = roundf(dollars_owed * 100.0);
    int remaining_cents_owed = initial_cents_owed;
    int coins_owed = 0;

    int available_coins_length = sizeof(available_coins) / sizeof(int);
    for (int i = 0; i < available_coins_length; i++)
    {
        coins_owed += remaining_cents_owed / available_coins[i];
        remaining_cents_owed = remaining_cents_owed % CENTS_PER_QUARTER;
    }

    return coins_owed;
}

int main(void)
{
    int initial_dime_count = 0;
    int initial_nickel_count = 0;
    int initial_penny_count = 0;

    float dollars_owed;
    do {
        printf("enter amount of dollars owed: ");
        dollars_owed = GetFloat();
    } while ( dollars_owed < 0 );

    int num_coins_owed = get_num_coins_owed(dollars_owed);
    printf("coins owed: %i\n", num_coins_owed);
}
