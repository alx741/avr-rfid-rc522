/* Registers

   MFRC522 Datasheed Page 36
*/

// Command and status
#define CommandReg    0x01 // Starts and stops command execution
#define ComIEnReg     0x02 // Enable and disable interrupt request control bits
#define DivIEnReg     0x03 // Enable and disable interrupt request control bits
#define ComIrqReg     0x04 // Interrupt request bits
#define DivIrqReg     0x05 // Interrupt request bits
#define ErrorReg      0x06 // Error bits showing the error status of the last command executed
#define Status1Reg    0x07 // Communication status bits
#define Status2Reg    0x08 // Receiver and transmitter status bits
#define FIFODataReg   0x09 // Input and output of 64 byte FIFO buffer
#define FIFOLevelReg  0x0A // Number of bytes stored in the FIFO buffer
#define WaterLevelReg 0x0B // Level of FIFO underflow and overflow warning
#define ControlReg    0x0C // Miscellaneous control registers
#define BitFramingReg 0x0D // Adjustments for bit-oriented frames
#define CollReg       0x0E // Bit position of the first bit-collision detected on the RF interface

// Command
#define ModeReg        0x11 // Defines general modes for transmitting and receiving
#define TxModeReg      0x12 // Defines general modes for transmitting and receiving
#define RxModeReg      0x13 // Defines reception data rate and framing
#define TxControlReg   0x14 // Controls the logical behavior of the antenna driver pins TX1 and TX2
#define TxASKReg       0x15 // Controls the setting of the transmission modulation
#define TxSelReg       0x16 // Selects the internal sources for the antenna driver
#define RxSelReg       0x17 // Selects internal receiver settings
#define RxThresholdReg 0x18 // Selects thresholds for the bit decoder
#define DemodReg       0x19 // Defines demodulator settings
#define MfTxReg        0x1C // Controls some MIFARE communication transmit parameters
#define MfRxReg        0x1D // Controls some MIFARE communication receive parameters
#define SerialSpeedReg 0x1F // Selects the speed of the serial UART interface

// Configuration
#define CRCResultRegL   0x21 // Shows the MSB and LSB values of the CRC calculation
#define CRCResultRegH   0x22
#define ModWidthReg     0x24 // Controls the ModWidth setting
#define RFCfgReg        0x26 // Configures the receiver gain
#define GsNReg          0x27 // Selects the conductance of the antenna driver pins for modulation
#define CWGsPReg        0x28 // Defines the conductance of the p-driver output during periods of no modulation
#define ModGsPReg       0x29 // Defines the conductance of the p-driver output during periods of no modulation
#define TModeReg        0x2A // Defines settings for the internal timer
#define TPrescalerReg   0x2B // Defines settings for the internal timer
#define TReloadRegL     0x2C // Defines the 16-bit timer reload value
#define TReloadRegH     0x2D
#define TCounterValRegL 0x2E // Shows the 16-bit timer value
#define TCounterValRegH 0x2F

// Test register
#define TestSel1Reg     0x31 // General test signal configuration
#define TestSel2Reg     0x32 // General test signal configuration and PRBS control
#define TestPinEnReg    0x33 // Enables pin output driver on pins D1 to D7
#define TestPinValueReg 0x34 // Defines the values for D1 to D7 when it is used as an I/O bus
#define TestBusReg      0x35 // Shows the status of the internal test bus
#define AutoTestReg     0x36 // Controls the digital self test
#define VersionReg      0x37 // Shows the software version
#define AnalogTestReg   0x38 // Controls the pins AUX1 and AUX2
#define TestDAC1Reg     0x39 // Defines the test value for TestDAC1
#define TestDAC2Reg     0x3A // Defines the test value for TestDAC2
#define TestADCReg      0x3B // Shows the value of ADC I and Q channels



/* Commands

   MFRC522 Datasheed Page 70
*/

#define cmd_idle             0x00 // No action, cancels the current command execution
#define cmd_mem              0x01 // Stores 25 bytes into the internal buffer
#define cmd_generateRandomID 0x02 // Generates a 10-byte random ID number
#define cmd_calcCRC          0x03 // Activates the CRC coprocessor of performs a self test
#define cmd_transmit         0x04 // Transmits data from the FIFO buffer
#define cmd_noCmdChange      0x07 // Can be used to modify the CommandReg register bits without affecting the command
#define cmd_recieve          0x08 // Activates the receiver circuits
#define cmd_transceive       0x0C // Transmits data from FIFO buffer to antenna and activate receiver after transmission
#define cmd_mfAuthent        0x0E // Performs the MIFARE standard authentication as a reader
#define cmd_softReset        0x0F // Resets the MFRC522
