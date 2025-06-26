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

#include "mock_ansc_wrapper_api.h"

extern AnscWrapperApiMock * g_anscWrapperApiMock;

extern "C" void AnscMacToLower(char* dst, char const* src, size_t size)
{
    if (g_anscWrapperApiMock)
    {
        return g_anscWrapperApiMock->AnscMacToLower(dst, src, size);
    }
}

extern "C" char * AnscCloneString(char *src_string)
{
    if (!g_anscWrapperApiMock)
    {
        return NULL;
    }
    return g_anscWrapperApiMock->AnscCloneString(src_string);
}

extern "C" PSINGLE_LINK_ENTRY AnscSListGetLastEntry(PSLIST_HEADER ListHead)
{
    if (!g_anscWrapperApiMock)
    {
        return NULL;
    }
    return g_anscWrapperApiMock->AnscSListGetLastEntry(ListHead);
}

extern "C" PSINGLE_LINK_ENTRY AnscSListPushEntryByIndex(PSLIST_HEADER ListHead, PSINGLE_LINK_ENTRY Entry, ULONG Index)
{
    if (!g_anscWrapperApiMock)
    {
        return NULL;
    }
    return g_anscWrapperApiMock->AnscSListPushEntryByIndex(ListHead, Entry, Index);
}

extern "C" ANSC_HANDLE AnscTcAllocate(char* string, char* separator)
{
    if (!g_anscWrapperApiMock)
    {
        return  (ANSC_HANDLE)NULL;
    }
    return g_anscWrapperApiMock->AnscTcAllocate(string, separator);
}

extern "C" ANSC_HANDLE AnscTcPopToken(ANSC_HANDLE hTokenChain)
{
    if (!g_anscWrapperApiMock)
    {
        return  (ANSC_HANDLE)NULL;
    }
    return g_anscWrapperApiMock->AnscTcPopToken(hTokenChain);
}

extern "C" void AnscTcFree(ANSC_HANDLE hTokenChain)
{
    if (g_anscWrapperApiMock)
    {
        return g_anscWrapperApiMock->AnscTcFree(hTokenChain);
    }
}

extern "C" ULONG AnscSizeOfToken(char* string,char* separator, ULONG range)
{
    if (!g_anscWrapperApiMock)
    {
        return -1;
    }
    return g_anscWrapperApiMock->AnscSizeOfToken(string, separator,range);
}

extern "C" ULONG AnscGetStringUlong(char* ulong_str)
{
    if (!g_anscWrapperApiMock)
    {
        return -1;
    }
    return g_anscWrapperApiMock->AnscGetStringUlong(ulong_str);
}

extern "C" BOOL AnscValidStringCheck(char *pString)
{
    if (!g_anscWrapperApiMock)
    {
        return FALSE;
    }
    return g_anscWrapperApiMock->AnscValidStringCheck(pString);
}

extern "C" PSINGLE_LINK_ENTRY AnscSListSearchEntryByIndex(PSLIST_HEADER ListHead, ULONG Index)
{
    if (!g_anscWrapperApiMock)
    {
        return NULL;
    }
    return g_anscWrapperApiMock->AnscSListSearchEntryByIndex(ListHead, Index);
}

extern "C" BOOL AnscSListPopEntryByLink(PSLIST_HEADER ListHead, PSINGLE_LINK_ENTRY Entry)
{
    if (!g_anscWrapperApiMock)
    {
        return FALSE;
    }
    return g_anscWrapperApiMock->AnscSListPopEntryByLink(ListHead, Entry);
}

extern "C" PUCHAR AnscBase64Decode(PUCHAR pEncode, PULONG pulSize)
{
    if (!g_anscWrapperApiMock)
    {
        return NULL;
    }
    return g_anscWrapperApiMock->AnscBase64Decode(pEncode, pulSize);
}

extern "C" ULONG AnscGetStringUlongHex(char* ulong_str_hex)
{
    if (!g_anscWrapperApiMock)
    {
        return -1;
    }
    return g_anscWrapperApiMock->AnscGetStringUlongHex(ulong_str_hex);
}

extern "C" PSINGLE_LINK_ENTRY AnscQueueSearchEntryByIndex(PQUEUE_HEADER QueueHead, ULONG Index)
{
    if (!g_anscWrapperApiMock)
    {
        return NULL;
    }
    return g_anscWrapperApiMock->AnscQueueSearchEntryByIndex(QueueHead, Index);
}