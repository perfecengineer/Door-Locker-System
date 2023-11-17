Project Title: Smart Door Locker System

Overview:
The Smart Door Locker System is an embedded system project designed to provide a secure and convenient way of accessing a door. The system utilizes an Atmega32 microcontroller to manage the authentication process, a keypad for user input, an LCD for displaying status information, a Bluetooth module for remote access via a smartphone, a servo motor to act as the door locker, and LEDs/buzzer for indicating the status of the entered password.

Components:

Atmega32 Microcontroller: The brain of the system, responsible for processing user input, managing the authentication process, and controlling the connected devices.

LCD Display: Displays the status of the password input and the door (ON / OFF). Provides user feedback and prompts.

Bluetooth Module: Enables communication with a smartphone through the UART protocol. Users can send passwords remotely via a dedicated mobile app.

Keypad: Allows users to input their passwords directly. Connected to the MCU, it serves as a local means of authentication.

Servo Motor: Acts as the physical door locker. The servo is controlled by the MCU based on the authentication results.

Buzzer: Audible feedback for users. It alerts users if the entered password is incorrect, and also serves as an indicator for successful authentication.

LEDs (Green and Red): Visual indicators of the authentication status. The green LED lights up when the password is correct, while the red LED indicates an incorrect password attempt.

Functionality:

Local Access: Users can enter their password using the connected keypad. The LCD provides real-time feedback on the status of the password input.

Remote Access: Users can send passwords remotely via the mobile app through Bluetooth communication. The system processes the received password and authenticates accordingly.

Authentication Process: The system allows three attempts for entering the correct password. If the user fails to enter the correct password within these attempts, the system remains locked.

Status Indication: The green LED lights up and the servo motor activates if the correct password is entered. In case of an incorrect password, the red LED lights up, and the buzzer provides audible feedback.

LCD Display: The LCD provides detailed information about the authentication process, including prompts and status updates.
