Project Overview: 
This project involves developing a smart home system that adjusts lighting, fan speed, and safety 
alerts based on environmental conditions: 
1. Lighting Control: The LDR detects ambient light intensity and controls three LEDs to 
indicate different levels of light. 
2. Fan Speed Control: The LM35 temperature sensor adjusts the fan speed proportionally to 
the room temperature. 
3. Fire Detection: A flame sensor detects fire, triggers an alarm, and displays a critical alert 
on the LCD. 
4. LCD Display: Shows real-time temperature readings, fan status, light intensity, and alerts. 
Features: 
•  Automatic Lighting Control: Based on the LDR readings, the system controls three LEDs 
according to light intensity thresholds: 
o Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON. 
o Intensity 16–50%: Red and Green LEDs turn ON. 
o Intensity 51–70%: Only the Red LED turns ON. 
o Intensity > 70%: All LEDs are turned OFF. 
2  
• Automatic Fan Speed Control: Fan speed is automatically adjusted based on room 
temperature, controlled by a PWM signal. The fan operates at different speeds based on 
temperature ranges: 
o Temperature ≥ 40°C: Fan ON at 100% speed. 
o Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed. 
o Temperature ≥ 30°C and < 35°C: Fan ON at 50% speed. 
o Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed. 
o Temperature < 25°C: Fan OFF. 
• Fire Detection and Alert: The system raises an alarm and displays "Critical alert!" on the 
LCD if fire is detected. The system remains in alert mode until the flame is no longer 
detected. 
• LCD Display: Real-time feedback on system status: 
o First Row: Displays "FAN is ON" or "FAN is OFF" based on the fan's state. 
o Second Row: Displays "Temp= xxC LDR= xxx%" showing temperature and light 
intensity.
