#include "Timers.h"
 	
void InitTimers(void)
{
    TCCR1A = 0x00;
	TCCR1B = (1<<CS12) | (1<<CS10); // Clock div by 1024: 128us per tick
}

uint16_t CurrentTime(void)
{
	return TCNT1;
}

uint16_t GetSpanUs(Timer * t)
{
	uint32_t time = CurrentTime();
	uint32_t span = time - t->startTime;
	return span;
}

void StartTimer(Timer * t)
{
	t->startTime = CurrentTime();
}
