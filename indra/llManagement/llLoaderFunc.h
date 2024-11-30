void LL_Load_Models(){
 // *******************************
 // * ALL MODEL LOADING GOES HERE *
 // *******************************
 // -------------------------------------------------------------------------------------------------------------------------------------------
 LL_Models->LL_Model_Push_ls("Res/Models/avatar/head.obj","Res/Textures/avatar.bmp",512,512);      // 0 | THESE ARE THE PLAYER
 LL_Models->LL_Model_Push_ls("Res/Models/avatar/body.obj","Res/Textures/avatar.bmp",512,512);      // 1 | PARTS THAT WILL BE LOADED
 // ------------------------------------------------------------------------------------------------    | INSIDE THE GAME
 LL_Models->LL_Model_Push_ls("Res/Models/avatar/lower_arm.obj","Res/Textures/avatar.bmp",512,512); // 2 | IT IS DIVIDED INTO DIFFERENT PARTS
 LL_Models->LL_Model_Push_ls("Res/Models/avatar/upper_arm.obj","Res/Textures/avatar.bmp",512,512); // 3 | TO MOVE IT, THE TEXTURE IS REPEATED
 // ------------------------------------------------------------------------------------------------    | IN PURPOSE, SO USER CAN CHANGE AND HAVE DIFFERENT
 LL_Models->LL_Model_Push_ls("Res/Models/avatar/lower_leg.obj","Res/Textures/avatar.bmp",512,512); // 4 | TEXTURES PER MODEL
 LL_Models->LL_Model_Push_ls("Res/Models/avatar/upper_leg.obj","Res/Textures/avatar.bmp",512,512); // 5 | --------------------------------------
 // ----------------------------------------------------------------------------------------------------+
 
}

void LL_Load_Textures(){
    LL_FLOOR_TEMPLATE = LL_Bmp_Load_Image("Res/Textures/floor.bmp", 256, 256);
    LL_GRASS_TEXTURES = LL_Bmp_Load_Image("Res/Textures/grass.bmp", 256, 256);
}