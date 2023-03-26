void doInverse (double x, double y, double z){
  x += startPos;
  y += startPos;
  z = height - z;

  float L1 = sqrt((x * x) + (y * y));
  float L = sqrt(((L1 - coxa)*(L1 - coxa) + (z * z)));
  alpha = atan(x/y);
  alpha = ((alpha * 57.296)  + 15) * 3.41;                                       //karna titik 0 nya gak pas horizontal dan pemasangan kaki servonya, makanya ditambah 15
  beta = acos(z/L) + acos(((femur*femur) + (L*L) - (tibia*tibia)) / (2*femur*L));
  beta = ((beta   * 57.296)  + 15) * 3.41;
  gama = acos((tibia*tibia + femur*femur - L*L) / (2 * tibia * femur));
  gama = (300 - ((gama * 57.296)  + 15)) * 3.41; 
}
