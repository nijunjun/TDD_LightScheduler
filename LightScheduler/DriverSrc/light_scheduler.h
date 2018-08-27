/*
 * light_scheduler.h
 *
 *  Created on: 2018Äê8ÔÂ27ÈÕ
 *      Author: THINK
 */

#ifndef DRIVERSRC_LIGHT_SCHEDULER_H_
#define DRIVERSRC_LIGHT_SCHEDULER_H_

enum Day{
	NONE = -1, EVERYDAY = 10,WEEKDAY,WEEKEND,
	SUNDAY = 1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};
typedef enum Day Day;

enum{
	UNUSED = -1
};

enum{
	TURN_ON = 1, TURN_OFF = ~TURN_ON
};

void LightScheduler_Create(void);
void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay);
void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay);
void LightScheduler_Wakeup(void);
void setTimeTo(int day, int minuteOfDay);
void checkLightState(int id, int level);

#endif /* DRIVERSRC_LIGHT_SCHEDULER_H_ */
