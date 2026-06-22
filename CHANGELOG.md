# Changelog

## R9 FAB_READY - 2026-06-22

### Status

R9 is the current manufacturing prototype candidate for the Teensy 4.1 dual CAN-FD + LIN/K automotive interface.

### Added

- Added explicit R9 final-candidate KiCad PCB/project files:
  - `teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pcb`
  - `teensy-41-dual-canfd-lin-r9-final-candidate.kicad_pro`
- Added clean FAB_READY manufacturing ZIP:
  - `FAB_READY_R9_teensy-41-dual-canfd-lin_CLEAN_SHARE_20260622T122624Z.zip`
- Added R9 Gerber/drill outputs under `gerbers/r9_fab_ready/`.
- Added R9 verification reports under `reports/r9_fab_ready/`.
- Added `R9_FAB_READY_STATUS.md` and `R9_README_STATUS.txt` manufacturing notes.
- Added project-local footprint library support with `fp-lib-table` and `teensy-41-can-lin.pretty/`.

### Changed

- Promoted the hardware status from R7 to R9 FAB_READY.
- Updated `README.md` and `CURRENT_STATUS.md` to point to R9 as the active manufacturing revision.
- Clarified that R9 uses OBD2 pigtail/cable solder pads instead of an uncertain board-mounted J1962 connector.
- Clarified prototype safety requirements before vehicle use.

### Verification

R9 was verified from the cleaned project copy with KiCad CLI 10.0.3.

- DRC violations: 0
- Unconnected pads/items: 0
- Footprint errors: 0
- Gerber/drill export: passed

### Notes

- The legacy schematic is not authoritative for R9. Manufacturing confidence is based on the KiCad PCB source, project-local footprints, KiCad CLI DRC, and KiCad-generated Gerber/drill files.
- R9 remains first-run prototype hardware: order a small batch, bench-test power rails first, start with passive/read-only firmware, and verify the OBD2 pigtail pinout with a multimeter.

## R7 - 2026-06-21

- Corrected Teensy 4.1 side-row footprint to 23 upper / 24 lower pads.
- Preserved R6 electrical fixes and LM2596S-5.0 buck-regulator support.
- Verified PCB DRC clean before R9 promotion.

## R6 - 2026-06-21

- Added complete 5 V buck regulator support section.
- Selected 3.3 V-compatible CAN/LIN transceivers.

## R5 - 2026-06-21

- Introduced OBD2 pigtail solder-pad mechanical approach.
- Added DIP-switch CAN/LIN routing selectors.
