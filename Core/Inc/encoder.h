#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

typedef struct{
	float pre_position;
	float position;
	float velocity;
	int16_t cur_cnt;
	int16_t pre_cnt;
} ENCODER;

void encoder_info(TIM_HandleTypeDef *htim, ENCODER *e);

#ifdef __cplusplus
}
#endif
#endif /* INC_ENCODER_H_ */
