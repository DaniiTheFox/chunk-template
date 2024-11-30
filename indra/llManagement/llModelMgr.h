// ************************************************
// * MODEL MANAGEMENT AND LOADER FOR GAME OBJECTS *
// ************************************************
// ---------------------------------------------------------------
struct Model {                  // THIS STRUCTURE WILL STORE ALL INGAME MODELS
  double model_vtx[9][20000];    // SO WHENEVER WE NEED MULTIPLE
  double model_uvs[6][20000];    // OBJECTS WITH THE SAME MODEL
  double model_nms[9][20000];    // ---------------------------------------
  int vertex_numer = 0;         // THEY CAN BE LOADED FAST WITHOUT THE NEED
  GLuint _texturel;             // OF LOADING IT FROM DISK, AND HAVE EVERYTHING IN MEMORY
};                              //
// ---------------------------------------------------------------
class LL_Model_Manager {
    public:
        int _model_ptr = 0;
        Model *_Models[10000];
        Model *m_aux = NULL;
        LL_Model_Manager();                                                                            // THIS WILL LOAD ALL THE OBJECTS WHEN THE GAME WINDOW STARTS
        void LL_Model_Push_ls(std::string _mdl_filename, std::string _tex_filename, int _tx, int _ty); // THIS WILL LOAD A MODEL INTO MEMORY (NOT SPECIFY THE POSITION)
        // IT IS DONE LIKE THIS SO WE CAN CREATE MULTIPLE COPIES OF THE OBJECTS WITH THE SAME MODEL AVOIDING
        // BLOATING THE MEMORY WITH A LOT OF THE SAME MODELS, BASICALLY LOAD IT AS IF IT WAS AN IMAGE THAT WE CAN COPY
        void LL_Model_Draw(int _Model_identifier); // THIS DRAWS THE MODEL BASED ON THE ID
};
// ----------------------------------------------------------------
LL_Model_Manager::LL_Model_Manager(){}                                                                                           
// ----------------------------------------------------------------
void LL_Model_Manager::LL_Model_Push_ls(std::string _mdl_filename, std::string _tex_filename, int _tx, int _ty){
  Model *_model = new Model();
  // --------------------------------------------------------------
  char *lnk = new char[strlen(_mdl_filename.c_str())+1];    // create a tiny temporal pointer with the directory 
  strcpy(lnk, _mdl_filename.c_str());                       // transform into other var type 
  
  _model->vertex_numer = ll_Obj_Load_Model(
                                           lnk, 
    /* THIS PART ACTUALLY LOADS THE MODEL*/_model->model_vtx, 
    /*AND STORES THE RESULT ON THE STRUCT*/_model->model_uvs, 
    /* IMPLEMENTED NORMAL LOADING FOR LT*/ _model->model_nms,
   /*SO WE CAN USE IT LATER WITH AN INDEX*/_model->vertex_numer
                                          );
  delete lnk;
  // --------------------------------------------------------------
  char *lnk2 = new char[strlen(_tex_filename.c_str())+1];    // create a tiny temporal pointer with the directory 
  strcpy(lnk2, _tex_filename.c_str());                       // transform into other var type 
  _model->_texturel = LL_Bmp_Load_Image(lnk2, _tx, _ty);
  delete lnk2;
  _Models[_model_ptr] = _model;
  _model_ptr++;
}
// ----------------------------------------------------------------
void LL_Model_Manager::LL_Model_Draw(int _Model_identifier){
    m_aux = _Models[_Model_identifier];
    glBindTexture(GL_TEXTURE_2D, m_aux->_texturel);
    ll_Obj_Draw_Model(m_aux->model_vtx, m_aux->model_uvs, m_aux->model_nms,m_aux->vertex_numer, m_aux->_texturel);
    // THIS WILL DRAW A MODEL BASED ON AN INDEX
}
// -----------------------------------------------------------------
LL_Model_Manager *LL_Models = new LL_Model_Manager();