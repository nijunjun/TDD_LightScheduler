/*
 * fake_time_service_test.c
 * ���ڲ���ϵͳʱ��
 *  Created on: 2018��8��27��
 *      Author: THINK
 */

#include "unity_fixture.h"
#include "light_scheduler.h"
#include "light_controllerspy.h"
/**************************************************
 * @function TDD����������
 *
 * @param	FakeTimeService ����
 *
 **************************************************/
TEST_GROUP(FakeTimeService);
/**************************************************
 * @function TDD���Դ�������
 *
 * @param	FakeTimeService ����
 *
 **************************************************/
TEST_SETUP(FakeTimeService)
{

}

/**************************************************
 * @function TDD���Խ�������
 *
 * @param	FakeTimeService ����
 *
 **************************************************/
TEST_TEAR_DOWN(FakeTimeService)
{

}

/**************************************************
 * @function TDD������
 *
 * @param	FakeTimeService ����
 * @param   Create ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(FakeTimeService,Create)
{
	Time time;
	TimeService_GetTime(&time);
	LONGS_EQUAL(TIME_UNKNOWN, time.minuteOfDay);
	LONGS_EQUAL(TIME_UNKNOWN, time.day);
}

/**************************************************
 * @function TDD������
 *
 * @param	FakeTimeService ����
 * @param   Set ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(FakeTimeService,Set)
{
	Time time;
	FakeTimeService_SetMinute(42);
	FakeTimeService_SetDay(SATURDAY);

	TimeService_GetTime(&time);

	LONGS_EQUAL(42, time.minuteOfDay);
	LONGS_EQUAL(SATURDAY, time.day);
}
