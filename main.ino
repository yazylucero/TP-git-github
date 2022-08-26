#define PIN_MOTOR_LEFT_DIR 1
#define PIN_MOTOR_LEFT_PWM 2
#define PIN_PULSADOR 3

class Pulsador {
  private:
    int pin;
    bool flanco = HIGH;
    bool estado_anterior = !flanco;

  public:
    Pulsador(int p) {
      pin = p;

      pinMode(pin, INPUT);
    }

    void setFlanco(bool f) {
      flanco = f;
      estado_anterior = !flanco;
    }

    bool getIsPress() {
      bool estado_actual = digitalRead(pin);
      bool estado = (estado_anterior != estado_actual) && estado_actual == flanco;
      estado_anterior = estado_actual;
      return estado;
    }
};

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

Pulsador *pulsador=new Pulsador(PIN_PULSADOR);

void setup(){

}
void loop(){

}
