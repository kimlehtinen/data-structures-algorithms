#include "duplicatesstring.h"

long int GetDuplicatesInString(char *str) {
    long int hashBitMap = 0, duplicatesBitMap = 0, x = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        x = 1;
        x = x << (str[i] - 97);
        if ((x & hashBitMap) > 0) {
            duplicatesBitMap = duplicatesBitMap | x;
        } else {
            hashBitMap = x | hashBitMap;
        }
    }
    return duplicatesBitMap;
}
