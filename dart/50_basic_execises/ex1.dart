import 'dart:io';

void main(List<String> args) {
  var fullName = stdin.readLineSync();
  print(
      '${remainingYearTo100(fullName)} years from now $fullName will be 100 years old');
}

num remainingYearTo100(String? fullname) {
  dynamic age = stdin.readLineSync() ?? 0;
  age = int.parse(age);
  return 100 - age;
}
