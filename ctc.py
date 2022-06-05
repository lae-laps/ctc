# ctc.py

import os
import sys

try:
    import pyperclip
except ModuleNotFoundError:
    print("[#] => Missing dependency \"pyperclip\" => Installing now\n")
    os.system("pip3 install pyperclip")
    print("\n[#] => All done. Please run again")
    exit()

def get_stdin():
    if not os.isatty(0):
        stdin = sys.stdin.read().rstrip()
        return stdin
    else:
        return False
    
def get_args():
    return ' '.join(sys.argv[1:])

if __name__ == "__main__":
    content = get_stdin()
    if not content:
        content = get_args()
        try:
            with open(content, "r") as file:
                content = file.read().rstrip()
                file.close()
                pyperclip.copy(content)
                exit()
        except OSError: 
            pyperclip.copy(content)
            exit()
    pyperclip.copy(content)
    exit()

