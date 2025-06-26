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
#include "mock_libxml.h"

extern libxmlMock *g_libxmlMock;

extern "C" void xmlStopParser (xmlParserCtxtPtr ctxt) {
    if (g_libxmlMock) {
        return g_libxmlMock->xmlStopParser(ctxt);
    }
}

extern "C" xmlParserCtxtPtr xmlCreatePushParserCtxt (xmlSAXHandlerPtr sax, void *user_data, const char *chunk, int size, const char *filename) {
    if (g_libxmlMock) {
        return g_libxmlMock->xmlCreatePushParserCtxt(sax, user_data, chunk, size, filename);
    }
    return NULL;
}

extern "C" int xmlParseChunk (xmlParserCtxtPtr ctxt, const char *chunk, int size, int terminate) {
    if (g_libxmlMock) {
        return g_libxmlMock->xmlParseChunk(ctxt, chunk, size, terminate);
    }
    return -1;
}

extern "C" void xmlFreeParserCtxt (xmlParserCtxtPtr ctxt) {
    if (g_libxmlMock) {
        return g_libxmlMock->xmlFreeParserCtxt(ctxt);
    }
}

extern "C" void xmlCleanupParser () {
    if (g_libxmlMock) {
        return g_libxmlMock->xmlCleanupParser();
    }
}
