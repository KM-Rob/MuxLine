#include "MuxLine.h"

MuxLine::begin(int Lines, int IN, int A, int B, int C, int max, int delau)
{
	num = Lines;
	lmax = max;
	del = delau;
	
	for(int i=0; i<num; i++)
		mux[i].begin(IN+i, A, B, C, max, delau);
	
	Reset();
}

MuxLine::Reset(void)
{
	for(int i=0; i<num; i++)
		mux[i].Reset();
	in_NO = 0;
	in_L = 0;
	
}

uint16_t MuxLine::readStep(void)
{
	uint16_t analog;
	mux[in_L].set_out(in_NO);
	delay(del);
	in_NO++;
	analog = mux[in_L].readStep1();
	
	if(in_NO==lmax)
	{
		in_NO =0;
		in_L++;
	}
	if(in_L==num) in_L = 0;
	
	return analog;
}