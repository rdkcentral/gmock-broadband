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

#include "mock_ansc_file_io.h"

extern AnscFileIOMock* g_anscFileIOMock;

extern "C" ULONG AnscGetFileSize(ANSC_HANDLE hFile)
{
    if (!g_anscFileIOMock) {
        return 0;
    }
    return g_anscFileIOMock->AnscGetFileSize(hFile);
}

extern "C" ANSC_STATUS AnscCopyFile(char* pSrcFile, char* pDstFile, BOOL bOverwriteDst)
{
    if (!g_anscFileIOMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscFileIOMock->AnscCopyFile(pSrcFile, pDstFile, bOverwriteDst);
}

extern "C" ANSC_STATUS AnscWriteFile(ANSC_HANDLE hFile, PVOID buffer, PULONG pulSize)
{
    if (!g_anscFileIOMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscFileIOMock->AnscWriteFile(hFile, buffer, pulSize);
}

extern "C" ANSC_STATUS AnscReadFile(ANSC_HANDLE hFile, PVOID buffer, PULONG pulSize)
{
    if (!g_anscFileIOMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscFileIOMock->AnscReadFile(hFile, buffer, pulSize);
}

extern "C" ANSC_STATUS AnscCloseFile(ANSC_HANDLE hFile)
{
    if (!g_anscFileIOMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_anscFileIOMock->AnscCloseFile(hFile);
}

extern "C" ANSC_HANDLE AnscOpenFile(char* name, ULONG mode, ULONG type)
{
    if (!g_anscFileIOMock) {
        return nullptr;
    }
    return g_anscFileIOMock->AnscOpenFile(name, mode, type);
}
