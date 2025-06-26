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

#include <stdarg.h>
#include "mock_safec_lib.h"

extern SafecLibMock* g_safecLibMock;

extern "C" errno_t strcmp_s(const char* s1, rsize_t s1max, const char* s2, int* result)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->strcmp_s(s1, s1max, s2, result);
}

extern "C" errno_t strcasecmp_s(const char* dst, int dmax, const char* src, int* result)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->strcasecmp_s(dst, dmax, src, result);
}

extern "C" int parseFormat(const char* dst, int max, const char* fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);
    int len = 0;
    if (!g_safecLibMock)
    {
        va_end(argp);
        return ESNULLP;
    }
    len = g_safecLibMock->parseFormat(dst, max, fmt, argp);
    va_end(argp);
    return len;
}

extern "C" errno_t _strcmp_s_chk(const char *dest, rsize_t dmax, const char *src, int *resultp, const size_t destbos, const size_t srcbos)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->_strcmp_s_chk(dest, dmax, src, resultp, destbos, srcbos);
}

extern "C" errno_t _strcpy_s_chk(char *dest, rsize_t dmax, const char *src, const size_t destbos)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->_strcpy_s_chk(dest, dmax, src, destbos);
}

extern "C" errno_t strcpy_s(char *dst, rsize_t max, const char *src) {
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->strcpy_s(dst, max, src);
}


extern "C" errno_t _strcat_s_chk(char *dest, rsize_t dmax, const char *src, const size_t destbos)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->_strcat_s_chk(dest, dmax, src, destbos);
}

extern "C" errno_t strcat_s(char *dest, rsize_t dmax, const char *src)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->strcat_s(dest, dmax, src);
}

extern "C" int _sprintf_s_chk(char *dest, rsize_t dmax, const size_t destbos, const char *fmt, ...)
{
    if (!g_safecLibMock)
    {
        return -1;
    }
    char *formatted_string = (char *)malloc(dmax);
    va_list args;
    va_start(args, fmt);
    vsnprintf(formatted_string, dmax, fmt, args);
    va_end(args);
    int result = g_safecLibMock->_sprintf_s_chk(dest, dmax, destbos, formatted_string);
    free(formatted_string);
    return result;
}

extern "C" int sprintf_s(char *dest, rsize_t dmax, const char *fmt, ...)
{
    if (!g_safecLibMock)
    {
        return -1;
    }
    char *formatted_string = (char *)malloc(dmax);
    va_list args;
    va_start(args, fmt);
    vsnprintf(formatted_string, dmax, fmt, args);
    va_end(args);
    int result = g_safecLibMock->sprintf_s(dest, dmax, formatted_string);
    free(formatted_string);
    return result;
}

extern "C" errno_t _strncpy_s_chk(char *dest, rsize_t dmax, const char *src, rsize_t slen, const size_t destbos, const size_t srcbos)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->_strncpy_s_chk(dest, dmax, src, slen, destbos, srcbos);
}

extern "C" errno_t strncpy_s(char *dest, rsize_t dmax, const char *src, rsize_t slen)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->strncpy_s(dest, dmax, src, slen);
}


extern "C" errno_t _memset_s_chk(void *dest, rsize_t dmax, int value, rsize_t n, const size_t destbos)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->_memset_s_chk(dest, dmax, value, n, destbos);
}

extern "C" errno_t memset_s(void *dest, rsize_t dmax, int value, rsize_t n)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->memset_s(dest, dmax, value, n);
}

extern "C" errno_t _memcpy_s_chk(void *dest, rsize_t dmax, const void *src, rsize_t slen, const size_t destbos, const size_t srcbos)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->_memcpy_s_chk(dest, dmax, src, slen, destbos, srcbos);
}

extern "C" errno_t memcpy_s(void *dest, rsize_t dmax, const void *src, rsize_t slen)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->memcpy_s(dest, dmax, src, slen);
}

extern "C" int sscanf_s(const char *buffer, const char *fmt, int* a, int* b, int* c, char* d)
{
    if (!g_safecLibMock)
    {
        return -1;
    }
    return g_safecLibMock->sscanf_s(buffer, fmt, a, b, c, d);
}

extern "C" errno_t _strcasecmp_s_chk(const char* dest, rsize_t dmax, const char* src, int* resultp, const size_t destbos)
{
    if (!g_safecLibMock)
    {
        return ESNULLP;
    }
    return g_safecLibMock->_strcasecmp_s_chk(dest, dmax, src, resultp, destbos);
}

extern "C" char* _strtok_s_chk(char *dest, rsize_t dmax, const char *delim, char **ptr, const size_t destbos)
{
    if (!g_safecLibMock)
    {
        return (char *)NULL;
    }
    return g_safecLibMock->_strtok_s_chk(dest, dmax, delim, ptr, destbos);
}
