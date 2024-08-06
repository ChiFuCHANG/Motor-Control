#ifndef INC_PID_H_
#define INC_PID_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "encoder.h"

typedef struct {
	float Kp;
	float Ki;
	float Kd;
    float error;
    float error_pre;
    float error_sum;
    float output;
} PID;

void pid_control(PID *, ENCODER *);

#ifdef __cplusplus
}
#endif
#endif /* INC_PID_H_ */
