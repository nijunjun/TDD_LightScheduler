/*
 * fake_time_service_test.c
 * 用于测试系统时钟
 *  Created on: 2018年8月27日
 *      Author: THINK
 */

#include "unity_fixture.h"
#include "light_scheduler.h"
#include "light_controllerspy.h"
/**************************************************
 * @function TDD测试组声明
 *
 * @param	FakeTimeService 组名
 *
 **************************************************/
TEST_GROUP(FakeTimeService);
/**************************************************
 * @function TDD测试创建声明
 *
 * @param	FakeTimeService 组名
 *
 **************************************************/
TEST_SETUP(FakeTimeService)
{

}

/**************************************************
 * @function TDD测试结束声明
 *
 * @param	FakeTimeService 组名
 *
 **************************************************/
TEST_TEAR_DOWN(FakeTimeService)
{

}

/**************************************************
 * @function TDD测试项
 *
 * @param	FakeTimeService 组名
 * @param   Create 测试函数定义,测试。。
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
 * @function TDD测试项
 *
 * @param	FakeTimeService 组名
 * @param   Set 测试函数定义,测试。。
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
