// *********************************************
// * THIS IS AN IMPROVEMENT ON CHUNK RENDERING *
// *********************************************
// ----------------------------------------------------
int upr_sec_x[3] = {0,1,2}; //   0          1        2
int mid_sec_x[3] = {3,4,5}; // 3 4 5   -- 4 5 3 -- 5 3 4
int lwr_sec_x[3] = {6,7,8}; // THIS IS THE ORGANIZATION FOR THE ARRAY SEGMENTS
// ----------------------------------------------------
struct LL_Chunk_Node {
    // ------- CHUNK SYSTEM ESSENTIALS --------------------------
    int LL_Zone_x = 0;           // FOR THE BIGGER X COORDINATES | CHUNK MAP SCALE
    int LL_Zone_y = 0;           // FOR THE BIGGER Y COORDINATES |
    int LL_C_State= 0;           // CHUNK STATE FOR 1-9 MAP
    // -----------CHUNK DATA GOES HERE ---------------------------
    float height_map[16][16];
    // -----------------------------------------------------------
    LL_Chunk_Node *parent = NULL;
};
// ------------------------------------------------------
class LL_World_Generator{
    public:
        LL_Chunk_Node *LL_Segments[9];        // THE LIST OF CHUNKS AND THEIR ORDER FOR SEGMENTS
        LL_Chunk_Node *LL_Auxiliar_P;         // AUXILIAR TO READ
        // -------------------------------------------------------
        LL_World_Generator();
        void LL_Chunk_Create(int p, int zx, int zy);           // function to start generating each chunk (here goes world generation)
        void LL_Chunk_Draw();                                  // function to move through the tree and start generating the terrain on renderer
        void LL_Chunk_Correction();                            // function to fix the broken chunks and avoid holes
        void LL_Chunk_Update();                                // function to generate new chunks as players moves
        // -------------------------------------------------------
};
// -------------------------------------------------------
// **********************************************
// * CHUNK MANAGER SETUP FUNCTION FOR FIRST GEN *
// **********************************************
LL_World_Generator::LL_World_Generator(){
 for(int i = 0; i < 9; i++){LL_Segments[i] = NULL;}
 // --------------------------------------------------------------
 int LL_Chunk_Pos_x[9] = {-1,0,1,-1,0,1,-1, 0, 1};            // LOCATIONS FOR THE FIRST 9 CHUNKS ON X
 int LL_Chunk_Pos_y[9] = { 1,1,1, 0,0,0,-1,-1,-1};            // LOCATIONS FOR THE NEXT  9 CHUNKS ON X
 for(int i = 0; i < 9; i++){                                  // LOOP ALONG ALL POSITIONS OF ARRAYS
  LL_Chunk_Create( i, LL_Chunk_Pos_x[i], LL_Chunk_Pos_y[i]);  // TO GENERATE THE FIRST POSITIONS
 }                                                            //
 // --------------------------------------------------------------
}
// ****************************************************
// * CHUNK GENERATION FUNCTION FOR CREATING NEW CHUNK *
// ****************************************************
// --------------------------------------------------------
void LL_World_Generator::LL_Chunk_Create(int p, int zx, int zy){
 LL_Sterm->LL_Termios_Log("Inserting new segment to chunks");
 LL_Chunk_Node *LL_New_Chunk = new LL_Chunk_Node();    // CREATE A NEW NODE INSIDE THE CHUNKS STRUCTURE
 LL_New_Chunk->LL_Zone_x = zx;                         // ASSIGN A X POSITION FOR THE CHUNK NODE ON BIG MAP
 LL_New_Chunk->LL_Zone_y = zy;                         // ASSIGN A Y POSITION FOR THE CHUNK NODE ON BIG MAP
 LL_Sterm->LL_Termios_Log("adding world data...");     // DEBUG MSG
 // --------------------------------------------------------------------------------------------------------
 for(int z = 0; z < 16; z++){
    for(int x = 0; x < 16; x++){
        height_map1 = 40+ValueNoise_2D((float)(std::abs(zx*15+x)), (float)(std::abs(zy*15+z)))*world_freq;
        LL_New_Chunk->height_map[x][z] = height_map1;
    }
 }
 // --------------------------------------------------------------------------------------------------------
 LL_New_Chunk->LL_C_State = p;                         // CHANGE THE POINTER TO THE CHUNK STATE
 if(LL_Segments[p] != NULL){                           // IF THE POINTER IS NOT EMPTY
  LL_Sterm->LL_Termios_Log("Memory cleaning....");     //
  LL_Chunk_Node *ll_tmp = new LL_Chunk_Node();         // CREATE A NEW TEMPORAL CHUNK
  LL_Auxiliar_P = LL_Segments[p];                      // ASSIGN THE ACTUAL CHUNK TO DELETE THE POINTER
  LL_Auxiliar_P->parent = ll_tmp;                      // SET THE PARENT FOR THE AUXILIAR POINTER TO THE TEMPORAL
  LL_Segments[p] = NULL;                               // MAKE THE POINTER TO LOOK AT NULL SO WE CAN STILL USE AUX
  delete ll_tmp;                                       // DELETE THE TEMPORAL POINTER TO CLEAN THE MEMORY
 }
 LL_New_Chunk->parent = NULL;                          // THE PARENT ALWAYS LOOKS TO NULL
 LL_Segments[p] = LL_New_Chunk;                        // PUSH THE CHUNK INTO THE CHUNK STRUCTURE
 LL_Sterm->LL_Termios_Log("Chunk pointer added");      // DEBUG MSG
}
// --------------------------------------------------------
// ==========================================================================
// = TODO: function to correct the holes in the chunk generator system      =
// ==========================================================================
void LL_World_Generator::LL_Chunk_Correction(){                                  // function to fix the positions of corrupted chunks
 // -----------------------------------------------------------------------------------------
 int locs_X[3] = {-1,0,1};                                                       // correct locations in x
 int locs_Y[3] = {1,0,-1};                                                       // correct locations in y
 for(int i = 0; i < 3; i++ ){                                                    // loop on x axis
 // -----------------------------------------------------------------------------------------
  LL_Auxiliar_P = LL_Segments[upr_sec_x[i]];                                                                   // upper sector fix
  if(LL_Auxiliar_P->LL_Zone_x != (LL_Loc_x + locs_X[i])||LL_Auxiliar_P->LL_Zone_y != (LL_Loc_y + locs_Y[0])){  // if it finds a missplaced chunk inside generation
   LL_Chunk_Create(upr_sec_x[i],(LL_Loc_x + locs_X[i]),(LL_Loc_y + locs_Y[0]));                                // create a new chunk on the pointer with correct location
  }// *******************************************************************************************************
  LL_Auxiliar_P = LL_Segments[mid_sec_x[i]];                                                                   // middle sector fix
  if(LL_Auxiliar_P->LL_Zone_x != (LL_Loc_x + locs_X[i])||LL_Auxiliar_P->LL_Zone_y != (LL_Loc_y + locs_Y[1])){  // if it finds a missplaced chunk inside generation
   LL_Chunk_Create(mid_sec_x[i],(LL_Loc_x + locs_X[i]),(LL_Loc_y + locs_Y[1]));                                // create a new chunk on the pointer with correct location
  }// *******************************************************************************************************
  LL_Auxiliar_P = LL_Segments[lwr_sec_x[i]];                                                                    // lower sector fix
  if(LL_Auxiliar_P->LL_Zone_x != (LL_Loc_x + locs_X[i])||LL_Auxiliar_P->LL_Zone_y != (LL_Loc_y + locs_Y[2])){   // if it finds a missplaced chunk inside generation
   LL_Chunk_Create(lwr_sec_x[i],(LL_Loc_x + locs_X[i]),(LL_Loc_y + locs_Y[2]));                                 // create a new chunk on the pointer with correct location
  }
 }
 // -----------------------------------------------------------------------------------------
}
// --------------------------------------------------------
// *********************************************
// * THIS IS THE FUNCTION TO UPDATE THE CHUNKS *
// *********************************************
int aux1,aux2; int auy1[3], auy2[3];               // AUXILIAR VARIALBES DECLARED HERE FOR FASTER MOVEMENT
void LL_World_Generator::LL_Chunk_Update(){        // FUNCTION TO GENERATE THE CHUNKS AS PLAYER MOVES ON UPDATES
 // ------------------------------------------------------------------------------------------------------------
 bool LL_Splitted = false; // LL_Splitted IS A BOOLEAN TO KNOW IF SPLITED
 // ------------------------------------------------------------------------------------------------------------
 if(player->player_x > (LL_Old_x+8)){          
  LL_Old_x += 15;                                     // update current player position on X of the greater scale
  LL_Loc_x++;                                         // update the location of chunk
  LL_Chunk_Create(upr_sec_x[0],LL_Loc_x+1,LL_Loc_y+1);   // create 3 new chunks on direction
  LL_Chunk_Create(mid_sec_x[0],LL_Loc_x+1,LL_Loc_y);     // these are represening their locations 
  LL_Chunk_Create(lwr_sec_x[0],LL_Loc_x+1,LL_Loc_y-1);   // by the use of locs of X and Y

  aux1 = upr_sec_x[2];aux2 = upr_sec_x[1];         // save one of the sectors into auxiliary variables
  upr_sec_x[2] = upr_sec_x[0];                     // move the current variables of x and switch locations 
  upr_sec_x[1] = aux1;                             // set middle current var
  upr_sec_x[0] = aux2;                             // set lower
                                                   // this process is repeated
  aux1 = mid_sec_x[2];aux2 = mid_sec_x[1];         // for each numer on array of sectors
  mid_sec_x[2] = mid_sec_x[0];                     // to assign next chunk location that will be drawn
  mid_sec_x[1] = aux1;                             // this array tells the pointers where to look at
  mid_sec_x[0] = aux2;                             // and how to organize them
  
  aux1 = lwr_sec_x[2];aux2 = lwr_sec_x[1];         // repeat the process of splitting the numbers on lower section of sectors
  lwr_sec_x[2] = lwr_sec_x[0];                     // the splitting it's done to keep the order of the loaded chunks
  lwr_sec_x[1] = aux1;                             // and help to understand which are the next pointers to be used on the generation
  lwr_sec_x[0] = aux2;                             // it's necessary to avoid location corruption
  LL_Splitted = true;                                 // just a variable with debug purposes
 }
 // ------------------------------------------------------------------------------------------------------------
 if(player->player_x < (LL_Old_x-8)){                   // repeat the same process for the negative X axis
  LL_Old_x -= 15;                                       // again move the position on the greater scale
  LL_Loc_x--;                                           // move the position on chunk greater scale
  LL_Chunk_Create(upr_sec_x[2],LL_Loc_x-1,LL_Loc_y+1);      // generate the new chunks inside the world
  LL_Chunk_Create(mid_sec_x[2],LL_Loc_x-1,LL_Loc_y);        // generate the new chunks inside the world
  LL_Chunk_Create(lwr_sec_x[2],LL_Loc_x-1,LL_Loc_y-1);      // generate the new chunks inside the world
  // *********************************************************
  aux1 = upr_sec_x[0];aux2 = upr_sec_x[1];         // save one of the sectors into auxiliary variables
  upr_sec_x[0] = upr_sec_x[2];                     // move the current variables of x and switch locations 
  upr_sec_x[1] = aux1;                             // set middle current var
  upr_sec_x[2] = aux2;                             // set lower
  
  aux1 = mid_sec_x[0];aux2 = mid_sec_x[1];         // the previous moving of the array of pointers is repeated
  mid_sec_x[0] = mid_sec_x[2];                     // in order to understand chich is the next pointer to be moved inside the world
  mid_sec_x[1] = aux1;                             // this array that is being moved is important 
  mid_sec_x[2] = aux2;                             // because it contains the pointers and their actual location
  
  aux1 = lwr_sec_x[0];aux2 = lwr_sec_x[1];         // which helps on the order to understand which are the next chunks being moved
  lwr_sec_x[0] = lwr_sec_x[2];                     // which order they follow
  lwr_sec_x[1] = aux1;                             // how are they organized
  lwr_sec_x[2] = aux2;                             // etc. thanks to this array being moved
  LL_Splitted = true;                                 // terrain is able to be generated on it's respective order
 }                                                 // LL_Splitted: is just a debug variable
 // ------------------------------------------------------------------------------------------------------------
 if(player->player_z > (LL_Old_y+8)){
  LL_Old_y += 15;                                                  // update the Y position on greater scale that tells when is a new chunk generated
  LL_Loc_y++;                                                      // update greater scale of chunk
  LL_Chunk_Create(lwr_sec_x[0],LL_Loc_x+1,LL_Loc_y+1);             // create upper chunk
  LL_Chunk_Create(lwr_sec_x[1],LL_Loc_x,  LL_Loc_y+1);             // create middle chunk
  LL_Chunk_Create(lwr_sec_x[2],LL_Loc_x-1,LL_Loc_y+1);             // create lower chunk
  // *******************************************************************************************
  auy1[0] = upr_sec_x[0]; auy1[1] = upr_sec_x[1]; auy1[2] = upr_sec_x[2];                // upper section saved on auxiliary 
  auy2[0] = mid_sec_x[0]; auy2[1] = mid_sec_x[1]; auy2[2] = mid_sec_x[2];                // middle section saved on auxiliary
  upr_sec_x[0] = lwr_sec_x[0]; upr_sec_x[1] = lwr_sec_x[1]; upr_sec_x[2] = lwr_sec_x[2]; // replace upper with lower sections
  mid_sec_x[0] = auy1[0]; mid_sec_x[1] = auy1[1]; mid_sec_x[2] = auy1[2];                // replace middle section with upper section
  lwr_sec_x[0] = auy2[0]; lwr_sec_x[1] = auy2[1]; lwr_sec_x[2] = auy2[2];                // replace lower section with middle section
  LL_Splitted = true;                                                                    // a debug variable
 }
 // ------------------------------------------------------------------------------------------------------------
 if(player->player_z < (LL_Old_y-8)){
  LL_Old_y -= 15;                                        // update the Y position on greater scale that tells when is a new chunk generated
  LL_Loc_y--;                                            // update greater scale of chunk
  // -----------------------------------------------------------------------------------------------------------------
  LL_Chunk_Create(upr_sec_x[0],LL_Loc_x+1,LL_Loc_y-1);                                           // create upper chunk
  LL_Chunk_Create(upr_sec_x[1],LL_Loc_x,  LL_Loc_y-1);                                           // create middle chunk
  LL_Chunk_Create(upr_sec_x[2],LL_Loc_x-1,LL_Loc_y-1);                                           // create lower chunk
  // ------------------------------------------------------------------------------------------------------------------
  auy1[0] = lwr_sec_x[0]; auy1[1] = lwr_sec_x[1]; auy1[2] = lwr_sec_x[2];                // upper section saved on auxiliary 
  auy2[0] = upr_sec_x[0]; auy2[1] = upr_sec_x[1]; auy2[2] = upr_sec_x[2];                // middle section saved on auxiliary
  upr_sec_x[0] = mid_sec_x[0]; upr_sec_x[1] = mid_sec_x[1]; upr_sec_x[2] = mid_sec_x[2]; // replace upper with lower sections
  mid_sec_x[0] = auy1[0]; mid_sec_x[1] = auy1[1]; mid_sec_x[2] = auy1[2];                // replace middle section with upper section
  lwr_sec_x[0] = auy2[0]; lwr_sec_x[1] = auy2[1]; lwr_sec_x[2] = auy2[2];                // replace lower section with middle section
  LL_Splitted = true;                                                                    // debug variable not used yet
 } 
 // ------------------------------------------------------------------------------------------------------------
 // *************************************
 if(LL_Splitted == true){LL_Splitted=false;} // FORMAT LL_Splitted IF TRUE
 // *************************************
 LL_Chunk_Correction();
}
// --------------------------------------------------------
// ==============================================================
// =  THIS IS THE CHUNK DRAWING FUNCTION TO GENERATE THE WORLD  =
// ==============================================================
// --------------------------------------------------------
void LL_World_Generator::LL_Chunk_Draw(){
	glDisable(GL_LIGHTING);
    for (int s = 0; s < 9; s++){        // for each chunk inside the structure
        LL_Auxiliar_P = LL_Segments[s]; // we fetch the segment that we need to draw
        glPushMatrix();
            for(int z = 0; z < 15; z++){
                for(int x = 0; x < 15; x++){
                    glPushMatrix();
                        glBindTexture(GL_TEXTURE_2D, LL_FLOOR_TEMPLATE);
                        glTranslatef(x+(LL_Auxiliar_P->LL_Zone_x*15),0,z+(LL_Auxiliar_P->LL_Zone_y*15));
                        LL_Prim_Floor(LL_Auxiliar_P->height_map, x, z);
                    glPopMatrix();
                }
            }
        glPopMatrix();
    }
	glEnable(GL_LIGHTING);
}
// --------------------------------------------------------
LL_World_Generator *LL_World = new LL_World_Generator();