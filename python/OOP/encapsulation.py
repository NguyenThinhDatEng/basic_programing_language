'''
Purpose:
    Hide information and internal processing of object
Meaning:
    security object, ensure data integrity /ɪnˈteɡrəti/
'''

class Computer:
    def __init__(self) -> None:
        # private attribute
        self.RAM = 8
        self.ROM = 512
        self.trademark = 'DELL'
    # regular method
    def getRAM(self):
        return self.RAM

c1 = Computer()
# print(c1.RAM) => ERROR
print(c1.getRAM())