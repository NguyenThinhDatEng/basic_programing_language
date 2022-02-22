import unittest

def isUnique(s):
    keyByChar = {}
    for c in s:
        if c in keyByChar:
            return False
        keyByChar[c] = True
    return True

class Test(unittest.TestCase):  # inheritance
    dataT = ['VOA', 'English', 'Nodemy', 'jTp,uo8Ml-']
    dataF = ['Learning', 'Pronounce', 'Everyday', 'Grammar', 'Self-Learning', 'CbPesiog6sQ_+qfv"G']

    def test_isUnque(self):
        # true check
        for testCase in self.dataT:
            result = isUnique(testCase)
            self.assertTrue(result)
        # false check
        for testCase in self.dataF:
            result = isUnique(testCase)
            self.assertFalse(result)
if __name__ == '__main__':
    unittest.main()
    # print(isUnique('Learning'))