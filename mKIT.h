/* 
 * File:   mKIT.h
 * Author: hossa
 *
 * Created on November 26, 2021, 10:43 AM
 */

#ifndef MKIT_H
#define	MKIT_H

#define LED0  2
#define LED1  7
#define LED2  3

#define RELAY  2
#define BUZZER 3

#define BTN0   0
#define BTN1   6
#define BTN2   2



void initLEDS();

void LED0_ON();
void LED0_OFF();
void LED0_Toggle();

void LED1_ON();
void LED1_OFF();

void LED2_ON();
void LED2_OFF();

int checkLED(int LED_No);

void init_Relay();
void Relay_ON();
void Relay_OFF();

void init_Buzzer();
void Buzzer_ON();
void Buzzer_OFF();


void init_BTNs();
int isPressed(int ButtonNumber);

#endif	/* MKIT_H */

