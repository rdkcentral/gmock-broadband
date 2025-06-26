/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2020 RDK Management
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

#include "mock_file_io.h"

extern FileIOMock * g_fileIOMock;   /* This is just a declaration! The actual mock
                                       obj is defined globally in the test file. */

// Mock Method
extern "C" char * fgets(char * str, int n, FILE * stream)
{
    if (!g_fileIOMock)
    {
        return NULL;
    }
    return g_fileIOMock->fgets(str, n, stream);
}

extern "C" FILE * popen(const char * command, const char * type)
{
    if (!g_fileIOMock)
    {
        return NULL;
    }
    return g_fileIOMock->popen(command, type);
}

extern "C" int pclose(FILE * stream)
{
    if (!g_fileIOMock)
    {
        return 0;
    }
    return g_fileIOMock->pclose(stream);
}

extern "C" int fclose(FILE * stream) 
{
	if(!g_fileIOMock)
	{
		return 0;
	}
	return g_fileIOMock->fclose(stream);
}

extern "C" int unlink(const char *path)
{
	if(!g_fileIOMock)
	{
		return 0;
	}
	return g_fileIOMock->unlink(path);
}

extern "C" int access(const char *path, int amode)
{
    if(!g_fileIOMock)
	{
		return 0;
	}
	return g_fileIOMock->access(path, amode);
}

extern "C" ssize_t write(int fd, const void *buf, size_t n)
{
    if (!g_fileIOMock)
    {
        return 0;
    }
    return g_fileIOMock->write(fd, buf, n);
}

extern "C" ssize_t getline(char **str, size_t *n, FILE * stream)
{
    if(!g_fileIOMock)
    {
          return 0;
    }
    return g_fileIOMock->getline(str, n , stream);
}

extern "C" int ferror(FILE* stream)
{
    if(!g_fileIOMock)
    {
          return 0;
    }
    return g_fileIOMock->ferror(stream);
}

extern "C" size_t fread(void *ptr, size_t size, size_t n, FILE *stream)
{
    if (!g_fileIOMock)
    {
        return 0;
    }
    return g_fileIOMock->fread(ptr, size, n, stream);
}

extern "C" long ftell(FILE *stream)
{
    if (!g_fileIOMock)
    {
        return -1;
    }
    return g_fileIOMock->ftell(stream);
}

extern "C" int fseek(FILE *stream, long int offset, int whence)
{
    if (!g_fileIOMock)
    {
        return -1;
    }
    return g_fileIOMock->fseek(stream, offset, whence);
}

extern "C" int fscanf(FILE *stream, const char *format, ...)
{
    if (!g_fileIOMock)
    {
        return -1;
    }
    va_list args;
    va_start(args, format);
    int result = g_fileIOMock->fscanf(stream, format, args);
    va_end(args);
    return result;
}

