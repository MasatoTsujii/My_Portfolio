EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4100 3000 0    50   Input ~ 0
motor_PWMH_IN
Text HLabel 4100 3100 0    50   Input ~ 0
motor_PWML_IN
Text HLabel 4100 3200 0    50   Input ~ 0
motor_PHASE_IN
Text HLabel 4100 3300 0    50   Input ~ 0
motor_SR_IN
Text HLabel 6000 3000 2    50   Output ~ 0
motor_PWMH_OUT
Text HLabel 6000 3100 2    50   Output ~ 0
motor_PWML_OUT
Text HLabel 6000 3200 2    50   Output ~ 0
motor_PHASE_OUT
Text HLabel 6000 3300 2    50   Output ~ 0
motor_SR_OUT
Wire Wire Line
	5700 3300 6000 3300
Wire Wire Line
	5700 3200 6000 3200
Wire Wire Line
	5700 3100 6000 3100
Wire Wire Line
	5700 3000 6000 3000
$Comp
L power:+3.3V #PWR?
U 1 1 60783643
P 4100 2400
F 0 "#PWR?" H 4100 2250 50  0001 C CNN
F 1 "+3.3V" H 4115 2573 50  0000 C CNN
F 2 "" H 4100 2400 50  0001 C CNN
F 3 "" H 4100 2400 50  0001 C CNN
	1    4100 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60789AAC
P 5700 2900
F 0 "#PWR?" H 5700 2650 50  0001 C CNN
F 1 "GND" H 5705 2727 50  0000 C CNN
F 2 "" H 5700 2900 50  0001 C CNN
F 3 "" H 5700 2900 50  0001 C CNN
	1    5700 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6078AE1A
P 5700 3500
F 0 "#PWR?" H 5700 3250 50  0001 C CNN
F 1 "GND" H 5705 3327 50  0000 C CNN
F 2 "" H 5700 3500 50  0001 C CNN
F 3 "" H 5700 3500 50  0001 C CNN
	1    5700 3500
	1    0    0    -1  
$EndComp
$Comp
L myLibrary:C_1608 C?
U 1 1 6083B3FA
P 4100 2550
F 0 "C?" H 4215 2596 50  0000 L CNN
F 1 "0.1u" H 4215 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4250 2600 50  0001 C CNN
F 3 "" H 4250 2600 50  0001 C CNN
	1    4100 2550
	1    0    0    -1  
$EndComp
$Comp
L myLibrary:C_1608 C?
U 1 1 615D98DB
P 6000 2550
F 0 "C?" H 6115 2596 50  0000 L CNN
F 1 "0.1u" H 6115 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6150 2600 50  0001 C CNN
F 3 "" H 6150 2600 50  0001 C CNN
	1    6000 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 2800 5850 2800
$Comp
L power:GND #PWR?
U 1 1 615DA6FF
P 6000 2700
F 0 "#PWR?" H 6000 2450 50  0001 C CNN
F 1 "GND" H 6005 2527 50  0000 C CNN
F 2 "" H 6000 2700 50  0001 C CNN
F 3 "" H 6000 2700 50  0001 C CNN
	1    6000 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 2400 5850 2800
Wire Wire Line
	5850 2400 6000 2400
Wire Wire Line
	4400 3300 4100 3300
Wire Wire Line
	4400 3200 4100 3200
Wire Wire Line
	4400 3100 4100 3100
Wire Wire Line
	4400 3000 4100 3000
$Comp
L Si8640EC-B-IS1:Si8640EC-B-IS1 IC2
U 1 1 607157C7
P 4400 2800
F 0 "IC2" H 5050 3065 50  0000 C CNN
F 1 "Si8640EC-B-IS1" H 5050 2974 50  0000 C CNN
F 2 "Si8640EC-B-IS1:SOIC127P600X175-16N" H 5550 2900 50  0001 L CNN
F 3 "http://uk.rs-online.com/web/p/products/7532425P" H 5550 2800 50  0001 L CNN
F 4 "Isolator,digital,150Mbps,3.7kV,SOIC16N" H 5550 2700 50  0001 L CNN "Description"
F 5 "1.75" H 5550 2600 50  0001 L CNN "Height"
F 6 "7532425P" H 5550 2500 50  0001 L CNN "RS Part Number"
F 7 "http://uk.rs-online.com/web/p/products/7532425P" H 5550 2400 50  0001 L CNN "RS Price/Stock"
F 8 "Silicon Labs" H 5550 2300 50  0001 L CNN "Manufacturer_Name"
F 9 "Si8640EC-B-IS1" H 5550 2200 50  0001 L CNN "Manufacturer_Part_Number"
F 10 "R1015692" H 5550 2100 50  0001 L CNN "Allied_Number"
	1    4400 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2800 4250 2800
Wire Wire Line
	4250 2800 4250 2400
Wire Wire Line
	4250 2400 4100 2400
Connection ~ 4100 2400
Text GLabel 6000 2400 1    50   Input ~ 0
V5
$Comp
L power:GNDS #PWR?
U 1 1 615DF2C7
P 4100 2700
F 0 "#PWR?" H 4100 2450 50  0001 C CNN
F 1 "GNDS" H 4105 2527 50  0000 C CNN
F 2 "" H 4100 2700 50  0001 C CNN
F 3 "" H 4100 2700 50  0001 C CNN
	1    4100 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDS #PWR?
U 1 1 615DFA4B
P 4400 3500
F 0 "#PWR?" H 4400 3250 50  0001 C CNN
F 1 "GNDS" H 4405 3327 50  0000 C CNN
F 2 "" H 4400 3500 50  0001 C CNN
F 3 "" H 4400 3500 50  0001 C CNN
	1    4400 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDS #PWR?
U 1 1 615DFFA8
P 4400 2900
F 0 "#PWR?" H 4400 2650 50  0001 C CNN
F 1 "GNDS" H 4405 2727 50  0000 C CNN
F 2 "" H 4400 2900 50  0001 C CNN
F 3 "" H 4400 2900 50  0001 C CNN
	1    4400 2900
	1    0    0    -1  
$EndComp
$EndSCHEMATC
