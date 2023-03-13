import 'dart:io';

void main(List<String> args) {
  int n = int.parse(stdin.readLineSync()!);
  print('$n is an ${n.isEven ? 'even' : 'old'} number');
}
