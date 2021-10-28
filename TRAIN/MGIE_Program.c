#include "LBIT_MATH.H"
#include "LSTD_TYPES.H"


#include  "MGIE_Private.h"
#include  "MGIE_Interface.h"


void MGIE_VidEnableGIE()
{
	SET_BIT(SREG,7);
}

void MGIE_VidDisableGIE()
{
	CLEAR_BIT(SREG,7);
}
