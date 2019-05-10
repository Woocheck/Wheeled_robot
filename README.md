# Wheeled_robot

Projekt robota kołowego linefollower.
Wymagania funkcjonalne:
1. Robot porusza się po trasie oznaczonej linią na podłożu.
2. Robot potrafi samodzielnie odszukać zagubioną trasę.
3. W przypadku natrafienia na przeszkodę, podczas poruszania się po rozpoznanej trasie, robot zatrzyma się.

Warstwa sprzętowa:
1. Sterownik: Raspberry Pi 3 B+.
2. Napęd: dwa Silnik z przekładnią SJ01 120:1 6V 160RPM + enkoder
3. Sterowane za pomocą mostka H w postaci układu L293D.
3. Pomiar prędkości: 2 enkodery 16 impulsów na obrót (po przełożeniu 1920 impulsów na obrót).
3. Wykrywanie trasy: Moduł z czujnikiem śledzenia linii TCRT5000L.
4. Wykrywanie przeszkód: ultradźwiękowy czujnik odległości HC - SR05.

Oprogramowanie:
Sterowanie robota będzie wykonywanie w oparciu o Raspberry Pi 3 B+ z systemem operacyjnym Linux Raspbian.
Oprogramowanie sterujące napisane w języku C++, z wykorzystaniem biblioteki WiringPi (http://wiringpi.com/). 

Narzędzia:
- kompilator GCC,
- IDE Visual Studio Code.
