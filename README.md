# SuperGameduino
In our project, we collected old vintage arcade games and bring them back with some modern technologies and less cost than old consoles in the market. This game console was made using an esp 32s and an old modified version of fabgl library which allowed us to control the VGA using canvas and simple commands.

All games in this project is cloned from [Rob Cai](https://www.instructables.com/ESP32-VGA-Arcade-Games-and-Joystick/) which has been modified to work in diffrent screen and controllers also it has now wifi terminal which was also cloned from bitluni library and modified to work in fabgl canvas.
For More information about fabgl Library [here](http://www.fabglib.org/)

![Super Gameduino Features](/Poster.png)
This Game Console is made by:
---------------
1.**Mazen Elnahla:-**  
> E-mail: mazen.elnahla@gmail.com  
> Linkedin: [mazenelnahla](https://www.linkedin.com/in/mazenelnahla/)  

2.**Yara Maher:-**  
> E-mail: yaramaher368@gmail.com  
> Linkedin: [yara-maher-8a964b245](https://www.linkedin.com/in/yara-maher-8a964b245/)  

3.**Shrook Ali:-**  
> E-mail: shrookali295@gmail.com  
> Linkedin: [shrook-ali-9999b0247](https://www.linkedin.com/in/shrook-ali-9999b0247/) 

4.**Massa Mostafa:-**  
> E-mail: massamostafa2001@gmail.com
---------------
# Programs Used in the project
> Fritzing [Download](https://fritzing.org/download/)
 
> Android Studio [Download](https://developer.android.com/studio?gclid=Cj0KCQiA5NSdBhDfARIsALzs2EAlj6Quvetqtclswul9n71aMF2TtcUv1U-Cebi1ctUQs-VpFrBFUhwaAhF9EALw_wcB&gclsrc=aw.ds)
 
> Arduino IDE [1.18.19](https://www.arduino.cc/en/software)

# Including ESP32 in Arduino IDE
1) open the Arduino IDE

2) open the preferences window, File/Preference, alternatively press "Ctrl+comma"

3) go to the “Additional Board Manager URLs”, copy and paste the following text:

[https://dl.espressif.com/dl/package_esp32_index.json](https://dl.espressif.com/dl/package_esp32_index.json)

and click the OK button .

4) Open boards manager. Go to Tools/Board/Boards Manager…

5) Search for ESP32 and press the install button for the “ESP32 by Espressif Systems“:

6) At this point, when you connect for the first time your ESP32, you should choose the right model in the long list of available ESP32 boards (see the picture in this step). In case of doubts about the model, just choose the generic one, i.e. the first one. It works for me.

7) the system should also choose the right USB (COM) port and the Upload Speed (normally 921600). At this point the connection between your PC and the ESP32 board should be established.

# Including the modified fabgl library
copy the file in the library to your arduino folder in Documents in windows or compress the file to (.zip) extertion and include it to arduino ide
