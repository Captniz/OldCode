# This is a simple demonstration on how to stream
# audio from microphone and then extract the pitch
# and volume directly with help of PyAudio and Aubio
# Python libraries. The PyAudio is used to interface
# the computer microphone. While the Aubio is used as
# a pitch detection object. There is also NumPy
# as well to convert format between PyAudio into
# the Aubio.
import aubio
import numpy as num
import pyaudio
import sys
from pynput.keyboard import Controller, Key
import keyboard
from termcolor import colored 
import pyautogui
import pydirectinput

# Some constants for setting the PyAudio and the
# Aubio.
BUFFER_SIZE             = 2048
CHANNELS                = 1
FORMAT                  = pyaudio.paFloat32
METHOD                  = "default"
SAMPLE_RATE             = 44100
HOP_SIZE                = BUFFER_SIZE//2
PERIOD_SIZE_IN_FRAME    = HOP_SIZE

def main(args):

    Keyboard= Controller()
    i=0
    SumPitch=0
    media=0

    # Initiating PyAudio object.
    pA = pyaudio.PyAudio()
    # Open the microphone stream.
    mic = pA.open(format=FORMAT, channels=CHANNELS,
        rate=SAMPLE_RATE, input=True,
        frames_per_buffer=PERIOD_SIZE_IN_FRAME)

    # Initiating Aubio's pitch detection object.
    pDetection = aubio.pitch(METHOD, BUFFER_SIZE,
        HOP_SIZE, SAMPLE_RATE)
    # Set unit.
    pDetection.set_unit("Hz")
    # Frequency under -40 dB will considered
    # as a silence.
    pDetection.set_silence(-40)

    # Infinite loop!
    while True:

        # Always listening to the microphone.
        data = mic.read(PERIOD_SIZE_IN_FRAME)
        # Convert into number that Aubio understand.
        samples = num.fromstring(data,
            dtype=aubio.float_type)
        # Finally get the pitch.
        pitch = pDetection(samples)[0]
        # Compute the energy (volume)
        # of the current frame.
        volume = num.sum(samples**2)/len(samples)
        # Format the volume output so it only
        # displays at most six numbers behind 0.
        volume = "{:6f}".format(volume)

        # Finally print the pitch and the volume.
        print(colored(str(pitch),"red")+ " " + colored(str(volume), "green"))
        


        # Finding out the values of pitch with my vocals
        #SumPitch += pitch
        #i+=1
        #if keyboard.is_pressed('q'):
        #    break
    #media=SumPitch/i
    #print(colored(media,"red"))



        #TODO: MOVEMENT
        # If floats surpass a determined amount print letter
        if float(pitch)<220 and float(pitch)>180:
            #pydirectinput.keyDown('a')
            #pydirectinput.keyUp('a')
            pydirectinput.keyDown('w')
            pydirectinput.keyUp('w')
        
        #TODO: INTERACTION
        # If floats surpass a determined amount print letter
        if float(pitch)<280 and float(pitch)>220:
            pydirectinput.keyDown('e')
            pydirectinput.keyUp('e')

        # If floats surpass a determined amount print letter
        if float(pitch)<320 and float(pitch)>300:
            pydirectinput.keyDown('i')
            pydirectinput.keyUp('i')

        #TODO: MOVEMENT CAMERA
        # If floats surpass a determined amount print letter
        if float(pitch)<180 and float(pitch)>160:
            #pydirectinput.keyDown('u')
            #pydirectinput.keyUp('u')
            pyautogui.dragRel(-30,0)

        # If floats surpass a determined amount print letter
        if float(pitch)<150 and float(pitch)>110:
            #pydirectinput.keyDown('o')
            #pydirectinput.keyUp('o')
            pyautogui.dragRel(30,0)

if __name__ == "__main__": main(sys.argv)