/*
 * IRRemote 紅外線遙控教學
 *   範例 2.1v2: 發射紅外線訊號
 *     注意! 紅外線發射器(IR LED)必須接到 pin 3, 不能接其它腳位
 */
#include <IRremote.h>                    // 引用 IRRemote 函式庫
#include <SoftwareSerial.h>
IRsend irsend;                           // 定義 IRsend 物件來發射紅外線訊號
SoftwareSerial BT(8, 7);//藍芽腳位
char v;
void setup()
{
  
  BT.begin(9600);
  Serial.begin(9600);                     // 開啟 Serial port, 通訊速率為 9600 bps
}

void loop() 
{
  if (BT.available()) {

    v = BT.read();
    Serial.print("BT rev:");
    Serial.println(v);
    BT.print('X');
    switch (v) {
      case '1':
        irsend.sendNEC(0x17B7F80, 32);
        Serial.println("Power On");
        break;
      case '2':
        irsend.sendNEC(0x17BBF40, 32);
        Serial.println("Fan Speen");
        break;
      case '3':
        irsend.sendNEC(0x17BF708, 32);
        Serial.println("Set Time");
        break;
      case '4':
        irsend.sendNEC(0x17BDF20, 32);
        Serial.println("Swing L/R");
        break;
      case '5':
        irsend.sendNEC(0x17BEF10, 32);
        Serial.println("Swing U/D");
        break;
      }
  }
  
}
