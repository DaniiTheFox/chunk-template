/*
================================================================================================================================
= JUST A FUNCTION TO LOAD THE CUBE TEXTURES FROM A BITMAP AND IMPLEMENT THEM INSIDE THE PROGRAM TO BE ABLE TO DO TEXTUREPACKS  =
================================================================================================================================
*/
#include "../../etc/broken.c"
GLuint LL_Bmp_Load_Image(char *filename, int w, int h){
 LL_Sterm->LL_Termios_Log("Game will load a new texture now.... texture size: "+std::to_string(w)+" x "+std::to_string(h));
 GLuint tmp_txt;                                                                //
 int comp = 4;                                                                  // LOAD THE IMAGE
 unsigned char* image = stbi_load(filename, &w, &h, &comp, STBI_rgb_alpha);     // 
 // --------------------------------------------------------------------------------------------
 if(image == nullptr){                                                          // 
    glGenTextures(1, &tmp_txt);                                                 // IF THE MODEL FAILS TO LOAD
    glBindTexture(GL_TEXTURE_2D, tmp_txt);                                      // THEN THE FUNCTION
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);                // WILL LOAD A DEFAULT TEXTURE
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);          // ----------------------------
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);          // THIS IS DONE TO AVOID ERRORS
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);               // AND FIND WHICH TEXTURE FAILED
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);               // 
    LL_Sterm->LL_Termios_Log("Failed to load texture.... default applied");
    gluBuild2DMipmaps(GL_TEXTURE_2D, brk_tex.bytes_per_pixel, brk_tex.width, brk_tex.height, GL_RGBA, GL_UNSIGNED_BYTE, brk_tex.pixel_data);
 }
 // -------------------------------------------------------------------------------------------------
 glGenTextures(1, &tmp_txt);                                        // 
 glBindTexture(GL_TEXTURE_2D, tmp_txt);                             // GENERATE THE TEXTURES
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);  // THAT WE LOADED FROM FILE
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // 
 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
 // --------------------------------------------------------------------------------------------------
 stbi_image_free(image);
 return tmp_txt;
}
// ---------------------------------------------------------------------------------------------------
