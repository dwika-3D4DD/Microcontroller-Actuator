//Halaman Menu - 0:
void Halaman_Menu_0() {
  //Kondisi untuk membuka halaman:
  if (Nomor_menu == 0) {

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
      lcd.setCursor(2, 0);
      lcd.print(Menu_judul[0]);

      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
      lcd.setCursor(1, 1);
      //Menulis di LCD:
      lcd.print(Menu_judul[1]);
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


    //Condição para selecionar página 1 e 3:
    if (Nomor_judul == 2 || Nomor_judul == 4) {
      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
      lcd.setCursor(0, 0);
      //Menulis di LCD:
      lcd.print(">");
    }
    //Condição para selecionar página 2 e 4:
    else if (Nomor_judul == 1 || Nomor_judul == 3 || Nomor_judul == 5) {
      //Mendefinisikan kolom (pada 16) dan baris (pada 2) dari LCD di mana menulis:
      lcd.setCursor(0, 1);
      //Menulis di LCD:
      lcd.print(">");
    }


    //  //Potensiometer bertindak disini
    //  //Kondisi untuk tindakan tombol pada halaman:
    //  if (digitalRead(btn_ok_cancel) == LOW) {
    //    //Kondisi untuk memilih halaman:
    //    if (Nomor_judul >= 1) {
    //      //Mengubah nilai pemilihan judul menu.
    //      Nomor_judul = Nomor_judul + 1;
    //    }
    //    //Kondisi untuk memilih halaman:
    //    if (Nomor_judul > 4) {
    //      //Mengubah nilai pemilihan judul menu.
    //      Nomor_judul = 4;
    //    }
    //  }


    //Kondisi untuk tindakan tombol pada halaman:
    if (digitalRead(btn_ok) == LOW) {
      //Kondisi untuk memilih halaman:
      if (Nomor_judul == 1) {
        //Mengubah nilai pemilihan menu.
        Nomor_menu = 1;
      }
      //Kondisi untuk memilih halaman:
      else if (Nomor_judul == 2) {
        //Mengubah nilai pemilihan judul menu.
        Nomor_judul = 6;
        //Mengubah nilai pemilihan menu.
        Nomor_menu = 2;
      }
      //Kondisi untuk memilih halaman:
      else if (Nomor_judul == 3) {
        //Mengubah nilai pemilihan judul menu.
        Nomor_judul = 7;
        //Mengubah nilai pemilihan menu.
        Nomor_menu = 3;
      }
      //Kondisi untuk memilih halaman:
      else if (Nomor_judul == 4) {
        Nomor_judul = 8;
        //Mengubah nilai pemilihan menu.
        Nomor_menu = 4;
      }
      //Kondisi untuk memilih halaman:
      else if (Nomor_judul == 5) {
        //Mengubah nilai pemilihan menu.
        Nomor_menu = 5;
      }
    }
  }
}
