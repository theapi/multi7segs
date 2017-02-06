EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:theapi
LIBS:multi7segs-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MAX7219 IC?
U 1 1 5894904D
P 3550 4700
F 0 "IC?" H 3550 5400 60  0000 C CNN
F 1 "MAX7219" H 3550 3950 60  0000 C CNN
F 2 "" H 3550 3750 60  0000 C CNN
F 3 "" H 3550 3750 60  0000 C CNN
	1    3550 4700
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 58949722
P 6750 2200
F 0 "#PWR?" H 6750 1950 50  0001 C CNN
F 1 "GND" H 6750 2050 50  0000 C CNN
F 2 "" H 6750 2200 50  0000 C CNN
F 3 "" H 6750 2200 50  0000 C CNN
	1    6750 2200
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 58949C24
P 6550 2550
F 0 "#PWR?" H 6550 2300 50  0001 C CNN
F 1 "GND" H 6550 2400 50  0000 C CNN
F 2 "" H 6550 2550 50  0000 C CNN
F 3 "" H 6550 2550 50  0000 C CNN
	1    6550 2550
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR?
U 1 1 58949C37
P 6300 1650
F 0 "#PWR?" H 6300 1500 50  0001 C CNN
F 1 "VCC" H 6300 1800 50  0000 C CNN
F 2 "" H 6300 1650 50  0000 C CNN
F 3 "" H 6300 1650 50  0000 C CNN
	1    6300 1650
	-1   0    0    1   
$EndComp
$Comp
L R_Small R?
U 1 1 5894A0C7
P 3450 5300
F 0 "R?" H 3400 5150 50  0000 L CNN
F 1 "47K" H 3400 5050 50  0000 L CNN
F 2 "" H 3450 5300 50  0000 C CNN
F 3 "" H 3450 5300 50  0000 C CNN
	1    3450 5300
	1    0    0    -1  
$EndComp
$Comp
L 7segsCAx4 AFF?
U 1 1 58971BE8
P 3300 2700
F 0 "AFF?" H 4150 3300 50  0000 C CNN
F 1 "7segsCAx4" H 2550 3300 50  0000 C CNN
F 2 "" H 2800 2700 50  0000 C CNN
F 3 "" H 2800 2700 50  0000 C CNN
	1    3300 2700
	1    0    0    -1  
$EndComp
Text GLabel 3050 4200 1    60   Input ~ 0
C1_P1
Text GLabel 3150 4200 1    60   Input ~ 0
C1_P2
Text GLabel 3950 4200 1    60   Input ~ 0
C1_P7
Text GLabel 3350 4200 1    60   Input ~ 0
C1_P3
Text GLabel 3450 4200 1    60   Input ~ 0
C1_P4
Text GLabel 3550 4200 1    60   Input ~ 0
C1_P5
Text GLabel 3650 4200 1    60   Input ~ 0
C1_P11
Text GLabel 3850 4200 1    60   Input ~ 0
C1_P10
Text GLabel 3550 2000 1    60   Input ~ 0
C1_P7
Text GLabel 3250 2000 1    60   Input ~ 0
C1_P10
Text GLabel 3150 2000 1    60   Input ~ 0
C1_P11
Text GLabel 3450 3400 3    60   Input ~ 0
C1_P5
Text GLabel 3350 3400 3    60   Input ~ 0
C1_P4
Text GLabel 3250 3400 3    60   Input ~ 0
C1_P3
Text GLabel 3150 3400 3    60   Input ~ 0
C1_P2
Text GLabel 3050 3400 3    60   Input ~ 0
C1_P1
Text GLabel 3550 3400 3    60   Input ~ 0
C1_P6
Text GLabel 3450 2000 1    60   Input ~ 0
C1_P8
Text GLabel 3350 2000 1    60   Input ~ 0
C1_P9
Text GLabel 3050 2000 1    60   Input ~ 0
C1_P12
Text GLabel 3050 5200 3    60   Input ~ 0
C1_P6
Text GLabel 3150 5200 3    60   Input ~ 0
C1_P12
Text GLabel 3250 5200 3    60   Input ~ 0
C1_P9
Text GLabel 3350 5200 3    60   Input ~ 0
C1_P8
$EndSCHEMATC
