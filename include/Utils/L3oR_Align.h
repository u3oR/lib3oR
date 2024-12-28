#ifndef L3oR_ALIGN_H
#define L3oR_ALIGN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define L3oR_AlignMsk(align) ((align) - 1)
#define L3oR_AlignUp(addr, align) (((addr) + L3oR_AlignMsk(align)) & ~L3oR_AlignMsk(align))
#define L3oR_AlignDn(addr, align) ((addr) & ~L3oR_AlignMsk(align))
#define L3oR_IsAligned(addr, align) (((uintptr_t)(addr) & L3oR_AlignMsk(align)) == 0)

#ifdef __cplusplus
}
#endif

#endif

// END 
