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

#ifndef MOCK_SYSCFG_H
#define MOCK_SYSCFG_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class SyscfgInterface {
public:
        virtual ~SyscfgInterface() {}
        virtual int syscfg_init() = 0;
        virtual int syscfg_commit() = 0;
        virtual int syscfg_get(const char *, const char *, char *, int) = 0;
        virtual int syscfg_set(const char *, const char *, const char *) = 0;
        virtual int syscfg_set_nns(const char *, const char *) = 0;
        virtual int syscfg_set_commit (const char *, const char *, const char *) = 0;
        virtual int syscfg_set_nns_commit(const char *, const char *) = 0;
        virtual int syscfg_unset(const char *, const char *) = 0;
        virtual int syscfg_set_nns_u_commit(const char *, unsigned long) = 0;
        virtual int syscfg_set_nns_u (const char *, unsigned long) = 0;
        virtual int syscfg_set_ns_u (const char *, const char *, unsigned long) = 0;
        virtual int syscfg_set_u_commit (const char *, const char *, unsigned long) = 0;
        virtual int syscfg_commit_lock() = 0;
        virtual int syscfg_commit_unlock() = 0;
        virtual int syscfg_set_ns_commit(const char *ns, const char *name, const char *value) = 0;
};

class SyscfgMock: public SyscfgInterface {
public:
        virtual ~SyscfgMock() {}
        MOCK_METHOD0(syscfg_init, int(void));
        MOCK_METHOD0(syscfg_commit, int(void));
        MOCK_METHOD4(syscfg_get, int(const char *, const char *, char *, int));
        MOCK_METHOD3(syscfg_set, int(const char *, const char *, const char *));
        MOCK_METHOD2(syscfg_set_nns, int(const char *, const char *));
        MOCK_METHOD3(syscfg_set_commit, int(const char *, const char *, const char *));
        MOCK_METHOD2(syscfg_set_nns_commit, int(const char *, const char *));
        MOCK_METHOD2(syscfg_unset, int(const char *, const char *));
        MOCK_METHOD2(syscfg_set_nns_u_commit, int(const char *, unsigned long));
        MOCK_METHOD2(syscfg_set_nns_u, int(const char *, unsigned long));
        MOCK_METHOD3(syscfg_set_ns_u, int(const char *, const char *, unsigned long));
        MOCK_METHOD3(syscfg_set_u_commit, int(const char *, const char *, unsigned long));
        MOCK_METHOD0(syscfg_commit_lock, int(void));
        MOCK_METHOD0(syscfg_commit_unlock, int(void));
        MOCK_METHOD3(syscfg_set_ns_commit, int(const char *, const char *, const char *));
};

#endif
