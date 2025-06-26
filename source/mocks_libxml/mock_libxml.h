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
#ifndef MOCK_LIBXML_H
#define MOCK_LIBXML_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
#include <libxml/parser.h>
}

class libxmlInterface
{
    public:
        virtual ~libxmlInterface() {}
        virtual void xmlStopParser (xmlParserCtxtPtr) = 0;
        virtual xmlParserCtxtPtr xmlCreatePushParserCtxt (xmlSAXHandlerPtr, void *, const char *, int, const char *) = 0;
        virtual int xmlParseChunk (xmlParserCtxtPtr, const char *, int, int) = 0;
        virtual void xmlFreeParserCtxt (xmlParserCtxtPtr) = 0;
        virtual void xmlCleanupParser (void) = 0;
};

class libxmlMock: public libxmlInterface
{
    public:
        virtual ~libxmlMock() {}
        MOCK_METHOD1(xmlStopParser, void(xmlParserCtxtPtr));
        MOCK_METHOD5(xmlCreatePushParserCtxt, xmlParserCtxtPtr(xmlSAXHandlerPtr, void *, const char *, int, const char *));
        MOCK_METHOD4(xmlParseChunk, int(xmlParserCtxtPtr, const char *, int, int));
        MOCK_METHOD1(xmlFreeParserCtxt, void(xmlParserCtxtPtr));
        MOCK_METHOD0(xmlCleanupParser, void(void));
};

#endif //MOCK_LIBXML_H
