import time
import serial

start_time = time.time()

arduino = serial.Serial('COM5',115200)
file_object = open('salida.txt', 'w')

# while 1:
#     rawString = arduino.read()
#     file_object.write(rawString)
#     if rawString[0] =='X':
#         break

out1 = ''
while 1:
    out = arduino.read(1)
    out1 += out
    if out == 'X':
        break

file_object.write(out1)
file_object.close()
arduino.close()


elapsed_time = time.time() - start_time

print 'Elapsed time %.3f' % (elapsed_time/60.0)
