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

#ifndef MOCK_ANSC_XML_H
#define MOCK_ANSC_XML_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
    
#include "ansc_platform.h"
}


class AnscXmlInterface {
public:
    virtual ~AnscXmlInterface() {}
    virtual ANSC_HANDLE AnscXmlDomParseString(ANSC_HANDLE hOwnContext, PCHAR* ppXMLString, ULONG length) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeRemove(ANSC_HANDLE hThisObject) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeSetName(ANSC_HANDLE hThisObject, char* name) = 0;
    virtual ULONG AnscXmlDomNodeGetEncodedSize(ANSC_HANDLE hThisObject) = 0;
    virtual ANSC_HANDLE AnscCreateXmlDomNode(ANSC_HANDLE hOwnerContext) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeEncode(ANSC_HANDLE hThisObject, PVOID buffer, PULONG pulSize) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeSetDataString(ANSC_HANDLE hThisObject, char* name, char* sTarget, ULONG ulSize) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeGetAttrString(ANSC_HANDLE hThisObject, char* name, char* sTarget, PULONG pulSize) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeGetAttrUlong(ANSC_HANDLE hThisObject, char* name, PULONG pulTarget) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeGetDataUlong(ANSC_HANDLE hThisObject, char* name, PULONG pulTarget) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeGetDataBinary(ANSC_HANDLE hThisObject, char* name, char* sTarget, PULONG pulSize) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeGetDataString(ANSC_HANDLE hThisObject, char* name, char* sTarget, PULONG pulSize) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeGetDataBoolean(ANSC_HANDLE hThisObject, char* name, PBOOL pbTarget) = 0;
    virtual ANSC_HANDLE AnscXmlDomNodeAddChild(ANSC_HANDLE hThisObject, ANSC_HANDLE hChildNode) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeSetAttrString(ANSC_HANDLE hThisObject, char* name, char* sTarget, ULONG ulSize) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeSetAttrUlong(ANSC_HANDLE hThisObject, char* name, ULONG ulTarget) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeSetDataUlong(ANSC_HANDLE hThisObject, char* name, ULONG ulTarget) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeSetDataBoolean(ANSC_HANDLE hThisObject, char* name, BOOL bTarget) = 0;
    virtual ANSC_STATUS AnscXmlDomNodeSetDataBinary(ANSC_HANDLE hThisObject, char* name, char* sTarget, ULONG ulSize) = 0;
    virtual ANSC_HANDLE AnscXmlDomNodeGetHeadChild(ANSC_HANDLE hThisObject) = 0;
    virtual char* AnscXmlDomNodeGetName(ANSC_HANDLE hThisObject) = 0;
    virtual ANSC_HANDLE AnscXmlDomNodeGetNextChild(ANSC_HANDLE hThisObject, ANSC_HANDLE hThisChild) = 0;
};

class AnscXmlMock : public AnscXmlInterface {
public:
    virtual ~AnscXmlMock() {}
    MOCK_METHOD3(AnscXmlDomParseString, ANSC_HANDLE(ANSC_HANDLE hOwnContext, PCHAR* ppXMLString, ULONG length));
    MOCK_METHOD1(AnscXmlDomNodeRemove, ANSC_STATUS(ANSC_HANDLE hThisObject));
    MOCK_METHOD2(AnscXmlDomNodeSetName, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name));
    MOCK_METHOD1(AnscXmlDomNodeGetEncodedSize, ULONG(ANSC_HANDLE hThisObject));
    MOCK_METHOD1(AnscCreateXmlDomNode, ANSC_HANDLE(ANSC_HANDLE hOwnerContext));
    MOCK_METHOD3(AnscXmlDomNodeEncode, ANSC_STATUS(ANSC_HANDLE hThisObject, PVOID buffer, PULONG pulSize));
    MOCK_METHOD4(AnscXmlDomNodeSetDataString, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, char* sTarget, ULONG ulSize));
    MOCK_METHOD4(AnscXmlDomNodeGetAttrString, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, char* sTarget, PULONG pulSize));
    MOCK_METHOD3(AnscXmlDomNodeGetAttrUlong, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, PULONG pulTarget));
    MOCK_METHOD3(AnscXmlDomNodeGetDataUlong, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, PULONG pulTarget));
    MOCK_METHOD4(AnscXmlDomNodeGetDataBinary, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, char* sTarget, PULONG pulSize));
    MOCK_METHOD4(AnscXmlDomNodeGetDataString, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, char* sTarget, PULONG pulSize));
    MOCK_METHOD3(AnscXmlDomNodeGetDataBoolean, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, PBOOL pbTarget));
    MOCK_METHOD2(AnscXmlDomNodeAddChild, ANSC_HANDLE(ANSC_HANDLE hThisObject, ANSC_HANDLE hChildNode));
    MOCK_METHOD4(AnscXmlDomNodeSetAttrString, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, char* sTarget, ULONG ulSize));
    MOCK_METHOD3(AnscXmlDomNodeSetAttrUlong, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, ULONG ulTarget));
    MOCK_METHOD3(AnscXmlDomNodeSetDataUlong, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, ULONG ulTarget));
    MOCK_METHOD3(AnscXmlDomNodeSetDataBoolean, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, BOOL bTarget));
    MOCK_METHOD4(AnscXmlDomNodeSetDataBinary, ANSC_STATUS(ANSC_HANDLE hThisObject, char* name, char* sTarget, ULONG ulSize));
    MOCK_METHOD1(AnscXmlDomNodeGetHeadChild, ANSC_HANDLE(ANSC_HANDLE hThisObject));
    MOCK_METHOD1(AnscXmlDomNodeGetName, char*(ANSC_HANDLE hThisObject));
    MOCK_METHOD2(AnscXmlDomNodeGetNextChild, ANSC_HANDLE(ANSC_HANDLE hThisObject, ANSC_HANDLE hThisChild));
};

#endif // MOCK_ANSC_XML_H
