#ifndef SRC_ENCODER_C_
#define SRC_ENCODER_C_

#include "encoder.h"


void encoder_info(TIM_HandleTypeDef *htim, ENCODER *e)
{
    e->cur_cnt = __HAL_TIM_GET_COUNTER(htim);
    float radians_per_count = 2 * M_PI / (float)PPR;  // 每個計數值對應的弧度
    int16_t delta = e->cur_cnt - e->pre_cnt;

    // 處理計數器溢出情況
    if (__HAL_TIM_IS_TIM_COUNTING_DOWN(htim))
    {
        if (delta > 0)
        {
            delta -= __HAL_TIM_GET_AUTORELOAD(htim);
        }
    }
    else
    {
        if (delta < 0)
        {
            delta += __HAL_TIM_GET_AUTORELOAD(htim);
        }
    }

    // 更新速度和位置（轉換為弧度和弧度每秒）
    e->position += delta * radians_per_count; // 弧度
    e->velocity = (delta * radians_per_count) / SAMP_TIME; // 弧度每秒
    e->pre_cnt = e->cur_cnt;
}

#endif /* SRC_ENCODER_C_ */
