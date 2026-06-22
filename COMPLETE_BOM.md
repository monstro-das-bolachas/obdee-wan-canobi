# Complete Component Bill of Materials for Teensy 4.1 Dual CAN + LIN Shield

## Master Bill of Materials (Commercial Shield Style)

This is the complete production BOM for the Teensy 4.1 Dual CAN + LIN Shield designed following MrDIY CAN Shield philosophy with enhanced functionality.

---

## 1. POWER SUPPLY SUBSYSTEM (12V → 5V @ 3A)

### Voltage Regulation
| Reference | Component | Value | Package | Quantity | LCSC | Alt Supplier |
|-----------|-----------|-------|---------|----------|------|-------------|
| U1 | LM2596-5.0 | Fixed 5V Output | TO-263-5 | 1 | C2837758 | Texas Instruments, Texas Instruments |
| L1 | Power Inductor | 47μH, 3A | Coilcraft XFL4030 | 1 | C60578 | Taiyo Yuden, Coilcraft |
| C1 | Electrolytic Capacitor | 1000μF, 25V | Radial, 10mm | 1 | C28041 | Panasonic, Nichicon |
| C2 | Ceramic Capacitor | 100μF, 16V | 0805 | 1 | C96100 | Samsung, Murata |
| C3 | Ceramic Capacitor | 470μF, 10V | 1206 | 1 | C96767 | TDK, Samsung |
| D1 | Schottky Diode | 1N5822, 30V, 3A | DO-201AD | 1 | C4149 | Vishay, ON Semi |
| D2 | Schottky Diode | 1N5822, 30V, 3A | DO-201AD | 1 | C4149 | Vishay, ON Semi |
| F1 | Polyfuse | 1A Hold, 2A Trip | Radial, 5mm | 1 | C318465 | Bussmann, Littelfuse |

**Power Supply Subtotal: €10-15**

---

## 2. CAN BUS INTERFACES (Dual CAN)

### CAN1 Transceiver (Engine CAN)
| Reference | Component | Value | Package | Quantity | LCSC | Alt Supplier |
|-----------|-----------|-------|---------|----------|------|-------------|
| U2 | CAN Transceiver | TJA1051T | SOIC-8 | 1 | C29210 | NXP, Microchip |
| C4 | Ceramic Capacitor | 0.1μF, 16V | 0603 | 1 | C14663 | Samsung, Murata |
| R1 | Termination Resistor | 120Ω, 0.25W | 0603 | 1 | C25805 | Yageo, KOA |
| R2 | Termination Resistor | 120Ω, 0.25W | 0603 | 1 | C25805 | Yageo, KOA |

### CAN2 Transceiver (Chassis CAN)
| Reference | Component | Value | Package | Quantity | LCSC | Alt Supplier |
|-----------|-----------|-------|---------|----------|------|-------------|
| U3 | CAN Transceiver | TJA1051T | SOIC-8 | 1 | C29210 | NXP, Microchip |
| C5 | Ceramic Capacitor | 0.1μF, 16V | 0603 | 1 | C14663 | Samsung, Murata |
| R3 | Termination Resistor | 120Ω, 0.25W | 0603 | 1 | C25805 | Yageo, KOA |
| R4 | Termination Resistor | 120Ω, 0.25W | 0603 | 1 | C25805 | Yageo, KOA |

**CAN Bus Subtotal: €12-16**

---

## 3. LIN BUS INTERFACE

### LIN Transceiver
| Reference | Component | Value | Package | Quantity | LCSC | Alt Supplier |
|-----------|-----------|-------|---------|----------|------|-------------|
| U4 | LIN Transceiver | TJA1020T | SOIC-8 | 1 | C75149 | NXP, Microchip |
| C6 | Ceramic Capacitor | 0.1μF, 16V | 0603 | 1 | C14663 | Samsung, Murata |

**LIN Bus Subtotal: €4-6**

---

## 4. PROTECTION CIRCUITRY

### Input Protection (Automotive 12V)
| Reference | Component | Value | Package | Quantity | LCSC | Alt Supplier |
|-----------|-----------|-------|---------|----------|------|-------------|
| D3 | TVS Diode | P6KE30CA, 30V | DO-204AC | 1 | C4411 | Littelfuse, Vishay |
| D4 | TVS Diode | P6KE30CA, 30V | DO-204AC | 1 | C4411 | Littelfuse, Vishay |
| D5 | TVS Diode | P6KE30CA, 30V | DO-204AC | 1 | C4411 | Littelfuse, Vishay |
| D6 | TVS Diode | P6KE30CA, 30V | DO-204AC | 1 | C4411 | Littelfuse, Vishay |
| C7 | Ceramic Capacitor | 10μF, 25V | 1206 | 1 | C96767 | TDK, Samsung |
| C8 | Ceramic Capacitor | 10μF, 25V | 1206 | 1 | C96767 | TDK, Samsung |

**Protection Subtotal: €3-5**

---

## 5. CONNECTORS

### Teensy 4.1 Interface
| Reference | Component | Type | Package | Quantity | Alt Supplier |
|-----------|-----------|------|---------|----------|-------------|
| J1 | Teensy 4.1 Header Block | 2x24 Pins, 2.54mm | Through-Hole, Vertical | 1 | Molex, Harwin |

**Teensy Header Subtotal: €4-6**

### OBD2 Vehicle Interface
| Reference | Component | Type | Package | Quantity | Alt Supplier |
|-----------|-----------|------|---------|----------|-------------|
| J2 | OBD2 DB9 Female | 9-Pin DB9, PCB Mount | Through-Hole, Vertical | 1 | TE Connectivity, Amphenol |

**OBD2 Connector Subtotal: €8-12**

### Programming Interface
| Reference | Component | Type | Package | Quantity | Alt Supplier |
|-----------|-----------|------|---------|----------|-------------|
| J3 | USB-C Receptacle | USB 2.0, 16-Pin | Through-Hole, Horizontal | 1 | GCT, Molex |

**USB-C Connector Subtotal: €3-5**

### Power Input
| Reference | Component | Type | Package | Quantity | Alt Supplier |
|-----------|-----------|------|---------|----------|-------------|
| J4 | 12V Terminal Block | 2-Pin, 5.08mm | Through-Hole | 1 | Phoenix, WAGO |

**Terminal Block Subtotal: €2-4**

**Connectors Subtotal: €17-27**

---

## 6. TEST POINTS

### Signal Access
| Reference | Component | Type | Package | Quantity | Alt Supplier |
|-----------|-----------|------|---------|----------|-------------|
| TP1 | Test Point | Gold Plated | 0.8mm | 1 | Harwin, Keystone |
| TP2 | Test Point | Gold Plated | 0.8mm | 1 | Harwin, Keystone |
| TP3 | Test Point | Gold Plated | 0.8mm | 1 | Harwin, Keystone |
| TP4 | Test Point | Gold Plated | 0.8mm | 1 | Harwin, Keystone |

**Test Points Subtotal: €1-2**

---

## COMPLETE BOM SUMMARY

### Component Category Breakdown
| Category | Quantity | Cost Range |
|----------|----------|------------|
| Power Supply | 8 | €10-15 |
| CAN Transceivers | 8 | €12-16 |
| LIN Transceiver | 2 | €4-6 |
| Protection | 8 | €3-5 |
| Connectors | 4 | €17-27 |
| Test Points | 4 | €1-2 |
| **TOTAL PCB COMPONENTS** | 34 | **€47-71** |

### Additional Required Items (Not on PCB)
| Item | Description | Cost Range |
|------|-------------|------------|
| Teensy 4.1 | Main processing unit | €25-30 |
| Header Pins | Pre-soldered to Teensy | €2-4 |
| OBD2 Cable | For vehicle connection | €5-10 |
| USB-C Cable | Programming | €3-5 |
| **ADDITIONAL HARDWARE** | - | **€35-49** |

### Complete Package Cost
| Category | Cost Range |
|----------|------------|
| PCB Fabrication | €20-30 |
| PCB Components | €47-71 |
| Additional Hardware | €35-49 |
| **TOTAL PROJECT COST** | **€102-150** |

---

## SUGGESTED SUPPLIER ORDERING STRATEGY

### Primary Supplier (LCSC.com - China)
1. Power Supply Components
2. CAN/LIN Transceivers
3. Protection Components
4. Passives

Cost: €40-60 (electronics only)

### Secondary Suppliers (Europe/US)
1. Connectors (may require minimum order)
2. High-quality inductors (if LCSC unavailable)
3. Teensy 4.1 (PJRC.com)

Cost: €30-40

### Recommended Order Sequence
1. Order connectors and Teensy first (lead time ~2-3 weeks)
2. Order PCB components from LCSC (lead time ~1-2 weeks)
3. Order PCB fabrication (parallel to component ordering)
4. Final assembly when all parts arrive

---

## CRITICAL NOTES

### Component Substitutions
- **LM2596-5.0**: Can substitute with LM2596-ADJ + external resistors if fixed voltage unavailable
- **TJA1051**: Can use TJA1051TJ (J-lead) if RTN version unavailable
- **TJA1020**: Can use TJA1020TJ (J-lead) if RTN version unavailable
- **Inductor L1**: Must be rated for ≥3A current, low DC resistance (≤15mΩ)

### Quality Considerations
- **Automotive Grade**: TJA1051/TJA1020 are automotive-grade transceivers
- **Temperature Range**: -40°C to +125°C for vehicle use
- **ESD Protection**: STMicroelectronics P6KE series for better reliability

### Manufacturing Notes
- **PCB Stack**: 4-layer recommended for proper CAN differential pair routing
- **Impedance Control**: 83Ω differential for CAN bus
- **Via Stubs**: Minimize in CAN differential pairs for signal integrity
- **Thermal Management**: Add thermal relief pads for power to SOIC-8 transceivers

---

This BOM provides a complete, production-ready bill of materials for the Teensy 4.1 Dual CAN + LIN Shield following commercial shield design philosophy.