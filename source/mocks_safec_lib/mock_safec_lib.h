/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#ifndef MOCK_SAFEC_LIB_H
#define MOCK_SAFEC_LIB_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdarg.h>

#ifndef errno_t
typedef int errno_t;
#endif

#ifndef _RSIZE_T /* PGI */
typedef size_t  rsize_t;
#endif

#define ERR_CHK(rc)                                             \
      if(rc !=EOK) {                                              \
          RDK_SAFECLIB_ERR(rc);                                   \
      }

#define EOK 0
#define ESNULLP          400        /* null ptr                    */
#define ESLEMAX          403       /* length exceeds RSIZE_MAX    */
#define ESNOSPC          406       /* not enough space for dest     */

class SafecLibInterface {
public:
    virtual ~SafecLibInterface() {}
    virtual errno_t strcmp_s(const char* s1, rsize_t s1max, const char* s2, int* result) = 0;
    virtual errno_t strcasecmp_s(const char* dst, int dmax, const char* src, int* result) = 0;
    virtual int parseFormat(const char* dst, int max, const char* fmt, va_list argp) = 0;
    virtual errno_t _strcmp_s_chk(const char *dest, rsize_t dmax, const char *src, int *resultp, const size_t destbos, const size_t srcbos) = 0;
    virtual errno_t _strcpy_s_chk(char *dest, rsize_t dmax, const char *src, const size_t destbos) = 0;
    virtual errno_t strcpy_s(char *dst, rsize_t max, const char *src) = 0;
    virtual errno_t _strcat_s_chk(char *dest, rsize_t dmax, const char *src, const size_t destbos) = 0;
    virtual errno_t strcat_s(char *dst, rsize_t max, const char *src) = 0;
    virtual int _sprintf_s_chk(char *dest, rsize_t dmax, size_t destbos, const char *fmt) = 0;
    virtual int sprintf_s(char *dest, rsize_t dmax, const char *fmt) = 0;
    virtual errno_t _strncpy_s_chk(char *dest, rsize_t dmax, const char *src, rsize_t slen, const size_t destbos, const size_t srcbos) = 0;
    virtual errno_t strncpy_s(char *dest, rsize_t dmax, const char *src, rsize_t slen) = 0;
    virtual errno_t _memset_s_chk(void *dest, rsize_t dmax, int value, rsize_t n, const size_t destbos) = 0;
    virtual errno_t memset_s(void *dest, rsize_t dmax, int value, rsize_t n) = 0;
    virtual errno_t _memcpy_s_chk(void *dest, rsize_t dmax, const void *src, rsize_t slen, const size_t destbos, const size_t srcbos) = 0;
    virtual errno_t memcpy_s(void *dest, rsize_t dmax, const void *src, rsize_t slen) = 0;
    virtual errno_t sscanf_s(const char *buffer, const char *fmt, int*, int*, int*, char*) = 0;
    virtual errno_t _strcasecmp_s_chk(const char* dest, rsize_t dmax, const char* src, int* resultp, const size_t destbos) = 0;
    virtual char* _strtok_s_chk(char *dest, rsize_t dmax, const char *delim, char **ptr, const size_t destbos) = 0;

};

class SafecLibMock : public SafecLibInterface {
public:
    virtual ~SafecLibMock() {}
    MOCK_METHOD4(strcmp_s, errno_t(const char*, rsize_t, const char*, int*));
    MOCK_METHOD4(strcasecmp_s, errno_t(const char*, int, const char*, int*));
    MOCK_METHOD4(parseFormat, int(const char*, int, const char*, va_list));
    MOCK_METHOD6(_strcmp_s_chk, errno_t(const char*, rsize_t, const char*, int*, const size_t, const size_t));
    MOCK_METHOD4(_strcpy_s_chk, errno_t(char*, rsize_t, const char*, const size_t));
    MOCK_METHOD3(strcpy_s, errno_t(char*, rsize_t, const char*));
    MOCK_METHOD4(_strcat_s_chk, errno_t(char*, rsize_t, const char*, const size_t));
    MOCK_METHOD3(strcat_s, errno_t(char*, rsize_t, const char*));
    MOCK_METHOD4(_sprintf_s_chk, int(char*, rsize_t, size_t, const char*));
    MOCK_METHOD3(sprintf_s, int(char*, rsize_t, const char*));
    MOCK_METHOD6(_strncpy_s_chk, errno_t(char*, rsize_t, const char*, rsize_t, const size_t, const size_t));
    MOCK_METHOD4(strncpy_s, errno_t(char*, rsize_t, const char*, rsize_t));
    MOCK_METHOD5(_memset_s_chk, errno_t(void*, rsize_t, int, rsize_t, const size_t));
    MOCK_METHOD4(memset_s, errno_t(void*, rsize_t, int, rsize_t));
    MOCK_METHOD6(_memcpy_s_chk, errno_t(void*, rsize_t, const void*, rsize_t, const size_t, const size_t));
    MOCK_METHOD4(memcpy_s, errno_t(void*, rsize_t, const void*, rsize_t));
    MOCK_METHOD6(sscanf_s, errno_t(const char*, const char*, int*, int*, int*, char*));
    MOCK_METHOD5(_strcasecmp_s_chk, errno_t(const char*, rsize_t, const char*, int*, const size_t));
    MOCK_METHOD5(_strtok_s_chk, char*(char*, rsize_t, const char*, char**, const size_t));
};

#endif // MOCK_SAFEC_LIB_H
