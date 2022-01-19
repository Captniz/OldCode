import cv2
import numpy

print("Inizio")

#Trova le IA gia allenate per occhi
trained_right_eye= cv2.CascadeClassifier('C:\Dati_riconoscimento_facciale\haarcascade_righteye_2splits.xml')
trained_left_eye= cv2.CascadeClassifier('C:\Dati_riconoscimento_facciale\haarcascade_lefteye_2splits.xml')
trained_face= cv2.CascadeClassifier('C:\Dati_riconoscimento_facciale\haarcascade_frontalface_default.xml')
trained_eye= cv2.CascadeClassifier('C:\Dati_riconoscimento_facciale\haarcascade_eye.xml')

#Trova la foto che vogliamo aprire
#img = cv2.imread('C:\Dati_riconoscimento_facciale\CasariFerro.PNG')


#Trova la webcam default
webcam= cv2.VideoCapture(0)


while True:
    ret, frame = webcam.read()


    #Converti a grayscale
    grayscaled_img=cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)


    #Trova faccia           #TODO:
    Face_coord= trained_face.detectMultiScale(frame)

    
    #Trova occhi            #TODO:
    Eye_coord= trained_eye.detectMultiScale(frame)


    #Trova occhio destro
    #Reye_coord= trained_right_eye.detectMultiScale(grayscaled_img)


    #Trova occhio sinistro
    #Leye_coord= trained_left_eye.detectMultiScale(grayscaled_img)


    #Disegna rettangolo faccia
    for (x,y,w,h) in Face_coord:    
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0,255,0), 2)
    

    #Disegna rettangolo occhi
    for (x,y,w,h) in Eye_coord:    
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0,0,255), 2)


    #Disegna rettangolo occhio destro
    #or (x,y,w,h) in Reye_coord:    
    #    cv2.rectangle(frame, (x, y), (x+w, y+h), (255,0,0), 2)


    #Disegna rettangolo occhio sinistro
    #for (x,y,w,h) in Leye_coord:    
    #    cv2.rectangle(frame, (x, y), (x+w, y+h), (0,0,255), 2)


    #Apre la foto 
    cv2.imshow("CasariTrovato", frame)


    #Aspetta una fine
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break


print("fine")


webcam.release()