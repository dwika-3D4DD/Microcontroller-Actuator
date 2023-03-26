void Halaman_1() {
  //Kondisi untuk membuka halaman:
  if (Nomor_menu == 1) {

    if (analogRead(A0) >= 0 && analogRead(A0) < 200) {
      Nomor_judul = 1;
    } else if (analogRead(A0) >= 200 && analogRead(A0) < 400) {
      Nomor_judul = 2;
    } else if (analogRead(A0) >= 400 && analogRead(A0) < 600) {
      Nomor_judul = 3;
    } else if (analogRead(A0) >= 600 && analogRead(A0) < 800) {
      Nomor_judul = 4;
    } else {
      Nomor_judul = 5;
    }

    //Syarat penulisan nama halaman di LCD :
    if (Nomor_judul > 0 & Nomor_judul < 2) {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("HASIL BACA");

      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
      lcd.setCursor(0, 1);
      //Menulis di LCD:
      lcd.print("SRFVal : ");
      readUltra();
      lcd.print(SRFVal);
      lcd.print("cm");

    }

    //Syarat penulisan nama halaman di LCD :
    else if (Nomor_judul > 1 & Nomor_judul < 4) {

      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
      lcd.clear();
      lcd.setCursor(1, 0);
      //Menulis di LCD:
      lcd.print(Menu_judul[2]);

      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
      lcd.setCursor(1, 1);
      //Menulis di LCD:
      lcd.print(Menu_judul[3]);
    }

    else if (Nomor_judul > 3 & Nomor_judul < 6) {
      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
      lcd.clear();
      lcd.setCursor(1, 0);
      //Menulis di LCD:
      lcd.print(Menu_judul[4]);

      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
      lcd.setCursor(1, 1);
      //Menulis di LCD:
      lcd.print(Menu_judul[5]);
    }


    //Kondisi untuk tindakan tombol pada halaman:
    if (digitalRead(btn_cancel) == LOW) {
      //Mengubah nilai pemilihan menu.
      Nomor_menu = 0;
    }
  }
}
