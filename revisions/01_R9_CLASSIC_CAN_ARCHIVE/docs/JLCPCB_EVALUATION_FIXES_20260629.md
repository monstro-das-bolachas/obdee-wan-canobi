# JLCPCB evaluation review and fixes — 2026-06-29

Input screenshots reviewed from `/mnt/VM share/Pictures/`:

- `Screenshot_20260629_153555.png`
- `Screenshot_20260629_153637.png`
- `Screenshot_20260629_153702.png`
- `Screenshot_20260629_154035.png`
- `Screenshot_20260629_154057.png`

## JLCPCB findings

### 1. Routing layer analysis — annular ring

JLCPCB warning:

- Top copper: warnings for annular ring width around `0.15 mm`
- Bottom copper: warnings for annular ring width around `0.15 mm`

KiCad source check:

- Component through-hole pads have larger annular rings, minimum around `0.35 mm`.
- The warnings correspond to vias: `0.6 mm` via diameter with `0.3 mm` drill, i.e. `0.15 mm` annular ring.

Action taken:

- Tested increasing vias to `0.7 mm` diameter. This caused 9 real KiCad clearance violations, so it was **not promoted**.
- Left vias at `0.6/0.3 mm`; this is a JLC warning-threshold item, not a KiCad failure.

Recommendation:

- Accept this warning for the first prototype unless JLCPCB blocks fabrication. Do not enlarge vias without rerouting.

### 2. Soldermask layer analysis — solder mask opening exposing trace

JLCPCB warning:

- One top-soldermask warning around `0.1 mm` clearance from a mask opening to a nearby trace.

KiCad status:

- KiCad DRC remains clean.
- This is a manufacturability warning, not a KiCad hard error.

Action taken:

- No copper/routing change made, because changing routing without exact JLC coordinates risks introducing worse errors.

Recommendation:

- Accept if JLCPCB allows it; if they reject, request their exact coordinate/object location and reroute that local trace.

### 3. Silkscreen to pad

JLCPCB warning:

- Top silkscreen too close to pads; many warning entries.

Action taken:

- Created a JLC-specific source variant:
  - `hardware/kicad/teensy-41-dual-canfd-lin-r9-jlc-silkfix.kicad_pcb`
- Thickened top silkscreen footprint strokes from `0.12 mm` to `0.15 mm`.
- Exported Gerbers with KiCad's `--subtract-soldermask` option so silkscreen is clipped away from solder-mask openings/pads.

### 4. Silkscreen to hole

JLCPCB warning:

- Top silkscreen too close to holes; some danger/warning entries.

Action taken:

- Same silkscreen fix as above: thicker silkscreen plus soldermask-subtracted Gerber plotting.

### 5. Silkscreen line width

JLCPCB warning:

- Many top silkscreen lines at `0.12 mm`.

Action taken:

- Thickened 446 top silkscreen graphical strokes to `0.15 mm`.
- KiCad DRC after the change: `0 violations`, `0 unconnected pads`, `0 footprint errors`.

## Verification

Corrected JLC-specific board:

- `hardware/kicad/teensy-41-dual-canfd-lin-r9-jlc-silkfix.kicad_pcb`

KiCad DRC report:

- `fabrication/r9/reports/drc-jlc-silkfix.rpt`

Result:

- DRC violations: `0`
- Unconnected pads: `0`
- Footprint errors: `0`

## New JLCPCB upload package

Use this new package instead of the earlier upload ZIP:

- `fabrication/r9/package/JLCPCB_UPLOAD_R9_JLC_SILKFIX_GERBERS_20260629T094626Z.zip`
- SHA256: `29364e7b4dc51a743bf5096e7a98fe817c0c0b5b58d173967a7c7d829d843632`

This package contains copper, mask, silkscreen, edge cuts, drill, and Gerber job files at ZIP root.

## Stencil package

For a standalone top/front stencil order:

- `fabrication/r9/package/JLCPCB_STENCIL_R9_FRONT_PASTE_20260629T094626Z.zip`
- SHA256: `9eb4de3f5875f06c347c607f3e65f37edc2c77c711e7bf1826768ada0d7cb9ba`

This package contains:

- Front paste layer: `F_Paste.gtp`
- Board outline: `Edge_Cuts.gm1`

Recommended stencil settings:

- Top/front side only
- Frameless
- `0.12 mm` thickness
- No nano coating
- No electropolishing
- No step stencil

## Remaining expected JLCPCB warnings

After using the new silkscreen-fixed package, the silkscreen warnings should be reduced or cleared.

The annular-ring warnings may remain for the 0.6/0.3 mm vias. These are at JLCPCB's warning threshold. KiCad DRC passes, and enlarging the vias without rerouting caused clearance errors.

The one soldermask-opening-to-trace warning may also remain. Treat it as acceptable unless JLCPCB refuses production or gives exact coordinates requiring a local reroute.
