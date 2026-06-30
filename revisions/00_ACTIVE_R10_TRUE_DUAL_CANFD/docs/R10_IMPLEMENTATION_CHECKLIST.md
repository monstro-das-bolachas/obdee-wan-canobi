# R10 implementation checklist — true dual CAN FD

Status: active working checklist.

Working KiCad project:

- `hardware/kicad/teensy-41-true-dual-canfd-lin-r10-working.kicad_pro`
- `hardware/kicad/teensy-41-true-dual-canfd-lin-r10-working.kicad_pcb`
- `hardware/kicad/teensy-r10-canfd.kicad_sym`
- `hardware/kicad/sym-lib-table`

Current R10 PCB scaffold:

- `U6` = MCP2518FD_A_VERIFY_PINOUT placeholder, SOIC-14, placed at approximately `(126 mm, 86 mm)`, rotated 90°.
- `U7` = MCP2518FD_B_VERIFY_PINOUT placeholder, SOIC-14, placed at approximately `(143 mm, 86 mm)`, rotated 90°.
- These are physical space-allocation placeholders only; pins are not wired because the exact datasheet/package pinout still needs verification.

Latest scaffold DRC:

- `fabrication/r10_drc_placeholders_moved.rpt`
- DRC violations: 0
- Unconnected items: 0
- Footprint errors: 0

## Phase 1 — exact part selection

Required before schematic/layout edits:

1. Select exact MCP2518FD orderable part from Mouser/Microchip.
2. Confirm package:
   - Prefer SOIC-14 for hand assembly if available.
   - Otherwise choose the most solderable package with available stock.
3. Download/store datasheet manually if automated access remains blocked.
4. Verify pinout for:
   - VDD/VSS
   - OSC1/OSC2 or clock input pins
   - TXCAN/RXCAN
   - SCK/SI/SO/CS
   - INT
   - RESET/optional control pins
5. Decide controller clock frequency and source:
   - crystal + load capacitors, or
   - oscillator module.

## Phase 2 — create authoritative schematic

R10 must have a real `.kicad_sch` before any fab-ready claim.

Schematic blocks:

1. Teensy 4.1 headers.
2. MCP2518FD_A controller.
3. MCP2518FD_B controller.
4. MCP2562FD_A transceiver.
5. MCP2562FD_B transceiver.
6. TLIN1029 LIN/K transceiver.
7. OBD2 pigtail pads.
8. AUX header.
9. LM2596 or replacement buck power section.
10. Protection/test points/DIP switches.

## Phase 3 — R10 PCB modifications

Starting from R9 working base:

1. Add MCP2518FD_A footprint.
2. Add MCP2518FD_B footprint.
3. Add clock-source components near each MCP2518FD, unless using a shared clock allowed by datasheet.
4. Add decoupling capacitors next to each MCP2518FD.
5. Add optional CS/INT/RESET pull-ups or pull-downs as required.
6. Reroute transceiver inputs:
   - MCP2518FD_A TXCAN/RXCAN -> MCP2562FD_A TXD/RXD.
   - MCP2518FD_B TXCAN/RXCAN -> MCP2562FD_B TXD/RXD.
7. Remove direct Teensy CAN_A/CAN_B controller wiring to the transceivers.
8. Route Teensy SPI to both controllers:
   - SCK shared.
   - MOSI/SI shared.
   - MISO/SO shared.
   - separate CS per controller.
   - separate INT per controller.
   - optional shared RESET.
9. Keep CAN bus side routing to SW1/OBD/AUX concept, then re-check DRC.
10. Re-run JLCPCB DFM preview after export.

## Phase 4 — firmware pin map

Provisional pin allocation:

| Function | Proposed Teensy pin |
|---|---:|
| SPI SCK | 13 |
| SPI MOSI | 11 |
| SPI MISO | 12 |
| CANFD_A_CS | 10 |
| CANFD_B_CS | 9 |
| CANFD_A_INT | 2 |
| CANFD_B_INT | 3 |
| CANFD_RESET | 4 optional/shared |
| LIN_EN | 6 |
| LIN_RX | 7 |
| LIN_TX | 8 |

Must be confirmed against the selected MCP2518FD firmware library.

## Phase 5 — fab-ready gates

R10 is fab-ready only after:

- authoritative schematic exists;
- ERC checked or exceptions documented;
- PCB DRC = 0;
- no unconnected pads;
- footprint/pinout audit completed against datasheet;
- BOM generated from the actual schematic/PCB;
- Gerbers/drills exported;
- JLCPCB DFM preview acceptable;
- stencil layer exported if SMD assembly is planned.
