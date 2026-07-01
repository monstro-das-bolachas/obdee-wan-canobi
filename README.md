# OBDee-Wan CANobi

    An open-source, open-hardware automotive interface for hackers, makers, reverse engineers, and the dangerously curious.
    
    OBDee-Wan CANobi is a Teensy 4.1-based vehicle bus tool designed to make CAN FD, classic CAN, LIN, and K-line experimentation more approachable. The goal is simple: build a powerful but understandable interface that everyday tinkerers can assemble, inspect, modify, and learn from.
    
    This project is not meant to be a black box. It is meant to be a teaching tool, a hacking platform, and a practical bridge between a laptop and the electrical nervous system of a vehicle.
    
##  What it is
    
    OBDee-Wan CANobi is an open hardware board for automotive diagnostics and reverse engineering. It is designed around:
    
    - Teensy 4.1
    - Dual external CAN FD controllers
    - Dual CAN FD transceivers
    - LIN / K-line interface support
    - OBD pigtail-friendly wiring
    - DIP-switch configurable routing
    - Beginner-visible design decisions
    - KiCad source files and manufacturing outputs
    
##  The project aims to be useful for:
    
    - automotive reverse engineering
    - CAN FD experimentation
    - LIN and K-line learning
    - custom diagnostic tools
    - EV conversion projects
    - maker/hacker education
    - bench testing vehicle modules
    - understanding how vehicle networks actually work
    
##  Philosophy
    
    Most vehicle bus tools are either expensive, closed, overcomplicated, or hard to modify.
    
    OBDee-Wan CANobi tries to be different:
    
    - open source
    - open hardware
    - understandable
    - repairable
    - hackable
    - affordable
    - documented for humans, not just engineers
    
    This is a tool for the person who wants to know what is happening on the wire, not just click buttons in a vendor app.
    
##  Current status
    
    R11 is a prototype manufacturing candidate.
    
    It is suitable for ordering a small bare-PCB batch for bench bring-up and validation.
    
    It is not yet approved for direct vehicle use.
    
    Before connecting to a real vehicle, assembled boards must pass:
    
    - bare PCB continuity checks
    - power rail short checks
    - current-limited bench power-up
    - OBD/pigtail pin mapping verification
    - DIP-switch default-state review
    - CAN/LIN/K-line bench testing
    - fused vehicle connection procedure
    
##  Safety warning
    
    Vehicle electrical systems can damage tools, modules, or cars if connected incorrectly.
    
    This project is provided for education, experimentation, and bench validation. Use at your own risk. Do not connect untested hardware directly to a vehicle.
    
    When in doubt:
    
    - use a bench supply
    - use current limiting
    - use fuses
    - verify pinouts with a multimeter
    - test on spare modules before testing on a car
    
##  License
    
    This project is open source and open hardware.
    
    - Hardware design files: CERN-OHL-P-2.0
    - Firmware/software: MIT
    - Documentation: CC-BY-4.0
    
    You are free to study, modify, build, remix, and share this project.  
    Attribution is appreciated and required by the licenses: please credit the original project and author when reusing or publishing derivative work.
