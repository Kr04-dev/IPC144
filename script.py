import pyautogui as gui
import time

print('Note: You have 5 sec to do this thing')
time.sleep(5)

with open('input.txt', 'r') as tst:
    time.sleep(1)
    tst = tst.readlines()
    for i in range(0, len(tst), 1):
        print(tst[i])
        gui.typewrite(tst[i])

print('Auto data input completed.')