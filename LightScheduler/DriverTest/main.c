/*
 * main.c
 *
 * ����ΪTDD�������������ڡ�����������Ƕ��ʽC���Կ�������8�½���
 *
 *  Created on: 2018��8��17��
 *      Author: NJ
 */

#include "unity_fixture.h"

static void RunAllTests(void)
{
	RUN_TEST_GROUP(LightControllerSpy);
	RUN_TEST_GROUP(LightScheduler);
}

int main(int argc, char *argv[])
{
	return UnityMain(argc, argv, RunAllTests);
}
