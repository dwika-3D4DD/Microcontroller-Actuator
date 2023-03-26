void standby_1(){
  doInverse(0, 0, 0);
  for (int i = 1; i <= 12; i+= 3){
    dxl.setGoalPosition(i, alpha, UNIT_RAW);
    dxl.setGoalPosition(i + 1, beta, UNIT_RAW);
    dxl.setGoalPosition(1 + 2, gama, UNIT_RAW);
  }
}
