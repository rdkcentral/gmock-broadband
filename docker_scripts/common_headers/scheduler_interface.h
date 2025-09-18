#ifndef __SCHEDULER_INTERFACE_H__
#define __SCHEDULER_INTERFACE_H__

#include <limits.h>
#include <time.h>
#include "scheduler_main.h"

#define MAX_SCHEDULE_ACTIONS  256

typedef struct schedule_input {
    time_t   time;                                  /**< Schedule time; */
    uint8_t  action_count;                          /**< Num of actions to taken during this schedule; */
    uint32_t action_indexes[MAX_SCHEDULE_ACTIONS];  /**< Indexes of actions to taken during this schedule; */
} input_t;

typedef struct schedule_info {
    char         **actions;         /**< List of actions string; */
    size_t       actions_size;      /**< Size of actions list; */
    input_t      *absolute;         /**< Absolute schedule; */
    size_t       absolute_size;     /**< Absolute schedule size; */
    input_t      *weekly;           /**< Weekly schedule; */
    size_t       weekly_size;       /**< Weekly schedule size; */
} schedule_info_t;

int scheduler_init(SchedulerData scheduler_data[], int scheduler_data_size, const char* rdk_log_module);

int run_schedule( schedule_info_t *t, char* action_key );

int delete_schedule(char *action_key);

void freeScheduleInfo(schedule_info_t* schedule);
#endif
