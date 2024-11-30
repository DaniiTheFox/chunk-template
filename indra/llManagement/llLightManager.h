// *******************************
// * THIS IS THE LIGHTING ENGINE *
// *******************************
// --------------------------------------------------------
class LL_Lights {
	public:
		LL_Lights(int);      // << THIS SETUPS THE LIGHTING ENGINE AND ENVIRONMENT
		void LL_Management();// << THIS STARTS THE AMBIENT LIGHTING
};
// ---------------------------------------------------------
LL_Lights::LL_Lights(int _null){} // THE CONSTRUCTOR DOES NOTHING
// ---------------------------------------------------------
void LL_Lights::LL_Management() {
  //-------------------------------
  	GLfloat light_ambient[] =	//
  	{0.7, 0.7, 0.7, 1.0};		// IN THIS SEGMENT OF CODE
  	GLfloat light_diffuse[] =	// WE DEFINE THE BASE LIGHTING
  	{1.0, 1.0, 1.0, 1.0};		// FOR OUR RENDERING ENGINE
  	GLfloat light_specular[] =	// WE DEFINE THE BASE SPECULAR
  	{1.0, 1.0, 1.0, 1.0};		// POSITION, DIFFUSE AND AMBIENT
  	GLfloat light_position[] =	// MOSTLY THE BASICS FOR MATERIALS
  	{1.0, 1.0, 1.0, 0.0};		//
  // ------------------------------
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  // ------------------------------
}

// ---------------------------------------
LL_Lights *LL_Latern = new LL_Lights(0);// We create the base object