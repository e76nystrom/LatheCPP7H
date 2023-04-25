#if defined(__STM32F4xx_HAL_H) || defined(__STM32F7xx_HAL_H) || defined(STM32H7xx_HAL_H)
#if !defined(__TIMERS_H)
#define __TIMERS_H

/*
board       nucH743
proc        STM32H743
step1       2
step1Pwm    3
step2       5
step2Pwm    3
step3       3
step3Pwm    2
step4       4
step4Pwm    3
spindleTmr  8
spindlePwm  1
usecTmr     6
encTestTmr  7
pwmTmr      12
pwmTmrPwm   2
intTmr      15
intTmrPwm   0
indexTmr    16
cmpTmr      17
step3Isr    TIM4
step4Isr    TIM3
pwmTmrIsr   TIM8_BRK_TIM12
spindleIsr  TIM8_UP_TIM13
intTmrIsr   TIM15
indexTmrIsr TIM16
cmpTmrIsr   TIM17
usecTmrIsr  None
*/

#define STEP1_TIM2
#define STEP1_PWM3
#define STEP2_TIM5
#define STEP2_PWM3
#define STEP3_TIM3
#define STEP3_PWM2
#define STEP4_TIM4
#define STEP4_PWM3
#define SPINDLE_TMR8
#define SPINDLE_PWM1
#define USEC_TMR_TIM6
#define ENC_TMR_TIM7
#define PWM_TMR12
#define PWM_TMR_PWM2
#define INT_TMR15
#define INT_TMR_PWM0
#define INDEX_TMR16
#define CMP_TMR17

constexpr auto SP_FWD = 1;
constexpr auto SP_REV = -1;
constexpr unsigned int STEP_WIDTH = 10;

#define DIR_SPIN_PORT (Dir5_GPIO_Port)
constexpr uint32_t DIR_SPIN_BIT = Dir5_Pin;

inline void dirSpinFwd() {DIR_SPIN_PORT->BSRR = spA.dirFwd;}
inline void dirSpinRev() {DIR_SPIN_PORT->BSRR = spA.dirRev;}
inline void dirZFwd() {Dir1_GPIO_Port->BSRR = zAxis.dirFwd;}
inline void dirZRev() {Dir1_GPIO_Port->BSRR = zAxis.dirRev;}
inline void dirXFwd() {Dir2_GPIO_Port->BSRR = xAxis.dirFwd;}
inline void dirXRev() {Dir2_GPIO_Port->BSRR = xAxis.dirRev;}
inline uint32_t CALC_STEP_WIDTH(unsigned int x) {return((rVar.cfgFcy * x) / 1000000l);}

/* zTmr timer 2 pwm 3 */

#define Z_TIMER 2
#define Z_TMR TIM2

#define zTmrISR(x) TIM2_IRQHandler(x)

inline void zTmrInit() { \
	__HAL_RCC_TIM2_CLK_ENABLE(); \
	TIM2->CR1 |= TIM_CR1_DIR; \
	TIM2->CR1 &= ~TIM_CR1_CEN;}

inline void     zTmrClrIE()         {TIM2->DIER &= ~TIM_IT_UPDATE;}
inline void     zTmrSetIE()         {TIM2->DIER |= TIM_IT_UPDATE;}
inline uint16_t zTmrTstIE()         {return((TIM2->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t zTmrIF()            {return((TIM2->SR & TIM_FLAG_UPDATE) != 0);}
inline void     zTmrClrIF()         {TIM2->SR = ~TIM_FLAG_UPDATE;}
inline void     zTmrStart()         {TIM2->CR1 |= TIM_CR1_CEN;}
inline void     zTmrPulse()         {TIM2->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     zTmrStop()          {TIM2->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     zTmrScl(uint16_t y) {TIM2->PSC = (y);}
inline uint32_t zTmrRead()          {return(TIM2->CNT);}
inline void     zTmrCntClr()        {TIM2->CNT = 0;}
inline void     zTmrCnt(uint32_t x) {TIM2->CNT = (x);}
inline void     zTmrMax(uint32_t x) {TIM2->ARR = ((x) - 1);}
inline void     zTmrSet(uint32_t x) {TIM2->ARR = (x);}
inline uint32_t zTmrMaxRead()       {return(TIM2->ARR);}

/* pwm 3 */

#define Z_TMR_PWM 3

inline void     zTmrCCR(uint32_t x) {TIM2->CCR3 = (x);}
inline void     zTmrPWMMode()       \
	{TIM2->CCMR2 = (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1);}
inline void     zTmrPWMEna()        {TIM2->CCER |= TIM_CCER_CC3E;}
inline void     zTmrPWMDis()        {TIM2->CCER &= ~TIM_CCER_CC3E;}
inline uint32_t zTmrReadCCR()       {return(TIM2->CCR3);}
inline uint16_t zTmrReadCCMR()      {return(TIM2->CCMR2);}

/* timer 8 trigger 1 */

inline void zTmrSlvEna() {TIM2->SMCR = (TIM_SMCR_TS_0 | \
	TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1);}
inline void zTmrSlvDis() {TIM2->SMCR = 0;}

/* xTmr timer 5 pwm 3 */

#define X_TIMER 5
#define X_TMR TIM5

#define xTmrISR(x) TIM5_IRQHandler(x)

inline void xTmrInit() { \
	__HAL_RCC_TIM5_CLK_ENABLE(); \
	TIM5->CR1 |= TIM_CR1_DIR; \
	TIM5->CR1 &= ~TIM_CR1_CEN;}

inline void     xTmrClrIE()         {TIM5->DIER &= ~TIM_IT_UPDATE;}
inline void     xTmrSetIE()         {TIM5->DIER |= TIM_IT_UPDATE;}
inline uint16_t xTmrTstIE()         {return((TIM5->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t xTmrIF()            {return((TIM5->SR & TIM_FLAG_UPDATE) != 0);}
inline void     xTmrClrIF()         {TIM5->SR = ~TIM_FLAG_UPDATE;}
inline void     xTmrStart()         {TIM5->CR1 |= TIM_CR1_CEN;}
inline void     xTmrPulse()         {TIM5->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     xTmrStop()          {TIM5->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     xTmrScl(uint16_t y) {TIM5->PSC = (y);}
inline uint32_t xTmrRead()          {return(TIM5->CNT);}
inline void     xTmrCntClr()        {TIM5->CNT = 0;}
inline void     xTmrCnt(uint32_t x) {TIM5->CNT = (x);}
inline void     xTmrMax(uint32_t x) {TIM5->ARR = ((x) - 1);}
inline void     xTmrSet(uint32_t x) {TIM5->ARR = (x);}
inline uint32_t xTmrMaxRead()       {return(TIM5->ARR);}

/* pwm 3 */

#define X_TMR_PWM 3

inline void     xTmrCCR(uint32_t x) {TIM5->CCR3 = (x);}
inline void     xTmrPWMMode()       \
	{TIM5->CCMR2 = (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1);}
inline void     xTmrPWMEna()        {TIM5->CCER |= TIM_CCER_CC3E;}
inline void     xTmrPWMDis()        {TIM5->CCER &= ~TIM_CCER_CC3E;}
inline uint32_t xTmrReadCCR()       {return(TIM5->CCR3);}
inline uint16_t xTmrReadCCMR()      {return(TIM5->CCMR2);}

/* timer 8 trigger 3 */

inline void xTmrSlvEna() {TIM5->SMCR = (TIM_SMCR_TS_1 | TIM_SMCR_TS_0 | \
	TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1);}
inline void xTmrSlvDis() {TIM5->SMCR = 0;}

/* step3Tmr timer 3 pwm 2 */

#define STEP3_TIMER 3
#define STEP3_TMR TIM3

#define step3TmrISR(x) TIM4_IRQHandler(x)

inline void step3TmrInit() { \
	__HAL_RCC_TIM3_CLK_ENABLE(); \
	TIM3->CR1 |= TIM_CR1_DIR; \
	TIM3->CR1 &= ~TIM_CR1_CEN;}

inline void     step3TmrClrIE()         {TIM3->DIER &= ~TIM_IT_UPDATE;}
inline void     step3TmrSetIE()         {TIM3->DIER |= TIM_IT_UPDATE;}
inline uint16_t step3TmrTstIE()         \
	{return((TIM3->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t step3TmrIF()            \
	{return((TIM3->SR & TIM_FLAG_UPDATE) != 0);}
inline void     step3TmrClrIF()         {TIM3->SR = ~TIM_FLAG_UPDATE;}
inline void     step3TmrStart()         {TIM3->CR1 |= TIM_CR1_CEN;}
inline void     step3TmrPulse()         \
	{TIM3->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     step3TmrStop()          \
	{TIM3->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     step3TmrScl(uint16_t y) {TIM3->PSC = (y);}
inline uint16_t step3TmrRead()          {return(TIM3->CNT);}
inline void     step3TmrCntClr()        {TIM3->CNT = 0;}
inline void     step3TmrCnt(uint16_t x) {TIM3->CNT = (x);}
inline void     step3TmrMax(uint16_t x) {TIM3->ARR = ((x) - 1);}
inline void     step3TmrSet(uint16_t x) {TIM3->ARR = (x);}
inline uint16_t step3TmrMaxRead()       {return(TIM3->ARR);}

/* pwm 2 */

#define STEP3_TMR_PWM 2

inline void     step3TmrCCR(uint16_t x) {TIM3->CCR2 = (x);}
inline void     step3TmrPWMMode()       \
	{TIM3->CCMR1 = (TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1);}
inline void     step3TmrPWMEna()        {TIM3->CCER |= TIM_CCER_CC2E;}
inline void     step3TmrPWMDis()        {TIM3->CCER &= ~TIM_CCER_CC2E;}
inline uint16_t step3TmrReadCCR()       {return(TIM3->CCR2);}
inline uint16_t step3TmrReadCCMR()      {return(TIM3->CCMR1);}

/* step4Tmr timer 4 pwm 3 */

#define STEP4_TIMER 4
#define STEP4_TMR TIM4

#define step4TmrISR(x) TIM3_IRQHandler(x)

inline void step4TmrInit() { \
	__HAL_RCC_TIM4_CLK_ENABLE(); \
	TIM4->CR1 |= TIM_CR1_DIR; \
	TIM4->CR1 &= ~TIM_CR1_CEN;}

inline void     step4TmrClrIE()         {TIM4->DIER &= ~TIM_IT_UPDATE;}
inline void     step4TmrSetIE()         {TIM4->DIER |= TIM_IT_UPDATE;}
inline uint16_t step4TmrTstIE()         \
	{return((TIM4->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t step4TmrIF()            \
	{return((TIM4->SR & TIM_FLAG_UPDATE) != 0);}
inline void     step4TmrClrIF()         {TIM4->SR = ~TIM_FLAG_UPDATE;}
inline void     step4TmrStart()         {TIM4->CR1 |= TIM_CR1_CEN;}
inline void     step4TmrPulse()         \
	{TIM4->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     step4TmrStop()          \
	{TIM4->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     step4TmrScl(uint16_t y) {TIM4->PSC = (y);}
inline uint16_t step4TmrRead()          {return(TIM4->CNT);}
inline void     step4TmrCntClr()        {TIM4->CNT = 0;}
inline void     step4TmrCnt(uint16_t x) {TIM4->CNT = (x);}
inline void     step4TmrMax(uint16_t x) {TIM4->ARR = ((x) - 1);}
inline void     step4TmrSet(uint16_t x) {TIM4->ARR = (x);}
inline uint16_t step4TmrMaxRead()       {return(TIM4->ARR);}

/* pwm 3 */

#define STEP4_TMR_PWM 3

inline void     step4TmrCCR(uint16_t x) {TIM4->CCR3 = (x);}
inline void     step4TmrPWMMode()       \
	{TIM4->CCMR2 = (TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1);}
inline void     step4TmrPWMEna()        {TIM4->CCER |= TIM_CCER_CC3E;}
inline void     step4TmrPWMDis()        {TIM4->CCER &= ~TIM_CCER_CC3E;}
inline uint16_t step4TmrReadCCR()       {return(TIM4->CCR3);}
inline uint16_t step4TmrReadCCMR()      {return(TIM4->CCMR2);}

/* spindleTmr timer 8 pwm 1 */

#define SPINDLE_TIMER 8
#define SPINDLE_TMR TIM8

#define spindleTmrISR(x) TIM8_UP_TIM13_IRQHandler(x)

inline void spindleTmrInit() { \
	__HAL_RCC_TIM8_CLK_ENABLE(); \
	TIM8->CR1 |= TIM_CR1_DIR; \
	TIM8->CR1 &= ~TIM_CR1_CEN;}

inline void spindleTmrBDTR() {TIM8->BDTR |= TIM_BDTR_MOE;}

inline void     spindleTmrClrIE()         {TIM8->DIER &= ~TIM_IT_UPDATE;}
inline void     spindleTmrSetIE()         {TIM8->DIER |= TIM_IT_UPDATE;}
inline uint16_t spindleTmrTstIE()         \
	{return((TIM8->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t spindleTmrIF()            \
	{return((TIM8->SR & TIM_FLAG_UPDATE) != 0);}
inline void     spindleTmrClrIF()         {TIM8->SR = ~TIM_FLAG_UPDATE;}
inline void     spindleTmrStart()         {TIM8->CR1 |= TIM_CR1_CEN;}
inline void     spindleTmrPulse()         \
	{TIM8->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     spindleTmrStop()          \
	{TIM8->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     spindleTmrScl(uint16_t y) {TIM8->PSC = (y);}
inline uint16_t spindleTmrRead()          {return(TIM8->CNT);}
inline void     spindleTmrCntClr()        {TIM8->CNT = 0;}
inline void     spindleTmrCnt(uint16_t x) {TIM8->CNT = (x);}
inline void     spindleTmrMax(uint16_t x) {TIM8->ARR = ((x) - 1);}
inline void     spindleTmrSet(uint16_t x) {TIM8->ARR = (x);}
inline uint16_t spindleTmrMaxRead()       {return(TIM8->ARR);}

/* pwm 1 */

#define SPINDLE_TMR_PWM 1

inline void     spindleTmrCCR(uint16_t x) {TIM8->CCR1 = (x);}
inline void     spindleTmrPWMMode()       \
	{TIM8->CCMR1 = (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1);}
inline void     spindleTmrPWMEna()        \
	{spindleTmrBDTR(); TIM8->CCER |= TIM_CCER_CC1E;}
inline void     spindleTmrPWMDis()        {TIM8->CCER &= ~TIM_CCER_CC1E;}
inline uint16_t spindleTmrReadCCR()       {return(TIM8->CCR1);}
inline uint16_t spindleTmrReadCCMR()      {return(TIM8->CCMR1);}

/* pwmTmr timer 12 pwm 2 */

#define PWM_TIMER 12
#define PWM_TMR TIM12

#define pwmTmrISR(x) TIM8_BRK_TIM12_IRQHandler(x)

inline void pwmTmrInit() { \
	__HAL_RCC_TIM12_CLK_ENABLE(); \
	TIM12->CR1 |= TIM_CR1_DIR; \
	TIM12->CR1 &= ~TIM_CR1_CEN;}

inline void     pwmTmrClrIE()         {TIM12->DIER &= ~TIM_IT_UPDATE;}
inline void     pwmTmrSetIE()         {TIM12->DIER |= TIM_IT_UPDATE;}
inline uint16_t pwmTmrTstIE()         \
	{return((TIM12->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t pwmTmrIF()            \
	{return((TIM12->SR & TIM_FLAG_UPDATE) != 0);}
inline void     pwmTmrClrIF()         {TIM12->SR = ~TIM_FLAG_UPDATE;}
inline void     pwmTmrStart()         {TIM12->CR1 |= TIM_CR1_CEN;}
inline void     pwmTmrPulse()         \
	{TIM12->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     pwmTmrStop()          \
	{TIM12->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     pwmTmrScl(uint16_t y) {TIM12->PSC = (y);}
inline uint16_t pwmTmrRead()          {return(TIM12->CNT);}
inline void     pwmTmrCntClr()        {TIM12->CNT = 0;}
inline void     pwmTmrCnt(uint16_t x) {TIM12->CNT = (x);}
inline void     pwmTmrMax(uint16_t x) {TIM12->ARR = ((x) - 1);}
inline void     pwmTmrSet(uint16_t x) {TIM12->ARR = (x);}
inline uint16_t pwmTmrMaxRead()       {return(TIM12->ARR);}

/* pwm 2 */

#define PWM_TMR_PWM 2

inline void     pwmTmrCCR(uint16_t x) {TIM12->CCR2 = (x);}
inline void     pwmTmrPWMMode()       \
	{TIM12->CCMR1 = (TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1);}
inline void     pwmTmrPWMEna()        {TIM12->CCER |= TIM_CCER_CC2E;}
inline void     pwmTmrPWMDis()        {TIM12->CCER &= ~TIM_CCER_CC2E;}
inline uint16_t pwmTmrReadCCR()       {return(TIM12->CCR2);}
inline uint16_t pwmTmrReadCCMR()      {return(TIM12->CCMR1);}

/* usecTmr timer 6 */

#define USEC_TIMER 6
#define USEC_TMR TIM6

inline void usecTmrInit() { \
	__HAL_RCC_TIM6_CLK_ENABLE(); \
	TIM6->CR1 |= TIM_CR1_DIR; \
	TIM6->CR1 &= ~TIM_CR1_CEN;}

inline void     usecTmrClrIE()         {TIM6->DIER &= ~TIM_IT_UPDATE;}
inline void     usecTmrSetIE()         {TIM6->DIER |= TIM_IT_UPDATE;}
inline uint16_t usecTmrTstIE()         \
	{return((TIM6->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t usecTmrIF()            \
	{return((TIM6->SR & TIM_FLAG_UPDATE) != 0);}
inline void     usecTmrClrIF()         {TIM6->SR = ~TIM_FLAG_UPDATE;}
inline void     usecTmrStart()         {TIM6->CR1 |= TIM_CR1_CEN;}
inline void     usecTmrPulse()         \
	{TIM6->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     usecTmrStop()          \
	{TIM6->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     usecTmrScl(uint16_t y) {TIM6->PSC = (y);}
inline uint16_t usecTmrRead()          {return(TIM6->CNT);}
inline void     usecTmrCntClr()        {TIM6->CNT = 0;}
inline void     usecTmrCnt(uint16_t x) {TIM6->CNT = (x);}
inline void     usecTmrMax(uint16_t x) {TIM6->ARR = ((x) - 1);}
inline void     usecTmrSet(uint16_t x) {TIM6->ARR = (x);}
inline uint16_t usecTmrMaxRead()       {return(TIM6->ARR);}

/* indexTmr timer 16 */

#define INDEX_TIMER 16
#define INDEX_TMR TIM16

#define indexTmrISR(x) TIM16_IRQHandler(x)

inline void indexTmrInit() { \
	__HAL_RCC_TIM16_CLK_ENABLE(); \
	TIM16->CR1 |= TIM_CR1_DIR; \
	TIM16->CR1 &= ~TIM_CR1_CEN;}

inline void     indexTmrClrIE()         {TIM16->DIER &= ~TIM_IT_UPDATE;}
inline void     indexTmrSetIE()         {TIM16->DIER |= TIM_IT_UPDATE;}
inline uint16_t indexTmrTstIE()         \
	{return((TIM16->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t indexTmrIF()            \
	{return((TIM16->SR & TIM_FLAG_UPDATE) != 0);}
inline void     indexTmrClrIF()         {TIM16->SR = ~TIM_FLAG_UPDATE;}
inline void     indexTmrStart()         {TIM16->CR1 |= TIM_CR1_CEN;}
inline void     indexTmrPulse()         \
	{TIM16->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     indexTmrStop()          \
	{TIM16->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     indexTmrScl(uint16_t y) {TIM16->PSC = (y);}
inline uint16_t indexTmrRead()          {return(TIM16->CNT);}
inline void     indexTmrCntClr()        {TIM16->CNT = 0;}
inline void     indexTmrCnt(uint16_t x) {TIM16->CNT = (x);}
inline void     indexTmrMax(uint16_t x) {TIM16->ARR = ((x) - 1);}
inline void     indexTmrSet(uint16_t x) {TIM16->ARR = (x);}
inline uint16_t indexTmrMaxRead()       {return(TIM16->ARR);}

/* encTestTmr timer 7 */

#define ENCTEST_TIMER 7
#define ENCTEST_TMR TIM7

#define encTestTmrISR(x) TIM7_IRQHandler(x)

inline void encTestTmrInit() { \
	__HAL_RCC_TIM7_CLK_ENABLE(); \
	TIM7->CR1 |= TIM_CR1_DIR; \
	TIM7->CR1 &= ~TIM_CR1_CEN;}

inline void     encTestTmrClrIE()         {TIM7->DIER &= ~TIM_IT_UPDATE;}
inline void     encTestTmrSetIE()         {TIM7->DIER |= TIM_IT_UPDATE;}
inline uint16_t encTestTmrTstIE()         \
	{return((TIM7->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t encTestTmrIF()            \
	{return((TIM7->SR & TIM_FLAG_UPDATE) != 0);}
inline void     encTestTmrClrIF()         {TIM7->SR = ~TIM_FLAG_UPDATE;}
inline void     encTestTmrStart()         {TIM7->CR1 |= TIM_CR1_CEN;}
inline void     encTestTmrPulse()         \
	{TIM7->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     encTestTmrStop()          \
	{TIM7->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     encTestTmrScl(uint16_t y) {TIM7->PSC = (y);}
inline uint16_t encTestTmrRead()          {return(TIM7->CNT);}
inline void     encTestTmrCntClr()        {TIM7->CNT = 0;}
inline void     encTestTmrCnt(uint16_t x) {TIM7->CNT = (x);}
inline void     encTestTmrMax(uint16_t x) {TIM7->ARR = ((x) - 1);}
inline void     encTestTmrSet(uint16_t x) {TIM7->ARR = (x);}
inline uint16_t encTestTmrMaxRead()       {return(TIM7->ARR);}

/* intTmr timer 15 */

#define INT_TIMER 15
#define INT_TMR TIM15

#define intTmrISR(x) TIM15_IRQHandler(x)

inline void intTmrInit() { \
	__HAL_RCC_TIM15_CLK_ENABLE(); \
	TIM15->CR1 |= TIM_CR1_DIR; \
	TIM15->CR1 &= ~TIM_CR1_CEN;}

inline void     intTmrClrIE()         {TIM15->DIER &= ~TIM_IT_UPDATE;}
inline void     intTmrSetIE()         {TIM15->DIER |= TIM_IT_UPDATE;}
inline uint16_t intTmrTstIE()         \
	{return((TIM15->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t intTmrIF()            \
	{return((TIM15->SR & TIM_FLAG_UPDATE) != 0);}
inline void     intTmrClrIF()         {TIM15->SR = ~TIM_FLAG_UPDATE;}
inline void     intTmrStart()         {TIM15->CR1 |= TIM_CR1_CEN;}
inline void     intTmrPulse()         \
	{TIM15->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     intTmrStop()          \
	{TIM15->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     intTmrScl(uint16_t y) {TIM15->PSC = (y);}
inline uint16_t intTmrRead()          {return(TIM15->CNT);}
inline void     intTmrCntClr()        {TIM15->CNT = 0;}
inline void     intTmrCnt(uint16_t x) {TIM15->CNT = (x);}
inline void     intTmrMax(uint16_t x) {TIM15->ARR = ((x) - 1);}
inline void     intTmrSet(uint16_t x) {TIM15->ARR = (x);}
inline uint16_t intTmrMaxRead()       {return(TIM15->ARR);}

/* cmpTmr timer 17 */

#define CMP_TIMER 17
#define CMP_TMR TIM17

#define cmpTmrISR(x) TIM17_IRQHandler(x)

inline void cmpTmrInit() { \
	__HAL_RCC_TIM17_CLK_ENABLE(); \
	TIM17->CR1 |= TIM_CR1_DIR; \
	TIM17->CR1 &= ~TIM_CR1_CEN;}

inline void     cmpTmrClrIE()         {TIM17->DIER &= ~TIM_IT_UPDATE;}
inline void     cmpTmrSetIE()         {TIM17->DIER |= TIM_IT_UPDATE;}
inline uint16_t cmpTmrTstIE()         \
	{return((TIM17->DIER & TIM_IT_UPDATE) != 0);}
inline uint16_t cmpTmrIF()            \
	{return((TIM17->SR & TIM_FLAG_UPDATE) != 0);}
inline void     cmpTmrClrIF()         {TIM17->SR = ~TIM_FLAG_UPDATE;}
inline void     cmpTmrStart()         {TIM17->CR1 |= TIM_CR1_CEN;}
inline void     cmpTmrPulse()         \
	{TIM17->CR1 |= (TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     cmpTmrStop()          \
	{TIM17->CR1 &= ~(TIM_CR1_OPM | TIM_CR1_CEN);}
inline void     cmpTmrScl(uint16_t y) {TIM17->PSC = (y);}
inline uint16_t cmpTmrRead()          {return(TIM17->CNT);}
inline void     cmpTmrCntClr()        {TIM17->CNT = 0;}
inline void     cmpTmrCnt(uint16_t x) {TIM17->CNT = (x);}
inline void     cmpTmrMax(uint16_t x) {TIM17->ARR = ((x) - 1);}
inline void     cmpTmrSet(uint16_t x) {TIM17->ARR = (x);}
inline uint16_t cmpTmrMaxRead()       {return(TIM17->ARR);}

inline void     cmpTmrCap1EnaSet() {TIM17->CCER |= TIM_CCER_CC1E;}
inline void     cmpTmrCap1SetIE()  {TIM17->DIER |= TIM_DIER_CC1IE;}
inline void     cmpTmrCap1ClrIE()  {TIM17->DIER &= ~TIM_DIER_CC1IE;}
inline uint16_t cmpTmrCap1IF()     {return((TIM17->SR & TIM_SR_CC1IF) != 0);}
inline void     cmpTmrCap1ClrIF()  {TIM17->SR &= ~TIM_SR_CC1IF;}
inline uint16_t cmpTmrCap1()       {return(TIM17->CCR1);}
inline void     cmpTmrCap2EnaSet() {TIM17->CCER |= TIM_CCER_CC2E;}
inline void     cmpTmrCap2SetIE()  {TIM17->DIER |= TIM_DIER_CC2IE;}
inline void     cmpTmrCap2ClrIE()  {TIM17->DIER &= ~TIM_DIER_CC2IE;}
inline uint16_t cmpTmrCap2IF()     {return((TIM17->SR & TIM_SR_CC1IF) != 0);}
inline void     cmpTmrCap2ClrIF()  {TIM17->SR &= ~TIM_SR_CC1IF;}
inline uint16_t cmpTmrCap2()       {return(TIM17->CCR2);}
inline void     cmpTmrOCP1Clr()    {TIM17->SR &= ~TIM_SR_CC1OF;}
inline void     cmpTmrOCP2Clr()    {TIM17->SR &= ~TIM_SR_CC2OF;}

#endif /* __TIMERS_H */
#endif /* __STM32F4xx_HAL_H */
