/*
 * light_scheduler.c
 *
 *  Created on: 2018��8��27��
 *      Author: THINK
 */
#include "light_scheduler.h"
#include "light_controllerspy.h"
#include "unity_fixture.h"
//��ͨ��������
typedef struct
{
	int id;
	int minuteOfDay;
	int event;
	int day;
}ScheduleLightEvent;

static ScheduleLightEvent scheduledEvent;

//��������
static void scheduleEvent(int id, Day day, int minuteOfDay, int event);
static void processEventDueNow(Time *time, ScheduleLightEvent *lightEvent);
static void operateLight(ScheduleLightEvent *lightEvent);
/**************************************************
 * @function �Բ���������������
 *
 * @param	none
 **************************************************/
void LightScheduler_Create(void)
{
	scheduledEvent.id = UNUSED;
}

/**************************************************
 * @function �Բ���������������
 *
 * @param	id ��ID��
 * @param   day ����
 * @param   minuteOfDay ÿ���ʱ�䣨��N���ӣ�
 *
 **************************************************/
void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
	scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

/**************************************************
 * @function �Բ���������������
 *
 * @param	id ��ID��
 * @param   day ����
 * @param   minuteOfDay ÿ���ʱ�䣨��N���ӣ�
 *
 **************************************************/
void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
	scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}

/**************************************************
 * @function TDD������
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
 * @function TDD������
 *
 * @param	day Ҫ���õ�����
 * @param   minuteOfDay �����ʱ�䣨�֣�
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
 * @function TDD������
 *
 * @param	id �Ƶ�id��
 * @param   level �Ƶ�״̬
 *
 **************************************************/
void checkLightState(int id, int level)
{
	LONGS_EQUAL(id, LightControllerSpy_GetLastId());
	LONGS_EQUAL(level, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD������
 *
 * @param	id  ���ƵƵ�id��
 * @param   day ����
 * @param   minuteOfDay ÿ���ʱ�䣨�֣�
 * @param   event �¼�
 **************************************************/
static void scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
	scheduledEvent.minuteOfDay = minuteOfDay;
	scheduledEvent.event = event;
	scheduledEvent.id = id;
}

/**************************************************
 * @function TDD������
 *
 * @param	time  ʱ������
 * @param   lightEvent �Ƶ�״̬����
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
 * @function TDD������
 *
 * @param   lightEvent �Ƶ�״̬����
 ***************************************************/
static void operateLight(ScheduleLightEvent *lightEvent)
{
	printf("light.event = %d..\n",lightEvent->event);
	if(lightEvent->event == TURN_ON)
		LightController_On(lightEvent->id);
	else if(lightEvent->event == TURN_OFF)
		LightController_Off(lightEvent->id);
}
