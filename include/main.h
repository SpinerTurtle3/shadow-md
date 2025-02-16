#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <PS3BT.h>
#include <usbhub.h>
#include <Sabertooth.h>

// General User Settings
extern String PS3ControllerFootMac;
extern String PS3ControllerDomeMAC;
extern String PS3ControllerBackupFootMac;
extern String PS3ControllerBackupDomeMAC;

extern byte drivespeed1;
extern byte drivespeed2;
extern byte turnspeed;
extern byte domespeed;
extern byte ramping;
extern byte joystickFootDeadZoneRange;
extern byte joystickDomeDeadZoneRange;
extern byte driveDeadBandRange;
extern int invertTurnDirection;
extern byte domeAutoSpeed;
extern int time360DomeTurn;

#define SHADOW_DEBUG
#define SHADOW_VERBOSE

// MarcDuino Button Settings
extern int btnUP_type;
extern int btnUP_MD_func;
extern int btnUP_cust_MP3_num;
extern int btnUP_cust_LD_type;
extern String btnUP_cust_LD_text;
extern int btnUP_cust_panel;
extern boolean btnUP_use_DP1;
extern int btnUP_DP1_open_start_delay;
extern int btnUP_DP1_stay_open_time;
extern boolean btnUP_use_DP2;
extern int btnUP_DP2_open_start_delay;
extern int btnUP_DP2_stay_open_time;
extern boolean btnUP_use_DP3;
extern int btnUP_DP3_open_start_delay;
extern int btnUP_DP3_stay_open_time;
extern boolean btnUP_use_DP4;
extern int btnUP_DP4_open_start_delay;
extern int btnUP_DP4_stay_open_time;
extern boolean btnUP_use_DP5;
extern int btnUP_DP5_open_start_delay;
extern int btnUP_DP5_stay_open_time;
extern boolean btnUP_use_DP6;
extern int btnUP_DP6_open_start_delay;
extern int btnUP_DP6_stay_open_time;
extern boolean btnUP_use_DP7;
extern int btnUP_DP7_open_start_delay;
extern int btnUP_DP7_stay_open_time;
extern boolean btnUP_use_DP8;
extern int btnUP_DP8_open_start_delay;
extern int btnUP_DP8_stay_open_time;
extern boolean btnUP_use_DP9;
extern int btnUP_DP9_open_start_delay;
extern int btnUP_DP9_stay_open_time;
extern boolean btnUP_use_DP10;
extern int btnUP_DP10_open_start_delay;
extern int btnUP_DP10_stay_open_time;

// Other button configurations follow the same pattern...

// System Variables
extern int motorControllerBaudRate;
extern int marcDuinoBaudRate;

#define SYREN_ADDR 129
#define SABERTOOTH_ADDR 128
#define ENABLE_UHS_DEBUGGING 1

// Panel Management Variables
extern boolean runningCustRoutine;
extern int DP1_Status;
extern unsigned long DP1_start;
extern int DP1_s_delay;
extern int DP1_o_time;
// Other dome panel variables follow the same pattern...

// Variables
extern long previousDomeMillis;
extern long previousFootMillis;
extern long previousMarcDuinoMillis;
extern long previousDomeToggleMillis;
extern long previousSpeedToggleMillis;
extern long currentMillis;

extern int serialLatency;
extern int marcDuinoButtonCounter;
extern int speedToggleButtonCounter;
extern int domeToggleButtonCounter;

extern Sabertooth *ST;
extern Sabertooth *SyR;

extern USB Usb;
extern BTD Btd;
extern PS3BT *PS3NavFoot;
extern PS3BT *PS3NavDome;

extern uint32_t msgLagTime;
extern uint32_t lastMsgTime;
extern uint32_t currentTime;
extern uint32_t lastLoopTime;
extern int badPS3Data;
extern int badPS3DataDome;

extern boolean firstMessage;
extern String output;

extern boolean isFootMotorStopped;
extern boolean isDomeMotorStopped;
extern boolean overSpeedSelected;
extern boolean isPS3NavigatonInitialized;
extern boolean isSecondaryPS3NavigatonInitialized;
extern boolean isStickEnabled;
extern boolean WaitingforReconnect;
extern boolean WaitingforReconnectDome;
extern boolean mainControllerConnected;
extern boolean domeControllerConnected;

// Dome Automation Variables
extern boolean domeAutomation;
extern int domeTurnDirection;
extern float domeTargetPosition;
extern unsigned long domeStopTurnTime;
extern unsigned long domeStartTurnTime;
extern int domeStatus;

extern byte action;
extern unsigned long DriveMillis;
extern int footDriveSpeed;

// Function declarations
void setup();
void loop();
boolean ps3FootMotorDrive(PS3BT *myPS3 = PS3NavFoot);
void footMotorDrive();
int ps3DomeDrive(PS3BT *myPS3 = PS3NavDome);
void rotateDome(int domeRotationSpeed, String mesg);
void domeDrive();
void ps3ToggleSettings(PS3BT *myPS3 = PS3NavFoot);
void toggleSettings();
void marcDuinoButtonPush(int type, int MD_func, int MP3_num, int LD_type, String LD_text, int panel_type,
                         boolean use_DP1, int DP1_str_delay, int DP1_open_time, boolean use_DP2, int DP2_str_delay,
                         int DP2_open_time, boolean use_DP3, int DP3_str_delay, int DP3_open_time, boolean use_DP4,
                         int DP4_str_delay, int DP4_open_time, boolean use_DP5, int DP5_str_delay, int DP5_open_time,
                         boolean use_DP6, int DP6_str_delay, int DP6_open_time, boolean use_DP7, int DP7_str_delay,
                         int DP7_open_time, boolean use_DP8, int DP8_str_delay, int DP8_open_time, boolean use_DP9,
                         int DP9_str_delay, int DP9_open_time, boolean use_DP10, int DP10_str_delay, int DP10_open_time);
void marcDuinoFoot();
void marcDuinoDome();
void custMarcDuinoPanel();
void autoDome();
void onInitPS3NavFoot();
void onInitPS3NavDome();
void writeControlerBatteryStatusToOutput(PS3BT *myPS3);
String getLastConnectedBtMAC();
boolean criticalFaultDetect();
boolean criticalFaultDetectDome();
void printOutput();
boolean readUSB();

#endif // MAIN_H