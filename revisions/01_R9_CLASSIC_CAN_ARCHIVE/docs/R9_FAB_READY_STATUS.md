# R9 status after true-CAN-FD decision

Former manufacturing candidate:

- `teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pcb`
- `teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pro`

## Current classification

R9 is **not** the final target board anymore because the project requirement is now true dual CAN FD.

R9 has:

- Teensy 4.1 shield-style board.
- Two MCP2562FD CAN-FD-capable physical transceivers, VIO at +3.3 V.
- TLIN1029 LIN/K interface.
- OBD2 pigtail solder pads.
- DIP-switch CAN normal/cross routing and LIN/K source selection.
- LM2596S-5.0 fixed 5 V buck regulator section.

R9 does **not** have:

- MCP2518FD controllers.
- Any other external CAN FD controller ICs.
- True dual CAN FD controller architecture.

Therefore R9 should be treated as:

> Optional bench prototype for dual classic CAN 2.0 + LIN/K only.

## New target

Proceed to R10:

- MCP2518FD controller A + MCP2562FD transceiver A.
- MCP2518FD controller B + MCP2562FD transceiver B.
- TLIN1029 LIN/K retained.

See:

- `docs/R10_TRUE_DUAL_CAN_FD_REDESIGN_PLAN.md`
- `docs/R10_TRUE_CAN_FD_BOM_DELTA.md`

## R9 manufacturing notes

A JLCPCB no-silkscreen upload package exists for optional bench-only R9 fabrication:

- `fabrication/r9/package/JLCPCB_UPLOAD_R9_NOSILK_GERBERS_20260629T101500Z.zip`

Do not order R9 if the goal is the final true dual CAN FD interface.

## Real-world prototype checks if R9 is still built

1. Verify every OBD2 pigtail wire-to-pin mapping with a multimeter before soldering.
2. Assemble and bench-test the power section first with current limiting.
3. Verify +5 V output before inserting/installing the Teensy.
4. Verify +3.3 V VIO/pull-up compatibility at CAN/LIN IC pins.
5. Start with passive/read-only CAN firmware.
6. Enable exactly one LIN/K source switch at a time.
7. Do not transmit vehicle frames until bench and passive capture tests pass.
