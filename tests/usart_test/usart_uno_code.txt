char TEST_STRING[] = "I AM FROM ARDUINO!";
u32 TEST_NUMBER = 12345;

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
}

void loop() {
    // Test case: Receive a string on the Arduino Uno from the ATmega32
    // Expected result: The Arduino Uno receives a string from the ATmega32
    // Actual result:
    String received_string = Serial.readStringUntil('\n');

    // Test case: Send a string from the Arduino Uno to the ATmega32
    // Expected result: The ATmega32 receives the string "I AM NOT HELLO WORLD!"
    // Actual result:
    Serial.println(TEST_STRING);

    // Test case: Receive a number on the Arduino Uno from the ATmega32
    // Expected result: The Arduino Uno receives a number from the ATmega32
    // Actual result:
    u32 received_number = 0;
    for (int i = 0; i < 4; i++) {
        received_number |= ((u32)Serial.read()) << (i * 8);
    }

    // Test case: Send a number from the Arduino Uno to the ATmega32
    // Expected result: The ATmega32 receives the number 12345
    // Actual result:
    for (int i = 0; i < 4; i++) {
        Serial.write((u8)(TEST_NUMBER >> (i * 8)));
    }
    
    TEST_NUMBER++;
    

    
    delay(1000);
}
