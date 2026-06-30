# R9 PCB-derived connectivity notes — Teensy 4.1 dual classic CAN + LIN/K shield

Status: PCB-derived public connectivity notes for R9 first prototype.

This file replaces the older hand-written schematic/netlist notes that described the wrong parts and connector scheme.

Important limitation:

- R9 does **not** currently have an authoritative `.kicad_sch` schematic.
- These notes are derived from the KiCad PCB file and are intended to prevent stale documentation from being treated as truth.
- The KiCad PCB remains the manufacturing source for R9.

## Architecture naming correction

R9 has:

- Teensy 4.1 internal CAN pins routed to two MCP2562FD transceivers.
- One TLIN1029 LIN/K transceiver.
- OBD2 pigtail solder pads and an auxiliary header.

R9 does **not** have:

- MCP2518FD external CAN FD controllers.
- Two independent external CAN FD controller channels.

Therefore R9 should be described as:

> Dual classic CAN 2.0 + LIN/K shield using CAN-FD-capable transceivers.

Do not describe R9 as true dual CAN FD unless the design is revised to include CAN FD-capable controllers for both channels.

## Main IC connectivity

### U2 — CAN A MCP2562FD transceiver

| U2 pad | Net |
|---:|---|
| 1 | CAN_A_TX |
| 2 | GND |
| 3 | +5V_REGULATED |
| 4 | CAN_A_RX |
| 5 | +3V3 |
| 6 | CAN_A_L |
| 7 | CAN_A_H |
| 8 | CAN_A_STB |

### U3 — CAN B MCP2562FD transceiver

| U3 pad | Net |
|---:|---|
| 1 | CAN_B_TX |
| 2 | GND |
| 3 | +5V_REGULATED |
| 4 | CAN_B_RX |
| 5 | +3V3 |
| 6 | CAN_B_L |
| 7 | CAN_B_H |
| 8 | CAN_B_STB |

### U4 — TLIN1029 LIN/K transceiver

| U4 pad | Net |
|---:|---|
| 1 | LIN_RX |
| 2 | LIN_EN |
| 3 | unconnected |
| 4 | LIN_TX |
| 5 | GND |
| 6 | LIN_BUS |
| 7 | +12V_PROTECTED |
| 8 | unconnected |

## Teensy 4.1 relevant nets

| Teensy pad | Net |
|---|---|
| VIN | +5V_REGULATED |
| 3V3_B | +3V3 |
| GND_B1/GND_T1/GND_T2 | GND |
| 22 | CAN_A_TX |
| 23 | CAN_A_RX |
| 0 | CAN_B_RX |
| 1 | CAN_B_TX |
| 4 | CAN_B_STB |
| 5 | CAN_A_STB |
| 6 | LIN_EN |
| 7 | LIN_RX |
| 8 | LIN_TX |

## OBD2 pigtail pad nets

J1 is a 16-wire OBD2 pigtail solder-pad block, not a DB9 connector.

| OBD/J1 pad | Net |
|---:|---|
| 1 | OBD1_SINGLE_WIRE_CANDIDATE |
| 2 | OBD2_SPARE_PWM_J1850_CANDIDATE |
| 3 | OBD3_CAN_B_PAIR_A_CANDIDATE |
| 4 | GND |
| 5 | GND |
| 6 | OBD6_CAN_A_PAIR_A |
| 7 | OBD7_SINGLE_WIRE_CANDIDATE |
| 8 | OBD8_SINGLE_WIRE_CANDIDATE |
| 9 | OBD9_SINGLE_WIRE_CANDIDATE |
| 10 | OBD10_SPARE_PWM_J1850_CANDIDATE |
| 11 | OBD11_CAN_B_PAIR_B_CANDIDATE |
| 12 | OBD12_SINGLE_WIRE_CANDIDATE |
| 13 | OBD13_SINGLE_WIRE_CANDIDATE |
| 14 | OBD14_CAN_A_PAIR_B |
| 15 | OBD15_SINGLE_WIRE_CANDIDATE |
| 16 | +12V_OBD |

Critical check:

- OBD pin 16 is +12 V battery input only.
- LIN/K must **not** be connected to OBD pin 16.
- The actual R9 PCB maps LIN/K source candidates through SW2 from OBD7, OBD15, OBD1, OBD8, OBD9, OBD12, OBD13, or AUX_LIN_K_IO.

## Auxiliary header J2

| J2 pad | Net |
|---:|---|
| 1 | CAN_B_H |
| 2 | CAN_B_L |
| 3 | AUX_LIN_K_IO |
| 4 | GND |
| 5 | +5V_REGULATED |
| 6 | +12V_PROTECTED |
| 7 | CAN_A_H |
| 8 | CAN_A_L |

## Prototype safety notes

- Verify the OBD2 pigtail wire-to-pin mapping with a multimeter before soldering.
- Bench-test the +12 V to +5 V buck section with current limiting before installing the Teensy.
- Verify +5 V and +3.3 V at the relevant IC pins.
- Keep CAN/LIN firmware passive/read-only until bench and passive capture tests pass.
- Enable exactly one SW2 LIN/K source at a time.
