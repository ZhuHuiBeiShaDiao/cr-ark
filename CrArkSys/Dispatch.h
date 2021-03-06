#pragma once

//初始化APC
//InputBuffer[0] == ThreadHandle
NTSTATUS
DispatchSpecialInitialize(PVOID InputBuffer, ULONG InputLength,
                          PVOID OutputBuffer, ULONG OutputLength,
                          PULONG Information);

//枚举进程
//InputBuffer[0] == 是否显示Deleting进程
//OutputBuffer ObjectIdTable缓冲
NTSTATUS
DispatchProcessEnum(PVOID InputBuffer, ULONG InputLength,
                    PVOID OutputBuffer, ULONG OutputLength,
                    PULONG Information);

//枚举进程
//InputBuffer[0] == 是否显示EPROCESS指针
//OutputBuffer ObjectIdTable缓冲
NTSTATUS
DispatchThreadEnum(PVOID InputBuffer, ULONG InputLength,
                   PVOID OutputBuffer, ULONG OutputLength,
                   PULONG Information);

//\获取进程名称
//InputBuffer[0] == PEPROCESS指针
//OutputBuffer ProcessNameInfo缓冲
NTSTATUS
DispatchQueryProcessName(PVOID InputBuffer, ULONG InputLength,
                         PVOID OutputBuffer, ULONG OutputLength,
                         PULONG Information);

//获取进程信息
//InputBuffer[0] == PEPROCESS指针
//OutputBuffer ProcessInfo缓冲
NTSTATUS
DispatchQueryProcessInfo(PVOID InputBuffer, ULONG InputLength,
                         PVOID OutputBuffer, ULONG OutputLength,
                         PULONG Information);

//获取线程信息
//InputBuffer[0] == PETHREAD指针
//OutputBuffer threadInfo缓冲
NTSTATUS
DispatchQueryThreadInfo(PVOID InputBuffer, ULONG InputLength,
                        PVOID OutputBuffer, ULONG OutputLength,
                        PULONG Information);

//获取进程的模块列表
//InputBuffer[0] == PEPROCESS指针
//OutputBuffer ProcessModuleList缓冲
NTSTATUS
DispatchQueryProcessModuleList(PVOID InputBuffer, ULONG InputLength,
                               PVOID OutputBuffer, ULONG OutputLength,
                               PULONG Information);

//获取进程的模块信息
//InputBuffer[0] == PEPROCESS指针
//InputBuffer[1] == LdrData指针
//OutputBuffer ModuleInfo缓冲
NTSTATUS
DispatchQueryProcessModuleInfo(PVOID InputBuffer, ULONG InputLength,
                               PVOID OutputBuffer, ULONG OutputLength,
                               PULONG Information);

//结束线程
//InputBuffer[0] == PETHREAD指针
//InputBuffer[1] == ExitStatus
//InputBuffer[2] == ForceExit
NTSTATUS
DispatchTerminateThread(PVOID InputBuffer, ULONG InputLength,
                        PVOID OutputBuffer, ULONG OutputLength,
                        PULONG Information);

//结束进程
//InputBuffer[0] == PPROCESS指针
//InputBuffer[1] == ExitStatus
//InputBuffer[2] == ForceExit
NTSTATUS
DispatchTerminateProcess(PVOID InputBuffer, ULONG InputLength,
                         PVOID OutputBuffer, ULONG OutputLength,
                         PULONG Information);

//卸载Process进程中的指定模块
//InputBuffer[0] == Process      PEPROCESS指针
//InputBuffer[1] == BaseAddress  模块起始地址
NTSTATUS
DispatchUnmapProcessModule(PVOID InputBuffer, ULONG InputLength,
                           PVOID OutputBuffer, ULONG OutputLength,
                           PULONG Information);

//保护对象
//InputBuffer[0] == Object
//InputBuffer[1] == 是否删除
NTSTATUS
DispatchProtectObject(PVOID InputBuffer, ULONG InputLength,
                      PVOID OutputBuffer, ULONG OutputLength,
                      PULONG Information);

//读内存
//InputBuffer[0] == 起始地址
//OutputBuffer == 读出的缓冲区
NTSTATUS
DispatchReadMem(PVOID InputBuffer, ULONG InputLength,
                PVOID OutputBuffer, ULONG OutputLength,
                PULONG Information);

//写内存
//InputBuffer[0] == source 
//InputBuffer[1] == dest
//InputBuffer[2] == length
NTSTATUS
DispatchWriteMem(PVOID InputBuffer, ULONG InputLength,
                 PVOID OutputBuffer, ULONG OutputLength,
                 PULONG Information);