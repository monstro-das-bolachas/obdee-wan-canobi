# R9 FAB_READY status

Active manufacturing candidate:

- `teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pcb`
- `teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pro`

R9 is promoted from the latest visible, verified R7 board. R7 already incorporated the current product requirements visible in this VM:

- Teensy 4.1 shield-style board.
- Dual CAN-FD transceivers: MCP2562FD-E/SN, VIO at +3.3 V.
- LIN/K interface: TLIN1029DRQ1, RXD pulled to +3.3 V.
- OBD2 pigtail solder pads instead of uncertain board-mounted J1962 connector.
- DIP-switch CAN normal/cross routing and LIN/K source selection.
- Complete LM2596S-5.0 fixed 5 V buck regulator support section.
- Corrected Teensy 4.1 side-row footprint: 23 upper / 24 lower side-row pads.

Manufacturing readiness statement:

- KiCad PCB DRC must be 0 before ordering.
- Use the generated R9 FAB_READY ZIP only if its included `reports/drc.rpt` says 0 DRC violations, 0 unconnected pads/items, and 0 footprint errors.
- The legacy schematic file in the repository is not treated as authoritative for R9; R9 is a PCB-first manufacturing prototype package.

Real-world prototype checks before vehicle use:

1. Verify every OBD2 pigtail wire-to-pin mapping with a multimeter before soldering.
2. Assemble and bench-test the power section first with current limiting.
3. Verify +5 V output before inserting/installing the Teensy.
4. Verify +3.3 V VIO/pull-up compatibility at CAN/LIN IC pins.
5. Start with passive/read-only CAN firmware.
6. Enable exactly one LIN/K source switch at a time.
7. Do not transmit vehicle frames until bench and passive capture tests pass.
