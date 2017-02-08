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
P 8050 3500
F 0 "IC?" H 8050 4150 60  0000 C CNN
F 1 "MAX7219" H 8050 2750 60  0000 C CNN
F 2 "" H 8050 2550 60  0000 C CNN
F 3 "" H 8050 2550 60  0000 C CNN
	1    8050 3500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 58949722
P 6950 4050
F 0 "#PWR?" H 6950 3800 50  0001 C CNN
F 1 "GND" H 6950 3900 50  0000 C CNN
F 2 "" H 6950 4050 50  0000 C CNN
F 3 "" H 6950 4050 50  0000 C CNN
	1    6950 4050
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 58949C37
P 9350 3500
F 0 "#PWR?" H 9350 3350 50  0001 C CNN
F 1 "VCC" H 9350 3650 50  0000 C CNN
F 2 "" H 9350 3500 50  0000 C CNN
F 3 "" H 9350 3500 50  0000 C CNN
	1    9350 3500
	1    0    0    -1  
$EndComp
$Comp
L R_Small R?
U 1 1 5894A0C7
P 8650 3600
F 0 "R?" V 8600 3400 50  0000 L CNN
F 1 "47K" V 8700 3350 50  0000 L CNN
F 2 "" H 8650 3600 50  0000 C CNN
F 3 "" H 8650 3600 50  0000 C CNN
	1    8650 3600
	0    -1   -1   0   
$EndComp
$Comp
L 7segsCAx4 AFF?
U 1 1 58971BE8
P 8050 5350
F 0 "AFF?" H 8900 5950 50  0000 C CNN
F 1 "7segsCAx4" H 7300 5950 50  0000 C CNN
F 2 "" H 7550 5350 50  0000 C CNN
F 3 "" H 7550 5350 50  0000 C CNN
	1    8050 5350
	1    0    0    -1  
$EndComp
Text GLabel 7550 4000 0    60   Input ~ 0
C1_P1
Text GLabel 7550 3900 0    60   Input ~ 0
C1_P2
Text GLabel 7550 3100 0    60   Input ~ 0
C1_P7
Text GLabel 7550 3700 0    60   Input ~ 0
C1_P3
Text GLabel 7550 3600 0    60   Input ~ 0
C1_P4
Text GLabel 7550 3500 0    60   Input ~ 0
C1_P5
Text GLabel 7550 3400 0    60   Input ~ 0
C1_P11
Text GLabel 7550 3200 0    60   Input ~ 0
C1_P10
Text GLabel 8300 4650 2    60   Input ~ 0
C1_P7
Text GLabel 8000 4550 2    60   Input ~ 0
C1_P10
Text GLabel 7900 4550 0    60   Input ~ 0
C1_P11
Text GLabel 8200 6050 3    60   Input ~ 0
C1_P5
Text GLabel 8100 6050 3    60   Input ~ 0
C1_P4
Text GLabel 8000 6050 3    60   Input ~ 0
C1_P3
Text GLabel 7900 6050 3    60   Input ~ 0
C1_P2
Text GLabel 7800 6050 3    60   Input ~ 0
C1_P1
$Comp
L 7segsCAx4 AFF?
U 1 1 5899D000
P 8050 1650
F 0 "AFF?" H 8900 2250 50  0000 C CNN
F 1 "7segsCAx4" H 7300 2250 50  0000 C CNN
F 2 "" H 7550 1650 50  0000 C CNN
F 3 "" H 7550 1650 50  0000 C CNN
	1    8050 1650
	1    0    0    -1  
$EndComp
Text GLabel 8300 950  2    60   Input ~ 0
C1_P7
Text GLabel 8000 850  2    60   Input ~ 0
C1_P10
Text GLabel 7900 850  0    60   Input ~ 0
C1_P11
Text GLabel 8200 2350 3    60   Input ~ 0
C1_P5
Text GLabel 8100 2350 3    60   Input ~ 0
C1_P4
Text GLabel 8000 2350 3    60   Input ~ 0
C1_P3
Text GLabel 7900 2350 3    60   Input ~ 0
C1_P2
Text GLabel 7800 2350 3    60   Input ~ 0
C1_P1
Wire Wire Line
	8550 4000 9250 4000
Wire Wire Line
	9250 6200 8300 6200
Wire Wire Line
	8300 6200 8300 6050
Wire Wire Line
	8550 3900 9150 3900
Wire Wire Line
	9150 3900 9150 4350
Wire Wire Line
	9150 4350 7800 4350
Wire Wire Line
	8100 4400 9050 4400
Wire Wire Line
	9050 4400 9050 3800
Wire Wire Line
	9050 3800 8550 3800
Wire Wire Line
	8200 4450 8950 4450
Wire Wire Line
	8950 4450 8950 3700
Wire Wire Line
	8950 3700 8550 3700
Wire Wire Line
	8550 3400 8950 3400
Wire Wire Line
	8950 3400 8950 2450
Wire Wire Line
	8950 2450 8300 2450
Wire Wire Line
	8300 2450 8300 2350
Wire Wire Line
	8550 3300 9550 3300
Wire Wire Line
	9550 3300 9550 650 
Wire Wire Line
	9550 650  7800 650 
Wire Wire Line
	7800 650  7800 950 
Wire Wire Line
	8550 3200 9450 3200
Wire Wire Line
	9450 3200 9450 700 
Wire Wire Line
	9450 700  8100 700 
Wire Wire Line
	8100 700  8100 950 
Wire Wire Line
	8550 3100 9350 3100
Wire Wire Line
	9350 3100 9350 750 
Wire Wire Line
	9350 750  8200 750 
Wire Wire Line
	8200 750  8200 950 
Wire Wire Line
	7550 3800 6950 3800
Wire Wire Line
	6950 3300 6950 3800
Wire Wire Line
	6950 3800 6950 4050
Wire Wire Line
	7550 3300 6950 3300
Connection ~ 6950 3800
Wire Wire Line
	8550 3500 9350 3500
Wire Wire Line
	8750 3600 9350 3600
Wire Wire Line
	9350 3600 9350 3500
Wire Wire Line
	7900 4550 7900 4650
Wire Wire Line
	8000 4550 8000 4650
Wire Wire Line
	9250 4000 9250 6200
Wire Wire Line
	8200 4650 8200 4450
Wire Wire Line
	8100 4650 8100 4400
Wire Wire Line
	7800 4350 7800 4650
Wire Wire Line
	8000 950  8000 850 
Wire Wire Line
	7900 950  7900 850 
$Comp
L MAX7219 IC?
U 1 1 5899E3D1
P 1950 3500
F 0 "IC?" H 1950 4150 60  0000 C CNN
F 1 "MAX7219" H 1950 2750 60  0000 C CNN
F 2 "" H 1950 2550 60  0000 C CNN
F 3 "" H 1950 2550 60  0000 C CNN
	1    1950 3500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5899E3D7
P 850 4050
F 0 "#PWR?" H 850 3800 50  0001 C CNN
F 1 "GND" H 850 3900 50  0000 C CNN
F 2 "" H 850 4050 50  0000 C CNN
F 3 "" H 850 4050 50  0000 C CNN
	1    850  4050
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 5899E3DD
P 3250 3500
F 0 "#PWR?" H 3250 3350 50  0001 C CNN
F 1 "VCC" H 3250 3650 50  0000 C CNN
F 2 "" H 3250 3500 50  0000 C CNN
F 3 "" H 3250 3500 50  0000 C CNN
	1    3250 3500
	1    0    0    -1  
$EndComp
$Comp
L R_Small R?
U 1 1 5899E3E3
P 2550 3600
F 0 "R?" V 2500 3400 50  0000 L CNN
F 1 "47K" V 2600 3350 50  0000 L CNN
F 2 "" H 2550 3600 50  0000 C CNN
F 3 "" H 2550 3600 50  0000 C CNN
	1    2550 3600
	0    -1   -1   0   
$EndComp
$Comp
L 7segsCAx4 AFF?
U 1 1 5899E3E9
P 1950 5350
F 0 "AFF?" H 2800 5950 50  0000 C CNN
F 1 "7segsCAx4" H 1200 5950 50  0000 C CNN
F 2 "" H 1450 5350 50  0000 C CNN
F 3 "" H 1450 5350 50  0000 C CNN
	1    1950 5350
	1    0    0    -1  
$EndComp
Text GLabel 1450 4000 0    60   Input ~ 0
C1_P1
Text GLabel 1450 3900 0    60   Input ~ 0
C1_P2
Text GLabel 1450 3100 0    60   Input ~ 0
C1_P7
Text GLabel 1450 3700 0    60   Input ~ 0
C1_P3
Text GLabel 1450 3600 0    60   Input ~ 0
C1_P4
Text GLabel 1450 3500 0    60   Input ~ 0
C1_P5
Text GLabel 1450 3400 0    60   Input ~ 0
C1_P11
Text GLabel 1450 3200 0    60   Input ~ 0
C1_P10
Text GLabel 2200 4650 2    60   Input ~ 0
C1_P7
Text GLabel 1900 4550 2    60   Input ~ 0
C1_P10
Text GLabel 1800 4550 0    60   Input ~ 0
C1_P11
Text GLabel 2100 6050 3    60   Input ~ 0
C1_P5
Text GLabel 2000 6050 3    60   Input ~ 0
C1_P4
Text GLabel 1900 6050 3    60   Input ~ 0
C1_P3
Text GLabel 1800 6050 3    60   Input ~ 0
C1_P2
Text GLabel 1700 6050 3    60   Input ~ 0
C1_P1
$Comp
L 7segsCAx4 AFF?
U 1 1 5899E3FF
P 1950 1650
F 0 "AFF?" H 2800 2250 50  0000 C CNN
F 1 "7segsCAx4" H 1200 2250 50  0000 C CNN
F 2 "" H 1450 1650 50  0000 C CNN
F 3 "" H 1450 1650 50  0000 C CNN
	1    1950 1650
	1    0    0    -1  
$EndComp
Text GLabel 2200 950  2    60   Input ~ 0
C1_P7
Text GLabel 1900 850  2    60   Input ~ 0
C1_P10
Text GLabel 1800 850  0    60   Input ~ 0
C1_P11
Text GLabel 2100 2350 3    60   Input ~ 0
C1_P5
Text GLabel 2000 2350 3    60   Input ~ 0
C1_P4
Text GLabel 1900 2350 3    60   Input ~ 0
C1_P3
Text GLabel 1800 2350 3    60   Input ~ 0
C1_P2
Text GLabel 1700 2350 3    60   Input ~ 0
C1_P1
Wire Wire Line
	2450 4000 3150 4000
Wire Wire Line
	3150 6200 2200 6200
Wire Wire Line
	2200 6200 2200 6050
Wire Wire Line
	2450 3900 3050 3900
Wire Wire Line
	3050 3900 3050 4350
Wire Wire Line
	3050 4350 1700 4350
Wire Wire Line
	2000 4400 2950 4400
Wire Wire Line
	2950 4400 2950 3800
Wire Wire Line
	2950 3800 2450 3800
Wire Wire Line
	2100 4450 2850 4450
Wire Wire Line
	2850 4450 2850 3700
Wire Wire Line
	2850 3700 2450 3700
Wire Wire Line
	2450 3400 2850 3400
Wire Wire Line
	2850 3400 2850 2450
Wire Wire Line
	2850 2450 2200 2450
Wire Wire Line
	2200 2450 2200 2350
Wire Wire Line
	2450 3300 3450 3300
Wire Wire Line
	3450 3300 3450 650 
Wire Wire Line
	3450 650  1700 650 
Wire Wire Line
	1700 650  1700 950 
Wire Wire Line
	2450 3200 3350 3200
Wire Wire Line
	3350 3200 3350 700 
Wire Wire Line
	3350 700  2000 700 
Wire Wire Line
	2000 700  2000 950 
Wire Wire Line
	2450 3100 3250 3100
Wire Wire Line
	3250 3100 3250 750 
Wire Wire Line
	3250 750  2100 750 
Wire Wire Line
	2100 750  2100 950 
Wire Wire Line
	1450 3800 850  3800
Wire Wire Line
	850  3300 850  3800
Wire Wire Line
	850  3800 850  4050
Wire Wire Line
	1450 3300 850  3300
Connection ~ 850  3800
Wire Wire Line
	2450 3500 3250 3500
Wire Wire Line
	2650 3600 3250 3600
Wire Wire Line
	3250 3600 3250 3500
Wire Wire Line
	1800 4550 1800 4650
Wire Wire Line
	1900 4550 1900 4650
Wire Wire Line
	3150 4000 3150 6200
Wire Wire Line
	2100 4650 2100 4450
Wire Wire Line
	2000 4650 2000 4400
Wire Wire Line
	1700 4350 1700 4650
Wire Wire Line
	1900 950  1900 850 
Wire Wire Line
	1800 950  1800 850 
$Comp
L MAX7219 IC?
U 1 1 5899E545
P 5050 3500
F 0 "IC?" H 5050 4150 60  0000 C CNN
F 1 "MAX7219" H 5050 2750 60  0000 C CNN
F 2 "" H 5050 2550 60  0000 C CNN
F 3 "" H 5050 2550 60  0000 C CNN
	1    5050 3500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5899E54B
P 3950 4050
F 0 "#PWR?" H 3950 3800 50  0001 C CNN
F 1 "GND" H 3950 3900 50  0000 C CNN
F 2 "" H 3950 4050 50  0000 C CNN
F 3 "" H 3950 4050 50  0000 C CNN
	1    3950 4050
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 5899E551
P 6350 3500
F 0 "#PWR?" H 6350 3350 50  0001 C CNN
F 1 "VCC" H 6350 3650 50  0000 C CNN
F 2 "" H 6350 3500 50  0000 C CNN
F 3 "" H 6350 3500 50  0000 C CNN
	1    6350 3500
	1    0    0    -1  
$EndComp
$Comp
L R_Small R?
U 1 1 5899E557
P 5650 3600
F 0 "R?" V 5600 3400 50  0000 L CNN
F 1 "47K" V 5700 3350 50  0000 L CNN
F 2 "" H 5650 3600 50  0000 C CNN
F 3 "" H 5650 3600 50  0000 C CNN
	1    5650 3600
	0    -1   -1   0   
$EndComp
$Comp
L 7segsCAx4 AFF?
U 1 1 5899E55D
P 5050 5350
F 0 "AFF?" H 5900 5950 50  0000 C CNN
F 1 "7segsCAx4" H 4300 5950 50  0000 C CNN
F 2 "" H 4550 5350 50  0000 C CNN
F 3 "" H 4550 5350 50  0000 C CNN
	1    5050 5350
	1    0    0    -1  
$EndComp
Text GLabel 4550 4000 0    60   Input ~ 0
C1_P1
Text GLabel 4550 3900 0    60   Input ~ 0
C1_P2
Text GLabel 4550 3100 0    60   Input ~ 0
C1_P7
Text GLabel 4550 3700 0    60   Input ~ 0
C1_P3
Text GLabel 4550 3600 0    60   Input ~ 0
C1_P4
Text GLabel 4550 3500 0    60   Input ~ 0
C1_P5
Text GLabel 4550 3400 0    60   Input ~ 0
C1_P11
Text GLabel 4550 3200 0    60   Input ~ 0
C1_P10
Text GLabel 5300 4650 2    60   Input ~ 0
C1_P7
Text GLabel 5000 4550 2    60   Input ~ 0
C1_P10
Text GLabel 4900 4550 0    60   Input ~ 0
C1_P11
Text GLabel 5200 6050 3    60   Input ~ 0
C1_P5
Text GLabel 5100 6050 3    60   Input ~ 0
C1_P4
Text GLabel 5000 6050 3    60   Input ~ 0
C1_P3
Text GLabel 4900 6050 3    60   Input ~ 0
C1_P2
Text GLabel 4800 6050 3    60   Input ~ 0
C1_P1
$Comp
L 7segsCAx4 AFF?
U 1 1 5899E573
P 5050 1650
F 0 "AFF?" H 5900 2250 50  0000 C CNN
F 1 "7segsCAx4" H 4300 2250 50  0000 C CNN
F 2 "" H 4550 1650 50  0000 C CNN
F 3 "" H 4550 1650 50  0000 C CNN
	1    5050 1650
	1    0    0    -1  
$EndComp
Text GLabel 5300 950  2    60   Input ~ 0
C1_P7
Text GLabel 5000 850  2    60   Input ~ 0
C1_P10
Text GLabel 4900 850  0    60   Input ~ 0
C1_P11
Text GLabel 5200 2350 3    60   Input ~ 0
C1_P5
Text GLabel 5100 2350 3    60   Input ~ 0
C1_P4
Text GLabel 5000 2350 3    60   Input ~ 0
C1_P3
Text GLabel 4900 2350 3    60   Input ~ 0
C1_P2
Text GLabel 4800 2350 3    60   Input ~ 0
C1_P1
Wire Wire Line
	5550 4000 6250 4000
Wire Wire Line
	6250 6200 5300 6200
Wire Wire Line
	5300 6200 5300 6050
Wire Wire Line
	5550 3900 6150 3900
Wire Wire Line
	6150 3900 6150 4350
Wire Wire Line
	6150 4350 4800 4350
Wire Wire Line
	5100 4400 6050 4400
Wire Wire Line
	6050 4400 6050 3800
Wire Wire Line
	6050 3800 5550 3800
Wire Wire Line
	5200 4450 5950 4450
Wire Wire Line
	5950 4450 5950 3700
Wire Wire Line
	5950 3700 5550 3700
Wire Wire Line
	5550 3400 5950 3400
Wire Wire Line
	5950 3400 5950 2450
Wire Wire Line
	5950 2450 5300 2450
Wire Wire Line
	5300 2450 5300 2350
Wire Wire Line
	5550 3300 6550 3300
Wire Wire Line
	6550 3300 6550 650 
Wire Wire Line
	6550 650  4800 650 
Wire Wire Line
	4800 650  4800 950 
Wire Wire Line
	5550 3200 6450 3200
Wire Wire Line
	6450 3200 6450 700 
Wire Wire Line
	6450 700  5100 700 
Wire Wire Line
	5100 700  5100 950 
Wire Wire Line
	5550 3100 6350 3100
Wire Wire Line
	6350 3100 6350 750 
Wire Wire Line
	6350 750  5200 750 
Wire Wire Line
	5200 750  5200 950 
Wire Wire Line
	4550 3800 3950 3800
Wire Wire Line
	3950 3300 3950 3800
Wire Wire Line
	3950 3800 3950 4050
Wire Wire Line
	4550 3300 3950 3300
Connection ~ 3950 3800
Wire Wire Line
	5550 3500 6350 3500
Wire Wire Line
	5750 3600 6350 3600
Wire Wire Line
	6350 3600 6350 3500
Wire Wire Line
	4900 4550 4900 4650
Wire Wire Line
	5000 4550 5000 4650
Wire Wire Line
	6250 4000 6250 6200
Wire Wire Line
	5200 4650 5200 4450
Wire Wire Line
	5100 4650 5100 4400
Wire Wire Line
	4800 4350 4800 4650
Wire Wire Line
	5000 950  5000 850 
Wire Wire Line
	4900 950  4900 850 
$EndSCHEMATC
