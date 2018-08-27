/*
 * light_controllerspy.h
 * 本文件为间谍代码头文件，
 * 只用于调试时用，故而此文件中的声明不放在产品代码中
 *  Created on: 2018年8月27日
 *      Author: NJ
 */

#ifndef DRIVERSRC_LIGHT_CONTROLLERSPY_H_
#define DRIVERSRC_LIGHT_CONTROLLERSPY_H_

#include "light_controller.h"

//由于这只是间谍代码用于临时调试用的，故而不定义在产品代码中
enum {
	LIGHT_ID_UNKNOWN = -1, LIGHT_STATE_UNKNOWN = -1,
	TIME_UNKNOWN = -1,
	LIGHT_OFF = 0, LIGHT_ON = 1
};

typedef struct
{
	int id;
	int minuteOfDay;
	int event;
	int day;
}Time;

void LightController_Create();
void LightController_On(int id);
void LightController_Off(int id);
int LightControllerSpy_GetLastId(void);
int LightControllerSpy_GetLastState(void);
void FakeTimeService_SetDay(int day);
void FakeTimeService_SetMinute(int minuteOfDay);
void TimeService_GetTime(Time *time);

#endif /* DRIVERSRC_LIGHT_CONTROLLERSPY_H_ */
