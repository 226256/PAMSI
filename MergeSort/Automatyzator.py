#!/usr/bin/python3
#Autor: 226332
#Wersja 1.0 Beta
#Skrypt przyspieszający badania złożeniości obliczeniowej programów na PAMSI
#Potrzebne biblioteki : 
#tkinter: sudo apt-get install python3-tk
#matplotlib: pip3 install matplotlib 

#Skrypt uruchamia program za każdym badaniem aby ograniczyć wpływy 
#błędów w kodzie, np wycieków pamięci.
#Skrypt ten uruchamia program z parametrami i zbiera czas wykonania
#aby potem je przenieśc na wykres.

import matplotlib.pyplot as plt
import subprocess as sbp
import numpy as np
import sys
import csv

N=20 #ilość powtórzeń pętli
nazwa_programu="lab4.exe"
dane_wejsciowe=["100","1000","10000","100000"]
flagi=["r","m","l"]
flagi=["-s w -o p -O " + s for s in flagi]
os_x="Wielkość sortowanej tablicy"    #podpis na osi x
os_y="Czas działania programu[ms]"	#podpis na osi y
tytul="Sortowanie przez scalanie"
kolor="bgrcmykw" 		   	#kolory na wykresie
podpis=["Rosnąca","Malejąca","Losowa"] 
#FAIL
#podpis_wz=["O(n*logn)","O(n)"] 
#n=0.00004				#mnożnik do wzorców
#dane=[n*float(i) for i in np.arange(int(dane_wejsciowe[0]),int(dane_wejsciowe[-1]),10)]
#danes=[float(i) for i in np.arange(int(dane_wejsciowe[0]),int(dane_wejsciowe[-1]),10)]
#wzorce=[dane*np.log2(dane)+dane+dane+dane,   				#nlogn
	#np.log2(dane), 				#logn
	#[i*i+0.00067920 for i in dane],		#n^2
#	dane]						#n
if len(podpis)!=len(flagi):
	sys.exit("ROZMIAR TABLICY FLAG NIE JEST RÓWNY ROZMIAROWI TABLICY PODPISÓW!!! WYCHODZĘ")
	

print("Podaj jak mają się nazywać pliki w których zapisze wyniki...")
print("!!!UWAŻAJ BO CELOWO NADPISUJĘ!!!")
wykres1=input('Pierwszy plik-skala liniowa:\n')
wykres2=input('Drugi plik-skala logarytmiczna\n')
tabela=input('Trzeci plik-tabela z wynikami\n')
print("Skrypt może milczy, ale to dlatego, że tak długo działają odpalone programy")
print("Usiądź wygodnie i czekaj, bo jeszcze daleko do wyników :-)")


srednie_wyniki_flagi={}
#narazie nieużywane zmienne, wszystkie obliczenia są tu najgorszego przypadku.
najlepsze_wyniki_flagi={}
najgorsze_wyniki_flagi={}
for j in flagi:
	wyniki_srednie=[]
	wyniki_najgorsze=[]
	wyniki_najlepsze=[]
	for i in dane_wejsciowe:
		sredni=0
		najgorszy=0
		najlepszy=100000000			# dłużej i tak bym nie czekał XD
		for k in range(0,N):
			p=float(sbp.run(["./"+nazwa_programu+" "+"-r "+i+" "+j],
					shell=True,
					stdout=sbp.PIPE)
					.stdout)
			sredni+=p
			if(p>najgorszy):
				najgorszy=p
			elif(p<najlepszy):
				najlepszy=p
			
		wyniki_srednie.append((1000*sredni)/N)    #zamień na milisekundy
		wyniki_najgorsze.append(1000*najgorszy) 
		wyniki_najlepsze.append(1000*najlepszy)
	srednie_wyniki_flagi[j]=wyniki_srednie[:]
	najlepsze_wyniki_flagi[j]=wyniki_najgorsze[:]
	najgorsze_wyniki_flagi[j]=wyniki_najlepsze[:]


csvfile=open(tabela+'.csv', 'w')
fieldnames = ['Rozmiar', 'Czas[ms]','Flaga']
writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
writer.writeheader()
print("Oto średnie wyniki dla kolejnego wejścia(ms):")
for j in srednie_wyniki_flagi:
	print("Dla flagi: ",j)
	writer.writerow({'Flaga': j})
	h=0
	for i in srednie_wyniki_flagi[j] :
		print(dane_wejsciowe[h],format(i, '.8f'))
		writer.writerow({'Rozmiar': dane_wejsciowe[h], 'Czas[ms]': format(i, '.8f')})
		h+=1

plt.figure(1)

for l in range(0,len(podpis)):
	plt.plot(
	dane_wejsciowe,
	srednie_wyniki_flagi[flagi[l]],
	kolor[l]+'o-',
	label=podpis[l])

#for l in range(0,len(wzorce)):
#	plt.plot(
#	danes,
#	wzorce[l], 
#	kolor[l]+'--',
#	label=podpis_wz[l])

figure = plt.gcf() #powiększam figure
figure.set_size_inches(6, 4)

plt.legend(bbox_to_anchor=(1, 1),loc=2, borderaxespad=0.)
plt.title(tytul+"-Skala Liniowa")
plt.ylabel(os_y)
plt.xlabel(os_x)
plt.grid(True)

plt.savefig(wykres1,bbox_inches='tight',papertype='a1',dpi=255)

plt.figure(2)
for l in range(0,len(flagi)):
	plt.loglog(
	dane_wejsciowe,
	srednie_wyniki_flagi[flagi[l]],
	kolor[l]+'o-',
	label=podpis[l])

#for l in range(0,len(wzorce)):
#	plt.loglog(
#	danes,
#	wzorce[l], 
#	kolor[l]+'--',
#	label=podpis_wz[l])

figure = plt.gcf() #powiększam figure
figure.set_size_inches(6, 4)

plt.legend(bbox_to_anchor=(1, 1),loc=2, borderaxespad=0.)
plt.title(tytul+"-Skala logarytmiczna")
plt.ylabel(os_y)
plt.xlabel(os_x)	
plt.grid(True)


plt.savefig(wykres2,bbox_inches='tight',papertype='a1',dpi=255)

print("Gotowe, teraz obczaj wyniki co ci wyplotowałem")

plt.show()





