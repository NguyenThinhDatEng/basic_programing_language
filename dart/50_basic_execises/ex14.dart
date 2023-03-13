import 'dart:io';

void main(List<String> args) {
  int n = int.parse(stdin.readLineSync()!);
  print(factorial(n));
}

int factorial(int n) {
  if (n <= 1) return 1;
  return n * factorial(n - 1);
}
