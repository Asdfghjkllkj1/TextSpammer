from pyautogui import typewrite as tw
from pyautogui import press as p
import time as t


def s(c, r=1):
    print('Run.')
    t.sleep(5)
    if isinstance(c, list):
        for _ in c:
            tw(_)
            p('enter')
            t.sleep(w)
    else:
        for i in range(r):
            tw(c)
            p('enter')
    return 'Done spamming'


print('''
Spammer v1.0.0 by AJ; 1/20/2021
NOTE: *The author* is not responsible for any actions preformed using this script.
Modes:
s: prints every line from text file with enters in between
b: concatenates all lines in text file into one big line and press enter
m: manual; you enter what you want spammed and how many times you need it spammed
''')
n = input('text file name: ')
m = input('mode: ').lower()
try:
    w = float(input('Time between enter-presses (in seconds): '))
except ValueError:
    print('Invalid type for time. Defaulting to 0.75s. ')
    w = 0.75
if m == 's':
    print(s(open(n, 'r+').readlines()))
elif m == 'b':
    print(s(str(open(n, 'r+').readlines())))
elif m == 'm':
    cont = input('content: ')
    t = int(input('number of times: '))
    print(s(cont, t))
else:
    print('unrecognized command; exiting')
