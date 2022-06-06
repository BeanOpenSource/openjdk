//
// Created by Le, Binh on 02/06/2022.
//

#include "CRC32Calc.h"
#include "precompiled.hpp"

int CRC32Calc::static_calcCrc32(int crc, const char *data, int dataOffset, int dataLen) {
    const int dataSize = dataLen - dataOffset;
    int result = crc;
    int uints32 = (int) (dataSize / sizeof(int));
    int units8 = dataSize % sizeof(int);

    /**
     * https://docs.microsoft.com/en-us/cpp/intrinsics/arm64-intrinsics?view=msvc-170
     */
    const int *pUint32 = (const int *) data;
    while (uints32--) {
        result = ::_mm_crc32_u32(result, *pUint32);
        pUint32++;
    }

    const char *pUnit8 = (const char *) pUint32;
    while (units8--) {
        result = ::_mm_crc32_u8(result, *pUnit8);
        pUnit8++;
    }
    return result;
}