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
#include "mock_rdklogger.h"

extern rdkloggerMock *g_rdkloggerMock;

extern "C" void RDK_LOG_ControlCB(const char *moduleName, const char *subComponentName, const char *loggingLevel, int log_status)
{
    if (g_rdkloggerMock)
    {
        g_rdkloggerMock->RDK_LOG_ControlCB(moduleName, subComponentName, loggingLevel, log_status);
    }
}

extern "C" void rdk_dbgDumpLog(const char* path)
{
    if (g_rdkloggerMock)
    {
        g_rdkloggerMock->rdk_dbgDumpLog(path);
    }
}

extern "C" void rdk_dbgInit()
{
    if (g_rdkloggerMock)
    {
        g_rdkloggerMock->rdk_dbgInit();
    }
}

extern "C" rdk_Error rdk_logger_init(const char* debugConfigFile)
{
    if (!g_rdkloggerMock)
    {
        return -1;
    }
    return g_rdkloggerMock->rdk_logger_init(debugConfigFile);
}

extern "C" rdk_Error rdk_logger_deinit()
{
    if (!g_rdkloggerMock)
    {
        return -1;
    }
    return g_rdkloggerMock->rdk_logger_deinit();
}

extern "C" void rdk_dbg_MsgRaw(rdk_LogLevel level, const char *module, const char *format, ...)
{
    if (g_rdkloggerMock)
    {
        va_list args;
        va_start(args, format);
        g_rdkloggerMock->rdk_dbg_MsgRaw(level, module, format, args);
        va_end(args);
    }
}

extern "C" void rdk_dbg_MsgRaw1(rdk_LogLevel level, const char *module,const char *format, va_list args)
{
    if (g_rdkloggerMock)
    {
        g_rdkloggerMock->rdk_dbg_MsgRaw1(level, module, format, args);
    }
}

extern "C" rdk_logger_Bool rdk_dbg_enabled(const char *module, rdk_LogLevel level)
{
    if (!g_rdkloggerMock)
    {
        return 0;
    }
    return g_rdkloggerMock->rdk_dbg_enabled(module, level);
}

extern "C" void rdk_log_onboard(const char *module, const char *msg, ...)
{
    if (g_rdkloggerMock)
    {
        va_list args;
        va_start(args, msg);
        g_rdkloggerMock->rdk_log_onboard(module, msg, args);
        va_end(args);
    }
}
