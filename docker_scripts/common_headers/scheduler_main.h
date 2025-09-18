#ifndef __SCHEDULER_MAIN_H__
#define __SCHEDULER_MAIN_H__

#include <stdio.h>
#include <stdint.h>

typedef void (*ExecSchedulerAction)(char *);

typedef struct _SchedulerData
{
    char *data_file;
    char *md5_file;
    char *scheduler_action_key;
    ExecSchedulerAction scheduler_action;
    int instanceNum;
    size_t max_actions;

} SchedulerData, *pSchedulerData;
#endif
