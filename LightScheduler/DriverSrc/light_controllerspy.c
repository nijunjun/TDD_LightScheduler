/*
 * light_controllerspy.c
 * 间谍代码源文件
 *  Created on: 2018年8月27日
 *      Author: NJ
 */

#include "light_controllerspy.h"

static int lastId;
static int lastState;
static int actual_day;
static int actual_time;
/**************************************************
 * @function 创建函数，初始化间谍的秘密情报放置点
 *
 * @param	none
 *
 **************************************************/
void LightController_Create(void)
{
	lastId = LIGHT_ID_UNKNOWN;
	lastState = LIGHT_STATE_UNKNOWN;
}

/**************************************************
 * @function 将灯的状态改为On
 *
 * @param	id
 *
 **************************************************/
void LightController_On(int id)
{
	lastId = id;
	lastState = LIGHT_ON;
}

/**************************************************
 * @function 将灯的状态改为Off
 *
 * @param	id
 *
 **************************************************/
void LightController_Off(int id)
{
	lastId = id;
	lastState = LIGHT_OFF;
}

/**************************************************
 * @function 返回最后改变的灯的ID号
 *
 * @param	none
 *
 **************************************************/
int LightControllerSpy_GetLastId(void)
{
	return lastId;
}

/**************************************************
 * @function 返回最后改变的灯的ID号
 *
 * @param	none
 *
 **************************************************/
int LightControllerSpy_GetLastState(void)
{
	return lastState;
}

/**************************************************
 * @function 返设置当前日期
 *
 * @param	day 日期
 *
 **************************************************/
void FakeTimeService_SetDay(int day)
{
	actual_day = day;
}

/**************************************************
 * @function 返设置当前日期
 *
 * @param	minuteOfDay 时间
 *
 **************************************************/
void FakeTimeService_SetMinute(int minuteOfDay)
{
	actual_time = minuteOfDay;
}

/**************************************************
 * @function 返设置当前日期信息
 *
 * @param	time 时间结构体
 *
 **************************************************/
void TimeService_GetTime(Time *time)
{
	time->day = actual_day;
	time->minuteOfDay = actual_time;
}
