###4.May 2020

Should be an european project!

 TODO 
1. It need to add a interface and protocol for an engine like UCI will call 
UniversalChineseChessInterface (UCCI).
The clue should be, that the hole move evaluation (is the move valid or not) 
would be outsourced to the engine, because an engine developer do it already. So only 
one move evaluation exists. Not one in the GUI and one in the engine.

The GUI should be written in Java, the Engine in C or C++. They talk about the standard 
IO-Streams.

See
https://www.shredderchess.de/schach-info/features/uci-universal-chess-interface.html

 
###5.Mai 2020
Es soll ein europäisches Projekts sein!
 
 
TODO
1. Man benötigt zunächst ein Interface bzw. Protokoll wie es das UCI vorgemacht hat. 
Es sollte UCCI UniversalChineseChessInterface (UCCI) heißen.
Der Witz daran ist, das die gesamte Gültigkeitsprüfung der Züge in die Engine ausgelagert
wird. Einem Engine-Entwickler traut man mehr zu, als einen GUI-Entwickler. Außerdem wird 
die Stellung nur einmal bewertet; das spart Zeit bei der Entwicklung und bei der Ausführung. 

Die GUI sollte in Java geschrieben sein, die Engine in C oder C++. Engine und GUI kommunizieren
über Standard-IO-Streams.
 
Siehe
- Was ist [UCI](https://www.shredderchess.de/schach-info/features/uci-universal-chess-interface.html)
- Was ist eine [GUI](https://de.wikipedia.org/wiki/Grafische_Benutzeroberfl%C3%A4che)
- Was ist [Java]()
- Was ist [C und C++]()
- Was sind [IO-Streams]()
- Was ist eine Engine

####09:30
UCI ist universell! Die Notation ist nicht festgelegt. Dank an Meyer-Kahlen. Somit kann man 
gleich mit der Implementierung anfangen. Ich hoffe ich irre mich nicht.
