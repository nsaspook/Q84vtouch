

/*
 * This program converts the rs-232 output from a carroltouch ELO 1939 touch-screen
 * to a format that can be used with the Varian Viision 80 Implanter
 * The LCD controller must be first programmed to the correct emulation
 *
 * Fred Brooks, Microchip Inc 2007
 * Version 1.02 COMM port and IRQ fixes Sept 7, 2011
 * Version 1.03 for the 45K80 chip and 1939L screen 2/12/2013
 *
 *
 * This application is designed for use with the
 * Oricom BOT40-II board, and the PIC18F45K80 device with cap on pin 6 for Vcore
 * regulator. 
 * requires a 9 pin male null-modem cable to connect the LCD serial to the
 * controller serial port, light-link host port is connected to TX2 pin 29
 */
