import serial
import time
import pyttsx3
import speech_recognition as sr

serial = serial.Serial('COM4', 9600)
time.sleep(1)


valor = []
for i in range(10):
    line = serial.readline()   # lee una cadena de bytes
    if line:
        string = line.decode()  #convierte el byte a una cadena unicode 
        pot = int(string) # convierte el valor unicode a entero
        print(pot)
        valor.append(pot) #agregamos un elemento al final de la lista valor (valor que lea en pot)
serial.close()


engine = pyttsx3.init()
voices=engine.getProperty('voices')
engine.setProperty('voice',voices[3].id,)
engine.setProperty('rate',150)

r=sr.Recognizer()

with sr.Microphone() as source:
    print("Ingresa un mensaje:")
    audio = r.listen(source)

try:
    entrada=r.recognize_google(audio)
except sr.UnknownValueError:
    print("No se pudo reconocer")
except sr.RequestError as e:
    print("No se pudo conectar al servicio; {0}".format(e))

if 'hola' in entrada:
    engine.say('Hola, ¿en qué puedo ayudarte?')

elif 'color' in entrada:
    if (pot < 100):
        engine.say('Ningún led está encendido.')

    if (pot>=100 and pot < 145):
        engine.say('Azul')

    if (pot>=145 and pot < 290):
        engine.say('Rojo.')

    if (pot>=290 and pot < 435):
        engine.say('Amarillo.')

    if (pot>=435 and pot < 580):
        engine.say('Rojo y azul.')

    if (pot>=580 and pot < 725):
        engine.say('Rojo y amarillo.')
    
    if (pot>=725 and pot<870):    
        engine.say('Azul y amarillo.')
    
    if (pot>=870 and pot<1020):
        engine.say('Rojo, azul y amarillo.')


elif 'hasta luego' in entrada:
    engine.say('Hasta la próxima')

else:
    engine.say('No entendí. Repite, por favor')
engine.runAndWait()
engine.stop()





