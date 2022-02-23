class Dictionary:
    key = ''
    value = ''
    def __init__(self, key, value):
        self.key = key
        self.value = value
    # getter
    @property
    def item(self):
        return '{}: {}'.format(self.key, self.value)
    # setter
    @item.setter
    def item(self, newItem):
        key, value = newItem.split(': ')
        self.key = key
        self.value = value

    @item.deleter
    def item (self):
        self.key = None
        self.value = None

nameDict = Dictionary('name', 'Nguyen Van Thinh')
ageDict = Dictionary('age', 20)

print(nameDict.item)
print(ageDict.item)

nameDict.item = 'name: The Will'
print(nameDict.value)

del ageDict.item
print(ageDict.name, ageDict.item)