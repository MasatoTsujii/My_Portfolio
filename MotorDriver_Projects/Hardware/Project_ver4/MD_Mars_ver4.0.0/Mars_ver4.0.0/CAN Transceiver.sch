EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
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
L Interface_CAN_LIN:MCP2562-E-SN U2
U 1 1 60736529
P 5400 3850
F 0 "U2" H 5400 4431 50  0000 C CNN
F 1 "MCP2562-E-SN" H 5400 4340 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5400 3350 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/25167A.pdf" H 5400 3850 50  0001 C CNN
	1    5400 3850
	1    0    0    -1  
$EndComp
Text HLabel 4600 3650 0    50   Input ~ 0
TXD
Text HLabel 4600 3750 0    50   Output ~ 0
RXD
Wire Wire Line
	4600 3650 4900 3650
Wire Wire Line
	4900 3750 4600 3750
$Comp
L power:+5V #PWR0101
U 1 1 6073743A
P 5400 3200
F 0 "#PWR0101" H 5400 3050 50  0001 C CNN
F 1 "+5V" H 5415 3373 50  0000 C CNN
F 2 "" H 5400 3200 50  0001 C CNN
F 3 "" H 5400 3200 50  0001 C CNN
	1    5400 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3200 5400 3450
$Comp
L power:+3.3V #PWR0102
U 1 1 60737F9F
P 4250 3750
F 0 "#PWR0102" H 4250 3600 50  0001 C CNN
F 1 "+3.3V" H 4265 3923 50  0000 C CNN
F 2 "" H 4250 3750 50  0001 C CNN
F 3 "" H 4250 3750 50  0001 C CNN
	1    4250 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3750 4250 3950
Wire Wire Line
	4250 3950 4900 3950
$Comp
L power:GNDD #PWR0103
U 1 1 60739F9A
P 5400 4250
F 0 "#PWR0103" H 5400 4000 50  0001 C CNN
F 1 "GNDD" H 5404 4095 50  0000 C CNN
F 2 "" H 5400 4250 50  0001 C CNN
F 3 "" H 5400 4250 50  0001 C CNN
	1    5400 4250
	1    0    0    -1  
$EndComp
$EndSCHEMATC
