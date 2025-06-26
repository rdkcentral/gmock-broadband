/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
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

#include "mock_ansc_xml.h"

extern AnscXmlMock* g_anscXmlMock;

extern "C" ANSC_HANDLE AnscXmlDomParseString(ANSC_HANDLE hOwnContext, PCHAR* ppXMLString, ULONG length)
{
    if (!g_anscXmlMock) {
        return nullptr;
    }
    return g_anscXmlMock->AnscXmlDomParseString(hOwnContext, ppXMLString, length);
}

extern "C" ANSC_STATUS AnscXmlDomNodeRemove(ANSC_HANDLE hThisObject)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeRemove(hThisObject);
}

extern "C" ANSC_STATUS AnscXmlDomNodeSetName(ANSC_HANDLE hThisObject, char* name)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeSetName(hThisObject, name);
}

extern "C" ULONG AnscXmlDomNodeGetEncodedSize(ANSC_HANDLE hThisObject)
{
    if (!g_anscXmlMock) {
        return 0;
    }
    return g_anscXmlMock->AnscXmlDomNodeGetEncodedSize(hThisObject);
}

extern "C" ANSC_HANDLE AnscCreateXmlDomNode(ANSC_HANDLE hOwnerContext)
{
    if (!g_anscXmlMock) {
        return nullptr;
    }
    return g_anscXmlMock->AnscCreateXmlDomNode(hOwnerContext);
}

extern "C" ANSC_STATUS AnscXmlDomNodeEncode(ANSC_HANDLE hThisObject, PVOID buffer, PULONG pulSize)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeEncode(hThisObject, buffer, pulSize);
}
extern "C" ANSC_STATUS AnscXmlDomNodeSetDataString(ANSC_HANDLE hThisObject, char* name, char* sTarget, ULONG ulSize)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeSetDataString(hThisObject, name, sTarget, ulSize);
}

extern "C" ANSC_STATUS AnscXmlDomNodeGetAttrString(ANSC_HANDLE hThisObject, char* name, char* sTarget, PULONG pulSize)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeGetAttrString(hThisObject, name, sTarget, pulSize);
}

extern "C" ANSC_STATUS AnscXmlDomNodeGetAttrUlong(ANSC_HANDLE hThisObject, char* name, PULONG pulTarget)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeGetAttrUlong(hThisObject, name, pulTarget);
}

extern "C" ANSC_STATUS AnscXmlDomNodeGetDataUlong(ANSC_HANDLE hThisObject, char* name, PULONG pulTarget)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeGetDataUlong(hThisObject, name, pulTarget);
}

extern "C" ANSC_STATUS AnscXmlDomNodeGetDataBinary(ANSC_HANDLE hThisObject, char* name, char* sTarget, PULONG pulSize)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeGetDataBinary(hThisObject, name, sTarget, pulSize);
}

extern "C" ANSC_STATUS AnscXmlDomNodeGetDataString(ANSC_HANDLE hThisObject, char* name, char* sTarget, PULONG pulSize)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeGetDataString(hThisObject, name, sTarget, pulSize);
}

extern "C" ANSC_STATUS AnscXmlDomNodeGetDataBoolean(ANSC_HANDLE hThisObject, char* name, PBOOL pbTarget)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeGetDataBoolean(hThisObject, name, pbTarget);
}

extern "C" ANSC_HANDLE AnscXmlDomNodeAddChild(ANSC_HANDLE hThisObject, ANSC_HANDLE hChildNode)
{
    if (!g_anscXmlMock) {
        return nullptr;
    }
    return g_anscXmlMock->AnscXmlDomNodeAddChild(hThisObject, hChildNode);
}

extern "C" ANSC_STATUS AnscXmlDomNodeSetAttrString(ANSC_HANDLE hThisObject, char* name, char* sTarget, ULONG ulSize)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeSetAttrString(hThisObject, name, sTarget, ulSize);
}

extern "C" ANSC_STATUS AnscXmlDomNodeSetAttrUlong(ANSC_HANDLE hThisObject, char* name, ULONG ulTarget)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeSetAttrUlong(hThisObject, name, ulTarget);
}

extern "C" ANSC_STATUS AnscXmlDomNodeSetDataUlong(ANSC_HANDLE hThisObject, char* name, ULONG ulTarget)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeSetDataUlong(hThisObject, name, ulTarget);
}

extern "C" ANSC_STATUS AnscXmlDomNodeSetDataBoolean(ANSC_HANDLE hThisObject, char* name, BOOL bTarget)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeSetDataBoolean(hThisObject, name, bTarget);
}

extern "C" ANSC_STATUS AnscXmlDomNodeSetDataBinary(ANSC_HANDLE hThisObject, char* name, char* sTarget, ULONG ulSize)
{
    if (!g_anscXmlMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscXmlMock->AnscXmlDomNodeSetDataBinary(hThisObject, name, sTarget, ulSize);
}

extern "C" ANSC_HANDLE AnscXmlDomNodeGetHeadChild(ANSC_HANDLE hThisObject)
{
    if (!g_anscXmlMock) {
        return nullptr;
    }
    return g_anscXmlMock->AnscXmlDomNodeGetHeadChild(hThisObject);
}

extern "C" char* AnscXmlDomNodeGetName(ANSC_HANDLE hThisObject)
{
    if (!g_anscXmlMock) {
        return nullptr;
    }
    return g_anscXmlMock->AnscXmlDomNodeGetName(hThisObject);
}

extern "C" ANSC_HANDLE AnscXmlDomNodeGetNextChild(ANSC_HANDLE hThisObject, ANSC_HANDLE hThisChild)
{
    if (!g_anscXmlMock) {
        return nullptr;
    }
    return g_anscXmlMock->AnscXmlDomNodeGetNextChild(hThisObject, hThisChild);
}