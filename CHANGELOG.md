# Changelog

## Repository cleanup - 2026-06-22

### Changed

- Reorganized the public repository around the current R9 FAB_READY release.
- Moved authoritative KiCad source and local footprints to `hardware/kicad/`.
- Moved R9 Gerbers, reports, and release package to `fabrication/r9/`.
- Moved public user-facing hardware docs to `docs/`.

### Removed from current branch

- Removed intermediate R5/R6/R7 KiCad variants, Gerbers, preview SVGs, BOMs, and reports from the public tree.
- Removed all tracked generation scripts from the public repository.
- Removed firmware/code example file from the public repository to keep code/scripts private.

Historical files may still exist in Git history and in older release tags; the current branch is the clean public R9 layout.

## R9 FAB_READY - 2026-06-22

### Status

R9 is the current manufacturing prototype candidate for the Teensy 4.1 dual CAN-FD + LIN/K automotive interface.

### Added

- Added explicit R9 final-candidate KiCad PCB/project files.
- Added clean FAB_READY manufacturing ZIP.
- Added R9 Gerber/drill outputs.
- Added R9 verification reports.
- Added project-local footprint library support.

### Verification

R9 was verified from the cleaned project copy with KiCad CLI 10.0.3.

- DRC violations: 0
- Unconnected pads/items: 0
- Footprint errors: 0
- Gerber/drill export: passed

### Notes

- The legacy schematic is not authoritative for R9. Manufacturing confidence is based on the KiCad PCB source, project-local footprints, KiCad CLI DRC, and KiCad-generated Gerber/drill files.
- R9 remains first-run prototype hardware: order a small batch, bench-test power rails first, start with passive/read-only firmware, and verify the OBD2 pigtail pinout with a multimeter.

## Earlier intermediate revisions

R5, R6, and R7 were development/intermediate variants leading to R9. They are no longer tracked in the current public branch layout.
