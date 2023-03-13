void main(List<String> args) {
  int i = 14;
  List result = [];
  while (i < 200) {
    if (i % 7 == 0 && i % 5 != 0) {
      result.add(i);
    }
    i += 7;
  }
  print(result.join(', '));
}
