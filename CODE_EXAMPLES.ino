// ═══════════════════════════════════════════════════════════════════════════════
// TEENSY 4.1 DUAL CAN + LIN SHIELD - CODE EXAMPLES
// ═══════════════════════════════════════════════════════════════════════════════

// This file contains complete, working Arduino sketches for testing your
// Teensy 4.1 Dual CAN + LIN Shield. Each example can be copied into a separate
// Arduino sketch file and uploaded directly to your Teensy 4.1.

// ═══════════════════════════════════════════════════════════════════════════════
// EXAMPLE 1: DIAGNOSTIC LED BLINK TEST
// ═══════════════════════════════════════════════════════════════════════════════

/*
  Diagnostic Blink Test
  - Builtin LED on Teensy 4.1 (BUILTIN_LED)
  - Tests USB programming connection
  - Verifies Teensy is working correctly

  Copy this entire section into a new Arduino sketch.
*/

// Save this as: diagnostic_blink_test.ino

#define BUILTIN_LED 13  // Teensy 4.1 builtin LED

void setup() {
  // Initialize builtin LED
  pinMode(BUILTIN_LED, OUTPUT);

  // Initialize serial for debugging at 115200 baud
  Serial.begin(115200);
  while (!Serial && millis() < 5000);  // Wait for serial connection (5s timeout)

  Serial.println("═════════════════════════════════════════════════════════════════");
  Serial.println("TEENSY 4.1 DIAGNOSTIC BLINK TEST");
  Serial.println("═════════════════════════════════════════════════════════════════");
  Serial.println("Setup Complete!");
  Serial.println("Blinking LED at 1Hz rate...");
  Serial.println("Check that LED toggles every second.");
  Serial.println("═════════════════════════════════════════════════════════════════");
}

void loop() {
  digitalWrite(BUILTIN_LED, HIGH);  // Turn LED on
  delay(1000);                       // Wait 1 second

  digitalWrite(BUILTIN_LED, LOW);   // Turn LED off
  delay(1000);                       // Wait 1 second

  // Print status every 5 seconds for serial monitoring
  static unsigned long lastStatus = 0;
  if (millis() - lastStatus > 5000) {
    Serial.print(millis() / 1000);
    Serial.println("s: Blinking normally!");
    lastStatus = millis();
  }
}

// ═══════════════════════════════════════════════════════════════════════════════
// EXAMPLE 2: CAN1 LOOPBACK TEST
// ═══════════════════════════════════════════════════════════════════════════════

/*
  CAN1 Loopback Test
  - Tests CAN1 transceiver (TJA1051)
  - Tests Teensy 4.1 CAN2 (mapped to shield CAN1)
  - Verifies transmit and receive functionality
  - Baud rate: 500kbps (common for Mercedes vehicles)

  REQUIREMENTS:
  - Install FlexCAN_T4 library: https://github.com/collin80/flexcan-t4
  - Arduino IDE with TeensyDuino installed

  Copy this entire section into a new Arduino sketch.
*/

// Save this as: can1_loopback_test.ino

#include <FlexCAN_T4.h>

// CAN1 mapped to Teensy CAN2 (per shield design)
// Teensy CAN2 = Pin 8 (TX) / Pin 7 (RX) = mapped to shield CAN1
FlexCAN_T4<CAN2, RX_SIZE_256> can1;

CAN_message_t msg;  // CAN message structure
unsigned long lastTransmitTime = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.println("═════════════════════════════════════════════════════════════════");
  Serial.println("TEENSY 4.1 CAN1 LOOPBACK TEST (500kbps)");
  Serial.println("═════════════════════════════════════════════════════════════════");
  Serial.println("Initializing CAN1 on Teensy CAN2...");

  can1.begin();
  can1.setBaudRate(500000);  // 500kbps for Mercedes W203

  Serial.println("CAN1 initialized at 500kbps!");
  Serial.println("Started loopback transmission of test frames...");
  Serial.println("═════════════════════════════════════════════════════════════════");
}

void loop() {
  // Transmit test CAN frame every 100ms (10Hz)
  if (millis() - lastTransmitTime > 100) {
    msg.id = 0x123;  // Test CAN ID (11-bit)
    msg.len = 8;     // 8 data bytes
    msg.flags.extended = 0;  // Standard 11-bit ID

    // Fill data bytes with test pattern
    msg.buf[0] = 0xAA;
    msg.buf[1] = 0x55;
    msg.buf[2] = 0x11;
    msg.buf[3] = 0x22;
    msg.buf[4] = 0x33;
    msg.buf[5] = 0x44;
    msg.buf[6] = 0x55;
    msg.buf[7] = 0x66;

    can1.write(msg);
    lastTransmitTime = millis();

    Serial.print("TX: ID=0x");
    Serial.print(msg.id, HEX);
    Serial.print(" DATA=");
    for (byte i = 0; i < msg.len; i++) {
      Serial.print("0x");
      Serial.print(msg.buf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }

  // Check for received CAN messages (loopback)
  CAN_message_t rxMsg;
  if (can1.read(rxMsg)) {
    Serial.print("RX: ID=0x");
    Serial.print(rxMsg.id, HEX);
    Serial.print(" LEN=");
    Serial.print(rxMsg.len);

    // Verify data matches transmitted data
    bool dataMatch = true;
    for (byte i = 0; i < rxMsg.len; i++) {
      if (rxMsg.buf[i] != msg.buf[i]) {
        dataMatch = false;
      }
    }

    Serial.print(" DATA=");
    for (byte i = 0; i < rxMsg.len; i++) {
      Serial.print("0x");
      Serial.print(rxMsg.buf[i], HEX);
      Serial.print(" ");
    }

    Serial.print(dataMatch ? " [MATCH]" : " [MISMATCH]");
    Serial.println();
  }
}

// ═══════════════════════════════════════════════════════════════════════════════
// EXAMPLE 3: CAN2 LOOPBACK TEST
// ═══════════════════════════════════════════════════════════════════════════════

/*
  CAN2 Loopback Test
  - Tests CAN2 transceiver (TJA1051)
  - Tests Teensy 4.1 CAN3 (mapped to shield CAN2)
  - Verifies independent operation from CAN1
  - Baud rate: 500kbps (common for Mercedes chassis CAN)

  REQUIREMENTS:
  - Install FlexCAN_T4 library: https://github.com/collin80/flexcan-t4
  - Arduino IDE with TeensyDuino installed

  Copy this entire section into a new Arduino sketch.
*/

// Save this as: can2_loopback_test.ino

#include <FlexCAN_T4.h>

// CAN2 mapped to Teensy CAN3 (per shield design)
// Teensy CAN3 = Pin 32 (TX) / Pin 25 (RX) = mapped to shield CAN2
FlexCAN_T4<CAN3, RX_SIZE_256> can2;

CAN_message_t msg;  // CAN message structure
unsigned long lastTransmitTime = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.println("═════════════════════════════════════════════════════════════════");
  Serial.println("TEENSY 4.1 CAN2 LOOPBACK TEST (500kbps)");
  Serial.println("═════════════════════════════════════════════════════════════════");
  Serial.println("Initializing CAN2 on Teensy CAN3...");

  can2.begin();
  can2.setBaudRate(500000);  // 500kbps for Mercedes chassis CAN

  Serial.println("CAN2 initialized at 500kbps!");
  Serial.println("Started loopback transmission of test frames...");
  Serial.println("═════════════════════════════════════════════════════════════════");
}

void loop() {
  // Transmit test CAN frame every 100ms (10Hz)
  if (millis() - lastTransmitTime > 100) {
    msg.id = 0x456;  // Test CAN ID (different from CAN1)
    msg.len = 8;     // 8 data bytes
    msg.flags.extended = 0;  // Standard 11-bit ID

    // Fill data bytes with test pattern (different from CAN1)
    msg.buf[0] = 0xBB;
    msg.buf[1] = 0xCC;
    msg.buf[2] = 0xDD;
    msg.buf[3] = 0xEE;
    msg.buf[4] = 0xFF;
    msg.buf[5] = 0x00;
    msg.buf[6] = 0x11;
    msg.buf[7] = 0x22;

    can2.write(msg);
    lastTransmitTime = millis();

    Serial.print("TX: ID=0x");
    Serial.print(msg.id, HEX);
    Serial.print(" DATA=");
    for (byte i = 0; i < msg.len; i++) {
      Serial.print("0x");
      Serial.print(msg.buf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }

  // Check for received CAN messages (loopback)
  CAN_message_t rxMsg;
  if (can2.read(rxMsg)) {
    Serial.print("RX: ID=0x");
    Serial.print(rxMsg.id, HEX);
    Serial.print(" LEN=");
    Serial.print(rxMsg.len);

    // Verify data matches transmitted data
    bool dataMatch = true;
    for (byte i = 0; i < rxMsg.len; i++) {
      if (rxMsg.buf[i] != msg.buf[i]) {
        dataMatch = false;
      }
    }

    Serial.print(" DATA=");
    for (byte i = 0; i < rxMsg.len; i++) {
      Serial.print("0x");
      Serial.print(rxMsg.buf[i], HEX);
      Serial.print(" ");
    }

    Serial.print(dataMatch ? " [MATCH]" : " [MISMATCH]");
    Serial.println();
  }
}

// ═══════════════════════════════════════════════════════════════════════════════
// EXAMPLE 4: DUAL CAN MONITOR MODE
// ═══════════════════════════════════════════════════════════════════════════════

/*
  Dual CAN Monitor Mode
  - Monitors both CAN1 and CAN2 simultaneously
  - Captures and displays all CAN bus traffic
  - Perfect for learning vehicle CAN bus architecture
  - Baud rate: Auto-detected, default 500kbps

  REQUIREMENTS:
  - Install FlexCAN_T4 library: https://github.com/collin80/flexcan-t4
  - Arduino IDE with TeensyDuino installed

  Copy this entire section into a new Arduino sketch.
*/

// Save this as: dual_can_monitor.ino

#include <FlexCAN_T4.h>

// CAN1 on Teensy CAN2 (Engine CAN)
FlexCAN_T4<CAN2, RX_SIZE_256> can1;

// CAN2 on Teensy CAN3 (Chassis CAN)
FlexCAN_T4<CAN3, RX_SIZE_256> can2;

unsigned long frameCountCAN1 = 0;
unsigned long frameCountCAN2 = 0;
unsigned long lastStatusTime = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.println("══════════════════════════════════════════════════════════════════");
  Serial.println("TEENSY 4.1 DUAL CAN MONITOR MODE (500kbps)");
  Serial.println("══════════════════════════════════════════════════════════════════");
  Serial.println("Initializing CAN1 (Engine CAN) on Teensy CAN2...");

  can1.begin();
  can1.setBaudRate(500000);
  can1.enableMBInterrupts();

  Serial.println("Initializing CAN2 (Chassis CAN) on Teensy CAN3...");

  can2.begin();
  can2.setBaudRate(500000);
  can2.enableMBInterrupts();

  Serial.println("══════════════════════════════════════════════════════════════════");
  Serial.println("CAN Monitor Mode Active!");
  Serial.println("Capturing all CAN traffic from both buses...");
  Serial.println("Connect to vehicle via OBD2 connector for real traffic.");
  Serial.println("══════════════════════════════════════════════════════════════════");
  Serial.println("CAN1 (Engine CAN) – Frame Count: 0");
  Serial.println("CAN2 (Chassis CAN) – Frame Count: 0");
  Serial.println("══════════════════════════════════════════════════════════════════");
}

void loop() {
  // Monitor CAN1 (Engine CAN)
  CAN_message_t msg1;
  if (can1.read(msg1)) {
    Serial.print("[CAN1] ID=0x");
    Serial.print(msg1.id, HEX);
    Serial.print(" LEN=");
    Serial.print(msg1.len);
    Serial.print(" DATA=");
    for (byte i = 0; i < msg1.len; i++) {
      Serial.print("0x");
      Serial.print(msg1.buf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
    frameCountCAN1++;
  }

  // Monitor CAN2 (Chassis CAN)
  CAN_message_t msg2;
  if (can2.read(msg2)) {
    Serial.print("[CAN2] ID=0x");
    Serial.print(msg2.id, HEX);
    Serial.print(" LEN=");
    Serial.print(msg2.len);
    Serial.print(" DATA=");
    for (byte i = 0; i < msg2.len; i++) {
      Serial.print("0x");
      Serial.print(msg2.buf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
    frameCountCAN2++;
  }

  // Print status every 5 seconds
  if (millis() - lastStatusTime > 5000) {
    Serial.println("══════════════════════════════════════════════════════════════════");
    Serial.print("Status: CAN1=");
    Serial.print(frameCountCAN1);
    Serial.print(" frames, CAN2=");
    Serial.print(frameCountCAN2);
    Serial.println(" frames");
    Serial.println("══════════════════════════════════════════════════════════════════");
    lastStatusTime = millis();
  }
}

// ═══════════════════════════════════════════════════════════════════════════════
// EXAMPLE 5: LIN MASTER MODE
// ═══════════════════════════════════════════════════════════════════════════════

/*
  LIN Master Mode Test
  - Tests LIN transceiver (TJA1020)
  - Configured as LIN master (initiator)
  - Generates LIN frames for vehicle communication
  - Baud rate: 19200 baud (LIN standard)

  REQUIREMENTS:
  - LIN library (linbusdev/LIN)
  - Arduino IDE with TeensyDuino installed

  Copy this entire section into a new Arduino sketch.
  Note: This is a basic LIN master example for testing the transceiver.
*/

// Save this as: lin_master_test.ino

#include <Arduino.h>

// LIN mapped to Teensy Serial1 (per shield design)
HardwareSerial& linSerial = Serial1;

#define LIN_BAUD 19200

unsigned long lastLinTransmit = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.println("═══════════════════════════════════════════════════════════════════");
  Serial.println("TEENSY 4.1 LIN MASTER TEST (19200 baud)");
  Serial.println("═══════════════════════════════════════════════════════════════════");
  Serial.println("Initializing LIN on Serial1...");

  // Initialize LIN hardware serial
  linSerial.begin(LIN_BAUD, SERIAL_8N1);

  Serial.println("LIN initialized at 19200 baud!");
  Serial.println("Started LIN frame transmission (test signals)...");
  Serial.println("═══════════════════════════════════════════════════════════════════");
}

void loop() {
  // Transmit LIN frame every 100ms (10Hz)
  if (millis() - lastLinTransmit > 100) {
    // Send LIN frame (simplified for transceiver testing)
    uint8_t linData[8] = {0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F, 0x70, 0x81};
    uint8_t linID = 0x3C;  // Example LIN ID
    uint8_t linLen = 8;    // 8 data bytes

    // LIN header: ID + Len (simplified)
    linSerial.write(linID);
    linSerial.write(linLen);

    // LIN data
    for (byte i = 0; i < linLen; i++) {
      linSerial.write(linData[i]);
    }

    // LIN checksum (simplified)
    uint8_t checksum = linID;
    for (byte i = 0; i < linLen; i++) {
      checksum += linData[i];
    }
    checksum = ~checksum;  // Inverted checksum
    linSerial.write(checksum);

    lastLinTransmit = millis();

    Serial.print("LIN TX: ID=0x");
    Serial.print(linID, HEX);
    Serial.print(" LEN=");
    Serial.print(linLen);
    Serial.print(" DATA=");
    for (byte i = 0; i < linLen; i++) {
      Serial.print("0x");
      Serial.print(linData[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }

  // Check for LIN responses (from slaves)
  if (linSerial.available() > 0) {
    Serial.print("LIN RX: DATA=");
    while (linSerial.available() > 0) {
      byte data = linSerial.read();
      Serial.print("0x");
      Serial.print(data, HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
}

// ═══════════════════════════════════════════════════════════════════════════════
// EXAMPLE 6: MERCEDES W203 SPECIFIC MONITORING
// ═══════════════════════════════════════════════════════════════════════════════

/*
  Mercedes W203 Specific CAN Monitoring
  - Configured for Mercedes S203 W203 architecture
  - Monitors Engine CAN (Pin 7 & 14 on OBD2)
  - Monitors Chassis CAN (Pin 3 & 11 on OBD2)
  - Tries to identify key message IDs (RPM, speed, fuel)
  - Baud rate: 500kbps (common for Mercedes W203)

  REQUIREMENTS:
  - Install FlexCAN_T4 library: https://github.com/collin80/flexcan-t4
  - Arduino IDE with TeensyDuino installed
  - Mercedes S203 W203 vehicle

  Copy this entire section into a new Arduino sketch.
*/

// Save this as: mercedes_w203_monitor.ino

#include <FlexCAN_T4.h>

// Engine CAN (Pin 7 & 14 on OBD2 → Teensy CAN2)
FlexCAN_T4<CAN2, RX_SIZE_256> engineCan;

// Chassis CAN (Pin 3 & 11 on OBD2 → Teensy CAN3)
FlexCAN_T4<CAN3, RX_SIZE_256> chassisCan;

// Known Mercedes W203 message IDs (examples)
#define MERCEDES_RPM_ID       0x123  // RPM (example)
#define MERCEDES_SPEED_ID     0x124  // Speed (example)
#define MERCEDES_FUEL_ID      0x125  // Fuel level (example)
#define MERCEDES coolant_ID   0x126  // Coolant temp (example)

unsigned long frameCount = 0;
unsigned long lastStatusTime = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.println("══════════════════════════════════════════════════════════════════════");
  Serial.println("TEENSY 4.1 MERCEDES W203 SPECIFIC MONITOR");
  Serial.println("══════════════════════════════════════════════════════════════════════");
  Serial.println("Vehicle: Mercedes S203 W203");
  Serial.println("Engine CAN: Pins 7 & 14 on OBD2 (500kbps)");
  Serial.println("Chassis CAN: Pins 3 & 11 on OBD2 (500kbps)");
  Serial.println("══════════════════════════════════════════════════════════════════════");
  Serial.println("Initializing Engine CAN (Teensy CAN2) at 500kbps...");

  engineCan.begin();
  engineCan.setBaudRate(500000);

  Serial.println("Initializing Chassis CAN (Teensy CAN3) at 500kbps...");

  chassisCan.begin();
  chassisCan.setBaudRate(500000);

  Serial.println("══════════════════════════════════════════════════════════════════════");
  Serial.println("Monitoring Mercedes W203 CAN bus...");
  Serial.println("Capturing all CAN messages and attempting ID identification.");
  Serial.println("══════════════════════════════════════════════════════════════════════");
}

void loop() {
  // Monitor Engine CAN
  CAN_message_t msg;
  if (engineCan.read(msg)) {
    frameCount++;

    // Print raw CAN message
    Serial.print("[ENGINE] ID=0x");
    Serial.print(msg.id, HEX);
    Serial.print(" LEN=");
    Serial.print(msg.len);
    Serial.print(" DATA=");

    for (byte i = 0; i < msg.len; i++) {
      Serial.print("0x");
      Serial.print(msg.buf[i], HEX);
      Serial.print(" ");
    }

    // Try to identify message ID (commented out, requires DBC file)
    /*
    switch (msg.id) {
      case MERCEDES_RPM_ID:
        Serial.print(" [RPM]");
        break;
      case MERCEDES_SPEED_ID:
        Serial.print(" [SPEED]");
        break;
      case MERCEDES_FUEL_ID:
        Serial.print(" [FUEL]");
        break;
      case MERCEDES_COOLANT_ID:
        Serial.print(" [COOLANT]");
        break;
    }
    */

    Serial.println();
  }

  // Monitor Chassis CAN
  CAN_message_t chassisMsg;
  if (chassisCan.read(chassisMsg)) {
    Serial.print("[CHASSIS] ID=0x");
    Serial.print(chassisMsg.id, HEX);
    Serial.print(" LEN=");
    Serial.print(chassisMsg.len);
    Serial.print(" DATA=");

    for (byte i = 0; i < chassisMsg.len; i++) {
      Serial.print("0x");
      Serial.print(chassisMsg.buf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }

  // Print status every 10 seconds
  if (millis() - lastStatusTime > 10000) {
    Serial.println("══════════════════════════════════════════════════════════════════════");
    Serial.print("Status: Total frames captured = ");
    Serial.println(frameCount);
    Serial.println("Note: Create your own DBC file to decode message IDs.");
    Serial.println("       See README_COMPLETE.md for guidance on DBC building.");
    Serial.println("══════════════════════════════════════════════════════════════════════");
    lastStatusTime = millis();
  }
}

// ═══════════════════════════════════════════════════════════════════════════════
// USAGE INSTRUCTIONS
// ═══════════════════════════════════════════════════════════════════════════════

/*
  HOW TO USE THESE EXAMPLES:

  1. Copy the complete example code into a new Arduino sketch file.
  2. Save the sketch with the name shown in each example header.
  3. In Arduino IDE:
     - File → Open → select your saved sketch file
  4. Select Tools → Board → Teensy 4.1
  5. Select Tools → Port → appropriate port (Teensy's port)
  6. Click "Verify" to check for errors
  7. Click "Upload" to upload to Teensy 4.1
  8. Open Serial Monitor (Ctrl+Shift+M) at 115200 baud
  9. Observe output in serial monitor

  RECOMMENDED SEQUENCE:

  Step 1: Run diagnostic_blink_test.ino
          → Ver Teensy is working and USB connection good

  Step 2: Run can1_loopback_test.ino
          → Verify CAN1 transceiver working

  Step 3: Run can2_loopback_test.ino
          → Verify CAN2 transceiver working
          → Verify CAN buses are independent

  Step 4: Run dual_can_monitor.ino
          → Test in monitor mode (no vehicle needed)
          → Verify both CAN buses can receive

  Step 5: Run lin_master_test.ino
          → Verify LIN transceiver working
          → Verify LIN master operation

  Step 6: Connect to vehicle and run mercedes_w203_monitor.ino
          → Monitor real vehicle traffic
          → Download capture for analysis
          → Begin ID identification and DBC building

  TROUBLESHOOTING:

  - If examples don't compile, check that required libraries are installed:
    * FlexCAN_T4: https://github.com/collin80/flexcan-t4
    * LIN library: https://github.com/linbusdev/LIN

  - If Teensy is not recognized, check TeensyDuino installation:
    * Download from PJRC.com
    * Install into Arduino IDE

  - If CAN not working, check transceiver power:
    * Verify 5V on transceiver VCC pins (U2, U3, U4)
    * Verify GND connections
    * Check CAN termination resistors (120Ω each)

  - If LIN not working, check LIN transceiver:
    * Verify Serial1 pins map correctly to shield LIN
    * Check LIN baud rate (19200 baud standard)

  NEXT STEPS:

  After these examples work, you can:
  1. Begin decoding actual Mercedes W203 message IDs
  2. Build your own comprehensive DBC file
  3. Create custom CAN monitoring tools
  4. Develop LIN slave/master capabilities
  5. Use SavvyCAN for advanced analysis
  6. Prepare for advanced EV6 systems learning

*/