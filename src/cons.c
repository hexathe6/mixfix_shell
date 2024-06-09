#ifndef CONS_C
#define CONS_C

typedef struct {void* car; void* cdr;} cons;

typedef struct {void* i0; void* i1; void* i2;} tuple3;
typedef struct {void* i0; void* i1; void* i2; void* i3;} tuple4;
typedef struct {void* i0; void* i1; void* i2; void* i3; void* i4;} tuple5;
typedef struct {void* i0; void* i1; void* i2; void* i3; void* i4; void* i5;} tuple6;
typedef struct {void* i0; void* i1; void* i2; void* i3; void* i4; void* i5; void* i6;} tuple7;
typedef struct {void* i0; void* i1; void* i2; void* i3; void* i4; void* i5; void* i6; void* i7;} tuple8;

#endif

