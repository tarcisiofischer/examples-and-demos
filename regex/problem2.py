import re
from pprint import pprint

name_regex = '[a-zA-Z\s]*'
value_regex = '[+-]?\d*\,?\d+\.?\d*e?[+-]?\d*'
unit_regex = '(?:m/s2|m/s|kg/m3|g/cm3|m3)'
full_regex = '^(%s)\s*(%s)\s*(%s)' % (name_regex, value_regex, unit_regex)
with open('problem2.txt', 'r') as f:
    pprint(re.findall(full_regex, f.read(), re.MULTILINE))
