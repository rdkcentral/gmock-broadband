/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2024 RDK Management
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

#include "mock_securewrapper.h"
#include <stdarg.h>


using namespace std;

extern SecureWrapperMock * g_securewrapperMock;

extern "C" FILE* v_secure_popen(const char *direction, const char *format,...)
{
	if(!g_securewrapperMock)
    {
        return NULL;
    }
    char formatted_string[256];
    va_list args;
    va_start(args, format);
    vsnprintf(formatted_string, sizeof(formatted_string), format, args);
    va_end(args);
    return g_securewrapperMock->v_secure_popen(direction, formatted_string, NULL);
}

extern "C" int v_secure_pclose(FILE *stream)
{
	if(!g_securewrapperMock)
	{
		return -1;
    }
    return g_securewrapperMock->v_secure_pclose(stream);
}

extern "C" int v_secure_system(const char *format,...)
{
	if(!g_securewrapperMock)
    {
        return -1;
    }
    char formatted_string[256];
    va_list args;
    va_start(args, format);
    vsnprintf(formatted_string, sizeof(formatted_string), format, args);
    va_end(args);

    return g_securewrapperMock->v_secure_system(formatted_string, NULL);
}

extern "C" int vsystem(const char *fmt, ...)
{
    if (!g_securewrapperMock)
    {
        return -1;
    }
    char format[250] = { 0 };

    va_list argptr;
    va_start(argptr, fmt);
    vsnprintf(format, sizeof(format), fmt, argptr);
    va_end(argptr);

    return g_securewrapperMock->v_secure_system(format, NULL);
}