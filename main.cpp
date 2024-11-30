/*
------------------------------------------------
- THESE ARE THE MAIN LIBRARIES FROM THE SYSTEM -
------------------------------------------------
*/
#include<GL/glut.h>
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <string.h> 
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <thread>
#include <future>
#include <chrono>
#include <iomanip>
#include <time.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <random>
/*
=====================================================
= LIB CALLS WILL OCCUR IN THIS PART OF THE CODE UWU =
=====================================================
*/

// MAIN GLOBAL VARIABLES INCLUDES FOR COMPILATION AND SIMULATION
#include "variables/LL_BUILD.h"
#include "variables/llGlobalVars.h"
/*
-------------------------------------------------------
- INCLUDE THE IMGUI LIBRARIES TO GET THE HUDS WORKING - 
------------------------------------------------------- 
*/
#include "lib/imgui/imgui.h"                       
#include "lib/imgui/backends/imgui_impl_opengl2.h" 
#include "lib/imgui/backends/imgui_impl_glut.h"    
#include "lib/style.h"   
#define  STB_IMAGE_IMPLEMENTATION"
#include "lib/stb_image.h"
/**
----------------------------------------
- THIS IS THE LOADING PART FOR OBJECTS -
----------------------------------------
*/           
#include "indra/llConsole/llTerminal.h"
#include "indra/llObjLoader/llObjLoad.h"
#include "indra/llObjLoader/llObjDraw.h"   
#include "indra/llManagement/llTextures.h"
#include "indra/llManagement/llModelMgr.h"  
#include "indra/llAvatar/llPlayer.h"        
/*
----------------------------------------
- WORLD GENERATION GOES INTO THIS PART -
----------------------------------------
*/  
#include "lib/llPerlin.h"
#include "indra/llPrimitives/llFloor.h"
#include "indra/llWorld/llChunks.h"
/*
-----------------------------------------------
- RENDERING AND SIMULATOR SET UP INCLUDES UWU -
-----------------------------------------------
*/
#include "indra/llRendering/llHud.h"
#include "indra/llPlayer/llCamera.h"
#include "indra/llControls/llUserInput.h"
#include "indra/llControls/llMouseInput.h"
#include "indra/llRendering/llAuxiliar.h"
#include "indra/llRendering/llDisplay.h"

int main(int argc, char **argv){
  LL_Sterm->LL_Termios_Log("Welcome to PRISM ENGINE!");
  IMGUI_CHECKVERSION();   // TEST VERSION OF IMGUI
  ImGui::CreateContext(); // CREATE AN IMGUI CONTEXT
  glutInit(&argc,argv);
  		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  		glutInitWindowSize(BON_SCREEN_W,BON_SCREEN_H);
  		glutCreateWindow(".:: Prism Engine - Delta ::.");
  ImGuiIO &io = ImGui::GetIO(); (void) io;                     // initialize input/output of the imgui API
  ImGui::StyleColorsDark();                                    // define dark color for the im gui api
  ImGui_ImplGLUT_Init();                                       // start the GLUT version of imgui
  ImGui_ImplGLUT_InstallFuncs();                               // install functions of imgui
  ImGui_ImplOpenGL2_Init();                                    // use opengl 2 on imgui (to avoid pipewire)
  glClearDepth(1.0f);
  glDepthFunc(GL_LEQUAL);
  LL_Gemini_start();
  glutIgnoreKeyRepeat(1);
  	glutDisplayFunc(LL_Gemini_display);
  	glutKeyboardFunc(LL_User_Input_Dwn);                 // THE FUNCTION FOR KEYBOARD INTERACTIONS
  	glutKeyboardUpFunc(LL_User_Input_Up);               // THE FUNCTION TO RESET THE KEYS THAT WHERE PRESSED
  	glutMouseFunc(LL_Mouse_Controller);
  	glutMotionFunc(LL_Mouse_Motion);
  	glutIdleFunc(LL_Gemini_stand);
  	glutTimerFunc(30, Timer, 0);
  glutMainLoop();
  ImGui_ImplOpenGL2_Shutdown();               // end the OpenGL2 of ImGui
  ImGui_ImplGLUT_Shutdown();                  // shut down glut of imgui
  ImGui::DestroyContext();                    // destroy the context
  return 0;
}
