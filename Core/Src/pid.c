#include "pid.h"

//void pid_control(PID *u, ENCODER *e)
//{
//	float target_cnt = (float)TARGET_POS * (4000.0 / (2 * M_PI));
//	u->error = (float)target_cnt - e->cur_cnt;
//	u->error_sum += u->error;
//	if (fabs(u->error_sum) >= MAX_INTEGRAL)
//	{
//		u->error_sum = u->error_sum > 0 ? MAX_INTEGRAL : -MAX_INTEGRAL;
//	}
//	u->output = u->Kp * u->error + u->Ki * u->error_sum + u->Kd * (u->error - u->error_pre);
//	u->error_pre = u->error;
//}

void pid_control(PID *u, ENCODER *e)
{
	u->error = (float)TARGET_POS - e->position;
	u->error_sum += u->error;
	if (fabs(u->error_sum) >= MAX_INTEGRAL)
	{
		u->error_sum = u->error_sum > 0 ? MAX_INTEGRAL : -MAX_INTEGRAL;
	}
	u->output = u->Kp * u->error + u->Ki * u->error_sum + u->Kd * (u->error - u->error_pre);
	u->error_pre = u->error;
}
