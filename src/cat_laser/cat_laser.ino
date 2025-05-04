#include <Servo.h>

Servo yawServo;
Servo pitchServo;

int yawPos = 90;
int pitchPos = 90;

#define YAW_MAX 180
#define YAW_MIN 0

#define PITCH_MAX 100
#define PITCH_MIN 0

#define YAW_PORT 9
#define PITCH_PORT 10

#define YAW_STEP 7
#define PITCH_STEP 7

void setup()
{
  yawServo.attach(YAW_PORT);
  pitchServo.attach(PITCH_PORT);

  yawServo.write(yawPos);
  pitchServo.write(pitchPos);
}

void loop()
{
  //testServos();
  updateServos();
  delay(50);
}

void updateServos()
{
  yawPos = getNewPosition(yawPos, YAW_MIN, YAW_MAX, YAW_STEP);
  pitchPos = getNewPosition(pitchPos, PITCH_MIN, PITCH_MAX, PITCH_STEP);

  yawServo.write(yawPos);
  pitchServo.write(pitchPos);
}

int getNewPosition(int current, int min, int max, int step)
{
  int newPosMax = current + step;

  if (newPosMax > max)
  {
    newPosMax = max;
  }

  int newPosMin = current - step;

  if (newPosMin < min)
  {
    newPosMin = min;
  }

  return random(newPosMin, newPosMax);
}

// Method used for setting min and max servos values
void testServos()
{
  testServo(yawServo, YAW_MIN, YAW_MAX);
  testServo(pitchServo, PITCH_MIN, PITCH_MAX);
}

void testServo(Servo servo, int min, int max)
{
  for (int pos = min; pos <= max; pos++)
  {
    servo.write(pos);
    delay(15);
  }

  for (int pos = max; pos >= min; pos--)
  {
    servo.write(pos);
    delay(15);
  }
}