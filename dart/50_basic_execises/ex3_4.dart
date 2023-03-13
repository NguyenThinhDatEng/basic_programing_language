import 'dart:io';

void main(List<String> args) {
  int i = 1;
  while (i < 100) {
    !i.isEven && isValid(i) ? print(i) : print('');
    i++;
  }
}

bool isValid(int i) {
  return i != 5 && i != 7 && i != 93;
}
