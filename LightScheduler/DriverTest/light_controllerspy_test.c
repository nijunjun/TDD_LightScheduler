/*
 * light_controllerspy_test.c
 *
 *  Created on: 2018��8��27��
 *      Author: NJ
 */
#include "unity_fixture.h"
#include "light_controllerspy.h"

/**************************************************
 * @function TDD����������
 *
 * @param	LightScheduler ����
 *
 **************************************************/
TEST_GROUP(LightControllerSpy);
/**************************************************
 * @function TDD���Դ�������
 *
 * @param	LightScheduler ����
 *
 **************************************************/
TEST_SETUP(LightControllerSpy)
{
	LightController_Create();
}

/**************************************************
 * @function TDD���Խ�������
 *
 * @param	LightScheduler ����
 *
 **************************************************/
TEST_TEAR_DOWN(LightControllerSpy)
{

}

/**************************************************
 * @function TDD������
 *
 * @param	LightControllerSpy ����
 * @param   Create ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(LightControllerSpy, Create)
{
	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD������
 *
 * @param	LightControllerSpy ����
 * @param   RememberTheLastLightIdControlled ���Ժ�������,���ԡ���
 *
 **************************************************/
TEST(LightControllerSpy, RememberTheLastLightIdControlled)
{
	LightController_On(10);
	LONGS_EQUAL(10, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_ON, LightControllerSpy_GetLastState());
}

/**************************************************
 * @function TDD���������������
 *
 * @param	LightScheduler ����
 *
 **************************************************/
TEST_GROUP_RUNNER(LightControllerSpy)
{
	RUN_TEST_CASE(LightControllerSpy, RememberTheLastLightIdControlled);
}
