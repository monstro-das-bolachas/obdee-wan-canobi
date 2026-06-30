# R9 PCB-derived bill of materials — Teensy 4.1 dual classic CAN + LIN/K shield

Status: PCB-derived public BOM for R9 first prototype.

Important naming correction:

- R9 uses two MCP2562FD CAN-FD-capable physical transceivers.
- R9 does **not** include external CAN FD controllers such as MCP2518FD.
- With Teensy 4.1 CAN1/CAN2 routing, R9 should be treated as **dual classic CAN 2.0 + LIN/K** for the first prototype, not true dual CAN FD.

## PCB-derived component list

| Ref | Value / description | Footprint / package | Qty | Notes |
|---|---|---:|---:|---|
| U1 | TEENSY_4.1_MAIN_HEADERS_PJRC_AUDITED | Teensy_4.1_MainHeaders_PJRC_Audited | 1 | Teensy module/header position; Teensy itself is not soldered as an IC |
| U2 | MCP2562FD_CAN_A_3V3_IO | SOIC-8_3.9x4.9mm_P1.27mm | 1 | CAN A transceiver, VIO on +3.3 V |
| U3 | MCP2562FD_CAN_B_3V3_IO | SOIC-8_3.9x4.9mm_P1.27mm | 1 | CAN B transceiver, VIO on +3.3 V |
| U4 | TLIN1029DRQ1_LIN_3V3_LOGIC | SOIC-8_3.9x4.9mm_P1.27mm | 1 | LIN/K transceiver |
| U5 | LM2596S-5.0_BUCK | TO-263-5_TabPin3 | 1 | Fixed 5 V buck regulator section; prototype-level automotive robustness |
| C1 | 100uF_50V_INPUT | CP_Radial_D8.0mm_P3.50mm | 1 | Input bulk capacitor |
| C2 | 100nF_50V_INPUT | C_0805_2012Metric_Pad1.18x1.45mm_HandSolder | 1 | Input decoupling |
| C3 | 330uF_16V_OUTPUT_LOW_ESR | CP_Radial_D8.0mm_P3.50mm | 1 | Output bulk capacitor |
| C4 | 100nF_16V_OUTPUT | C_0805_2012Metric_Pad1.18x1.45mm_HandSolder | 1 | Output decoupling |
| C5 | 100nF_CAN_A_DECOUPLING | C_0805_2012Metric_Pad1.18x1.45mm_HandSolder | 1 | CAN A decoupling |
| C6 | 100nF_CAN_B_DECOUPLING | C_0805_2012Metric_Pad1.18x1.45mm_HandSolder | 1 | CAN B decoupling |
| C7 | 100nF_LIN_DECOUPLING | C_0805_2012Metric_Pad1.18x1.45mm_HandSolder | 1 | LIN decoupling |
| D1 | SMBJ24CA_TVS_12V | D_SMA | 1 | 12 V input TVS |
| D2 | SS34_BUCK_SCHOTTKY | D_SMA | 1 | Buck catch diode |
| F1 | POLYFUSE_500mA | Fuse_1206_3216Metric | 1 | Input protection |
| L1 | 33uH_3A_BUCK_INDUCTOR | L_Radial_D8.7mm_P5.00mm_Fastron_07HCP | 1 | Buck inductor |
| R1 | 10k_LIN_RX_PULLUP | R_0805_2012Metric_Pad1.20x1.40mm_HandSolder | 1 | LIN RX pull-up |
| J1 | OBD2_PIGTAIL_16_WIRE_SOLDER_PADS | OBD2_PigtailPads_Manufacturing | 1 | 16-wire OBD2 pigtail solder pads, not DB9 |
| J2 | AUX_HEADER | PinHeader_1x08_P2.54mm_Vertical | 1 | Auxiliary CAN/LIN/power header |
| SW1 | CAN_NORMAL_CROSS_DIP_8POS | SW_DIP_SPSTx08_Slide_9.78x22.5mm_W7.62mm_P2.54mm | 1 | CAN normal/cross routing |
| SW2 | LIN_K_SOURCE_DIP_8POS_SELECT_ONE | SW_DIP_SPSTx08_Slide_9.78x22.5mm_W7.62mm_P2.54mm | 1 | LIN/K source selector; enable exactly one source |
| TP1 | 12V | TestPoint_Pad_D1.5mm | 1 | 12 V test point |
| TP2 | 5V | TestPoint_Pad_D1.5mm | 1 | 5 V test point |
| TP3 | GND | TestPoint_Pad_D1.5mm | 1 | Ground test point |
| TP4 | CAN_A_H | TestPoint_Pad_D1.5mm | 1 | CAN A high test point |
| TP5 | CAN_A_L | TestPoint_Pad_D1.5mm | 1 | CAN A low test point |
| TP6 | CAN_B_H | TestPoint_Pad_D1.5mm | 1 | CAN B high test point |
| TP7 | CAN_B_L | TestPoint_Pad_D1.5mm | 1 | CAN B low test point |
| TP8 | LIN_BUS | TestPoint_Pad_D1.5mm | 1 | LIN/K bus test point |
| TP9 | AUX_LIN_K | TestPoint_Pad_D1.5mm | 1 | Auxiliary LIN/K test point |
| MH1-MH4 | M3 | MountingHole_3.2mm_M3 | 4 | Board mounting holes |
| SR1-SR2 | CABLE_STRAIN_RELIEF | MountingHole_3.2mm_M3 | 2 | Cable strain relief holes |

## Not present on R9 PCB

These items appeared in older/stale documentation but are **not** part of the current R9 PCB:

- TJA1051T CAN transceivers
- TJA1020T LIN transceiver
- DB9 OBD connector
- USB-C receptacle on the shield PCB
- MCP2518FD or other external CAN FD controller ICs
- 4-layer stackup; current exported board is a 2-layer prototype PCB

## Ordering caution

Order parts from the actual KiCad PCB/footprint list above, not from older R8/R7 notes. Bench-test the buck converter and bus interfaces before vehicle connection.
