# SIMD-CRC32
Header Only CRC32 implement with SIMD instruction

https://crackme.net/articles/simdcrc/

```C++
#include"SIMD-CRC32.h"

int main() {
    uint8_t data[] = {"test"};
    uint32_t crc = crc32(data, 4); //0x86a072c0
}
```
