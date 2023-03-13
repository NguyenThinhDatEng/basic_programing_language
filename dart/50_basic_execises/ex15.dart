import 'dart:io';

void main(List<String> args) {
  int n = int.parse(stdin.readLineSync()!);
  int m = int.parse(stdin.readLineSync()!);
  print(greatestCommonDivisor(m, n));
  print(smallestCommonMultiple(m, n, greatestCommonDivisor));
}

int greatestCommonDivisor(int a, int b) {
  while (a * b > 0) {
    a > b ? a = a % b : b = b % a;
  }
  return a + b; // a == 0 ? b : a;
}

int smallestCommonMultiple(int a, int b, int Function(int m, int n) func) {
  return a * b ~/ func(a, b);
}
