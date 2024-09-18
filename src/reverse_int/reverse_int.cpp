#include "reverse_int.h"

/**
 * TODO: large numbers will overflow, handle this
 */
int reverseInt(int n) {
    int reversed = 0;
    while (n != 0) {
        int lastDigit = n % 10;
        reversed *= 10; // shift
        reversed += lastDigit; // add last digit now when there's space for it
        n /= 10; // remove last digit from original number
    }

    return reversed;
}
