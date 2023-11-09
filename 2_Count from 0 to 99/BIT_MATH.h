#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SETBIT(VAR,BITNUM)          VAR|=(1<<BITNUM)
#define CLRBIT(VAR,BITNUM)          VAR&=~(1<<BITNUM)
#define TOGGLEBIT(VAR,BITNUM)       VAR^=(1<<BITNUM)
#define GETBIT(VAR,BITNUM)          ((VAR>>BITNUM)&1)












#endif
