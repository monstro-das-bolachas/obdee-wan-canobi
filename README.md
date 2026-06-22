# Teensy 4.1 Dual CAN-FD + LIN/K shield

This repository contains the public hardware release for a Teensy 4.1 based automotive diagnostics and reverse-engineering shield with dual CAN-FD transceivers and a LIN/K-line interface.

## Current active revision

Use **R9 FAB_READY** for the first real-world prototype PCB order.

The repository is intentionally kept clean: only the latest public R9 hardware source, fabrication outputs, reports, and user-facing documentation are tracked. Intermediate R5/R6/R7 variants and private generation scripts were removed from the public tree.

## Repository layout

- `hardware/kicad/` — authoritative R9 KiCad PCB project and local footprint library.
- `fabrication/r9/gerbers/` — R9 Gerber/drill manufacturing outputs.
- `fabrication/r9/reports/` — R9 KiCad CLI verification reports.
- `fabrication/r9/package/` — clean FAB_READY release ZIP and SHA256 checksum.
- `docs/` — user-facing hardware documentation.
- `CHANGELOG.md` — revision notes.
- `CURRENT_STATUS.md` — current manufacturing/prototype status.

## Authoritative R9 PCB source

- `hardware/kicad/teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pcb`
- `hardware/kicad/teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pro`
- `hardware/kicad/fp-lib-table`
- `hardware/kicad/teensy-41-can-lin.pretty/`

Open the `.kicad_pro` file from inside `hardware/kicad/` so KiCad resolves the project-local footprint table correctly.

## Fabrication package

- `fabrication/r9/package/FAB_READY_R9_teensy-41-dual-canfd-lin_CLEAN_SHARE_20260622T122624Z.zip`
- `fabrication/r9/package/FAB_READY_R9_CLEAN_SHARE_SHA256.txt`

Gerber/drill directory:

- `fabrication/r9/gerbers/`

Verification reports:

- `fabrication/r9/reports/drc.rpt`
- `fabrication/r9/reports/summary.txt`

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

## Scripts and automation

No generation, packaging, verification, or publishing scripts are tracked in this public repository. Those remain private.

## Firmware

Firmware work can proceed before the PCB arrives, but keep defaults passive/read-only until the assembled hardware is bench-tested.

The legacy schematic is not treated as authoritative for R9. R9 manufacturing confidence is based on the KiCad PCB source, project-local footprints, KiCad CLI DRC, and KiCad-generated Gerber/drill files.
