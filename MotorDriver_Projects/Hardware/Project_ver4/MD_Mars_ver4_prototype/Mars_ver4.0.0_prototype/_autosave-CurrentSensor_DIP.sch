EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Connector_Generic:Conn_01x04 J?
U 1 1 61BF9181
P 7300 3250
F 0 "J?" H 7250 3500 50  0000 L CNN
F 1 "Conn_01x04" H 7450 3250 50  0001 L CNN
F 2 "" H 7300 3250 50  0001 C CNN
F 3 "~" H 7300 3250 50  0001 C CNN
	1    7300 3250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J?
U 1 1 61BF95F5
P 7500 3250
F 0 "J?" H 7450 3500 50  0000 C CNN
F 1 "Conn_01x04" H 7418 3476 50  0001 C CNN
F 2 "" H 7500 3250 50  0001 C CNN
F 3 "~" H 7500 3250 50  0001 C CNN
	1    7500 3250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7100 3150 7100 3250
Wire Wire Line
	7100 3350 7100 3450
Text HLabel 7850 3150 2    50   Input ~ 0
VCC
Text HLabel 6950 3150 0    50   Input ~ 0
IP+
Text HLabel 6950 3350 0    50   Output ~ 0
IP-
Wire Wire Line
	7100 3150 6950 3150
Connection ~ 7100 3150
Wire Wire Line
	7100 3350 6950 3350
Connection ~ 7100 3350
Wire Wire Line
	7700 3150 7850 3150
Wire Wire Line
	7700 3450 7850 3450
Text HLabel 7850 3450 2    50   Output ~ 0
GND
$EndSCHEMATC
