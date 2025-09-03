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

#ifndef MOCK_ANSC_WRAPPER_API_H
#define MOCK_ANSC_WRAPPER_API_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#ifndef ULONG

typedef unsigned long ULONG;

#endif

extern "C"{
    #include "ansc_platform.h"
}

class AnscWrapperApiInterface
{
    public:
        virtual ~AnscWrapperApiInterface() {}
        virtual void AnscMacToLower(char*, char const*, size_t) = 0;
        virtual char * AnscCloneString(char *) = 0;
        virtual PSINGLE_LINK_ENTRY AnscSListGetLastEntry(PSLIST_HEADER ListHead) = 0;
        virtual PSINGLE_LINK_ENTRY AnscSListPushEntryByIndex(PSLIST_HEADER ListHead,PSINGLE_LINK_ENTRY Entry,ULONG Index) = 0;
        virtual ANSC_HANDLE AnscTcAllocate(char* string,char* separator) = 0;
        virtual ANSC_HANDLE AnscTcPopToken(ANSC_HANDLE hTokenChain) = 0;
        virtual void AnscTcFree(ANSC_HANDLE hTokenChain) = 0;
        virtual ULONG AnscSizeOfToken(char* string,char* separator,ULONG   range) = 0;
        virtual ULONG AnscGetStringUlong(char* ulong_str)=0;
        virtual BOOL AnscValidStringCheck(char *pString)=0;
        virtual PSINGLE_LINK_ENTRY AnscSListSearchEntryByIndex(PSLIST_HEADER ListHead, ULONG Index)=0;
        virtual BOOL AnscSListPopEntryByLink(PSLIST_HEADER ListHead, PSINGLE_LINK_ENTRY Entry)=0;
        virtual PUCHAR AnscBase64Decode(PUCHAR pEncode, PULONG pulSize) = 0;
        virtual ULONG AnscGetStringUlongHex(char* hex_str)=0;
        virtual PSINGLE_LINK_ENTRY AnscQueueSearchEntryByIndex(PQUEUE_HEADER QueueHead, ULONG Index)=0;
};

class AnscWrapperApiMock : public AnscWrapperApiInterface
{
    public:
        virtual ~AnscWrapperApiMock() {}
        MOCK_METHOD3(AnscMacToLower, void(char*, char const*, size_t));
        MOCK_METHOD1(AnscCloneString, char*(char*));
        MOCK_METHOD1(AnscSListGetLastEntry,PSINGLE_LINK_ENTRY( PSLIST_HEADER ));
        MOCK_METHOD3(AnscSListPushEntryByIndex,PSINGLE_LINK_ENTRY(PSLIST_HEADER ,PSINGLE_LINK_ENTRY ,ULONG ));
        MOCK_METHOD2(AnscTcAllocate,ANSC_HANDLE(char* ,char* ));
        MOCK_METHOD1(AnscTcPopToken,ANSC_HANDLE(ANSC_HANDLE ));
        MOCK_METHOD1(AnscTcFree,void(ANSC_HANDLE ));
        MOCK_METHOD3(AnscSizeOfToken,ULONG (char* ,char* ,ULONG ));
        MOCK_METHOD1(AnscGetStringUlong,ULONG(char*));
        MOCK_METHOD1(AnscValidStringCheck,BOOL(char *));
        MOCK_METHOD2(AnscSListSearchEntryByIndex,PSINGLE_LINK_ENTRY(PSLIST_HEADER ,ULONG ));
        MOCK_METHOD2(AnscSListPopEntryByLink,BOOL(PSLIST_HEADER ,PSINGLE_LINK_ENTRY ));
        MOCK_METHOD2(AnscBase64Decode, PUCHAR(PUCHAR, PULONG));
        MOCK_METHOD1(AnscGetStringUlongHex,ULONG(char*));
        MOCK_METHOD2(AnscQueueSearchEntryByIndex,PSINGLE_LINK_ENTRY(PQUEUE_HEADER ,ULONG ));
};

#endif
