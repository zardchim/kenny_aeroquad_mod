/*
  AeroQuad v3.x - 2012
  www.AeroQuad.com
  Copyright (c) 2012 Ted Carancho.  All rights reserved.
  An Open Source Arduino based multicopter.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/****************************************************************************
				The AeroQuad Manual can be found here:
		http://aeroquad.com/showwiki.php?title=Book:AeroQuad+Manual
 ****************************************************************************/


/****************************************************************************
 ************************* Hardware Configuration ***************************
 ****************************************************************************/
// Select which hardware you wish to use with the AeroQuad Flight Software

// 328p processor
//#define AeroQuad_v18        // Arduino Uno with AeroQuad Shield v1.8 or 1.9
//#define AeroQuad_Mini       // Arduino Pro Mini with AeroQuad Mini Shield v1.0
//#define MWCFlip15           // MWCFlip1.5 board from ready to fly quad -> http://witespyquad.gostorego.com/flight-controllers/flip-mwc-flight-controller.html

// Mega processor
//#define AeroQuadMega_v2     // Arduino Mega with AeroQuad Shield v2.0
//#define AeroQuadMega_v21    // Arduino Mega with AeroQuad Shield v2.1
//#define MWCProEz30          // MWC Prop Ez3.0 from ready to fly quad -> http://witespyquad.gostorego.com/flight-controllers/multiwii-pro-ez3-0-flight-controller-w-gps-option.html

// STM32 processor
#define AeroQuadSTM32
//#define Naze32


/****************************************************************************
 *********************** Define Flight Configuration ************************
 ****************************************************************************/
// Use only one of the following definitions
//For more information please refer to http://aeroquad.com/showwiki.php?title=Flight+Configurations


// MOTOR ADVANCE CONFIG SECTION
//#define CHANGE_YAW_DIRECTION	// only needed if you want to reverse the yaw correction direction


// define wireless communication on serial 0 at 57600
//#define USE_WIRELESS_COMMUNICATION
//
// *******************************************************************************************************************************
// Optional Sensors
// Warning:  If you enable HeadingMagHold or AltitudeHold and do not have the correct sensors connected, the flight software may hang
// For more information on how to activate theese features with your transmitter
// Please refer to http://aeroquad.com/showwiki.php?title=Using+the+transmitters+sticks+and+switches+to+operate+your+AeroQuad
// *******************************************************************************************************************************
//#define HeadingMagHold		// Enables Magnetometer, gets automatically selected if CHR6DM is defined
//#define AltitudeHoldBaro		// Enables Barometer
//#define AltitudeHoldRangeFinder	// Enables Altitude Hold with range finder, not displayed on the configurator (yet)
//#define AutoLanding			// Enables auto landing on channel AUX3 of the remote, NEEDS AltitudeHoldBaro AND AltitudeHoldRangeFinder to be defined

//
// *******************************************************************************************************************************
// GPS Options
// *******************************************************************************************************************************
//#define UseGPS		        // Enables GPS (for mega v2.0/v2.1 on Serial1 & AeroQuad32 on Serial2)
//#define UseGPSNavigator

// Device specific settings
//#define UseGPSMTKBINARY   // Set MTK devices to binary protocol (only DiyDrones MTK1.6 protocol supported)

//
// *******************************************************************************************************************************
// Battery Monitor Options
// For more information on how to setup the Battery Monitor please refer to http://aeroquad.com/showwiki.php?title=Battery+Monitor
// *******************************************************************************************************************************
//#define BattMonitor			  // Enables Battery monitor
//#define BattMonitorAutoDescent  // NEED BattMonitor defined. If you want the craft to auto descent when the battery reaches the alarm voltage
//#define POWERED_BY_VIN          // NEED BattMonitor defined. Uncomment this if your v2.x shield is powered directly by the Vin/Gnd of the arduino
//
// Advanced configuration. Please refer to the wiki for instructions.
//#define BattCustomConfig DEFINE_BATTERY(0,A4,51.8,0,A3,180.3,0)

//
// *******************************************************************************************************************************
// Receiver Setup
// For more information on how to connect your receiver to your AeroQuad board please refer to http://aeroquad.com/showwiki.php?title=Connecting+the+receiver+to+your+AeroQuad+board
// *******************************************************************************************************************************
//#define NormalReceiver	// This does nothing really, but it indicates users that they don't have to define other options here if they have a normal receiver
//#define RemotePCReceiver	// EXPERIMENTAL Use PC as transmitter via serial communicator with XBEE
//#define ReceiverSBUS		// Use a Futaba sBUS RX, connect sBUS data line via an inverter (see wiki) to Serial2 RX, supports up to 8 channels on v2 and STM32 boards
//#define ReceiverPPM		// Use a PPM receiver
//#define ReceiverHWPPM		// Use a PPM receiver with HW timer (less jitter on channel values than PPM), needs a HW modification (see wiki)

//#define UseAnalogRSSIReader	// Reads RSSI for receiver failsafe, NEEDS A RECEIVER WITH FAILSAVE CONNECTED ON PIN A6 OF THE SHIELD
//#define UseEzUHFRSSIReader	// Reads RSSI and Signal quality on channel 7(RSSI) and 8(Signal Quality) of the EzUHF receiver (Receiver have to be configures this way)
//#define UseSBUSRSSIReader		



//
// *******************************************************************************************************************************
// Optional telemetry (for debug or ground station tracking purposes)
// For more information on how to setup Telemetry please refer to http://aeroquad.com/showwiki.php?title=Wireless+Connection
// *******************************************************************************************************************************

//#define MavLink               // Enables the MavLink protocol
//#define MAV_SYSTEM_ID 100		// Needs to be enabled when using MavLink, used to identify each of your copters using MavLink
								// If you've only got one, leave the default value unchanged, otherwise make sure that each copter has a different ID 

//#define CONFIG_BAUDRATE 19200 // overrides default baudrate for serial port (Configurator/MavLink/WirelessTelemetry)

//
// *******************************************************************************************************************************
// Camera Stabilization
// Servo output goes to D11(pitch), D12(roll), D13(yaw) on AeroQuad v1.8 shield
// If using v2.0 Shield place jumper between:
// D12 to D33 for roll, connect servo to SERVO1
// D11 to D34 for pitch, connect servo to SERVO2
// D13 to D35 for yaw, connect servo to SERVO3
// Please note that you will need to have battery connected to power on servos with v2.0 shield
// For more information please refer to http://aeroquad.com/showwiki.php?title=Camera+Stabilization
// *******************************************************************************************************************************
//#define CameraControl
//#define CameraTXControl  // need to have CameraControl to work

//
// *******************************************************************************************************************************
// On screen display implementation using MAX7456 chip. See MAX7456.h in libraries for more info and configuration.
// For more information on how to setup OSD please refer to http://aeroquad.com/showwiki.php?title=On-Screen-Display
// *************************************************************.******************************************************************
//#define OSD
//#define ShowRSSI                  // This REQUIRES a RSSI reader
//#define PAL                       // uncomment this to default to PAL video
//#define AUTODETECT_VIDEO_STANDARD // detect automatically, signal must be present at Arduino powerup!
//#define CALLSIGN "AQ"             // Show (optional) callsign
//#define ShowAttitudeIndicator     // Display the attitude indicator calculated by the AHRS
//#define USUnits                   // Enable for US units (feet,miles,mph), leave uncommented for metric units (meter,kilometer,km/h)
//#define OSD_LOADFONT              // Include MAX7456 font into binary, give & on serial to upload

//#define OSD_SYSTEM_MENU           // Menu system, currently only usable with OSD or SERIAL_LCD

//
// *******************************************************************************************************************************
// Support menu on serial enabled LCD display (16x2 characters).  You can change serial port if needed
// Note: Can NOT be enabled at the same time with OSD
// For more information please refer to http://aeroquad.com/showwiki.php?title=OnBoardMenu
// *************************************************************.******************************************************************
//#define SERIAL_LCD Serial3



/****************************************************************************
 ****************************************************************************
 ****************************************************************************
 ********************* End of User Definition Section ***********************
 ****************************************************************************
 ****************************************************************************
 ****************************************************************************/
