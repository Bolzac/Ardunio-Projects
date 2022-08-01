#define trigPin 10
#define echoPin 8

int counter = 0;
float duration_us, current_distance_of_person;
float previous_distance_of_person, speed_of_person;
float total_distance = 332;
float t1, t2, time;
float estimated_passing_time, remained_passing_time;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  t1 = millis();
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration_us = pulseIn(echoPin, HIGH);
  current_distance_of_person = 0.017 * duration_us;
  if(!speed_of_person && !previous_distance_of_person){
    previous_distance_of_person = current_distance_of_person;
    return;
  }else if(!speed_of_person && previous_distance_of_person != current_distance_of_person){
    t2 = millis();
    time = t2-t1;
    speed_of_person = (previous_distance_of_person - current_distance_of_person)/(time);
  }
  
  estimated_passing_time = total_distance/speed_of_person;
  remained_passing_time = estimated_passing_time - time;
  
  delay(remained_passing_time);
  
  if(current_distance_of_person > 332){ //332 because the output return this value while sensor can't detect person
    counter++;
  }
  
  //Kullanıcının bir koridor boyunca bir eşiğe doğru yürüdüğünü ve artık sensöre olan uzaklığı 0
  //olduğunda giriş yaptığı varsayılarak hazırlandı
  //Neden böyle yaptığımı hatırlayamadım şuan
  
  Serial.print("Person number :");
  Serial.println(counter);
  delay(1000);
}
