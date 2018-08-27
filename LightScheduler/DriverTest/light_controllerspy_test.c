/*
 * light_controllerspy_test.c
 *
 *  Created on: 2018年8月27日
 *      Author: NJ
 */
#include "unity_fixture.h"
#include "light_controllerspy.h"

/**************************************************
 * @function TDD测试组声明
 *
 * @param	LightScheduler 组名
 *
 **************************************************/
TEST_GROUP(LightControllerSpy);
/**************************************************
 * @function TDD测试创建声明
 *
 * @param	LightScheduler 组名
 *
 **************************************************/
TEST_SETUP(LightControllerSpy)
{
	LightController_Create();
}

/**************************************************
 * @function TDD测试结束声明
 *
 * @param	LightScheduler 组名
 *
 **************************************************/
TEST_TEAR_DOWN(LightControllerSpy)
{

}

/**************************************************
 * @function TDD测试项
 *
 * @param	LightControllerSpy 组名
 * @param   Create 测试函数定义,测试。。
 *
 **************************************************/
TEST(LightControllerSpy, Create)
{
	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD测试项
 *
 * @param	LightControllerSpy 组名
 * @param   RememberTheLastLightIdControlled 测试函数定义,测试。。
 *
 **************************************************/
TEST(LightControllerSpy, RememberTheLastLightIdControlled)
{
	LightController_On(10);
	LONGS_EQUAL(10, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_ON, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD测试项的所有内容
 *
 * @param	LightScheduler 组名
 *
 **************************************************/
TEST_GROUP_RUNNER(LightControllerSpy)
{
	RUN_TEST_CASE(LightControllerSpy, RememberTheLastLightIdControlled);
}
