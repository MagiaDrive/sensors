#define PHOTORESISTOR A0
#define RED_LED A2
#define GREEN_LED A3
#define BLUE_LED A4

int redValue, greenValue, blueValue;
float r_filtered, g_filtered, b_filtered;

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

    r_filtered = map(1023 - redValue, 0, 1023, 0, 255);
    g_filtered = floor(map(1023 - greenValue, 0, 1023, 0, 255) * 1.04);
    b_filtered = floor(map(1023 - blueValue, 0, 1023, 0, 255) * 1.42);
    
    Serial.print("R: ");
    Serial.print(r_filtered);
    Serial.print(" G: ");
    Serial.print(g_filtered);
    Serial.print(" B: ");
    Serial.println(b_filtered);

    if (r_filtered > g_filtered && r_filtered > b_filtered)
    {
      Serial.println("recognized color: red");
    }
    else if (g_filtered > r_filtered && g_filtered > b_filtered)
    {
      Serial.println("recognized color: green");
    }
    if (b_filtered > g_filtered && b_filtered > r_filtered)
    {
      Serial.println("recognized color: blue");
    }
    delay(500);
}

// Helper function to set the LED color
void setColor(bool r, bool g, bool b) {
    digitalWrite(RED_LED, r);
    digitalWrite(GREEN_LED, g);
    digitalWrite(BLUE_LED, b);
}
