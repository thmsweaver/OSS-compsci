#include <stdio.h>
#include <math.h>
#include <cs50.h>

const float GALLONS_PER_MINUTE = 1.5;
const float OUNCES_PER_GALLON = 128.0;
const float OUNCES_PER_BOTTLE = 16.0;

int main(void)
{
    printf("minutes: ");

    double shower_duration_minutes = GetFloat();
    double gallons_per_shower = shower_duration_minutes * GALLONS_PER_MINUTE;
    double ounces_per_shower = gallons_per_shower * OUNCES_PER_GALLON;
    double bottles_per_shower = ounces_per_shower / OUNCES_PER_BOTTLE;

    printf("bottles: %.2f\n", bottles_per_shower);
}
