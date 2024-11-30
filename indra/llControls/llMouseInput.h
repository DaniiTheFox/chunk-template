// ******************************************
// *  THESE IS THE MOUSE INPUT FOR CONTROLS *
// ******************************************
// -------------------------------------------------------------
void LL_Mouse_Controller(int button, int state, int x, int y){
    // -------------------------
    if(button == 3){        // ---------------------------------------------
        LL_Cam->_Zoom--;    // THIS IS THE MOUSE CONTROLLER FOR THE MIDDLE
    }else if(button == 4){  // MOUSE, AND IT WILL CONTROL THE WHEEL FOR ZOOM
        LL_Cam->_Zoom++;    // OF THE CAMERA
    }                       // ---------------------------------------------
    if(button == GLUT_LEFT_BUTTON){
        _Clicked = true;
    }
}

void LL_Mouse_Motion(int x, int y){
    if(_Clicked == true){
        // -------------------------
        if(x < (LL_Mouse_oldx-LL_Mouse_sensitv)){LL_Cam->_AngleH+=2;}
        if(x > (LL_Mouse_oldx+LL_Mouse_sensitv)){LL_Cam->_AngleH-=2;}
        // -------------------------
        if(y > (LL_Mouse_oldy+LL_Mouse_sensitv)){if(LL_Cam->_AngleV <=50){LL_Cam->_AngleV+=1;}}
        if(y < (LL_Mouse_oldy-LL_Mouse_sensitv)){if(LL_Cam->_AngleV >=-50){LL_Cam->_AngleV-=1;}}
        // -------------------------
        LL_Mouse_oldx = x; // STORE THE CURRENT MOUSE STATE
        LL_Mouse_oldy = y; // TO COMPARE THE OLD MOUSE
    }
}