// ***************************************
// * THIS IS THE FILE FOR KEYBOARD INPUT *
// ***************************************
// --------------------------------------------------------
void LL_Input_Controller(){
    player->_idanm = 1;
    if(up == true || down == true|| left == true || right == true){
        player->_idanm = 2;
        player->LL_Player_Move();
    }
    // ---------------------------------------
    // - ALL THE MOVEMENT CODE GOES IN HERE  -
    // ---------------------------------------
    if(up && left){
        player->player_a = LL_Cam->_AngleH+45;
    }else if(up && right){
        player->player_a = LL_Cam->_AngleH-45;
    }else if(up){
        player->player_a = LL_Cam->_AngleH;
    }

    if(down && left){
        player->player_a = 180 + LL_Cam->_AngleH-45;
    }else if(down && right){
        player->player_a = 180 + LL_Cam->_AngleH+45;
    }else if(down){
        player->player_a = 180 + LL_Cam->_AngleH;
    }

    if(left && !down && !up){
        player->player_a = LL_Cam->_AngleH+90;
    }

    if(right && !down && !up){
        player->player_a = LL_Cam->_AngleH-90;
    }
    // ---------------------------------------
    LL_World->LL_Chunk_Update();
}
void LL_User_Input_Dwn(unsigned char key, int x, int y){
    switch(key){
        case 'w':up   =true;break; // THIS CHECKS WHICH KEYS ARE
        case 'a':left =true;break; // PRESSED AND THEN IT SETS A VAL
        case 's':down =true;break; // TO TRUE, WHEN DETECTED
        case 'd':right=true;break; // 
        case 'W':up   =true;break; // THIS CHECKS WHICH KEYS ARE
        case 'A':left =true;break; // PRESSED AND THEN IT SETS A VAL
        case 'S':down =true;break; // TO TRUE, WHEN DETECTED
        case 'D':right=true;break; // 
        case ' ':player->player_y++;break;
        case 'x':player->player_y--;break;
    }
}
// -------------------------------------------------------
void LL_User_Input_Up(unsigned char key, int x, int y){
    switch(key){
        case 'w':up   =false;break; // ONCE THE KEY STOPS BEING PRESSED
        case 'a':left =false;break; // IT IS SET TO FALSE, THIS WILL
        case 's':down =false;break; // ALLOW THE CREATION OF
        case 'd':right=false;break; // MULTIPLE KEY DETECTION INPUT
        case 'W':up   =false;break; // ONCE THE KEY STOPS BEING PRESSED
        case 'A':left =false;break; // IT IS SET TO FALSE, THIS WILL
        case 'S':down =false;break; // ALLOW THE CREATION OF
        case 'D':right=false;break; // MULTIPLE KEY DETECTION INPUT
    }
}
// -------------------------------------------------------