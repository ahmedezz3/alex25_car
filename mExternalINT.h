/* 
 * File:   mExternalINT.h
 * Author: hossa
 *
 * Created on December 4, 2021, 12:41 PM
 */

#ifndef MEXTERNALINT_H
#define	MEXTERNALINT_H


#define RisingMode             3
#define FallingMode            2
#define AnyChangeMode          1
#define LowLevelMode           0

void init_INT(char INT_no, unsigned char senseMode);


#endif	/* MEXTERNALINT_H */

