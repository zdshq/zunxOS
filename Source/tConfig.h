#ifndef TCONFIG_H
#define TCONFIG_H

#define	zunxOS_PRO_COUNT				32						// zunxOS任务的优先级序号
#define zunxOS_SLICE_MAX				10						// 每个任务最大运行的时间片计数

#define zunxOS_IDLETASK_STACK_SIZE		1024					// 空闲任务的堆栈单元数
#define zunxOS_TIMERTASK_STACK_SIZE		1024					// 定时器任务的堆栈单元数
#define zunxOS_TIMERTASK_PRIO           1                       // 定时器任务的优先级

#endif /* TCONFIG_H */
