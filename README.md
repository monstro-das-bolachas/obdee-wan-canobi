# Teensy 4.1 Dual CAN-FD + LIN/K shield

This repository contains a Teensy 4.1 based automotive diagnostics and reverse-engineering shield with dual CAN-FD transceivers and a LIN/K-line interface.

## Current active revision

Use **R9 FAB_READY** for the first real-world prototype PCB order.

Authoritative R9 PCB source:

- `teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pcb`
- `teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pro`

Project-local footprint support:

- `fp-lib-table`
- `teensy-41-can-lin.pretty/`

Fabrication package:

- `FAB_READY_R9_teensy-41-dual-canfd-lin_CLEAN_SHARE_20260622T122624Z.zip`
- SHA256 is recorded in `FAB_READY_R9_CLEAN_SHARE_SHA256.txt`

Gerber/drill directory:

- `gerbers/r9_fab_ready/`

Verification reports:

- `reports/r9_fab_ready/drc.rpt`
- `reports/r9_fab_ready/summary.txt`

## R9 verification summary

Verified with KiCad CLI 10.0.3 from the cleaned project copy.

Result:

- DRC violations: 0
- Unconnected pads/items: 0
- Footprint errors: 0
- Gerber/drill export: passed
- Local footprint-library warnings mitigated by including `fp-lib-table` and `teensy-41-can-lin.pretty/`

## Hardware overview

R9 implements:

- Teensy 4.1 shield-style board.
- Dual CAN-FD channels using MCP2562FD-E/SN transceivers with VIO tied to +3.3 V.
- LIN/K-line interface using TLIN1029DRQ1, with RXD pulled up to +3.3 V.
- OBD2 pigtail/cable solder pads instead of an uncertain board-mounted J1962 connector.
- DIP-switch CAN normal/cross routing and LIN/K source selection.
- Complete LM2596S-5.0 fixed 5 V buck regulator support section.
- Corrected Teensy 4.1 side-row footprint: 23 upper / 24 lower side-row pads.

## DIP switch summary

SW1 selects CAN routing:

- 1+2: CAN A normal, OBD6/14
- 3+4: CAN A crossed, OBD6/14
- 5+6: CAN B normal, OBD3/11
- 7+8: CAN B crossed, OBD3/11

SW2 selects LIN/K source:

- 1: OBD7
- 2: OBD15
- 3: OBD1
- 4: OBD8
- 5: OBD9
- 6: OBD12
- 7: OBD13
- 8: AUX_LIN_K_IO

Rule: enable exactly one LIN/K source at a time.

## Prototype safety

Before connecting to a vehicle:

1. Verify every OBD2 pigtail wire-to-pin mapping with a multimeter.
2. Assemble and bench-test the power section first with current limiting.
3. Verify +5 V output before installing the Teensy.
4. Verify +3.3 V VIO/pull-up compatibility at CAN/LIN IC pins.
5. Start with passive/read-only CAN firmware.
6. Enable exactly one LIN/K source switch at a time.
7. Do not transmit vehicle frames until bench and passive capture tests pass.

## Software

Firmware work can proceed before the PCB arrives, but keep defaults passive/read-only until the assembled hardware is bench-tested.

The legacy schematic in this repository is not treated as authoritative for R9. R9 manufacturing confidence is based on the KiCad PCB source, project-local footprints, KiCad CLI DRC, and KiCad-generated Gerber/drill files.
