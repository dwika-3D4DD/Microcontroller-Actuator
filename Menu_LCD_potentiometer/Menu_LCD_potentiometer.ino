#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SRF_trig      4
#define SRF_echo      5

// Inisialisasi tampilan di alamat 0x27
LiquidCrystal_I2C lcd(0x27, 20, 2);

int btn_ok = 3;
int btn_cancel = 6;

int Nomor_menu = 0;         //Variabel untuk pemilihan halaman.
int Nomor_judul = 1;        //Variabel untuk memilih judul halaman.

//Variabel untuk judul halaman.
char* Menu_judul[] = { "PILIH SENSOR",
                       "ULTRASONIC",
                       "IR",
                       "FLAME",
                       "KOMPAS",
                       "KAMERA",
                       };
                       
float SRFVal;

void setup() {
  //Mulai Komunikasi dengan LCD 16x2:
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  //Definisi jenis pin (Output atau input):
  pinMode(btn_ok, INPUT_PULLUP);
  pinMode(btn_cancel, INPUT_PULLUP);
  pinMode(SRF_trig, OUTPUT);
  pinMode(SRF_echo, INPUT);
}

//Jalankan fungsi LOOP berulang kali:
void loop() {
  //Jalankan fungsi:
  Halaman_Menu_0();
  //Jalankan fungsi:
    Halaman_1();
//    //Jalankan fungsi:
//    Halaman_Menu_2();
//    //Jalankan fungsi:
//    Halaman_2_1();
//    //Jalankan fungsi:
//    Halaman_2_2();
//    //Jalankan fungsi:
//    Halaman_Menu_3();
//    //Jalankan fungsi:
//    Halaman_3_1();
//    //Jalankan fungsi:
//    Halaman_3_2();
//    //Jalankan fungsi:
//    Halaman_3_3();
//    //Jalankan fungsi:
//    Halaman_4();

  //Penundaan untuk langkah selanjutnya:
  delay(200);
}

//Halaman Menu - 1:


//Halaman Menu - 2:
//void Halaman_Menu_2(){
//  //Kondisi untuk membuka halaman:
//  if (Nomor_menu == 2){
//    //Menghapus informasi dari LCD.
//    lcd.clear();
//    //Syarat penulisan nama halaman di LCD :
//    if (Nomor_judul == 5 || Nomor_judul == 6){
//      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//      lcd.setCursor(1, 0);
//      //Menulis di LCD:
//      lcd.print(Menu_judul[5]);
//      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//      lcd.setCursor(1, 1);
//      //Menulis di LCD:
//      lcd.print(Menu_judul[6]);
//    }
//    //Condição para selecionar página 2.1:
//    if (Nomor_judul == 5){
//      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//      lcd.setCursor(0, 0);
//      //Menulis di LCD:
//      lcd.print(">");
//    }
//    //Condição para selecionar página 2.2:
//    else if (Nomor_judul == 6){
//      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//      lcd.setCursor(0, 1);
//      //Menulis di LCD:
//      lcd.print(">");
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_up) == LOW){
//      //Kondisi untuk memilih halaman:
//      if (Nomor_judul == 5){
//        //Mengubah nilai pemilihan judul menu.
//        Nomor_judul = Nomor_judul + 1;
//      }
//      //Kondisi untuk memilih halaman:
//      else if (Nomor_judul == 6){
//        //Mengubah nilai pemilihan judul menu.
//        Nomor_judul = Nomor_judul - 1;
//      }
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_kembali) == LOW){
//      //Mengubah nilai pemilihan judul menu.
//      Nomor_judul = 2;
//      //Mengubah nilai pemilihan menu.
//      Nomor_menu = 0;
//    }
//
//    //Atraso para o próximo passo:
//    delay(100);
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_konfirmasi) == LOW){
//      //Kondisi untuk memilih halaman:
//      if (Nomor_judul == 5){
//        //Mengubah nilai pemilihan menu.
//        Nomor_menu = 5;
//      }
//      //Kondisi untuk memilih halaman:
//      else if (Nomor_judul == 6){
//        //Mengubah nilai pemilihan menu.
//        Nomor_menu = 6;
//      }
//    }
//  }
//}
//
////Halaman Menu - 2.1:
//void Halaman_2_1(){
//  //Kondisi untuk membuka halaman:
//  if (Nomor_menu == 5){
//    //Menghapus informasi dari LCD.
//    lcd.clear();
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(0, 0);
//    //Menulis di LCD:
//    lcd.print(Menu_judul[5]);
//    lcd.print(":");
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(1, 1);
//    //Menulis di LCD:
//     lcd.print("Led Azul ON...");
//     digitalWrite(Led_biru, HIGH);
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_kembali) == LOW) {
//      //Mengubah nilai pemilihan menu.
//      Nomor_menu = 2;
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_konfirmasi) == LOW) {
//      //Tidak melakukan tindakan apapun.
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_up) == LOW) {
//      //Tidak melakukan tindakan apapun.
//    }
//  }
//}
//
////Halaman Menu - 2.2:
//void Halaman_2_2() {
//  //Kondisi untuk membuka halaman:
//  if (Nomor_menu == 6){
//    //Menghapus informasi dari LCD.
//    lcd.clear();
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(0, 0);
//    //Menulis di LCD:
//    lcd.print(Menu_judul[6]);
//    lcd.print(":");
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(1, 1);
//    //Menulis di LCD:
//    lcd.print("Led Azul OFF...");
//    digitalWrite(Led_biru, LOW);
//    delay(500);
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_kembali) == LOW) {
//      //Altera o valor de selecção do menu
//      Nomor_menu = 2;
//    }
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_konfirmasi) == LOW) {
//      //Tidak melakukan tindakan apapun.
//    }
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_up) == LOW) {
//      //Tidak melakukan tindakan apapun.
//    }
//  }
//}
//
////Halaman Menu - 3:
//void Halaman_Menu_3(){
//  //Kondisi untuk membuka halaman:
//  if (Nomor_menu == 3){
//    //Menghapus informasi dari LCD.
//    lcd.clear();
//    //Syarat penulisan nama halaman di LCD :
//    if (Nomor_judul > 6 & Nomor_judul < 9){
//      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//      lcd.setCursor(1, 0);
//      //Menulis di LCD:
//      lcd.print(Menu_judul[7]);
//      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//      lcd.setCursor(1, 1);
//      //Menulis di LCD:
//      lcd.print(Menu_judul[8]);
//    }
//    //Syarat penulisan nama halaman di LCD :
//    else if (Nomor_judul == 9){
//      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//      lcd.setCursor(1, 0);
//      //Menulis di LCD:
//      lcd.print(Menu_judul[9]);
//    }
//    //Condição para selecionar Halaman 3.1:
//    if (Nomor_judul == 7 || Nomor_judul == 9){
//      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//      lcd.setCursor(0, 0);
//      //Menulis di LCD:
//      lcd.print(">");
//    }
//    //Condição para selecionar Halaman 3.2:
//    else if (Nomor_judul == 8){
//      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//      lcd.setCursor(0, 1);
//      //Menulis di LCD:
//      lcd.print(">");
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_up) == LOW){
//      //Kondisi untuk memilih halaman:
//      if (Nomor_judul >= 7){
//        //Mengubah nilai pemilihan judul menu.
//        Nomor_judul = Nomor_judul + 1;
//      }
//      //Kondisi untuk memilih halaman:
//      if (Nomor_judul > 9){
//        //Mengubah nilai pemilihan judul menu.
//        Nomor_judul = 7;
//      }
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_kembali) == LOW){
//      //Altera o valor de selecção do titulo do menu.
//      Nomor_judul = 3;
//      //Mengubah nilai pemilihan menu.
//      Nomor_menu = 0;
//    }
//
//    //Atraso para o próximo passo:
//    delay(100);
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_konfirmasi) == LOW){
//      //Kondisi untuk memilih halaman:
//      if (Nomor_judul == 7){
//        //Mengubah nilai pemilihan menu.
//        Nomor_menu = 7;
//      }
//      //Kondisi untuk memilih halaman:
//      else if (Nomor_judul == 8){
//        //Mengubah nilai pemilihan menu.
//        Nomor_menu = 8;
//      }
//      //Condição para selecionar Halaman:
//      else if (Nomor_judul == 9){
//        //Mengubah nilai pemilihan menu.
//        Nomor_menu = 9;
//      }
//    }
//  }
//}
//
////Halaman Menu - 3.1:
//void Halaman_3_1() {
//  //Kondisi untuk membuka halaman:
//  if (Nomor_menu == 7){
//    //Menghapus informasi dari LCD.
//    lcd.clear();
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(0, 0);
//    //Menulis di LCD:
//    lcd.print(Menu_judul[7]);
//    lcd.print(":");
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(1, 1);
//    //Menulis di LCD:
//    lcd.print("Led Verm. ON");
//    digitalWrite(Led_merah,HIGH);
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_kembali) == LOW) {
//      //Mengubah nilai pemilihan menu.
//      Nomor_menu = 3;
//    }
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_konfirmasi) == LOW) {
//      //Tidak melakukan tindakan apapun.
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_up) == LOW) {
//      //Tidak melakukan tindakan apapun.
//    }
//  }
//}
////Halaman Menu - 3.2:
//void Halaman_3_2() {
//  //Kondisi untuk membuka halaman:
//  if (Nomor_menu == 8){
//    //Menghapus informasi dari LCD.
//    lcd.clear();
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(0, 0);
//    //Menulis di LCD:
//    lcd.print(Menu_judul[8]);
//    lcd.print(":");
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(1, 1);
//    //Menulis di LCD:
//    lcd.print("Led verm. OFF");
//    digitalWrite(Led_merah,LOW);
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_kembali) == LOW) {
//      //Mengubah nilai pemilihan menu.
//      Nomor_menu = 3;
//    }
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_konfirmasi) == LOW) {
//      //Tidak melakukan tindakan apapun.
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_up) == LOW) {
//      //Tidak melakukan tindakan apapun.
//    }
//  }
//}
//
////Halaman Menu - 3.3:
//void Halaman_3_3() {
//  //Kondisi untuk membuka halaman:
//  if (Nomor_menu == 9){
//    //Menghapus informasi dari LCD.
//    lcd.clear();
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(0, 0);
//    //Menulis di LCD:
//    lcd.print(Menu_judul[9]);
//    lcd.print(":");
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(1, 1);
//    //Menulis di LCD:
//    lcd.print("Piscando...");
//    digitalWrite(Led_merah,HIGH);
//    delay(500);
//    digitalWrite(Led_merah,LOW);
//    delay(500);
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_kembali) == LOW) {
//      //Mengubah nilai pemilihan menu.
//      Nomor_menu = 3;
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_konfirmasi) == LOW) {
//      //Tidak melakukan tindakan apapun.
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_up) == LOW) {
//      //Tidak melakukan tindakan apapun.
//    }
//  }
//}
//
////Halaman Menu - 4:
//void Halaman_4() {
//  //Kondisi untuk membuka halaman:
//  if (Nomor_menu == 4){
//    //Menghapus informasi dari LCD.
//    lcd.clear();
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(0, 0);
//    //Menulis di LCD:
//    lcd.print(Menu_judul[Nomor_judul]);
//    lcd.print(":");
//    //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
//    lcd.setCursor(1, 1);
//
//    //Menulis di LCD:
//
//    readUltra();
//    lcd.print("Jarak: ");
//    lcd.print(SRFVal); // CM or INC
//    lcd.print(" cm");
//    delay(500);
//
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_kembali) == LOW){
//      //Mengubah nilai pemilihan menu.
//      Nomor_menu = 0;
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_konfirmasi) == LOW){
//      //Tidak melakukan tindakan apapun.
//    }
//    //Kondisi untuk tindakan tombol pada halaman:
//    if (digitalRead(Tombol_up) == LOW){
//      //Tidak melakukan tindakan apapun.
//    }
//  }
//}
