#ifndef L3oR_ERROR_H
#define L3oR_ERROR_H

typedef int L3oR_Error_t;

#define L3oR_ERROR_NONE                    0 // Success
#define L3oR_ERROR_NULL_POINTER           -1 // Null pointer
#define L3oR_ERROR_INVALID_PARAM          -2 // Invalid parameter
#define L3oR_ERROR_OUT_OF_RANGE           -3 // Out of range
#define L3oR_ERROR_NO_MEMORY              -4 // Memory allocation failed
#define L3oR_ERROR_BUFFER_OVERFLOW        -5 // Buffer overflow
#define L3oR_ERROR_OPERATION_FAIL         -6 // General operation failure
#define L3oR_ERROR_NOT_INITIALIZED        -7 // Not initialized
#define L3oR_ERROR_ALREADY_INITIALIZED    -8 // Already initialized
#define L3oR_ERROR_TIMEOUT                -9 // Operation timeout
#define L3oR_ERROR_UNSUPPORTED           -10 // Unsupported operation
#define L3oR_ERROR_CHECKSUM_FAIL         -11 // Checksum failed
#define L3oR_ERROR_BUSY                  -12 // Resource busy
#define L3oR_ERROR_UNKNOWN               -99 // Unknown error

#endif // L3oR_ERROR_H
