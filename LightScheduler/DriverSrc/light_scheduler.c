/*
 * light_scheduler.c
 *
 *  Created on: 2018年8月27日
 *      Author: THINK
 */
#include "light_scheduler.h"
#include "light_controllerspy.h"
#include "unity_fixture.h"
//普通数据声明
typedef struct
{
	int id;
	int minuteOfDay;
	int event;
	int day;
}ScheduleLightEvent;

static ScheduleLightEvent scheduledEvent;

//函数声明
static void scheduleEvent(int id, Day day, int minuteOfDay, int event);
static void processEventDueNow(Time *time, ScheduleLightEvent *lightEvent);
static void operateLight(ScheduleLightEvent *lightEvent);
/**************************************************
 * @function 对测试用例进行设置
 *
 * @param	none
 **************************************************/
void LightScheduler_Create(void)
{
	scheduledEvent.id = UNUSED;
}

/**************************************************
 * @function 对测试用例进行设置
 *
 * @param	id 灯ID号
 * @param   day 日期
 * @param   minuteOfDay 每天的时间（第N分钟）
 *
 **************************************************/
void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
	scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

/**************************************************
 * @function 对测试用例进行设置
 *
 * @param	id 灯ID号
 * @param   day 日期
 * @param   minuteOfDay 每天的时间（第N分钟）
 *
 **************************************************/
void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
	scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}

/**************************************************
 * @function TDD测试项
 *
 * @param	none
 *
 **************************************************/
void LightScheduler_Wakeup(void)
{
	Time time;
	//todo:get time
	TimeService_GetTime(&time);
	printf("time.minute = %d..\n",time.minuteOfDay);
	printf("time.day  = %d..\n",time.day);
	processEventDueNow(&time, &scheduledEvent);
}

/**************************************************
 * @function TDD测试项
 *
 * @param	day 要设置的日期
 * @param   minuteOfDay 具体的时间（分）
 *
 **************************************************/
void setTimeTo(int day, int minuteOfDay)
{
	//todo:setDay
	FakeTimeService_SetDay(day);
	//todo:setMinute
	FakeTimeService_SetMinute(minuteOfDay);
}

/**************************************************
 * @function TDD测试项
 *
 * @param	id 灯的id号
 * @param   level 灯的状态
 *
 **************************************************/
void checkLightState(int id, int level)
{
	LONGS_EQUAL(id, LightControllerSpy_GetLastId());
	LONGS_EQUAL(level, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD测试项
 *
 * @param	id  控制灯的id号
 * @param   day 日期
 * @param   minuteOfDay 每天的时间（分）
 * @param   event 事件
 **************************************************/
static void scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
	scheduledEvent.minuteOfDay = minuteOfDay;
	scheduledEvent.event = event;
	scheduledEvent.id = id;
}

/**************************************************
 * @function TDD测试项
 *
 * @param	time  时间向量
 * @param   lightEvent 灯的状态向量
 ***************************************************/
static void processEventDueNow(Time *time, ScheduleLightEvent *lightEvent)
{
	printf("time.minuteOfday = %d..,lightEvent.minuteOfday=%d..\n",
			time->minuteOfDay,lightEvent->minuteOfDay);
	printf("lightEvent->day = %d..\n",lightEvent->day);
	printf("lightEvent->id = %d..\n",lightEvent->id);
	if(lightEvent->id == UNUSED)
		return;

	if(lightEvent->minuteOfDay != time->minuteOfDay)
		return;

	if(lightEvent->day != EVERYDAY)
		return;

	operateLight(lightEvent);

}

/**************************************************
 * @function TDD测试项
 *
 * @param   lightEvent 灯的状态向量
 ***************************************************/
static void operateLight(ScheduleLightEvent *lightEvent)
{
	printf("light.event = %d..\n",lightEvent->event);
	if(lightEvent->event == TURN_ON)
		LightController_On(lightEvent->id);
	else if(lightEvent->event == TURN_OFF)
		LightController_Off(lightEvent->id);
}
