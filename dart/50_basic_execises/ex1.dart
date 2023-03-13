import 'dart:io';

void main(List<String> args) {
  var fullName = stdin.readLineSync();
  print(
      '${remainingYearTo100(fullName)} years from now $fullName will be 100 years old');
  // -------
  int n = int.parse(stdin.readLineSync()!);
  print(isEven(n));
}

num remainingYearTo100(String? fullname) {
  int age = int.parse(stdin.readLineSync()!);
  return 100 - age;
}

bool isEven(int n) {
  return n.isEven;
}
