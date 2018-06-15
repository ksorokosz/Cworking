#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define HOST_NAME_MAX 50
#define MAX_COMMAND_LENGTH 50
#define MAX_COMMAND_ELEMENTS (MAX_COMMAND_LENGTH >> 1) + 1

#define ERROR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

#if DEBUG
#define LOG(fmt, ...) fprintf(stderr, "%s: %s[%d] -> ", __FILE__, __func__,__LINE__); fprintf(stderr, fmt, ##__VA_ARGS__)
#else
#define LOG(fmt, ...) 
#endif

#endif /* MICROSHELL_H */
