#pragma once
#include <stdio.h>      // макрос использует fprintf и stderr, поэтому подключаем здесь

#ifdef DEBUG
    // __FILE__ и __LINE__ подставляются препроцессором в том месте, где LOG ВЫЗВАН (не где определён)
    #define LOG(message) fprintf(stderr, "[DEBUG] %s: %d: %s\n", __FILE__, __LINE__, message)
#else
    // без DEBUG макрос превращается в "ничего", но "LOG(...);" остаётся валидным оператором
    #define LOG(message) ((void)0)
#endif
