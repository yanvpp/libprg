#ifndef LIBPRG_MYTYPES_H
#define LIBPRG_MYTYPES_H

typedef struct {
  double value;
  int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

#endif
