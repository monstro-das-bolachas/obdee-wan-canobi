R9 FAB_READY package - clean share copy
Generated: 20260622T122624Z

Use for manufacturer upload:
- gerbers/ directory, or this ZIP after confirming your PCB vendor accepts nested packages.

Active KiCad source:
- teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pcb
- teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pro

Project-local footprint support included:
- fp-lib-table
- teensy-41-can-lin.pretty/

KiCad CLI DRC from this cleaned share folder:
- reports/drc_recheck_from_share_after_libcopy.rpt
- 0 DRC violations
- 0 unconnected pads/items
- 0 footprint errors

Prototype safety gates before vehicle use:
1. Verify OBD pigtail pinout with a multimeter.
2. Bench-test power section current-limited.
3. Verify +5 V rail before installing Teensy.
4. Start passive/read-only firmware first.
