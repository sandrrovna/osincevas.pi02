//Создание списка на C++
#include <iostream>
#include <string>

int main() {
  std::string lst[] = {'Пушкин', 'Есенин', 'Толстой'};
  int size = 3;

  for(int i=0; i < size; i++) {
      std::cout << lst[i] << std::endl;
  }
  return 0;
}

//Создание стека на C++
stack <string> stack;
stack.push('Пушкин');
stack.push('Есенин');
stack.push('Толстой');
