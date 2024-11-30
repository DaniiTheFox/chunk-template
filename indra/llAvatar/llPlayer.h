// --------------------------------------------
// - THIS IS THE AVATAR MODEL WITH ANIMATIONS -
// --------------------------------------------
#include "llAnimator/llAnimations.h"
// ********************************************************************
class LL_Player {                                               // 
    public:                                                     // THIS IS THE PLAYER OBJECT
        float player_a = 0;                                     //
        float player_x = 0, player_y = 0, player_z = 0;         // AND IT'S RENDERER FOR THE ANIMATIONS
        float _accel = 1, _accl = 0.1,                          //
              _max_acc = 3, _min_acc = 1;                       //
        int _frame = 0;                                         //
        int _idanm = 1;                                         // y = mx + b
        int _id_am = 0;                                         //
        LL_Player(float _startx, float _starty, float _startz); // y = 30x + 1
        void LL_Player_Draw();                                  // 
        void LL_Player_Move();                                  //
};                                                              // 
// --------------------------------------------------------------------
LL_Player::LL_Player(float _startx, float _starty, float _startz){  // THIS IS THE PLAYER CONSTRUCTOR
    player_x = _startx;             // ------------------------------
    player_y = _starty;             //  THIS IS THE STARTUP POSITION
    player_z = _startz;             // ------------------------------
}
// --------------------------------------------------------------------
void LL_Player::LL_Player_Draw(){
    glTranslatef(player_x,player_y+0.6,player_z);
    glRotatef(player_a, 0.0, 1.0, 0.0);
    glScalef(0.4,0.4,0.4);
    _frame = (30*_id_am)+(1*_id_am);
    glPushMatrix();
        //glTranslatef(player_x,player_y,player_z);
        glRotatef(_anim[_idanm][_frame], 1.0, 0.0, 0.0); //rotate 45 on y axis
        //---------------------------------------------------------------
        // -------------------
        // -  PLAYER'S HEAD  - 
        // -------------------
        glPushMatrix();
            // ----------------------------------------------------
            glTranslatef(0,1.2,0); // OFFSET MOVEMENT FOR CENTER
            // ----------------------------------------------------
            glRotatef(_anim[_idanm][_frame+1], 1.0, 0.0, 0.0); //rotate 45 on x axis
            glRotatef(_anim[_idanm][_frame+2], 0.0, 1.0, 0.0); //rotate 45 on y axis
            glRotatef(_anim[_idanm][_frame+3], 0.0, 0.0, 1.0); //rotate 45 on z axis
            // ----------------------------------------------------
            glScalef(0.3,0.3,0.3); // KEEP THE SCALE FOR EACH PIECE
            // ----------------------------------------------------
            LL_Models->LL_Model_Draw(0); // ACTUALLY DRAW THE MODEL
            // ----------------------------------------------------
        glPopMatrix();
        //---------------------------------------------------------------
        // -------------------
        // -  PLAYER'S BODY  -
        // -------------------
        glPushMatrix();
            // ----------------------------------------------------
            glTranslatef(0,0,0); // OFFSET MOVEMENT FOR CENTER
            // ----------------------------------------------------
            glRotatef(_anim[_idanm][_frame+4], 1.0, 0.0, 0.0); //rotate 45 on x axis
            glRotatef(_anim[_idanm][_frame+5], 0.0, 1.0, 0.0); //rotate 45 on y axis
            glRotatef(_anim[_idanm][_frame+6], 0.0, 0.0, 1.0); //rotate 45 on z axis
            // ----------------------------------------------------
            glScalef(0.3,0.3,0.3); // KEEP THE SCALE FOR EACH PIECE
            // ----------------------------------------------------
            LL_Models->LL_Model_Draw(1); // ACTUALLY DRAW THE MODEL
            // ----------------------------------------------------
        glPopMatrix();
        //---------------------------------------------------------------
        // ----------------------
        // - PLAYER'S LEFT ARM  -
        // ----------------------
        glPushMatrix();
            // ----------------------------------------------------
            glTranslatef(-0.4,0.9,0); // OFFSET MOVEMENT FOR CENTER
            // ----------------------------------------------------
            glRotatef(_anim[_idanm][_frame+7], 1.0, 0.0, 0.0); //rotate 45 on x axis
            glRotatef(_anim[_idanm][_frame+8], 0.0, 1.0, 0.0); //rotate 45 on y axis
            glRotatef(_anim[_idanm][_frame+9], 0.0, 0.0, 1.0); //rotate 45 on z axis
            // ----------------------------------------------------
            glPushMatrix();
            // ----------------------------------------------------
                glTranslatef(-0.7,0,0); // OFFSET MOVEMENT FOR CENTER
                // ----------------------------------------------------
                    glRotatef(_anim[_idanm][_frame+10], 1.0, 0.0, 0.0); //rotate 45 on x axis
                    glRotatef(_anim[_idanm][_frame+11], 0.0, 1.0, 0.0); //rotate 45 on y axis
                    glRotatef(_anim[_idanm][_frame+12], 0.0, 0.0, 1.0); //rotate 45 on z axis
                // ----------------------------------------------------
                    glScalef(0.3,0.3,0.3); // KEEP THE SCALE FOR EACH PIECE
                // ----------------------------------------------------
                    LL_Models->LL_Model_Draw(2); // ACTUALLY DRAW THE MODEL
            // ----------------------------------------------------
            glPopMatrix();
            // ----------------------------------------------------
            glScalef(0.3,0.3,0.3); // KEEP THE SCALE FOR EACH PIECE
            // ----------------------------------------------------
            LL_Models->LL_Model_Draw(3); // ACTUALLY DRAW THE MODEL
            // ----------------------------------------------------
        glPopMatrix();
    //glPopMatrix();
    //---------------------------------------------------------------
    // ----------------------
    // - PLAYER'S RIGHT ARM -
    // ----------------------
    glPushMatrix();
        // ----------------------------------------------------
        glTranslatef(0.4,0.9,0); // OFFSET MOVEMENT FOR CENTER
        glRotatef(180.0, 0.0, 1.0, 0.0); //rotate 180 on y axis
        // ----------------------------------------------------
        glRotatef(_anim[_idanm][_frame+13], 1.0, 0.0, 0.0); //rotate 45 on x axis
        glRotatef(_anim[_idanm][_frame+14], 0.0, 1.0, 0.0); //rotate 45 on y axis
        glRotatef(_anim[_idanm][_frame+15], 0.0, 0.0, 1.0); //rotate 45 on z axis
        // ----------------------------------------------------
        glPushMatrix();
        // ----------------------------------------------------
            glTranslatef(-0.7,0,0); // OFFSET MOVEMENT FOR CENTER
            // ----------------------------------------------------
                glRotatef(_anim[_idanm][_frame+16], 1.0, 0.0, 0.0); //rotate 45 on x axis
                glRotatef(_anim[_idanm][_frame+17], 0.0, 1.0, 0.0); //rotate 45 on y axis
                glRotatef(_anim[_idanm][_frame+18], 0.0, 0.0, 1.0); //rotate 45 on z axis
            // ----------------------------------------------------
                glScalef(0.3,0.3,0.3); // KEEP THE SCALE FOR EACH PIECE
            // ----------------------------------------------------
                LL_Models->LL_Model_Draw(2); // ACTUALLY DRAW THE MODEL
        // ----------------------------------------------------
        glPopMatrix();
        // ----------------------------------------------------
        glScalef(0.3,0.3,0.3); // KEEP THE SCALE FOR EACH PIECE
        // ----------------------------------------------------
        LL_Models->LL_Model_Draw(3); // ACTUALLY DRAW THE MODEL
        // ----------------------------------------------------
        glPopMatrix();
    //glPopMatrix();
    //---------------------------------------------------------------
    // ----------------------
    // - PLAYER'S LEFT LEG  -
    // ----------------------
    glPushMatrix();
        // ----------------------------------------------------
        glTranslatef(-0.2,-0.35,0); // OFFSET MOVEMENT FOR CENTER
        // ----------------------------------------------------
        glRotatef(_anim[_idanm][_frame+19], 1.0, 0.0, 0.0); //rotate 45 on x axis
        glRotatef(_anim[_idanm][_frame+20], 0.0, 1.0, 0.0); //rotate 45 on y axis
        glRotatef(_anim[_idanm][_frame+21], 0.0, 0.0, 1.0); //rotate 45 on z axis
        // ----------------------------------------------------
        glPushMatrix();
        // ----------------------------------------------------
            glTranslatef(0,-0.65,0); // OFFSET MOVEMENT FOR CENTER
            // ----------------------------------------------------
                glRotatef(_anim[_idanm][_frame+22], 1.0, 0.0, 0.0); //rotate 45 on x axis
                glRotatef(_anim[_idanm][_frame+23], 0.0, 1.0, 0.0); //rotate 45 on y axis
                glRotatef(_anim[_idanm][_frame+24], 0.0, 0.0, 1.0); //rotate 45 on z axis
            // ----------------------------------------------------
                glScalef(0.3,0.3,0.3); // KEEP THE SCALE FOR EACH PIECE
            // ----------------------------------------------------
                LL_Models->LL_Model_Draw(4); // ACTUALLY DRAW THE MODEL
        // ----------------------------------------------------
        glPopMatrix();
        // ----------------------------------------------------
        glScalef(0.3,0.3,0.3); // KEEP THE SCALE FOR EACH PIECE
        // ----------------------------------------------------
        LL_Models->LL_Model_Draw(5); // ACTUALLY DRAW THE MODEL
        // ----------------------------------------------------
        //glPopMatrix();
    glPopMatrix();
    //---------------------------------------------------------------
    // -----------------------
    // - PLAYER'S RIGHT LEG  -
    // -----------------------
    glPushMatrix();
        // ----------------------------------------------------
        glTranslatef(0.2,-0.35,0); // OFFSET MOVEMENT FOR CENTER
        // ----------------------------------------------------
        glRotatef(_anim[_idanm][_frame+25], 1.0, 0.0, 0.0); //rotate 45 on x axis
        glRotatef(_anim[_idanm][_frame+26], 0.0, 1.0, 0.0); //rotate 45 on y axis
        glRotatef(_anim[_idanm][_frame+27], 0.0, 0.0, 1.0); //rotate 45 on z axis
        // ----------------------------------------------------
        glPushMatrix();
        // ----------------------------------------------------
            glTranslatef(0,-0.65,0); // OFFSET MOVEMENT FOR CENTER
            // ----------------------------------------------------
                glRotatef(_anim[_idanm][_frame+28], 1.0, 0.0, 0.0); //rotate 45 on x axis
                glRotatef(_anim[_idanm][_frame+29], 0.0, 1.0, 0.0); //rotate 45 on y axis
                glRotatef(_anim[_idanm][_frame+30], 0.0, 0.0, 1.0); //rotate 45 on z axis
            // ----------------------------------------------------
                glScalef(0.3,0.3,0.3); // KEEP THE SCALE FOR EACH PIECE
            // ----------------------------------------------------
                LL_Models->LL_Model_Draw(4); // ACTUALLY DRAW THE MODEL
        // ----------------------------------------------------
        glPopMatrix();
        // ----------------------------------------------------
        glScalef(0.3,0.3,0.3); // KEEP THE SCALE FOR EACH PIECE
        // ----------------------------------------------------
        LL_Models->LL_Model_Draw(5); // ACTUALLY DRAW THE MODEL
        // ----------------------------------------------------
        glPopMatrix();
    glPopMatrix();
    //---------------------------------------------------------------
}
// -------------------------------------------------------------------
void LL_Player::LL_Player_Move(){
    player_x = player_x + cos(((player_a-90) * 3.14159)/180) * _accel;
    player_z = player_z - sin(((player_a-90) * 3.14159)/180) * _accel;
}
// -------------------------------------------------------------------
LL_Player *player = new LL_Player(8,51,8);