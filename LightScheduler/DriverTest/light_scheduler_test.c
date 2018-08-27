/*
 * light_scheduler_test.c
 *
 *  Created on: 2018年8月26日
 *      Author: NJ
 */
#include "unity_fixture.h"
#include "light_controllerspy.h"
#include "light_scheduler.h"

/**************************************************
 * @function TDD测试组声明
 *
 * @param	LightScheduler 组名
 *
 **************************************************/
TEST_GROUP(LightScheduler);
/**************************************************
 * @function TDD测试创建声明
 *
 * @param	LightScheduler 组名
 *
 **************************************************/
TEST_SETUP(LightScheduler)
{
	LightController_Create();
	LightScheduler_Create();
}

/**************************************************
 * @function TDD测试结束声明
 *
 * @param	LightScheduler 组名
 *
 **************************************************/
TEST_TEAR_DOWN(LightScheduler)
{

}

/**************************************************
 * @function TDD测试项
 *
 * @param	LightScheduler 组名
 * @param   ScheduleEverydayNotTimeYet 测试函数定义,测试。。
 *
 **************************************************/
TEST(LightScheduler, ScheduleEverydayNotTimeYet)
{
	LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200); //设置灯光控制条件
	FakeTimeService_SetDay(MONDAY); //设置当前日期
	FakeTimeService_SetMinute(1199); //设置系统时间（当前分钟数）

	LightScheduler_Wakeup(); //灯光控制函数
	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LightScheduler 组名
 * @param   NoChangeToLightsDuringInitialization 测试函数定义,测试。。
 *
 **************************************************/
TEST(LightScheduler, NoChangeToLightsDuringInitialization)
{
	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}


/**************************************************
 * @function TDD测试项
 *
 * @param	LightScheduler 组名
 * @param   ScheduleOnEverydayNotTimeYet 测试函数定义,测试。。
 *
 **************************************************/
TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(100);

	LightScheduler_Wakeup(); //灯光控制函数

	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LightScheduler 组名
 * @param   ScheduleOnEverydayItsTime 测试函数定义,测试。。
 *
 **************************************************/
TEST(LightScheduler, ScheduleOnEverydayItsTime)
{
	LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200); //设置灯光控制条件
	FakeTimeService_SetDay(MONDAY); //设置当前日期
	FakeTimeService_SetMinute(1200); //设置系统时间（当前分钟数）

	LightScheduler_Wakeup(); //灯光控制函数

	LONGS_EQUAL(3, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_ON, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LightScheduler 组名
 * @param   ScheduleOffEverydayItsTime 测试函数定义,测试。。
 *
 **************************************************/
TEST(LightScheduler, ScheduleOffEverydayItsTime)
{
	LightScheduler_ScheduleTurnOff(3, EVERYDAY, 1200); //设置灯光控制条件
	FakeTimeService_SetDay(MONDAY); //设置当前日期
	FakeTimeService_SetMinute(1200); //设置系统时间（当前分钟数）

	LightScheduler_Wakeup(); //灯光控制函数

	LONGS_EQUAL(3, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_OFF, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LightScheduler 组名
 * @param   ScheduleWeekEndItsMonday 测试函数定义,测试。。
 *
 **************************************************/
TEST(LightScheduler, ScheduleWeekEndItsMonday)
{
	LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200); //设置灯光控制条件
	setTimeTo(MONDAY, 1200);
	LightScheduler_Wakeup(); //灯光控制函数

	checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LightScheduler 组名
 * @param   ScheduleTuesdayButItsMonday 测试函数定义,测试。。
 *
 **************************************************/
TEST(LightScheduler, ScheduleTuesdayButItsMonday)
{
	LightScheduler_ScheduleTurnOn(3, TUESDAY, 1200); //设置灯光控制条件
	setTimeTo(MONDAY, 1201);
	LightScheduler_Wakeup(); //灯光控制函数

	checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LightScheduler 组名
 * @param   ScheduleWeekEndItsSunday 测试函数定义,测试。。
 *
 **************************************************/
TEST(LightScheduler, ScheduleWeekEndItsSunday)
{
	LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200); //设置灯光控制条件
	setTimeTo(SUNDAY, 1201);
	LightScheduler_Wakeup(); //灯光控制函数
	checkLightState(2, LIGHT_ON);
}

/**************************************************
 * @function TDD测试项的所有内容
 *
 * @param	LightScheduler 组名
 *
 **************************************************/
TEST_GROUP_RUNNER(LightScheduler)
{
	RUN_TEST_CASE(LightScheduler, ScheduleEverydayNotTimeYet);
	RUN_TEST_CASE(LightScheduler, ScheduleTuesdayButItsMonday);
	RUN_TEST_CASE(LightScheduler, ScheduleWeekEndItsSunday);
}
