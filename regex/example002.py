import re

# Note: This is just an example, and should not be used for real world problems.
# A better one (but more complex) can be found at "RegEx for RFC 2822 compliant email address.":
# https://gist.github.com/gregseth/5582254
#
# mail_regex = '''[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?'''
#

print(re.findall('[-_a-zA-Z0-9]+@[-_a-zA-Z0-9]+(?:\.com\.br|\.com)',
'''
Marcos - marcos1990@gmail.com
Pedro ----> pedro@hotmail.com.br
Emanuel      eman-12@hotmail.com
'''))
