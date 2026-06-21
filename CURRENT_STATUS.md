# Current project status

Last checked/updated: 2026-06-21

## Executive summary

The active design is now R7: a Teensy 4.1 dual-CAN + LIN/K automotive interface using OBD2 pigtail/cable solder pads and DIP-switch configurable routing.

R7 supersedes R6.

Reason: R6 added the missing LM2596 buck-regulator support components and 3.3 V-compatible transceiver choices, but visual review found that the generated Teensy 4.1 footprint had only 22 pads on the upper long row. The intended Teensy 4.1 side-row pattern for this design is asymmetric but should be 23 upper-row pads and 24 lower-row pads. R7 corrects this.

Authoritative routed board:

- `teensy-41-can-lin-r7-teensy-footprint-corrected-routed.kicad_pcb`

Preferred fabrication ZIP:

- `r7_teensy_footprint_corrected_fabrication_minimal_gerbers.zip`

Main R7 documentation:

- `R7_PROCUREMENT_BOM_EU.md`
- `BOM_R7_PROCUREMENT_EU.csv`

## KiCad verification

Verified with:

- KiCad CLI version: 10.0.3
- pcbnew Python build: 10.0.3+dfsg-1
- FreeRouting: 2.2.4 local app

Latest authoritative DRC report:

- `reports/teensy-41-can-lin-r7-teensy-footprint-corrected-routed-drc.rpt`

Result:

- DRC violations: 0
- Unconnected pads: 0
- Footprint errors: 0
- Teensy U1 pad rows: 23 upper / 24 lower, 47 total side-row pads

Generated fabrication files:

- `gerbers/r7_teensy_footprint_corrected_fabrication_minimal/`
- `r7_teensy_footprint_corrected_fabrication_minimal_gerbers.zip`

Generated preview files:

- `previews/r7_teensy_footprint_corrected_svg/`

## R7 feature summary

### Mechanical form

R7 uses an OBD2 cable/pigtail instead of a board-mounted OBD connector.

The user should:

1. Buy or make an OBD2 male pigtail cable.
2. Verify every OBD pin/wire with a multimeter.
3. Solder wires to the labeled J1 pads.
4. Use the strain-relief holes with a zip tie.

### Teensy 4.1

Key assignments:

- CAN A / CAN1: Teensy pins 22 TX and 23 RX
- CAN B / CAN2: Teensy pins 1 TX and 0 RX
- LIN/K UART: Teensy pins 8 TX and 7 RX
- CAN standby/control: pins 5 and 4
- LIN enable/control: pin 6
- Teensy +3.3 V is used for CAN VIO and LIN RX pull-up logic compatibility

R7 Teensy side-row footprint pattern:

- Upper row: GND, VIN, 23..13, GND, 41..33 = 23 pads
- Lower row: GND, 0..12, 3.3V, 24..32 = 24 pads

### Communication ICs

- CAN A/B: MCP2562FD-E/SN, SOIC-8, VIO pin connected to +3.3 V.
- LIN/K: TLIN1029DRQ1, SOIC-8, RXD open-drain pulled up to +3.3 V through R1.

### Power section

R7 includes the complete LM2596S-5.0 fixed 5 V buck-regulator support circuit:

- F1: 500 mA resettable fuse
- D1: SMBJ24CA input TVS
- U5: LM2596S-5.0 fixed 5 V buck regulator
- L1: 33 uH buck inductor
- D2: Schottky catch diode
- C1/C3: input/output electrolytic bulk capacitors
- C2/C4: input/output ceramic decoupling capacitors
- C5/C6/C7: CAN/LIN IC local decoupling capacitors

### DIP switches

SW1 configures CAN routing:

- SW1-1 + SW1-2: CAN A normal, OBD6/14
- SW1-3 + SW1-4: CAN A crossed, OBD6/14
- SW1-5 + SW1-6: CAN B normal, OBD3/11
- SW1-7 + SW1-8: CAN B crossed, OBD3/11

SW2 configures LIN/K source selection:

- SW2-1: OBD7
- SW2-2: OBD15
- SW2-3: OBD1
- SW2-4: OBD8
- SW2-5: OBD9
- SW2-6: OBD12
- SW2-7: OBD13
- SW2-8: AUX_LIN_K_IO

Rule: enable exactly one LIN/K source at a time.

## Manufacturing status

PCB fabrication status: ready to upload as a first-run fabrication candidate.

Use:

- `r7_teensy_footprint_corrected_fabrication_minimal_gerbers.zip`

Recommended order settings:

- 2-layer FR4
- 1.6 mm thickness
- 1 oz copper
- HASL lead-free or ENIG
- Small prototype quantity first, e.g. 5 boards

Remaining practical checks before vehicle use:

1. Confirm exact OBD2 pigtail/cable pinout with a multimeter.
2. Assemble and test the power section on a current-limited bench supply.
3. Verify +5 V before installing the Teensy.
4. Confirm DIP switch settings.
5. Start with read-only/silent CAN firmware.

## Previous revisions

R6:

- `teensy-41-can-lin-r6-complete-power-routed.kicad_pcb`
- Added complete LM2596 support parts and 3.3 V-compatible CAN/LIN IC selections.
- Superseded by R7 because U1 Teensy footprint upper side-row was one pad short.

R5:

- `teensy-41-can-lin-r5-pigtail-dipswitch-routed.kicad_pcb`
- Introduced the safer OBD2 pigtail/DIP-switch mechanical concept.
- Superseded by R6/R7 because it lacked required LM2596 support components and procurement-ready IC choices.

R4:

- `teensy-41-can-lin-r4-universal-routing-matrix.kicad_pcb`
- Implemented CAN/LIN routing matrix, but still used a board-mounted OBD connector approach.

R7 supersedes R4/R5/R6 for ordering and procurement.
