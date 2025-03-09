#define PHOTORESISTOR A0
#define RED_LED A2
#define GREEN_LED A3
#define BLUE_LED A4

int redValue, greenValue, blueValue;

void setup() {
    pinMode(PHOTORESISTOR, INPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Measure red reflection
    setColor(HIGH, LOW, LOW);
    delay(100);
    redValue = analogRead(PHOTORESISTOR);
    

    // Measure green reflection
    setColor(LOW, HIGH, LOW);
    delay(100);
    greenValue = analogRead(PHOTORESISTOR);

    // Measure blue reflection
    setColor(LOW, LOW, HIGH);
    delay(100);
    blueValue = analogRead(PHOTORESISTOR);

    // Turn off LED before processing
    setColor(LOW, LOW, LOW);

    Serial.print("R: ");
    Serial.print(redValue);
    Serial.print(" G: ");
    Serial.print(greenValue);
    Serial.print(" B: ");
    Serial.println(blueValue);

    

    delay(500);
}

// Helper function to set the LED color
void setColor(bool r, bool g, bool b) {
    digitalWrite(RED_LED, r);
    digitalWrite(GREEN_LED, g);
    digitalWrite(BLUE_LED, b);
}
