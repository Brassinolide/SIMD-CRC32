#ifndef __SIMDCRC32_H__
#define __SIMDCRC32_H__

#include <cstdint>
#include <intrin.h>

static uint32_t crc32(const uint8_t* data, size_t size, uint32_t init_crc = 0xffffffff) {
    for (size_t offset = 0; offset < size;) {
        size_t remaining = size - offset;
        if (remaining >= 8) {
            init_crc = _mm_crc32_u64(init_crc, *(uint64_t*)(data + offset));
            offset += 8;
        }
        else if (remaining >= 4) {
            init_crc = _mm_crc32_u32(init_crc, *(uint32_t*)(data + offset));
            offset += 4;
        }
        else if (remaining >= 2) {
            init_crc = _mm_crc32_u16(init_crc, *(uint16_t*)(data + offset));
            offset += 2;
        }
        else if (remaining >= 1) {
            init_crc = _mm_crc32_u8(init_crc, *(data + offset));
            offset += 1;
        }
    }
    return init_crc ^ 0xffffffff;
}

#endif
