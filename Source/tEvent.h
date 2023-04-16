#ifndef TEVENT_H
#define TEVENT_H

#include "tConfig.h"
#include "tLib.h"
#include "tTask.h"

// Event类型
typedef enum  _tEventType {   
    tEventTypeUnknown   = (0 << 16), 				// 未知类型
    tEventTypeSem   	= (1 << 16), 				// 信号量类型
    tEventTypeMbox  	= (2 << 16), 				// 邮箱类型
	tEventTypeMemBlock  = (3 << 16),				// 存储块类型
	tEventTypeFlagGroup = (4 << 16),				// 事件标志组
	tEventTypeMutex     = (5 << 16),				// 互斥信号量类型
}tEventType;

// Event控制结构
typedef struct _tEvent {
    tEventType type;						// Event类型

    tList waitList;							// 任务等待列表
}tEvent;

/**********************************************************************************************************
** Function name        :   tEventInit
** Descriptions         :   初始化事件控制块
** parameters           :   event 事件控制块
** parameters           :   type 事件控制块的类型
** Returned value       :   无
***********************************************************************************************************/
void tEventInit (tEvent * event, tEventType type);

/**********************************************************************************************************
** Function name        :   tEventWait
** Descriptions         :   让指定在事件控制块上等待事件发生
** parameters           :   event 事件控制块
** parameters           :   task 等待事件发生的任务
** parameters           :   msg 事件消息存储的具体位置
** parameters           :   state 消息类型
** parameters           :   timeout 等待多长时间
** Returned value       :   优先级最高的且可运行的任务
***********************************************************************************************************/
void tEventWait (tEvent * event, tTask * task, void * msg, uint32_t state, uint32_t timeout);

/**********************************************************************************************************
** Function name        :   tEventWakeUp
** Descriptions         :   从事件控制块中唤醒首个等待的任务
** parameters           :   event 事件控制块
** parameters           :   msg 事件消息
** parameters           :   result 告知事件的等待结果
** Returned value       :   首个等待的任务，如果没有任务等待，则返回0
***********************************************************************************************************/
tTask * tEventWakeUp (tEvent * event, void * msg, uint32_t result);

/**********************************************************************************************************
** Function name        :   tEventWakeUpTask
** Descriptions         :   从事件控制块中唤醒指定任务
** parameters           :   event 事件控制块
** parameters           :   task 等待唤醒的任务
** parameters           :   msg 事件消息
** parameters           :   result 告知事件的等待结果
** Returned value       :   首个等待的任务，如果没有任务等待，则返回0
***********************************************************************************************************/
tTask * tEventWakeUpTask (tEvent * event, tTask * task, void * msg, uint32_t result);

/**********************************************************************************************************
** Function name        :   tEventRemoveTask
** Descriptions         :   将任务从其等待队列中强制移除
** parameters           :   task 待移除的任务
** parameters           :   result 告知事件的等待结果
** Returned value       :   无
***********************************************************************************************************/
void tEventRemoveTask (tTask * task, void * msg, uint32_t result);

/**********************************************************************************************************
** Function name        :   tEventRemoveAll
** Descriptions         :   清除所有等待中的任务，将事件发送给所有任务
** parameters           :   event 事件控制块
** parameters           :   msg 事件消息
** parameters           :   result 告知事件的等待结果
** Returned value       :   唤醒的任务数量
***********************************************************************************************************/
uint32_t tEventRemoveAll (tEvent * event, void * msg, uint32_t result);

/**********************************************************************************************************
** Function name        :   tEventWaitCount
** Descriptions         :   事件控制块中等待的任务数量
** parameters           :   event 事件控制块
** parameters           :   msg 事件消息
** parameters           :   result 告知事件的等待结果
** Returned value       :   唤醒的任务数量
***********************************************************************************************************/
uint32_t tEventWaitCount (tEvent * event);


#endif /* TEVENT_H */
