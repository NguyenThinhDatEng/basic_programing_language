import 'dart:io';

void main(List<String> args) {
  double a = double.parse(stdin.readLineSync()!);
  double b = double.parse(stdin.readLineSync()!);
  double c = double.parse(stdin.readLineSync()!);
  print(max(a, b, c));
  print(isSameSign(a, b));
}

num max(num a, num b, num c) {
  if (a > b) b = a;
  if (c > b) return c;
  return b;
}

bool isSameSign(num a, num b) {
  return a * b > 0;
}
