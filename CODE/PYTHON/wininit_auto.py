import subprocess
from time import sleep
from pynput.keyboard import Controller, Key
import keyboard
import os
sleep(2)

keyboard = Controller()

os.system("start powershell.exe")

sleep(0.75)
for char in "cd ..":
    keyboard.press(char)
    keyboard.release(char)
keyboard.press(Key.enter)
keyboard.release(Key.enter)

for char in "belandi sei stato besugato":
    keyboard.press(char)
    keyboard.release(char)
keyboard.press(Key.enter)
keyboard.release(Key.enter)

for char in "wininit":
    keyboard.press(char)
    keyboard.release(char)
keyboard.press(Key.enter)
keyboard.release(Key.enter)