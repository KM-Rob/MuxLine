#include "MuxLine.h"

MuxLine::begin(int Lines, int IN, int A, int B, int C, int max, int delau)
{
	num = Lines;
	lmax = max;
	del = delau;
	for(int i=0; i<num; i++)
		mux[i].begin(IN+i, A, B, C, max, delau);
}

MuxLine::Reset(void)
{
	in_NO = 0;
	in_L = 0;
	for(int i=0; i<num; i++)
		mux[i].Reset();
}

int MuxLine::readStep(void)
{
	mux[in_L].set_out(in_NO++);
	if(in_NO==lmax)
	{
		in_NO =0;
		in_L++;
	}
	if(in_L==num) in_L = 0;
	delay(del);
	return mux[in_L].readStep();
	
}