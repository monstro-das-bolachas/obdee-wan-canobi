# OBDee-Wan CANobi

An open-source, open-hardware automotive bus interface for hackers, makers, reverse engineers, and the dangerously curious.

OBDee-Wan CANobi is a Teensy 4.1 based vehicle-network tool for CAN FD, classic CAN, LIN, and K-line exploration. The goal is to make a powerful interface that is still understandable, inspectable, modifiable, and buildable by everyday tinkerers.

This project is not meant to be a black box. It is meant to be a teaching tool, a hacking platform, and a practical bridge between a laptop and the electrical nervous system of a vehicle.

## What it is

The current design targets:

- Teensy 4.1 host MCU
- dual external CAN FD controllers
- dual CAN FD transceivers
- LIN / K-line interface support
- OBD pigtail-friendly wiring
- DIP-switch configurable routing
- KiCad hardware source files
- prototype manufacturing packages

Useful for:

- automotive reverse engineering
- CAN FD experimentation
- LIN and K-line learning
- custom diagnostic tools
- EV conversion projects
- maker/hacker education
- bench testing vehicle modules

## Current status — R11 prototype manufacturing candidate

R11 is suitable for ordering a small bare-PCB prototype batch for bench bring-up.

It is not approved for direct vehicle testing yet.

Current release:

- `revisions/00_WORK_R11_TRUE_DUAL_CANFD/release/R11_PROTOTYPE_MANUFACTURING_CANDIDATE_20260630/`

JLCPCB / PCBWay upload ZIP:

- `revisions/00_WORK_R11_TRUE_DUAL_CANFD/release/R11_PROTOTYPE_MANUFACTURING_CANDIDATE_20260630/package/JLCPCB_PCBWAY_UPLOAD_R11_MINIMAL_GERBERS_ONLY_20260630.zip`

Verification summary:

- KiCad CLI DRC: 0 violations
- Known residual: one GND zone-to-zone report at 1.0000 mm / 1.0000 mm
- GND continuity: visually confirmed in KiCad after refill/highlight
- Gerbers/drill: exported successfully

Before vehicle connection, assembled boards must pass bare-board continuity, power rail checks, current-limited bench power-up, OBD/pigtail pin mapping, DIP-switch default review, and CAN/LIN/K bench testing.

## Repository layout

- `README_START_HERE.txt` — short navigation and safety guide.
- `CURRENT_STATUS.md` — current revision status and ordering notes.
- `revisions/00_WORK_R11_TRUE_DUAL_CANFD/` — active R11 prototype manufacturing candidate.
- `revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/` — previous R10 archive, not for fabrication.
- `revisions/01_R9_CLASSIC_CAN_ARCHIVE/` — previous R9 classic-CAN archive.
- `LICENSE` and `LICENSES/` — open hardware, software, and documentation license texts.

## Safety warning

Vehicle electrical systems can damage tools, modules, or cars if connected incorrectly.

This project is provided for education, experimentation, and bench validation. Use at your own risk. Do not connect untested hardware directly to a vehicle.

When in doubt:

- use a bench supply
- use current limiting
- use fuses
- verify pinouts with a multimeter
- test on spare modules before testing on a car

## License

This project is open source and open hardware.

- Hardware design files: CERN-OHL-P-2.0
- Firmware/software/scripts: MIT
- Documentation: CC-BY-4.0

You are free to study, modify, build, remix, and share this project. Attribution is required where applicable: please credit the original project and author when reusing or publishing derivative work.

See `LICENSES/README.md` for the license split and SPDX identifiers.
