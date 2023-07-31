# Weather-Monitoring-System
## ESP8266 Weather Monitoring Web Server
This GitHub repository contains an Arduino sketch for an ESP8266-based weather monitoring system that displays real-time temperature, humidity, and rain percentage on a web page. The ESP8266 acts as a web server, enabling users to access weather data from any device connected to the same local network.
### Features
- Displays the current date and time on an analog clock-like widget.
- Provides real-time temperature, humidity, and rain percentage readings.
- Stylish and responsive user interface with a modern design.
- Uses AJAX to fetch data from the ESP8266 without reloading the entire page.
- Simple setup, requiring only an ESP8266 development board, a DHT11 sensor, and an analog rain sensor.
### How to Use
1. Set up the hardware connections:
   - Connect the DHT11 sensor to GPIO pin 14 of the ESP8266 board.
   - Connect the analog rain sensor to A0 pin of the ESP8266 board.
2. Flash the provided Arduino sketch to the ESP8266 board using the Arduino IDE.
3. Connect the ESP8266 to your local Wi-Fi network by providing the SSID and password in the sketch.
4. Access the weather monitoring web page by typing the ESP8266's IP address in the browser. The page will display the temperature, humidity, and rain percentage data in real-time.
### Credits
The web page design and styling have been created by Team Visionex. The design incorporates Google Fonts for a clean and modern appearance. The AJAX-based dynamic data retrieval is achieved through JavaScript.
### Dependencies
- ESP8266WiFi library
- WiFiClient library
- ESP8266WebServer library
- DHTesp library (DHT sensor library for ESP8266)
- Google Fonts (Montserrat and Roboto)
Please note that this code assumes you have the required hardware components and have installed the necessary libraries in your Arduino IDE.
