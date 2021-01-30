from pyautogui import typewrite as tw
from pyautogui import press as p
import time as t


def s(c, w, r=1):
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
    return 'Spamming complete.'


def main():
    print('''
    Spammer v1.0.1 Python by AJ; 1/29/2021\n
    NOTE: *The author* is not responsible for any actions preformed using this script.\n
    Modes:\n
    s: prints every line from text file with enters in between\n
    b: concatenates all lines in text file into one big line and press enter\n
    m: manual; you enter what you want spammed and how many times you need it spammed
    ''')
    m = input('mode: ').lower()
    try:
        w = float(input('Time between enter-presses (in seconds): '))
    except ValueError:
        print('Invalid type for time. Defaulting to 0.75s. ')
        w = 0.75
    if m == 's' or m == 'b':
        n = input('What filename (to spam with)? ')
        if m == 's':
            print(s(open(n, 'r+').readlines(), w))
        else:
            print(s(open(n, 'r+').readlines(), w))
    elif m == 'm':
        cont = input('What to spam? ')
        t = int(input('Spam "{cont}" how many times?'))
        print(s(cont, t))
    else:
        print('Unrecognized command. (Check that you only entered one letter (the name of the mode)?), exiting...')


if __name__ == '__main__':
    main()
