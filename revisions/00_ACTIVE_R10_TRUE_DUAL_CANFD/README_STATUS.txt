R10 TRUE DUAL CAN FD / LIN-K - ACTIVE REVISION

Active board:
  kicad/teensy-41-true-dual-canfd-lin-r10.kicad_pcb

Architecture:
  Teensy 4.1 SPI -> two MCP2518FD CAN FD controllers -> MCP2562FD transceivers
  LIN/K interface and DIP/pigtail routing options retained from project requirements.

Verification status after cleanup:
  KiCad CLI DRC recheck from this cleaned folder is stored in:
    reports/R10_TRUE_DUAL_CANFD_DRC_RECHECK.rpt

Expected clean result:
  0 DRC violations
  0 unconnected pads
  0 footprint errors

Manufacturing files:
  package/R10_TRUE_DUAL_CANFD_JLCPCB_GERBERS.zip

Full handoff/source package:
  package/R10_TRUE_DUAL_CANFD_FULL_PACKAGE.zip

Notes:
  - This revision was promoted from the user-routed file originally named `test.kicad_pcb`.
  - A track-width optimization attempt was tested on a disposable copy and rejected because it introduced clearance violations.
  - The clean FreeRouting result was preserved instead of applying unsafe changes.
  - Before ordering, still visually confirm Teensy header orientation, OBD/pigtail pad mapping, DIP switch orientation, and assembly side choices.
