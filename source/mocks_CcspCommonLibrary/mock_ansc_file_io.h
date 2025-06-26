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

#ifndef MOCK_ANSC_FILE_IO_H
#define MOCK_ANSC_FILE_IO_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
   #include "ansc_platform.h"
}

class AnscFileIOInterface {
public:
    virtual ~AnscFileIOInterface() {}
    virtual ULONG AnscGetFileSize(ANSC_HANDLE hFile) = 0;
    virtual ANSC_STATUS AnscCopyFile(char* pSrcFile, char* pDstFile, BOOL bOverwriteDst) = 0;
    virtual ANSC_STATUS AnscWriteFile(ANSC_HANDLE hFile, PVOID buffer, PULONG pulSize) = 0;
    virtual ANSC_STATUS AnscReadFile(ANSC_HANDLE hFile, PVOID buffer, PULONG pulSize) = 0;
    virtual ANSC_STATUS AnscCloseFile(ANSC_HANDLE hFile) = 0;
    virtual ANSC_HANDLE AnscOpenFile(char* name, ULONG mode, ULONG type) = 0;
};

class AnscFileIOMock : public AnscFileIOInterface {
public:
    virtual ~AnscFileIOMock() {}
    MOCK_METHOD1(AnscGetFileSize, ULONG(ANSC_HANDLE hFile));
    MOCK_METHOD3(AnscCopyFile, ANSC_STATUS(char* pSrcFile, char* pDstFile, BOOL bOverwriteDst));
    MOCK_METHOD3(AnscWriteFile, ANSC_STATUS(ANSC_HANDLE hFile, PVOID buffer, PULONG pulSize));
    MOCK_METHOD3(AnscReadFile, ANSC_STATUS(ANSC_HANDLE hFile, PVOID buffer, PULONG pulSize));
    MOCK_METHOD1(AnscCloseFile, ANSC_STATUS(ANSC_HANDLE hFile));
    MOCK_METHOD3(AnscOpenFile, ANSC_HANDLE(char* name, ULONG mode, ULONG type));
};

#endif // MOCK_ANSC_FILE_IO_H
