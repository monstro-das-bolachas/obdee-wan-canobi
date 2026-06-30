Teensy 4.1 CAN/LIN interface project - cleaned layout

Start here:

1. Active current revision:
   revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/

2. Active KiCad board:
   revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/kicad/teensy-41-true-dual-canfd-lin-r10.kicad_pcb

3. Active JLCPCB Gerber upload ZIP:
   revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/package/R10_TRUE_DUAL_CANFD_JLCPCB_GERBERS.zip

4. Active full handoff/source package:
   revisions/00_ACTIVE_R10_TRUE_DUAL_CANFD/package/R10_TRUE_DUAL_CANFD_FULL_PACKAGE.zip

5. Previous R9/classic-CAN archive:
   revisions/01_R9_CLASSIC_CAN_ARCHIVE/

6. Cleanup manifests:
   99_MANIFESTS/cleanup_manifest_before_reorg_20260630.json
   99_MANIFESTS/cleanup_actions_20260630.json

Important status:
- R10 is the current true dual CAN FD architecture using MCP2518FD controllers.
- R9 is retained only as historical/classic-CAN archive material.
- Test, draft, failed optimization, intermediate DRC, FreeRouting scratch, and invalid R10 working files were removed from the root project after preserving the active R10 and R9 archive artifacts.
- KiCad DRC must be checked from the active revision folder before ordering.
