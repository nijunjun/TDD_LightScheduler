/*
 * light_controllerspy.h
 * ���ļ�Ϊ�������ͷ�ļ���
 * ֻ���ڵ���ʱ�ã��ʶ����ļ��е����������ڲ�Ʒ������
 *  Created on: 2018��8��27��
 *      Author: NJ
 */

#ifndef DRIVERSRC_LIGHT_CONTROLLERSPY_H_
#define DRIVERSRC_LIGHT_CONTROLLERSPY_H_

#include "light_controller.h"

//������ֻ�Ǽ������������ʱ�����õģ��ʶ��������ڲ�Ʒ������
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
