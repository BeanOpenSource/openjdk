//
// Created by Le, Binh on 02/06/2022.
//

#ifndef MACOSX_AARCH64_SERVER_FASTDEBUG_CRC32CALC_H
#define MACOSX_AARCH64_SERVER_FASTDEBUG_CRC32CALC_H


class CRC32Calc {
public:
    CRC32Calc(){};
    virtual ~CRC32Calc() {};
    static int static_calcCrc32(int crc, const char* data, int dataOffset, int dataLen);
};


#endif //MACOSX_AARCH64_SERVER_FASTDEBUG_CRC32CALC_H
