# Task-Manager
This project was created to practice the principles of object-oriented programming and writing code in C++ during the summer of 2023.

## How to start

To build the project and documentation, use command

make

To run the project use the command

make run

To clean the project repository, run the command

make clean

## About the project
Implementace kalendáře se řídí příkazy v konzolové aplikaci. Kalendář vypisuje příkazy, které jsou
k dispozici v danou chvíli. Umožňuje importování, exportování, ukládání a odstranění událostí. Kalendář 
může zobrazovat přehled událostí denně, týdně a měsíčně pro zvolený datum, pro současný datum je taky
možnost vypisu údalostí pro příští hodinu.
	Po spuštění kalendáře se pokusí načíst uložené události z souboru "save_events.txt". Pokud se mu 
to povede, události budou načtené. Jinak se objeví chybová hláška a události nebudou načtené.
	Manuální přidávání nových událostí je možné v sekci "Add new event". Program nabídne možné druhy 
přidávaných událostí: "Meeting", "Birthday", "Party", "Task" a "Reminder". Dále uživatel může zadat 
parametry zvolené události, které se liší v závislosti na druhu události. Program kontroluje správnost 
zadaných parametrů a v případě nesprávných vstupů ukončí přidávání nové události a vrátí se do "main menu". 
Atributy typu "members" a "tags" se ukládají bez opakování, ale jsou "case sensitive".
	Kalendář umožňuje ke každé konkrétní události (kromě "Reminder") definovat, zda je opakující se, 
a také frekvenci a počet opakování opakování ve dnech.
	Ke každé události (kromě "Reminder") je možné definovat přípustný počet kolizí, a to včetně 
opakujících se událostí. Pokud by nově přidávaná událost po přidání přesáhla přípustný počet kolizí nějaké 
existující události, nebo vlastní, nebude přidána a vypíše se hláška, upozorňující na to.
	Smazání události probíhá na základě druhu, data a času události. Existuje také možnost smazání všech 
událostí.
	Vyhledávání událostí je možné na základě jednotlivých atributů pomocí spojek "AND" a "OR". Uživatel 
nejprve vybere spojku a pak jednotlivé atributy pro vyhledávání. Po ukončení vyhledávání budou všechny 
nalezené události vytisknuty na obrazovku a bude nabídnuto uložení nenalezených událostí do souboru. Pokud 
nebudou nalezeny žádné události, program se vrátí do "main menu". Pro exportování událostí je možné zvolit 
název souboru, do kterého budou události exportovány.
	Pro importování událostí je taky možné zvolit název souboru, ze kterého budou události importovány. 
Po ukončení programu budou všechny uložené události zapsány do souboru "save_events.txt".

Využití dědičnosti a polymorfismu:
	Dědičnost a polymorfismus jsou použity při implementaci třídy "Events" a jejích potomků: "Activity" 
(a jejích potomků "Party", "Meeting", "ActivityToPickWith") a "Reminder". Třída "Events" je abstraktní 
třídou, obsahuje virtuální metodu pro výpis třídy na obrazovku a virtuální metodu pro zápis třídy do souborů.
	Každá konkrétní (neabstraktní) třída přepisuje tyto metody různě. Tím je zajištěna možnost ukládání 
různých objektů, které jsou odvozené od stejného rodiče, do společného kontejneru a volání vhodné metody 
potomků pro výpis a ukládání při čtení objektů z kontejneru.
	Dědičnost a polymorfismus jsou také využity při implementaci tříd "ShowEvents", které se používají 
pro zobrazení událostí v nějakém intervalu. Objekty těchto tříd jsou uloženy do jedné mapy a pro vhodný výpis 
se vyhledává vhodný objekt a používá se příslušně přepsaná metoda "show..".

## Requirements
To compile the project, you will need the g++ compiler

sudo apt-get install g++

For creating documentation, install Doxygen

sudo apt install doxygen
