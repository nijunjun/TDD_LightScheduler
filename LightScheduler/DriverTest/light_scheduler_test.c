/*
 * light_scheduler_test.c
 *
 *  Created on: 2018��8��26��
 *      Author: NJ
 */
#include "unity_fixture.h"
#include "light_controllerspy.h"
#include "light_scheduler.h"

/**************************************************
 * @function TDD����������
 *
 * @param	LightScheduler ����
 *
 **************************************************/
TEST_GROUP(LightScheduler);
/**************************************************
 * @function TDD���Դ�������
 *
 * @param	LightScheduler ����
 *
 **************************************************/
TEST_SETUP(LightScheduler)
{
	LightController_Create();
	LightScheduler_Create();
}

/**************************************************
 * @function TDD���Խ�������
 *
 * @param	LightScheduler ����
 *
 **************************************************/
TEST_TEAR_DOWN(LightScheduler)
{

}

/**************************************************
 * @function TDD������
 *
 * @param	LightScheduler ����
 * @param   ScheduleEverydayNotTimeYet ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(LightScheduler, ScheduleEverydayNotTimeYet)
{
	LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200); //���õƹ��������
	FakeTimeService_SetDay(MONDAY); //���õ�ǰ����
	FakeTimeService_SetMinute(1199); //����ϵͳʱ�䣨��ǰ��������

	LightScheduler_Wakeup(); //�ƹ���ƺ���
	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD������
 *
 * @param	LightScheduler ����
 * @param   NoChangeToLightsDuringInitialization ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(LightScheduler, NoChangeToLightsDuringInitialization)
{
	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}


/**************************************************
 * @function TDD������
 *
 * @param	LightScheduler ����
 * @param   ScheduleOnEverydayNotTimeYet ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(100);

	LightScheduler_Wakeup(); //�ƹ���ƺ���

	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD������
 *
 * @param	LightScheduler ����
 * @param   ScheduleOnEverydayItsTime ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(LightScheduler, ScheduleOnEverydayItsTime)
{
	LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200); //���õƹ��������
	FakeTimeService_SetDay(MONDAY); //���õ�ǰ����
	FakeTimeService_SetMinute(1200); //����ϵͳʱ�䣨��ǰ��������

	LightScheduler_Wakeup(); //�ƹ���ƺ���

	LONGS_EQUAL(3, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_ON, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD������
 *
 * @param	LightScheduler ����
 * @param   ScheduleOffEverydayItsTime ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(LightScheduler, ScheduleOffEverydayItsTime)
{
	LightScheduler_ScheduleTurnOff(3, EVERYDAY, 1200); //���õƹ��������
	FakeTimeService_SetDay(MONDAY); //���õ�ǰ����
	FakeTimeService_SetMinute(1200); //����ϵͳʱ�䣨��ǰ��������

	LightScheduler_Wakeup(); //�ƹ���ƺ���

	LONGS_EQUAL(3, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_OFF, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD������
 *
 * @param	LightScheduler ����
 * @param   ScheduleWeekEndItsMonday ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(LightScheduler, ScheduleWeekEndItsMonday)
{
	LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200); //���õƹ��������
	setTimeTo(MONDAY, 1200);
	LightScheduler_Wakeup(); //�ƹ���ƺ���

	checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

/**************************************************
 * @function TDD������
 *
 * @param	LightScheduler ����
 * @param   ScheduleTuesdayButItsMonday ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(LightScheduler, ScheduleTuesdayButItsMonday)
{
	LightScheduler_ScheduleTurnOn(3, TUESDAY, 1200); //���õƹ��������
	setTimeTo(MONDAY, 1201);
	LightScheduler_Wakeup(); //�ƹ���ƺ���

	checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

/**************************************************
 * @function TDD������
 *
 * @param	LightScheduler ����
 * @param   ScheduleWeekEndItsSunday ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(LightScheduler, ScheduleWeekEndItsSunday)
{
	LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200); //���õƹ��������
	setTimeTo(SUNDAY, 1201);
	LightScheduler_Wakeup(); //�ƹ���ƺ���
	checkLightState(2, LIGHT_ON);
}

/**************************************************
 * @function TDD���������������
 *
 * @param	LightScheduler ����
 *
 **************************************************/
TEST_GROUP_RUNNER(LightScheduler)
{
	RUN_TEST_CASE(LightScheduler, ScheduleEverydayNotTimeYet);
	RUN_TEST_CASE(LightScheduler, ScheduleTuesdayButItsMonday);
	RUN_TEST_CASE(LightScheduler, ScheduleWeekEndItsSunday);
}
