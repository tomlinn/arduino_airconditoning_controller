import bluetooth
import time
import sys
import urllib2
from datetime import datetime

def is_ascii(s):
	return all(ord(c)<128 for c in s)

bd_addr = "98:D3:32:20:A8:61"  # here need to modify. use hciconfig to get address
port = 1

sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
sock.connect((bd_addr, port))
print ('Connected')
#sock.settimeout(1.0)	
temp=''
print ('1. On/Off')
print ('2. Swing On/Off')
print ('3. Temperature(24~29)')
print ('4. Fan( Speed(1,2,3,4,5) 5=auto,6=moon )')
print ('5. Mode( 0=FAN, 1=COOL, 2=DRY, 3=HEAT )')
print ('6. Show State')
print ('')
while 1:
	tosend = raw_input()
	if tosend != 'q':
		
		sock.send(tosend)
	else:
		print('break');
		break
	#################################
	
	while(1):
		data = sock.recv(1)
		if is_ascii(data):
			temp=temp+data
			#print (data)
		else: 
			print ('not a ascii')
		if data=='.':
			print(temp)
			temp=''	
			break
	
	


