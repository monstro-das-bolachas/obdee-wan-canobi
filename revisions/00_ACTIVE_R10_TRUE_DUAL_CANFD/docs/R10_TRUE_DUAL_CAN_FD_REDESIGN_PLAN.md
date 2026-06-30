# R10 true dual CAN FD redesign plan

Status: design target for the next hardware revision.

Reason for R10:

- R9 uses Teensy 4.1 CAN1/CAN2 pins directly into MCP2562FD transceivers.
- MCP2562FD devices are CAN-FD-capable **physical transceivers**, not CAN FD controllers.
- Teensy 4.1 does not provide two independent CAN FD-capable controller channels on CAN1/CAN2 in the same way R9 is wired.
- Therefore R9 is useful as a dual classic CAN 2.0 + LIN/K prototype, but it is not true dual CAN FD.

## R10 goal

Build a true dual CAN FD + LIN/K interface:

```text
Teensy 4.1 SPI bus
    -> MCP2518FD #1 CAN FD controller -> MCP2562FD #1 transceiver -> CAN FD channel A
    -> MCP2518FD #2 CAN FD controller -> MCP2562FD #2 transceiver -> CAN FD channel B
Teensy GPIO/UART-style pins
    -> TLIN1029 LIN/K transceiver -> selectable OBD/AUX single-wire source
```

## Recommended architecture

### CAN FD controller stage

Use two external CAN FD controllers:

- `MCP2518FD x2`
- Preferred beginner-friendly package: `SOIC-14`, if available for the selected exact orderable part.
- Alternative compact package: VDFN/QFN, but harder for hand assembly.

Each MCP2518FD needs:

- SPI: SCK, MOSI, MISO shared between both controllers.
- Separate chip-select pin per controller.
- Separate interrupt pin per controller.
- Optional reset pin, either shared or separate.
- Local decoupling close to VDD/ground.
- Crystal/oscillator network according to selected MCP2518FD variant/reference design.
- Short digital routing to the Teensy SPI pins.

### CAN FD transceiver stage

Keep MCP2562FD transceivers:

- `MCP2562FD x2`
- VIO tied to Teensy +3.3 V logic rail.
- VDD on +5 V regulated rail.
- TXD/RXD connect to the MCP2518FD TXCAN/RXCAN pins, not directly to Teensy CAN1/CAN2.
- STBY controlled by Teensy GPIO or pulled to a safe default.

### LIN/K stage

Keep the R9 LIN/K concept:

- `TLIN1029DRQ1`
- SW2 source selection from OBD7, OBD15, OBD1, OBD8, OBD9, OBD12, OBD13, AUX.
- Keep the rule: exactly one LIN/K source enabled at a time.
- Confirm default EN/sleep state during Teensy reset.

## Proposed Teensy pin allocation

Use Teensy 4.1 primary SPI pins unless a firmware constraint says otherwise:

| Function | Proposed Teensy pin | Notes |
|---|---:|---|
| SPI SCK | 13 | Shared MCP2518FD SCK |
| SPI MOSI | 11 | Shared MCP2518FD MOSI |
| SPI MISO | 12 | Shared MCP2518FD MISO |
| CANFD_A_CS | 10 | MCP2518FD A chip select |
| CANFD_B_CS | 9 | MCP2518FD B chip select |
| CANFD_A_INT | 2 | MCP2518FD A interrupt |
| CANFD_B_INT | 3 | MCP2518FD B interrupt |
| CANFD_RESET | 4 | Optional shared reset; can be changed |
| LIN_EN | 6 | Reuse R9-style control if practical |
| LIN_RX | 7 | Reuse R9-style control if practical |
| LIN_TX | 8 | Reuse R9-style control if practical |

These are provisional. Final allocation must be checked against firmware libraries, Teensy boot behavior, and physical routing.

## R10 layout changes from R9

Required PCB changes:

1. Add two MCP2518FD footprints.
2. Add oscillator/crystal or clock source components required by the selected MCP2518FD reference circuit.
3. Add local decoupling capacitors for both MCP2518FD ICs.
4. Reroute Teensy CAN_A_TX/RX and CAN_B_TX/RX away from the transceivers.
5. Connect MCP2518FD TXCAN/RXCAN pins to MCP2562FD TXD/RXD pins.
6. Route shared SPI bus from Teensy to both MCP2518FD chips.
7. Route CS/INT/RESET control lines.
8. Keep CAN bus side routing from MCP2562FD to SW1/OBD/AUX concept.
9. Re-run DRC and JLCPCB DFM preview.
10. Create authoritative schematic before claiming fab-ready.

## Important design gates before fabrication

R10 should not be called FAB_READY until:

- Exact MCP2518FD orderable part/package is chosen.
- Datasheet pinout is verified against footprint and symbol.
- Oscillator/crystal circuit is copied from datasheet/reference design.
- Authoritative `.kicad_sch` exists and ERC passes or documented exceptions are reviewed.
- PCB DRC passes.
- Gerbers/drills export cleanly.
- JLCPCB DFM preview is acceptable.
- BOM matches actual PCB footprints.
- Firmware pin map is documented.

## R9 order recommendation after this decision

If true dual CAN FD is required, do **not** order R9 as the main target board.

R9 can still be ordered only as a cheap learning/bench prototype for:

- power section validation;
- OBD pigtail pad mechanics;
- DIP-switch ergonomics;
- LIN/K source selection testing;
- classic CAN 2.0 experiments.

But R9 should not be represented as the final true dual CAN FD interface.
