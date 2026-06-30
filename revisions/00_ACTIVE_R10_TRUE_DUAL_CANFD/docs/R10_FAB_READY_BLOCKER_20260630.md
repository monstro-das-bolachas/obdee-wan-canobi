# R10 fab-ready blocker — 2026-06-30

Target: true dual CAN FD R10 using two MCP2518FD controllers and two MCP2562FD transceivers.

## Datasheet used

Local datasheet:

- `/mnt/VM share/External-CAN-FD-Controller-with-SPI-Interface-DS20006027B.pdf`

Confirmed SOIC-14 MCP2518FD pinout:

1. TXCAN
2. RXCAN
3. CLKO/SOF
4. INT
5. OSC2
6. OSC1
7. VSS
8. INT1/GPIO1
9. INT0/GPIO0/XSTBY
10. SCK
11. SDI
12. SDO
13. nCS
14. VDD

## Current R10 board file

- `hardware/kicad/teensy-41-true-dual-canfd-lin-r10-fab-candidate.kicad_pcb`

Current state: clean placement, **not routed / not fab-ready**.

Current placement DRC report:

- `fabrication/r10_drc_current_clean_placement.rpt`

Result:

- Physical DRC violations: 0
- Unconnected pads: 40
- Footprint errors: 0

## What was attempted

1. Bottom-right controller placement:
   - physically clean;
   - too far from transceivers and Teensy;
   - manual route produced many crossings;
   - FreeRouting got to 5 unrouted but CLI did not emit a `.ses` file on this host.

2. Near-transceiver controller placement:
   - final clean placement uses:
     - U6 MCP2518FD_A around `(104 mm, 8 mm)`
     - U7 MCP2518FD_B around `(104 mm, 52 mm)`
   - physically clean after moving C12/C13;
   - FreeRouting got stuck after pass 1 with this DSN in CLI mode;
   - manual direct routing still produced many crossings against existing R9 copper.

## Blocker

The R9 board was routed around Teensy-native CAN directly into MCP2562FD transceivers. Adding MCP2518FD controllers into that already-routed topology is not a small patch. The remaining issue is layout/routing, not part selection.

The current R10 candidate is a correct net/pin/placement basis, but not manufacturable until routed and DRC-clean.

## Honest order recommendation

Do not order R10 yet.

Do not upload any R10 Gerbers until KiCad reports:

- 0 DRC violations
- 0 unconnected pads
- 0 footprint errors

## Recommended next path

Use KiCad GUI or a functioning SPECCTRA route/import workflow to route the current clean-placement candidate, or perform a larger floorplan change rather than trying to patch-route through the old R9 copper.

Best next layout approach:

1. Keep U6 near U2 and U7 near U3.
2. Move/reshape existing CANH/CANL and LIN tracks where they block MCP2518FD digital fanout.
3. Route local crystal networks first.
4. Route TXCAN/RXCAN/XSTBY controller-to-transceiver second.
5. Route SPI/CS/INT to Teensy third.
6. Re-run KiCad DRC after every group.
7. Export Gerbers only after DRC is fully clean.
