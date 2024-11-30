// ********************************
// *  TERMINAL EMULATOR FOR GAME  *
// ********************************
// ---------------------------------------------------------------
class LL_Termios {
    public:             // --------------------
        std::tm *now = NULL;   // TO AVOID NEW POINTERS TRASH
        int _msg_ptr = 0;      // MESSAGE PTR FOR THE ARRAY
        std::string _msgd[200];// ARRAY FOR MESSAGES
        LL_Termios();          // THIS IS THE TERMINAL SETUP START MODE
        void LL_Termios_Log(std::string _print); // PRINT A TERMINAL MESSAGE
        void LL_Termios_Exec(std::string _cmd_); // EXECUTE A COMMAND
        void LL_Termios_Show();
        // ----------------------------------------------------------
};
// -----------------------------------------------------------------
LL_Termios::LL_Termios(){};
// -----------------------------------------------------------------
void LL_Termios::LL_Termios_Log(std::string _print){
    std::time_t t = std::time(0);   // get time now
    now = std::localtime(&t);
    std::cout<<"\033[1;31m{"<<now->tm_mday<<"-"<<now->tm_mon<<"-"<<(now->tm_year+1900)<<"} \033[1;33m<Prism Engine>> \033[1;35m"<<_print<<std::endl;
    std::string _ms = "{*} <Prism Engine>> "+_print;
    _msgd[_msg_ptr] = _ms;
    _msg_ptr++;
    if(_msg_ptr >= 16){
        _msg_ptr = 0;
        for(int i = 0; i <= 16; i++){
            _msgd[i] = "";
        }
    }
    //delete now;
}
// ------------------------------------------------------------------
void LL_Termios::LL_Termios_Show(){
    for(int i = 0; i <= 16; i++){
            ImGui::Text(_msgd[i].c_str());
    }
}
// ------------------------------------------------------------------
LL_Termios *LL_Sterm = new LL_Termios();