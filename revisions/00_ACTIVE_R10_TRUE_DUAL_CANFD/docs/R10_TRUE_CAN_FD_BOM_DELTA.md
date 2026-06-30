# R10 true CAN FD BOM delta

Status: preliminary BOM delta for redesign from R9 to R10.

This file lists the functional BOM changes required to turn R9 from dual classic CAN into true dual CAN FD.

## Add

| Qty | Function | Suggested part family | Package preference | Notes |
|---:|---|---|---|---|
| 2 | CAN FD controller | MCP2518FD | SOIC-14 preferred if orderable; otherwise VDFN/QFN variant | One per CAN FD channel |
| 2 | Controller decoupling | 100 nF ceramic | 0805 or 0603 | Place close to each MCP2518FD VDD pin |
| 2 | Bulk/local decoupling | 1 uF to 4.7 uF ceramic | 0805 | Local digital supply support |
| 2 | Clock source | Crystal/resonator/oscillator per MCP2518FD datasheet/reference design | TBD | Exact values depend on selected clock architecture |
| 4 | Crystal load capacitors | Datasheet-calculated | 0603/0805 | Only if using crystal requiring external load caps |
| 2 | INT pull-up/pad option | 10 kΩ optional | 0805 | Depending on firmware/input configuration |
| 2 | CS pull-up option | 10 kΩ optional | 0805 | Keeps controllers deselected during reset |
| 1 | Reset pull-up/down option | 10 kΩ optional | 0805 | If using shared reset line |
| 2-4 | Test pads | SPI/INT/CS debug pads | test point pads | Optional but recommended for first prototype |

## Keep from R9

| Ref/function | Keep? | Notes |
|---|---|---|
| MCP2562FD transceivers | Yes | TXD/RXD move from Teensy direct CAN pins to MCP2518FD TXCAN/RXCAN |
| TLIN1029 LIN/K | Yes | Keep SW2 selection rule: exactly one source |
| OBD2 pigtail solder pads | Yes | Safer than unverified board-mounted J1962 connector |
| SW1 CAN normal/cross routing | Probably | Re-check against CAN FD routing/signal integrity |
| SW2 LIN/K source selector | Yes | Verify source labels and no OBD16 LIN path |
| LM2596S-5.0 buck | Maybe | Acceptable for bench prototype; consider modern automotive buck for robust final version |
| Test points | Yes | Add SPI/CANFD controller debug pads if space permits |

## Remove / reroute

| R9 item | R10 action |
|---|---|
| Teensy CAN_A_TX/CAN_A_RX directly to U2 | Reroute MCP2518FD_A TXCAN/RXCAN to U2 |
| Teensy CAN_B_TX/CAN_B_RX directly to U3 | Reroute MCP2518FD_B TXCAN/RXCAN to U3 |
| R9 documentation calling board dual CAN FD | Replace with R10-only true-CAN-FD language |

## Firmware implications

R10 firmware needs an MCP2518FD driver/library instead of direct Teensy CAN1/CAN2 use for the two FD channels.

Required firmware configuration:

- SPI bus pins.
- CANFD_A CS pin.
- CANFD_B CS pin.
- CANFD_A INT pin.
- CANFD_B INT pin.
- Optional shared reset pin.
- Clock frequency configured to match the selected MCP2518FD oscillator.

## Open engineering decisions

Before layout starts:

1. Select exact MCP2518FD orderable part/package.
2. Select clock architecture and frequency.
3. Decide whether the board remains 2-layer or moves to 4-layer.
4. Decide whether to keep LM2596 for R10 prototype or replace it with an automotive buck.
5. Confirm firmware library support and pin allocation.
