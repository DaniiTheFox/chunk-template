void LL_Imgui_interface(){
      ImGui::SetNextWindowPos(ImVec2(0,0));
      ImGui::SetNextWindowSize(ImVec2(BON_SCREEN_W,128));
      ImGui::SetupImGuiStyle(true,0.9);
      ImGui::Begin(".: Debug Terminal:.");
     // ImGui::SetupImGuiStyle(true,0.5);
       ImGui::TextColored(ImVec4(1,1,0,1), "Console output:");
       ImGui::BeginChild("Scrolling");
        LL_Sterm->LL_Termios_Show();
        //ImGui::SetScrollHereY(0.0f);
       ImGui::EndChild();
      ImGui::End();  
}