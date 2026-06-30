# Current project status

Last checked/updated: 2026-06-30

## Executive summary

The active hardware revision is now **R10 true dual CAN FD + LIN/K**.

R10 includes the required external CAN FD controller architecture:

```text
Teensy 4.1 SPI bus
  -> MCP2518FD controller A -> MCP2562FD transceiver A
  -> MCP2518FD controller B -> MCP2562FD transceiver B
TLIN1029 LIN/K interface retained
```

The previous R9 hardware is archived as a classic CAN 2.0 + LIN/K reference design. R9 used CAN-FD-capable MCP2562FD physical transceivers, but did not include MCP2518FD or another CAN FD controller/MAC, so it is not true CAN FD.

## Active R10 files

Active revision folder:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/`

KiCad source:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/kicad/teensy-41-true-dual-canfd-lin-r10.kicad_pcb`
- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/kicad/teensy-41-true-dual-canfd-lin-r10.kicad_pro`

Project-local support:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/kicad/fp-lib-table`
- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/kicad/sym-lib-table`
- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/kicad/teensy-41-can-lin.pretty/`
- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/kicad/teensy-r10-canfd.kicad_sym`

## R10 verification

KiCad CLI 10.0.3 DRC was run from the cleaned active revision folder.

Report:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/reports/R10_TRUE_DUAL_CANFD_DRC_RECHECK.rpt`

Result:

- DRC violations: 0
- Unconnected pads/items: 0
- Footprint errors: 0

Manufacturing export was regenerated from the cleaned active folder.

JLCPCB/root-upload package:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/package/R10_TRUE_DUAL_CANFD_JLCPCB_GERBERS.zip`

Full source/handoff package:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/package/R10_TRUE_DUAL_CANFD_FULL_PACKAGE.zip`

Checksums:

- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/package/R10_TRUE_DUAL_CANFD_SHA256.txt`

## R9 status

R9 is archived here:

- `revisions/01_R9_CLASSIC_CAN_ARCHIVE/`

R9 remains useful only as historical/reference material for:

- power-section validation;
- OBD pigtail solder-pad mechanics;
- DIP switch ergonomics;
- LIN/K source selection testing;
- classic CAN 2.0 experimentation.

R9 should not be ordered or presented as the final true dual CAN FD interface.

## Required real-world checks before any vehicle connection

1. Verify OBD2 pigtail pinout with a multimeter before soldering.
2. Bench-test the power section with current limiting.
3. Verify +5 V before installing the Teensy.
4. Confirm DIP-switch settings.
5. Start with passive/read-only firmware.
6. Do not transmit vehicle frames until bench and passive capture tests pass.
7. Confirm Teensy header orientation, pigtail pad mapping, and assembly-side choices before PCB order.
