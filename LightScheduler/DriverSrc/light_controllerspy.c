/*
 * light_controllerspy.c
 * �������Դ�ļ�
 *  Created on: 2018��8��27��
 *      Author: NJ
 */

#include "light_controllerspy.h"

static int lastId;
static int lastState;
static int actual_day;
static int actual_time;
/**************************************************
 * @function ������������ʼ������������鱨���õ�
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
 * @function ���Ƶ�״̬��ΪOn
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
 * @function ���Ƶ�״̬��ΪOff
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
 * @function �������ı�ĵƵ�ID��
 *
 * @param	none
 *
 **************************************************/
int LightControllerSpy_GetLastId(void)
{
	return lastId;
}

/**************************************************
 * @function �������ı�ĵƵ�ID��
 *
 * @param	none
 *
 **************************************************/
int LightControllerSpy_GetLastState(void)
{
	return lastState;
}

/**************************************************
 * @function �����õ�ǰ����
 *
 * @param	day ����
 *
 **************************************************/
void FakeTimeService_SetDay(int day)
{
	actual_day = day;
}

/**************************************************
 * @function �����õ�ǰ����
 *
 * @param	minuteOfDay ʱ��
 *
 **************************************************/
void FakeTimeService_SetMinute(int minuteOfDay)
{
	actual_time = minuteOfDay;
}

/**************************************************
 * @function �����õ�ǰ������Ϣ
 *
 * @param	time ʱ��ṹ��
 *
 **************************************************/
void TimeService_GetTime(Time *time)
{
	time->day = actual_day;
	time->minuteOfDay = actual_time;
}
