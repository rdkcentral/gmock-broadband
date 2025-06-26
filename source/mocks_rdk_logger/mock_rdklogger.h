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
#ifndef MOCK_RDKLOGGER_H
#define MOCK_RDKLOGGER_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
#include <rdk_debug.h>
}

class rdkloggerInterface
{
    public:
        virtual ~rdkloggerInterface() {}
        virtual void RDK_LOG_ControlCB(const char *, const char *, const char *, int) = 0;
        virtual void rdk_dbgDumpLog(const char*) = 0;
        virtual void rdk_dbgInit() = 0;
        virtual rdk_Error rdk_logger_init(const char*) = 0;
        virtual rdk_Error rdk_logger_deinit() = 0;
        virtual void rdk_dbg_MsgRaw(rdk_LogLevel, const char *, const char *, va_list) = 0;
        virtual void rdk_dbg_MsgRaw1(rdk_LogLevel, const char *,const char *, va_list) = 0;
        virtual rdk_logger_Bool rdk_dbg_enabled(const char *, rdk_LogLevel) = 0;
        virtual void rdk_log_onboard(const char *, const char *, va_list) = 0;
};

class rdkloggerMock: public rdkloggerInterface
{
    public:
        virtual ~rdkloggerMock() {}
        MOCK_METHOD4(RDK_LOG_ControlCB, void(const char*, const char*, const char*, int));
        MOCK_METHOD1(rdk_dbgDumpLog, void(const char*));
        MOCK_METHOD0(rdk_dbgInit, void());
        MOCK_METHOD1(rdk_logger_init, rdk_Error(const char*));
        MOCK_METHOD0(rdk_logger_deinit, rdk_Error());
        MOCK_METHOD4(rdk_dbg_MsgRaw, void(rdk_LogLevel, const char*, const char*, va_list));
        MOCK_METHOD4(rdk_dbg_MsgRaw1, void(rdk_LogLevel, const char*, const char*, va_list));
        MOCK_METHOD2(rdk_dbg_enabled, rdk_logger_Bool(const char*, rdk_LogLevel));
        MOCK_METHOD3(rdk_log_onboard, void(const char*, const char*, va_list));
};

#endif //MOCK_RDKLOGGER_H