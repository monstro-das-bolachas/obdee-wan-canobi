# Current project status

Last checked/updated: 2026-06-22

## Executive summary

The active hardware revision is **R9 FAB_READY**: a Teensy 4.1 dual-CAN-FD + LIN/K automotive interface using OBD2 pigtail/cable solder pads and DIP-switch configurable routing.

R9 supersedes earlier intermediate variants for manufacturing/prototype ordering. The public repository has been cleaned so only R9 public source, fabrication outputs, reports, and user-facing docs are tracked.

## Authoritative R9 files

PCB source:

- `hardware/kicad/teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pcb`
- `hardware/kicad/teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pro`

Project-local footprint support:

- `hardware/kicad/fp-lib-table`
- `hardware/kicad/teensy-41-can-lin.pretty/`

Fabrication package:

- `fabrication/r9/package/FAB_READY_R9_teensy-41-dual-canfd-lin_CLEAN_SHARE_20260622T122624Z.zip`
- `fabrication/r9/package/FAB_READY_R9_CLEAN_SHARE_SHA256.txt`

Gerbers/drill:

- `fabrication/r9/gerbers/`

Reports:

- `fabrication/r9/reports/drc.rpt`
- `fabrication/r9/reports/summary.txt`

## KiCad verification

Verified with KiCad CLI 10.0.3 from the cleaned project copy.

Result:

- DRC violations: 0
- Unconnected pads/items: 0
- Footprint errors: 0
- Gerber/drill export: passed

## R9 feature summary

- Teensy 4.1 shield-style board.
- Dual CAN-FD transceivers: MCP2562FD-E/SN with VIO at +3.3 V.
- LIN/K transceiver: TLIN1029DRQ1 with +3.3 V RXD pull-up.
- OBD2 pigtail solder pads and strain-relief holes instead of an uncertain board-mounted J1962 connector.
- DIP-switch selectable CAN normal/cross routing.
- DIP-switch selectable LIN/K source; exactly one LIN/K source should be enabled at a time.
- Complete LM2596S-5.0 5 V buck regulator support circuit.
- Corrected Teensy 4.1 side-row footprint: 23 upper / 24 lower pads.

## Manufacturing status

PCB fabrication status: **FAB_READY for first-run prototype order**.

Order a small prototype batch first. This remains prototype hardware and must be bench-tested before vehicle use.

## Required real-world checks

1. Verify OBD2 pigtail pinout with a multimeter before soldering.
2. Bench-test the power section with current limiting.
3. Verify +5 V before installing the Teensy.
4. Confirm DIP-switch settings.
5. Start with passive/read-only firmware.
6. Do not transmit vehicle frames until bench and passive capture tests pass.
