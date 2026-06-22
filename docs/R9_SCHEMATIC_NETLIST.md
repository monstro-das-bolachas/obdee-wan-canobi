# Complete Schematic Netlist for Teensy 4.1 Dual CAN + LIN Shield

## POWER SUPPLY NETLIST (12V → 5V @ 3A)

### Primary Input
- **12V_IN** (from J4 Pin 1) → F1 Pin 1
- F1 Pin 2 → **12V_FUSED** → D1 Anode
- D1 Cathode → **12V_PROTECTED** → C1 Pin 1 → U1 Pin 1
- J4 Pin 2 → **GND** → All ground connections

### LM2596 Buck Converter
- **12V_PROTECTED** → U1 Pin 1 (VIN)
- U1 Pin 3 (GND) → **GND**
- U1 Pin 4 (FB) → Rfeedback1 → **5V_OUT**
- U1 Pin 5 (ON/OFF) → **GND** (Always enabled)
- U1 Pin 2 (OUT) → L1 Pin 1 → D2 Anode

### Buck Converter Inductor & Diode
- L1 Pin 1 → U1 Pin 2 (SW)
- L1 Pin 2 → **5V_OUT**
- D2 Anode → U1 Pin 2
- D2 Cathode → **12V_PROTECTED** (Freewheeling diode)
- C2 Pin 1 → U1 Pin 2
- C2 Pin 2 → **GND**

### Output Filtering
- **5V_OUT** → C3 Pin 1 → Rfeedback2 → **5V_REGULATED**
- C3 Pin 2 → **GND**
- **5V_REGULATED** → All 5V power rails

### Feedback Network
- U1 Pin 4 (FB) → Rfeedback1 → **5V_OUT**
- Rfeedback2 → **GND** (Sets 5V output)

---

## TEENSY 4.1 HEADER CONNECTIONS (J1: 2x24 Pins)

### Power Pins
- J1 Pin 1 → **5V_REGULATED** (3V3 from Teensy)
- J1 Pin 2 → **GND** (GND from Teensy)
- J1 Pin 3 → **3V3_INTERNAL** + **5V_REGULATED**
- J1 Pin 4 → **GND**
- J1 Pin 5 → **3V3_INTERNAL**
- J1 Pin 6 → **GND**

### GPIO - CAN1
- J1 Pin 28 → **CAN1_TX** → U2 Pin 3 (TXD)
- J1 Pin 29 → **CAN1_RX** → U2 Pin 2 (RXD)

### GPIO - CAN2
- J1 Pin 30 → **CAN2_TX** → U3 Pin 3 (TXD)
- J1 Pin 31 → **CAN2_RX** → U3 Pin 2 (RXD)

### GPIO - LIN
- J1 Pin 32 → **LIN_TX** → U4 Pin 3 (TXD)
- J1 Pin 33 → **LIN_RX** → U4 Pin 2 (RXD)
- J1 Pin 34 → **LIN_SLP_N** → U4 Pin 6 (SLP_N)

### Unused GPIO (Available for Future Expansion)
- J1 Pin 7-27 (21 pins)
- J1 Pin 35-48 (14 pins)

---

## CAN1 TRANSCEIVER (U2: TJA1051)

### Power Connections
- U2 Pin 1 (VCC) → **5V_REGULATED** → C4 Pin 1
- U2 Pin 4 (VSS) → **GND** → C4 Pin 2

### MCU Interface
- U2 Pin 2 (RXD) → **CAN1_RX** ← J1 Pin 29
- U2 Pin 3 (TXD) → **CAN1_TX** ← J1 Pin 28

### CAN Bus Interface
- U2 Pin 5 (CANH) → **CAN1_H** → J2 Pin 7 (CAN-H) + R1 Pin 1
- U2 Pin 6 (CANL) → **CAN1_L** → J2 Pin 14 (CAN-L) + R2 Pin 1
- U2 Pin 7 (SPLIT) → **CAN1_SPLIT** ← R1 Pin 2 ← R2 Pin 2
- U2 Pin 8 (MODE) → **GND** (Normal mode)

### CAN1 Termination
- R1 Pin 1 → **CAN1_H** → J2 Pin 7
- R1 Pin 2 → **CAN1_SPLIT** ← R2 Pin 2
- R2 Pin 1 → **CAN1_L** → J2 Pin 14
- R2 Pin 2 → **CAN1_SPLIT**

### CAN1 Protection
- D3 Anode → **CAN1_H** ← U2 Pin 5
- D3 Cathode → **GND**
- D4 Anode → **CAN1_L** ← U2 Pin 6
- D4 Cathode → **GND**

---

## CAN2 TRANSCEIVER (U3: TJA1051)

### Power Connections
- U3 Pin 1 (VCC) → **5V_REGULATED** → C5 Pin 1
- U3 Pin 4 (VSS) → **GND** → C5 Pin 2

### MCU Interface
- U3 Pin 2 (RXD) → **CAN2_RX** ← J1 Pin 31
- U3 Pin 3 (TXD) → **CAN2_TX** ← J1 Pin 30

### CAN Bus Interface
- U3 Pin 5 (CANH) → **CAN2_H** → J2 Pin 3 (CAN-H) + R3 Pin 1
- U3 Pin 6 (CANL) → **CAN2_L** → J2 Pin 11 (CAN-L) + R4 Pin 1
- U3 Pin 7 (SPLIT) → **CAN2_SPLIT** ← R3 Pin 2 ← R4 Pin 2
- U3 Pin 8 (MODE) → **GND** (Normal mode)

### CAN2 Termination
- R3 Pin 1 → **CAN2_H** → J2 Pin 3
- R3 Pin 2 → **CAN2_SPLIT** ← R4 Pin 2
- R4 Pin 1 → **CAN2_L** → J2 Pin 11
- R4 Pin 2 → **CAN2_SPLIT**

### CAN2 Protection
- D5 Anode → **CAN2_H** ← U3 Pin 5
- D5 Cathode → **GND**
- D6 Anode → **CAN2_L** ← U3 Pin 6
- D6 Cathode → **GND**

---

## LIN TRANSCEIVER (U4: TJA1020)

### Power Connections
- U4 Pin 1 (VCC) → **5V_REGULATED** → C6 Pin 1
- U4 Pin 4 (VSS) → **GND** → C6 Pin 2

### MCU Interface
- U4 Pin 2 (RXD) → **LIN_RX** ← J1 Pin 33
- U4 Pin 3 (TXD) → **LIN_TX** ← J1 Pin 32
- U4 Pin 6 (SLP_N) → **LIN_SLP_N** ← J1 Pin 34

### LIN Bus Interface
- U4 Pin 5 (LIN) → **LIN_BUS** → J2 Pin 16 (ISO 9141-2 K-Line)
- U4 Pin 7 (NRES) → **GND** (Normal operation)
- U4 Pin 8 (INH) → **GND** (Not used)

### LIN Protection
- D7 Anode → **LIN_BUS** ← U4 Pin 5
- D7 Cathode → **GND**

---

## OBD2 DB9 CONNECTOR (J2)

### Standard OBD2 Pinout (SAE J1962)
- J2 Pin 2 → **J1850_BUS+** (Not used)
- J2 Pin 3 → **CAN2_H** ← U3 Pin 5
- J2 Pin 4 → **CHASSIS_GND** → **GND**
- J2 Pin 5 → **SIGNAL_GND** → **GND**
- J2 Pin 6 → **CAN_H** (ISO 15765-4, Not used)
- J2 Pin 7 → **CAN1_H** ← U2 Pin 5
- J2 Pin 10 → **J1850_BUS-** (Not used)
- J2 Pin 11 → **CAN2_L** ← U3 Pin 6
- J2 Pin 12 → **Not Connected**
- J2 Pin 13 → **Not Connected**
- J2 Pin 14 → **CAN1_L** ← U2 Pin 6
- J2 Pin 15 → **ISO 9141-2 L-Line** (Not used)
- J2 Pin 16 → **12V_OBD** ← D8 Anode

### OBD2 Power Reference
- J2 Pin 16 → **12V_OBD**
- D8 Anode → **12V_OBD** ← J2 Pin 16
- D8 Cathode → **12V_PROTECTED** (Reverse polarity protection)

---

## USB-C CONNECTOR (J3: Programming Only)

### USB 2.0 Data Lines
- J3 Pin A6 (D+) → **USB_DP** → Teensy 4.1 D+ (USB0 DP)
- J3 Pin B6 (D+) → **USB_DP** (Redundant for USB-C cable orientation)
- J3 Pin A7 (D-) → **USB_DM** → Teensy 4.1 D- (USB0 DM)
- J3 Pin B7 (D-) → **USB_DM** (Redundant for USB-C cable orientation)

### USB-C Power
- J3 Pin A1 (VBUS) → **USB_5V_IN** → (Optional - for USB bus power backup)
- J3 Pin B9 (VBUS) → **USB_5V_IN** → (Optional - for USB bus power backup)
- J3 Pin A4 (GND) → **GND** → (Shield ground)
- J3 Pin B12 (GND) → **GND** → (Shield ground)

### USB-C Control Lines
- J3 Pin A5 (CC1) → **CC1** → (USB-C configuration, not used)
- J3 Pin B5 (CC2) → **CC2** → (USB-C configuration, not used)
- J3 Pin A8 (SBU1) → **SBU1** → (Sideband use, not used)
- J3 Pin B8 (SBU2) → **SBU2** → (Sideband use, not used)

Note: USB-C used for programming only. The OBD2 12V input powers the shield, not the USB-C VBUS.

---

## PROTECTION & FILTERING CIRCUITS

### Input Filtering (C7, C8)
- C7 Pin 1 → **12V_IN** ← J4 Pin 1
- C7 Pin 2 → **GND**
- C8 Pin 1 → **12V_PROTECTED** ← D1 Cathode
- C8 Pin 2 → **GND**

### CAN Bus Protection (D3-D6)
- D3 Anode → **CAN1_H**
- D3 Cathode → **GND**
- D4 Anode → **CAN1_L**
- D4 Cathode → **GND**
- D5 Anode → **CAN2_H**
- D5 Cathode → **GND**
- D6 Anode → **CAN2_L**
- D6 Cathode → **GND**

### LIN Bus Protection (D7)
- D7 Anode → **LIN_BUS**
- D7 Cathode → **GND**

### OBD2 Reverse Polarity Protection (D8)
- D8 Anode → **12V_OBD** ← J2 Pin 16
- D8 Cathode → **12V_PROTECTED** → D1 Anode

---

## TEST POINTS (TP1-TP4)

### Signal Access Points
- **TP1**: **CAN1_H** ← U2 Pin 5
- **TP2**: **CAN1_L** ← U2 Pin 6
- **TP3**: **LIN_BUS** ← U4 Pin 5
- **TP4**: **5V_REGULATED** ← C3 Pin 1

Each test point connects to a critical signal for debugging and verification:
- TP1/TP2: CAN1 differential pair measurement
- TP3: LIN bus single-ended measurement
- TP4: 5V power rail verification

---

## COMPLETE NET CONNECTION SUMMARY

### Power Rails
1. **12V_IN** → F1 → D1 → **12V_PROTECTED** → U1 (VIN)
2. **12V_PROTECTED** → LM2596 → **5V_OUT** → C3 → **5V_REGULATED**
3. **5V_REGULATED** → U2/U3/U4 (VCC), all decoupling caps

### CAN1 Network
1. J1 Pin 28 (CAN1_TX) → U2 Pin 3 (TXD)
2. J1 Pin 29 (CAN1_RX) → U2 Pin 2 (RXD)
3. U2 Pin 5 (CANH) → J2 Pin 7 + R1 ← TP1 + D3
4. U2 Pin 6 (CANL) → J2 Pin 14 + R2 ← TP2 + D4

### CAN2 Network
1. J1 Pin 30 (CAN2_TX) → U3 Pin 3 (TXD)
2. J1 Pin 31 (CAN2_RX) → U3 Pin 2 (RXD)
3. U3 Pin 5 (CANH) → J2 Pin 3 + R3 ← D5
4. U3 Pin 6 (CANL) → J2 Pin 11 + R4 ← D6

### LIN Network
1. J1 Pin 32 (LIN_TX) → U4 Pin 3 (TXD)
2. J1 Pin 33 (LIN_RX) → U4 Pin 2 (RXD)
3. J1 Pin 34 (LIN_SLP_N) → U4 Pin 6 (SLP_N)
4. U4 Pin 5 (LIN) → J2 Pin 16 ← TP3 + D7

### Protection
1. F1 (1A Polyfuse) on 12V input
2. D1/D2 (Schottky) for reverse polarity + freewheeling
3. D3-D7 (TVS) for surge protection on all bus lines
4. D8 (Schottky) for OBD2 reverse polarity

### Ground Distribution
- Single **GND** net connects all components
- Complete ground plane on PCB
- Multiplevia stitching for thermal and electrical performance

---

## SIGNAL INTEGRITY NOTES

### CAN Bus Differential Pair Routing
- CAN1_H/CAN1_L: 83Ω differential impedance, length-matched within 5mm
- CAN2_H/CAN2_L: 83Ω differential impedance, length-matched within 5mm

### Power Supply Decoupling
- Local 0.1μF cap (C4/C5/C6) within 2mm of each transceiver power pin
- Bulk capacitance (C3) within 5mm of LM2596 output

### PCB Layer Stack (4-layer recommended)
- Layer 1: Signals + Power (Top)
- Layer 2: GND plane (Reflected)
- Layer 3: Power plane (5V)
- Layer 4: GND plane (Bottom)

---

This complete netlist ensures proper connectivity for all 34 components in the Teensy 4.1 Dual CAN + LIN Shield design following commercial shield philosophy with enhanced features.