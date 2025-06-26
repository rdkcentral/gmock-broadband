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
#include "mock_base64.h"

extern base64Mock *g_base64Mock;

extern "C" size_t b64_get_encoded_buffer_size( const size_t decoded_size )
{
    if (!g_base64Mock)
    {
        return 0;
    }
    return g_base64Mock->b64_get_encoded_buffer_size(decoded_size);
}

extern "C" void b64_encode( const uint8_t *input, const size_t input_size, uint8_t *output )
{
    if (g_base64Mock)
    {
        g_base64Mock->b64_encode(input, input_size, output);
    }
}

extern "C" size_t b64_get_decoded_buffer_size( const size_t encoded_size )
{
    if (!g_base64Mock)
    {
        return 0;
    }
    return g_base64Mock->b64_get_decoded_buffer_size(encoded_size);
}

extern "C" size_t b64_decode( const uint8_t *input, const size_t input_size, uint8_t *output )
{
    if (!g_base64Mock)
    {
        return 0;
    }
    return g_base64Mock->b64_decode(input, input_size, output);
}