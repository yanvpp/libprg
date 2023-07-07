#include <libprg/sub.h>

result_t sub(double a, double b){
    result_t res;
    res.value = a - b;
    res.error = 0;
    return res;
}