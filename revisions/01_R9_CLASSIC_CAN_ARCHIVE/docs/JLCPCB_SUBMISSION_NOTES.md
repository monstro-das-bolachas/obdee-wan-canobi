# JLCPCB submission notes — R9 CAN/LIN interface

Date prepared: 2026-06-29

## Security note

Do **not** store JLCPCB credentials in this repository or in a plaintext `.txt` file.

Use a password manager instead. If account recovery details are needed, store only a non-secret note such as the account email address and recovery owner, never the password or 2FA backup codes.

## Current order recommendation

Because the project target is now **true dual CAN FD**, do **not** order R9 as the final/interface target. R9 can still be ordered only as an optional bench-learning prototype for power, OBD pigtail mechanics, DIP switches, LIN/K, and classic CAN 2.0.

For the true FD target, proceed to R10 with MCP2518FD controllers. See `docs/R10_TRUE_DUAL_CAN_FD_REDESIGN_PLAN.md`.

## Recommended R9 bench-only upload package

Use this corrected Gerber-only ZIP for JLCPCB upload/evaluation. It includes JLC-specific silkscreen fixes based on the 2026-06-29 JLCPCB preview screenshots:

- `fabrication/r9/package/JLCPCB_UPLOAD_R9_JLC_SILKFIX_GERBERS_20260629T094626Z.zip`
- SHA256: `29364e7b4dc51a743bf5096e7a98fe817c0c0b5b58d173967a7c7d829d843632`

Earlier superseded upload ZIP:

- `fabrication/r9/package/JLCPCB_UPLOAD_R9_teensy-41-dual-canfd-lin_GERBERS_ONLY_20260629.zip`
- SHA256: `48bb759698e0248d32a82fbea188f86bcc9c9b2e903e5315862a93c9dfe105cf`

This ZIP contains the manufacturing layers at the archive root:

- `F_Cu.gtl`
- `B_Cu.gbl`
- `F_Mask.gts`
- `B_Mask.gbs`
- `F_Silkscreen.gto`
- `B_Silkscreen.gbo`
- `Edge_Cuts.gm1`
- `.drl`
- `.gbrjob`

## Verification basis

Project status file: `CURRENT_STATUS.md`

The R9 board was previously verified with KiCad CLI 10.0.3:

- DRC violations: 0
- Unconnected pads/items: 0
- Footprint errors: 0
- Gerber/drill export: passed

This is **prototype hardware**. Bench-test before vehicle use.

## Suggested JLCPCB options for first prototype batch

For first-run bare PCBs:

- Product: FR-4 PCB
- Layers: 2
- Quantity: 5
- Delivery format: Single PCB
- PCB thickness: 1.6 mm
- Copper weight: 1 oz
- PCB color: Green, or any preferred color
- Surface finish: LeadFree HASL for cost, or ENIG if budget allows
- Electrical test: Flying Probe Fully Test
- Mark on PCB: Remove Mark, if available/preferred
- Assembly: No for the first bare-board validation run

## Upload flow

1. Go to https://jlcpcb.com/ and choose **Order Now** / **Online PCB Quote**.
2. Upload `JLCPCB_UPLOAD_R9_JLC_SILKFIX_GERBERS_20260629T094626Z.zip`.
3. Confirm JLCPCB detects the board as 2-layer FR-4 and reads the outline/dimensions correctly.
4. Select the suggested options above.
5. Let JLCPCB run its online Gerber/DFM preview.
6. Check the preview carefully:
   - board outline present;
   - front/back copper visible;
   - drill holes visible;
   - solder mask openings on pads;
   - silkscreen readable and not on pads;
   - no unexpected panelization.
7. If JLCPCB raises a fabrication question, do not approve automatically; review the message against the KiCad source and DRC report.

## Required real-world checks before use

1. Verify the OBD2 pigtail pinout with a multimeter before soldering.
2. Bench-test the power section with current limiting.
3. Verify +5 V before installing the Teensy.
4. Confirm DIP-switch settings.
5. Start with passive/read-only firmware.
6. Do not transmit vehicle frames until bench and passive capture tests pass.
