# JLCPCB latest screenshot review — 2026-06-29

Reviewed latest screenshots from `/mnt/VM share/Pictures/`:

- `Screenshot_20260629_160714.png`
- `Screenshot_20260629_160736.png`

## Screenshot 1 — Silkscreen to pad

JLCPCB page:

- `Silkscreen layer analysis > Silkscreen to pad`
- Layer: `Top silkscreen`
- Counts shown: `(18, 32, 0)`
  - 18 danger
  - 32 warning
  - 0 good for that filtered layer summary
- Example value: `0.12 mm`
- Alert thresholds shown:
  - Danger below `0.13 mm`
  - Warning below `0.18 mm`
  - Good above `0.18 mm`

Meaning:

- This is not a copper, drill, netlist, or electrical error.
- It means JLC thinks some top silkscreen ink is too close to exposed pads and may print on pads or be clipped/voided.
- It can make soldering uglier and can sometimes trigger manual review/rejection depending on the fab flow.

## Screenshot 2 — Silkscreen to hole

JLCPCB page:

- `Silkscreen layer analysis > Silkscreen to hole`
- Layer: `Top silkscreen`
- Counts shown: `(4, 1, 4)`
  - 4 danger
  - 1 warning
  - 4 good
- Example values: `0.01 mm`, `0.08 mm`, `0.1 mm`, `0.14 mm`, `0.24 mm`
- Alert thresholds shown:
  - Danger below `0.13 mm`
  - Warning below `0.18 mm`
  - Good above `0.18 mm`

Meaning:

- This is also a silkscreen manufacturability issue, not a board-function issue.
- Risk is ink bleeding into holes or silkscreen being clipped around holes.

## Are these blocking manufacturability?

Electrically: **No.**

They do not affect copper traces, drills, solder mask openings, or net connectivity.

Manufacturing-order flow: **Possibly.**

JLCPCB labels some items as `Danger`, so their order system or CAM review may block, ask for approval, or silently modify/remove the affected silkscreen.

For a prototype, the safest approach is to remove top silkscreen from the submitted manufacturing Gerbers rather than changing copper layout.

## Correction made

Created a no-silkscreen JLCPCB upload package.

Source board used:

- `hardware/kicad/teensy-41-dual-canfd-lin-r9-jlc-silkfix.kicad_pcb`

DRC verification:

- Report: `fabrication/r9/reports/drc-jlc-nosilk-source.rpt`
- KiCad DRC violations: `0`
- Unconnected pads: `0`
- Footprint errors: `0`

New upload package:

- `fabrication/r9/package/JLCPCB_UPLOAD_R9_NOSILK_GERBERS_20260629T101500Z.zip`
- SHA256: `aa7b8e65b058fb386f445408de3171bc6650e2acfc77c80271a521d93a10be8f`

This package contains:

- Front copper
- Back copper
- Front solder mask
- Back solder mask
- Edge cuts
- Drill file
- Gerber job file

It intentionally omits top and bottom silkscreen layers.

## Tradeoff

Benefit:

- Removes the JLC silkscreen-to-pad and silkscreen-to-hole danger/error categories.
- Avoids risky copper/routing changes.
- Highest chance of clean JLC manufacturability acceptance.

Downside:

- The fabricated PCB will not have printed reference designators or component outlines.
- Use KiCad/PDF/assembly notes during hand assembly instead.

## Recommendation

Upload this package for the first prototype:

- `JLCPCB_UPLOAD_R9_NOSILK_GERBERS_20260629T101500Z.zip`

Keep the stencil package unchanged:

- `JLCPCB_STENCIL_R9_FRONT_PASTE_20260629T094626Z.zip`

If a later revision needs nice silkscreen, fix it properly by editing/removing specific footprint silkscreen outlines around through-hole pads and holes, then rerun JLC DFM. For this first prototype, no-silkscreen is the safest order path.
