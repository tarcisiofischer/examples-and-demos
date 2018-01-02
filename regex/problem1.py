import unittest

# find
# self.assertEqual\((.*?(?:\(.*\))*), (.*?(?:\(.*\))*)\)$
#
# replace with
# assert $1 == $2

def multiply(a, b):
    return a * b
 
class TestUM(unittest.TestCase):
 
    def test_numbers(self):
        assert multiply(3, 4) == 12
        assert multiply('a', 3) == 'aaa'
        assert multiply('a', 3) == multiply(3, 'a')
