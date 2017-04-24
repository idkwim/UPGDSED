
/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2017
*
*  TITLE:       GLOBAL.H
*
*  VERSION:     1.00
*
*  DATE:        22 Apr 2017
*
*  Common header file for the project.
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/
#pragma once

#if !defined UNICODE
#error ANSI build is not supported
#endif

#if (_MSC_VER >= 1900) 
#ifdef _DEBUG
#pragma comment(lib, "vcruntimed.lib")
#pragma comment(lib, "ucrtd.lib")
#else
#pragma comment(lib, "libvcruntime.lib")
#endif
#endif

//disable nonmeaningful warnings.
#pragma warning(disable: 4005) // macro redefinition
#pragma warning(disable: 4055) // %s : from data pointer %s to function pointer %s
#pragma warning(disable: 4091) //'typedef ': ignored on left of '' when no variable is declared
#pragma warning(disable: 4152) // nonstandard extension, function/data pointer conversion in expression
#pragma warning(disable: 4201) // nonstandard extension used : nameless struct/union
#pragma warning(disable: 6102) // Using %s from failed function call at line %u
#pragma warning(disable: 6320) // exception-filter expression is the constant EXCEPTION_EXECUTE_HANDLER

#include <Windows.h>
#include <DbgHelp.h>
#include <ntstatus.h>
#include "resource.h"
#include "ntdll\ntos.h"
#include "minirtl\minirtl.h"
#include "minirtl\_filename.h"
#include "cui\cui.h"
#include "sup.h"
#include "scan.h"

#pragma comment(lib, "version.lib")

//source filenames
#define WINLOAD_EXE     L"winload.exe"
#define WINLOAD_EFI     L"winload.efi"
#define NTOSKRNL_EXE    L"ntoskrnl.exe"

//destination filenames
#define OSLOAD_EXE      L"osloader.exe"
#define OSLOAD_EFI      L"osloader.efi"
#define NTOSKRNMP_EXE   L"ntkrnlmp.exe"

#define BCDEDIT_EXE     L"bcdedit.exe"
#define BCDEDIT_LENGTH  sizeof(BCDEDIT_EXE) / 2

#define CONTINUE_CMD    L"CONTINUE"

#define PROGRAMTITLE    L"UPGDSED v1.0.0"
#define PROGRAMFULLNAME L"Universal PatchGuard and Driver Signature Enforcement Disable"

#define MIN_SUPPORTED_NT_BUILD 7601  //Windows 7 SP1
#define MAX_SUPPORTED_NT_BUILD 15063 //Windows 10 RS2

typedef struct _PATCH_CONTEXT {
    ULONG_PTR AddressOfPatch;
    PVOID PatchData;
    ULONG SizeOfPatch;
} PATCH_CONTEXT, *PPATCH_CONTEXT;

typedef struct _SYMBOL_ENTRY {
    struct _SYMBOL_ENTRY *Next;
    LPWSTR   Name;
    DWORD64  Address;
} SYMBOL_ENTRY, *PSYMBOL_ENTRY;

typedef int(__cdecl *fnptr_snwprintf_s)(
    wchar_t *buffer,
    size_t sizeOfBuffer,
    size_t count,
    const wchar_t *format,
    ...
    );

extern HANDLE   g_ConOut;
extern BOOL     g_ConsoleOutput;
extern WCHAR    g_szTempDirectory[MAX_PATH + 1];
extern fnptr_snwprintf_s _snwprintf_s;