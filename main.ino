#define PIN_MOTOR_LEFT_DIR 1
#define PIN_MOTOR_LEFT_PWM 2

class Motor
{
private:
    int pin_dir, pin_pwm;

public:
    Motor(int p_dir, int p_pwm)
    {
        pin_dir = p_dir;
        pin_pwm = p_pwm;

        pinMode(pin_dir, OUTPUT);
        pinMode(pin_pwm, OUTPUT);
    }
    void avanzar(int velocidad)
    {
        digitalWrite(pin_dir, LOW);
        analogWrite(pin_pwm, velocidad);
    }
    void retroceder( int velocidad)
    {
        digitalWrite(pin_dir, LOW);
        analogWrite(pin_pwm, velocidad);
    }
    void frenar()
    {
        digitalWrite(pin_dir, LOW);
        digitalWrite(pin_pwm, LOW);
    }
};

Motor *motor = new Motor(PIN_MOTOR_LEFT_DIR,PIN_MOTOR_LEFT_PWM);


void setup(){

}
void loop(){

}
