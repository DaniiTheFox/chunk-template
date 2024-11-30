// ===============================================
// =  THIS IS THE PRIMITIVE SHAPE FOR THE FLOOR  =
// ===============================================
// ***********************************************************
void LL_Prim_Floor(float _corners[16][16], int pos_x, int pos_z){
    glPushMatrix();                     
      glBegin(GL_QUADS);
        // ----------------------------------------------------------------------
        if(_corners[pos_x+1][pos_z] > 40){glColor3f(0.25,0.7,0);                 //    
        }else{glColor3f(0.9,0.9,0.6);}                                           //
  	    glTexCoord2d(0.0,0.0);glVertex3f( 0.5, _corners[pos_x+1][pos_z ],-0.5);  // 
        if(_corners[pos_x][pos_z] > 40){glColor3f(0.25,0.7,0);                   //
        }else{glColor3f(0.9,0.9,0.6);}                                           //
        glTexCoord2d(0.0,1.0);glVertex3f(-0.5, _corners[pos_x  ][pos_z  ],-0.5); // THIS IS THE BASIC PRIMITIVE SHAPE
        if(_corners[pos_x][pos_z+1] > 40){glColor3f(0.25,0.7,0);                 //
        }else{glColor3f(0.9,0.9,0.6);}                                           //
        glTexCoord2d(1.0,1.0);glVertex3f(-0.5, _corners[pos_x  ][pos_z+1], 0.5); // WHICH WILL GET EACH CORNER HEIGHT
        if(_corners[pos_x+1][pos_z+1] > 40){glColor3f(0.25,0.7,0);               //
        }else{glColor3f(0.9,0.9,0.6);}                                           //
        glTexCoord2d(1.0,0.0);glVertex3f( 0.5, _corners[pos_x+1][pos_z+1], 0.5); // BASED ON THE CHUNKS 0,0
        // ----------------------------------------------------------------------
      glEnd();
      if(_corners[pos_x][pos_z] > 40){ // draw grass because i love grass
       glBindTexture(GL_TEXTURE_2D, LL_GRASS_TEXTURES);
        glRotatef(0,0,0,1);
            glDisable(GL_CULL_FACE);
            glBegin(GL_QUADS);        // begin a cube
     	        glTexCoord2d(0.0,1.0);glVertex3f( 0.5,0.6+_corners[pos_x  ][pos_z  ]+  0.5, -0.5);
     	        glTexCoord2d(1.0,1.0);glVertex3f(-0.5,0.6+_corners[pos_x  ][pos_z  ]+  0.5,  0.5+air); // vertices and texture mapping
     	        glTexCoord2d(1.0,0.0);glVertex3f(-0.5,0.6+_corners[pos_x  ][pos_z  ]+ -0.5,  0.5+air);
     	        glTexCoord2d(0.0,0.0);glVertex3f( 0.5,0.6+_corners[pos_x  ][pos_z  ]+ -0.5, -0.5);
            glEnd();
            glBegin(GL_QUADS);
                glTexCoord2d(0.0,1.0);glVertex3f( 0.5,0.6+_corners[pos_x  ][pos_z  ]+  0.5,  0.5+air);
     	        glTexCoord2d(1.0,1.0);glVertex3f(-0.5,0.6+_corners[pos_x  ][pos_z  ]+  0.5, -0.5); // vertices and texture mapping
     	        glTexCoord2d(1.0,0.0);glVertex3f(-0.5,0.6+_corners[pos_x  ][pos_z  ]+ -0.5, -0.5);
     	        glTexCoord2d(0.0,0.0);glVertex3f( 0.5,0.6+_corners[pos_x  ][pos_z  ]+ -0.5,  0.5+air);
            glEnd();
            glPopMatrix();
            glEnable(GL_CULL_FACE);
        glPushMatrix(); 
      }
    glPopMatrix();
}