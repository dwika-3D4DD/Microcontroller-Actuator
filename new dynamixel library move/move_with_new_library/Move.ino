void move_1(float x, float y, float z){
  move_counter++;
  if (move_counter == 1){
    doInverse(0, 0, z);
    dxl.setGoalPosition(servoID_fr[0], alpha);
    dxl.setGoalPosition(servoID_fr[1], beta);
    dxl.setGoalPosition(servoID_fr[2], gama);
    dxl.setGoalPosition(servoID_bl[0], alpha);
    dxl.setGoalPosition(servoID_bl[1], beta);
    dxl.setGoalPosition(servoID_bl[2], gama);
    
    delay(10);

    doInverse(x, y, z);
    dxl.setGoalPosition(servoID_fr[0], alpha);
    dxl.setGoalPosition(servoID_fr[1], beta);
    dxl.setGoalPosition(servoID_fr[2], gama);
    doInverse(-x, -y, z);
    dxl.setGoalPosition(servoID_bl[0], alpha);
    dxl.setGoalPosition(servoID_bl[1], beta);
    dxl.setGoalPosition(servoID_bl[2], gama);    

    delay(10);

    doInverse(x, y, 0);
    dxl.setGoalPosition(servoID_fr[0], alpha);
    dxl.setGoalPosition(servoID_fr[1], beta);
    dxl.setGoalPosition(servoID_fr[2], gama);
    doInverse(-x, -y, 0);
    dxl.setGoalPosition(servoID_bl[0], alpha);
    dxl.setGoalPosition(servoID_bl[1], beta);
    dxl.setGoalPosition(servoID_bl[2], gama);    

    delay(10);

    doInverse(0, 0, z);
    dxl.setGoalPosition(servoID_fl[0], alpha);
    dxl.setGoalPosition(servoID_fl[1], beta);
    dxl.setGoalPosition(servoID_fl[2], gama);
    dxl.setGoalPosition(servoID_br[0], alpha);
    dxl.setGoalPosition(servoID_br[1], beta);
    dxl.setGoalPosition(servoID_br[2], gama);
    doInverse(0, 0, 0);
    dxl.setGoalPosition(servoID_fr[0], alpha);
    dxl.setGoalPosition(servoID_fr[1], beta);
    dxl.setGoalPosition(servoID_fr[2], gama);    
    dxl.setGoalPosition(servoID_bl[0], alpha);
    dxl.setGoalPosition(servoID_bl[1], beta);
    dxl.setGoalPosition(servoID_bl[2], gama);
    
    delay(10);
  }
    else if (move_counter == 2){
    doInverse(0, 0, z);
    dxl.setGoalPosition(servoID_fl[0], alpha);
    dxl.setGoalPosition(servoID_fl[1], beta);
    dxl.setGoalPosition(servoID_fl[2], gama);
    dxl.setGoalPosition(servoID_br[0], alpha);
    dxl.setGoalPosition(servoID_br[1], beta);
    dxl.setGoalPosition(servoID_br[2], gama);
    doInverse(y, x, z);
    dxl.setGoalPosition(servoID_fl[0], alpha);
    dxl.setGoalPosition(servoID_fl[1], beta);
    dxl.setGoalPosition(servoID_fl[2], gama);
    doInverse(-y,-x, z);
    dxl.setGoalPosition(servoID_br[0], alpha);
    dxl.setGoalPosition(servoID_br[1], beta);
    dxl.setGoalPosition(servoID_br[2], gama);

    delay(10);

    doInverse(y, x, 0);
    dxl.setGoalPosition(servoID_fl[0], alpha);
    dxl.setGoalPosition(servoID_fl[1], beta);
    dxl.setGoalPosition(servoID_fl[2], gama);
    doInverse(-y, -x, 0);
    dxl.setGoalPosition(servoID_br[0], alpha);
    dxl.setGoalPosition(servoID_br[1], beta);
    dxl.setGoalPosition(servoID_br[2], gama);    

    delay(10);

    doInverse(0, 0, z);
    dxl.setGoalPosition(servoID_fr[0], alpha);
    dxl.setGoalPosition(servoID_fr[1], beta);
    dxl.setGoalPosition(servoID_fr[2], gama);    
    dxl.setGoalPosition(servoID_bl[0], alpha);
    dxl.setGoalPosition(servoID_bl[1], beta);
    dxl.setGoalPosition(servoID_bl[2], gama);
    doInverse(0, 0, 0);
    dxl.setGoalPosition(servoID_fl[0], alpha);
    dxl.setGoalPosition(servoID_fl[1], beta);
    dxl.setGoalPosition(servoID_fl[2], gama);    
    dxl.setGoalPosition(servoID_br[0], alpha);
    dxl.setGoalPosition(servoID_br[1], beta);
    dxl.setGoalPosition(servoID_br[2], gama);    

    delay(10);

    move_counter = 0;
  } 
}
