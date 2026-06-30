# Teensy 4.1 true dual CAN FD + LIN/K interface

This repository contains the cleaned public hardware release for a Teensy 4.1 based automotive diagnostics and reverse-engineering interface.

## Current active revision

The active revision is **R10 true dual CAN FD + LIN/K**.

Authoritative active folder:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/`

Active KiCad board:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/kicad/teensy-41-true-dual-canfd-lin-r10.kicad_pcb`
- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/kicad/teensy-41-true-dual-canfd-lin-r10.kicad_pro`

R10 architecture:

```text
Teensy 4.1 SPI bus
  -> MCP2518FD CAN FD controller A -> MCP2562FD CAN transceiver A
  -> MCP2518FD CAN FD controller B -> MCP2562FD CAN transceiver B
LIN/K interface retained
OBD pigtail pads and DIP-switch routing retained
```

## Verification summary

Verified from the cleaned active revision folder with KiCad CLI 10.0.3.

Latest report:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/reports/R10_TRUE_DUAL_CANFD_DRC_RECHECK.rpt`

Result:

- DRC violations: 0
- Unconnected pads/items: 0
- Footprint errors: 0
- Gerber/drill export: passed

## Fabrication package

JLCPCB/root-upload Gerber package:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/package/R10_TRUE_DUAL_CANFD_JLCPCB_GERBERS.zip`

Full source/handoff package:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/package/R10_TRUE_DUAL_CANFD_FULL_PACKAGE.zip`

Checksums:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/package/R10_TRUE_DUAL_CANFD_SHA256.txt`

Before ordering, visually confirm mechanical fit/orientation of the Teensy 4.1 headers, OBD/pigtail pad mapping, DIP switch orientation, and assembly side choices.

## Repository layout

- `README_START_HERE.txt` — short navigation guide.
- `CURRENT_STATUS.md` — current revision status and safety notes.
- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/` — active R10 true-CAN-FD KiCad source, reports, Gerbers, and packages.
- `revisions/01_R9_CLASSIC_CAN_ARCHIVE/` — previous R9 classic-CAN archive retained for historical/reference purposes.
- `99_MANIFESTS/` — cleanup and reorganization manifests.
- `CHANGELOG.md` — revision notes.

## R9 archive note

R9 is retained only as a historical/classic-CAN archive. R9 used MCP2562FD CAN-FD-capable physical transceivers, but did not include external CAN FD controllers. Therefore R9 is not true dual CAN FD.

Use R10 for the current true dual CAN FD design.

## Prototype safety

Before connecting to a vehicle:

1. Verify every OBD2 pigtail wire-to-pin mapping with a multimeter.
2. Assemble and bench-test the power section first with current limiting.
3. Verify +5 V output before installing the Teensy.
4. Verify +3.3 V VIO/pull-up compatibility at CAN/LIN/CAN-FD controller pins.
5. Start with passive/read-only CAN firmware.
6. Enable exactly one LIN/K source switch at a time.
7. Do not transmit vehicle frames until bench and passive capture tests pass.

## Scripts and automation

No generation, packaging, verification, or publishing scripts are tracked in this public repository. Those remain private.
