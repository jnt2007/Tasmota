/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2019  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *   (3) for platformio:
 *         define USE_CONFIG_OVERRIDE as a build flags.
 *         ie1 : export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE'
 *       for Arduino IDE:
 *         enable define USE_CONFIG_OVERRIDE in my_user_config.h
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

#undef  STA_SSID1
#define STA_SSID1              "MikroTik"        // [Ssid1] Wifi SSID
#undef  STA_PASS1
#define STA_PASS1              ""       // [Password1] Wifi password
#undef  STA_SSID2
#define STA_SSID2              "rv220"           // [Ssid2] Optional alternate AP Wifi SSID
#undef  STA_PASS2
#define STA_PASS2              ""        // [Password2] Optional alternate AP Wifi password

#undef  MQTT_HOST
#define MQTT_HOST              "192.168.88.221"  // [MqttHost]
#undef  MQTT_PORT
#define MQTT_PORT              1883              // [MqttPort] MQTT port (10123 on CloudMQTT)
#undef  MQTT_USER
#define MQTT_USER              ""            // [MqttUser] MQTT user
#undef  MQTT_PASS
#define MQTT_PASS              ""       // [MqttPassword] MQTT password

// -- HTTP ----------------------------------------
#undef  WEB_PASSWORD
#define WEB_PASSWORD           ""           // [WebPassword] Web server Admin mode Password for WEB_USERNAME (empty string = Disable)

// -- Time - Up to three NTP servers in your region
#undef  NTP_SERVER1
#define NTP_SERVER1            "pool.ntp.org"       // [NtpServer1] Select first NTP server by name or IP address (129.250.35.250)
#undef  NTP_SERVER2
#define NTP_SERVER2            "ua.pool.ntp.org"    // [NtpServer2] Select second NTP server by name or IP address (5.39.184.5)
#undef  NTP_SERVER3
#define NTP_SERVER3            "0.ua.pool.ntp.org"  // [NtpServer3] Select third NTP server by name or IP address (93.94.224.67)
#undef APP_TIMEZONE
#define APP_TIMEZONE           99

// -- Time - Start Daylight Saving Time (Summer time for Ukraine) and timezone offset from UTC in minutes
// Backlog TIMEDST 0,0,1,3,3,180; TIMESTD 0,0,1,10,4,120
#undef TIME_DST_HEMISPHERE
#define TIME_DST_HEMISPHERE    North             // [TimeDst] Hemisphere (0 or North, 1 or South)
#undef TIME_DST_WEEK
#define TIME_DST_WEEK          Last              // Week of month (0 or Last, 1 or First, 2 or Second, 3 or Third, 4 or Fourth)
#undef TIME_DST_DAY
#define TIME_DST_DAY           Sun               // Day of week (1 or Sun, 2 or Mon, 3 or Tue, 4 or Wed, 5 or Thu, 6 or Fri, 7 or Sat)
#undef TIME_DST_MONTH
#define TIME_DST_MONTH         Mar               // Month (1 or Jan, 2 or Feb, 3 or Mar, 4 or Apr, 5 or May, 6 or Jun, 7 or Jul, 8 or Aug, 9 or Sep, 10 or Oct, 11 or Nov, 12 or Dec)
#undef TIME_DST_HOUR
#define TIME_DST_HOUR          3                 // Hour (0 to 23)
#undef TIME_DST_OFFSET
#define TIME_DST_OFFSET        +180              // Offset from UTC in minutes (-780 to +780)

// -- Time - Start Standard Time (Winter time for Ukraine) and timezone offset from UTC in minutes
// Backlog TIMEDST 0,0,1,3,3,180; TIMESTD 0,0,1,10,4,120
#undef TIME_STD_HEMISPHERE
#define TIME_STD_HEMISPHERE    North             // [TimeStd] Hemisphere (0 or North, 1 or South)
#undef TIME_STD_WEEK
#define TIME_STD_WEEK          Last              // Week of month (0 or Last, 1 or First, 2 or Second, 3 or Third, 4 or Fourth)
#undef TIME_STD_DAY
#define TIME_STD_DAY           Sun               // Day of week (1 or Sun, 2 or Mon, 3 or Tue, 4 or Wed, 5 or Thu, 6 or Fri, 7 or Sat)
#undef TIME_STD_MONTH
#define TIME_STD_MONTH         Oct               // Month (1 or Jan, 2 or Feb, 3 or Mar, 4 or Apr, 5 or May, 6 or Jun, 7 or Jul, 8 or Aug, 9 or Sep, 10 or Oct, 11 or Nov, 12 or Dec)
#undef TIME_STD_HOUR
#define TIME_STD_HOUR          4                 // Hour (0 to 23)
#undef TIME_STD_OFFSET
#define TIME_STD_OFFSET        +120              // Offset from UTC in minutes (-780 to +780)

// -- Location ------------------------------------
#undef  LATITUDE
#define LATITUDE               50.43732          // [Latitude] Your location to be used with sunrise and sunset
#undef  LONGITUDE
#define LONGITUDE              30.50291          // [Longitude] Your location to be used with sunrise and sunset

// // Room meteo station
// #define USE_MHZ19                                // Add support for MH-Z19 CO2 sensor (+2k code)
// #define USE_BMP                                  // [I2cDriver10] Enable BMP085/BMP180/BMP280/BME280 sensors (I2C addresses 0x76 and 0x77) (+4k4 code)
// #define USE_BH1750                             // [I2cDriver11] Enable BH1750 sensor (I2C address 0x23 or 0x5C) (+0k5 code)
// // #define USE_CCS811                               // [I2cDriver24] Enable CCS811 sensor (I2C address 0x5A) (+2k2 code)
// #define USE_DISPLAY                              // Add I2C Display Support (+2k code)
// #define USE_DISPLAY_SSD1306                      // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)

// Humidifier
// #define USE_A4988_STEPPER                        // Add support for A4988/DRV8825 stepper-motor-driver-circuit (+10k5 code)
// #define USE_EXPRESSION                           // Add support for expression evaluation in rules (+3k2 code, +64 bytes mem)
// #define SUPPORT_IF_STATEMENT                     // Add support for IF statement in rules (+4k2 code, -332 bytes mem)
// Rule1
//  ON system#boot DO Backlog var1 0; MotorMove -100 ENDON
//  ON button2#state=3 DO Power1 2 ENDON
//  ON button2#state=2 DO if (var1<100) Backlog MotorMove 20; var1=var1+20 else Backlog MotorMove -100; var1 0 endif ENDON


#endif  // _USER_CONFIG_OVERRIDE_H_